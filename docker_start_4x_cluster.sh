#!/bin/bash
set -ex

source $(dirname $0)/common.sh


GIT_REPO=~/workspace/gpdb4
GIT_BRANCH=4.3_STABLE
GPDB_VERSION_TO_RUN=$1

TRANSFER_DIR=/tmp/${GPDB_VERSION_TO_RUN}_docker

GPDB_BIN_DIR=~/platform/gpdb/rhel5/bin/

start_gpdb() {
    GPDB_VERSION=$1

    docker pull ${DOCKER_RUN_IMAGE}


    DOCKER_CONTAINER=$(docker run -it --rm -d \
      -v ${TEMP_GPDB_DOCKER_REPO}:/gpdb_repo \
      -v ${GPDB_BIN_DIR}/:/bin_gpdb \
      -v ${TRANSFER_DIR}:/transfer \
      --name gpdb_${GPDB_VERSION} \
      --cap-add=SYS_PTRACE \
          ${DOCKER_TEST_IMAGE} \
          /bin/bash
    )

    SKIP=`awk '/^__END_HEADER__/ {print NR + 1; exit 0; }' ${GPDB_BIN_DIR}/greenplum-db-${GPDB_VERSION}-rhel5-x86_64.bin`

    docker exec -it ${DOCKER_CONTAINER} \
    bash -c "cp -R /gpdb_repo /gpdb_src
       mkdir /usr/local/greenplum-db-devel/
       tail -n +${SKIP} /bin_gpdb/greenplum-db-4.3.29.0-rhel5-x86_64.bin | tar zxf - -C /usr/local/greenplum-db-devel/
       gpdb_src/ci/concourse/scripts/setup_gpadmin_user.bash centos
       source gpdb_src/ci/concourse/scripts/common.bash
       time setup_gpadmin_user
       time make_cluster
       "

       echo container=${DOCKER_CONTAINER} || \
       echo "ICW Failed on container ${DOCKER_CONTAINER}" && \
       echo "   HINT: docker exec -it ${DOCKER_CONTAINER}"
}

main() {
    setup_helper_environment

    if [ ! -d ${TRANSFER_DIR} ]; then
        mkdir ${TRANSFER_DIR}
    fi

    if [ -f ${GPDB_BIN_DIR}/greenplum-db*${GPDB_VERSION_TO_RUN}*.bin ]; then
        start_gpdb ${GPDB_VERSION_TO_RUN}
    fi
}

main
