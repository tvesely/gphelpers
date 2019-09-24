#!/bin/bash
set -ex

source $(dirname $0)/common.sh

GIT_REPO=~/workspace/gpdb4
GIT_BRANCH=4.3_STABLE
GPDB_VERSION_TO_RUN=$1
FASTCLONE=true

TRANSFER_DIR=/tmp/${GPDB_VERSION_TO_RUN}_docker

start_gpdb() {
    GPDB_VERSION=$1

    GPDB_BIN_DIR=/tmp/gpdb_bin_dir_$$
    mkdir ${GPDB_BIN_DIR}
    pushd ${GPDB_BIN_DIR}
        unzip ${GPDB_4X_ZIP_DIRECTORY}/greenplum-db-${GPDB_VERSION}*rhel5*.zip
    popd

    docker pull ${DOCKER_TEST_IMAGE}

    DOCKER_CONTAINER=$(docker run -it --rm -d \
      -v ${TEMP_GPDB_DOCKER_REPO}:/gpdb_repo \
      -v ${GPDB_BIN_DIR}/:/bin_gpdb \
      -v ${TRANSFER_DIR}:/transfer \
      --name gpdb_${GPDB_VERSION} \
      --cap-add=SYS_PTRACE \
          ${DOCKER_TEST_IMAGE} \
          /bin/bash
    )


    SKIP=`awk '/^__END_HEADER__/ {print NR + 1; exit 0; }' ${GPDB_BIN_DIR}/greenplum-db-${GPDB_VERSION}*rhel5*.bin`

    docker exec -it ${DOCKER_CONTAINER} \
    bash -c "cp -R /gpdb_repo /gpdb_src
       mkdir /usr/local/greenplum-db-devel/
       tail -n +${SKIP} /bin_gpdb/greenplum-db-${GPDB_VERSION}*rhel5*.bin | tar zxf - -C /usr/local/greenplum-db-devel/
       gpdb_src/ci/concourse/scripts/setup_gpadmin_user.bash centos
       source gpdb_src/ci/concourse/scripts/common.bash
       time setup_gpadmin_user
       time make_cluster
       "

       echo container=${DOCKER_CONTAINER} || \
       echo "ICW Failed on container ${DOCKER_CONTAINER}" && \
       echo "   HINT: docker exec -it ${DOCKER_CONTAINER}"

    rm ${GPDB_BIN_DIR}
}

main() {
    setup_helper_environment

    if [ ! -d ${TRANSFER_DIR} ]; then
        mkdir ${TRANSFER_DIR}
    fi

    pivnet_download_gpdb_4X ${GPDB_VERSION_TO_RUN}

    if [ -f ${GPDB_4X_ZIP_DIRECTORY}/greenplum-db*${GPDB_VERSION_TO_RUN}*.zip ]; then
        start_gpdb ${GPDB_VERSION_TO_RUN}
    fi
}

main
