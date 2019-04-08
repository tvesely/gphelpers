#!/bin/bash
set -ex

source $(dirname $0)/common.sh

GIT_REPO=$1
GIT_BRANCH=$2
MAKE_COMMAND=${3:-"-k PGOPTIONS='-c optimizer=on' installcheck-world"}

ARTIFACT_DIR=/tmp/artifacts

export CLOUDSDK_CORE_PROJECT=data-gp-releng

build_gpdb() {
    GPDB_VERSION=$1

    


	docker pull ${DOCKER_BUILD_IMAGE}


	docker run -it --rm \
	  -v ${TEMP_GPDB_DOCKER_REPO}:/gpdb_repo \
	  -v ${TEMP_GPADDON_REPO}:/gpaddon_src \
	  -v ${ARTIFACT_DIR}/${LIBQUICKLZ_RPM}:/libquicklz-installer/${LIBQUICKLZ_RPM} \
	  -v ${ARTIFACT_DIR}/${LIBQUICKLZ_DEVEL_RPM}:/libquicklz-devel-installer/${LIBQUICKLZ_DEVEL_RPM} \
	  -v ${ARTIFACT_DIR}/${LIBSIGAR_RPM}:/libsigar-installer/${LIBSIGAR_RPM} \
	  -v ${ARTIFACT_DIR}/${PYTHON_TGZ}:/python-tarball/${PYTHON_TGZ} \
	  -v /tmp/artifacts:/gpdb_artifacts \
	  -e IVYREPO_PASSWD="${IVYREPO_PASSWD}" \
	  -e IVYREPO_USER="${IVYREPO_USER}" \
	  -e IVYREPO_REALM="${IVYREPO_REALM}" \
	  -e IVYREPO_HOST="${IVYREPO_HOST}" \
	  -e TARGET_OS=centos \
	  -e TARGET_OS_VERSION=7 \
	  -e TASK_OS=centos \
	  -e TASK_OS_VERSION=7 \
	  -e CONFIGURE_FLAGS="--enable-cassert ${CONFIGURE_FLAGS}" \
	  -e BLD_TARGETS="clients loaders" \
	  -e OUTPUT_ARTIFACT_DIR=gpdb_artifacts/${GPDB_SHA} \
	  ${DOCKER_BUILD_IMAGE} \
	  bash -c "mkdir /gpAux_ext/ &&
				cp -R /gpdb_repo gpdb_src &&
				gpdb_src/concourse/scripts/sync_tools.bash &&
				gpdb_src/concourse/scripts/compile_gpdb.bash"
}

test_gpdb() {

	docker pull ${DOCKER_TEST_IMAGE}

	DOCKER_CONTAINER=$(docker run -it --rm -d \
	  -v ${TEMP_GPDB_DOCKER_REPO}:/gpdb_repo \
	  -v ${ARTIFACT_DIR}/${GPDB_SHA}:/bin_gpdb \
      -e MAKE_TEST_COMMAND="${MAKE_COMMAND}" \
      -e TEST_OS=centos \
	  ${DOCKER_TEST_IMAGE} \
	  /bin/bash)


	docker exec -it ${DOCKER_CONTAINER} \
	  bash -c "mkdir /gpAux_ext/ &&
				cp -R /gpdb_repo gpdb_src
			    gpdb_src/concourse/scripts/ic_gpdb.bash" && \
	echo container=${DOCKER_CONTAINER} || \
	echo "ICW Failed on container ${DOCKER_CONTAINER}" && \
	echo "   HINT: docker exec -it ${DOCKER_CONTAINER}"

}

main() {
    setup_helper_environment

	[ -d ${ARTIFACT_DIR} ] || mkdir ${ARTIFACT_DIR}

	[ -d ${ARTIFACT_DIR}/$GPDB_SHA ] ||	mkdir ${ARTIFACT_DIR}/$GPDB_SHA

	[ -f ${ARTIFACT_DIR}/$GPDB_SHA/bin_gpdb.tar.gz ] ||	build_gpdb ${GPDB_VERSION}

	test_gpdb
}

main
