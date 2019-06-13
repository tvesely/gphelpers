#!/bin/bash
set -ex

source $(dirname $0)/common.sh

GIT_REPO=$1
GIT_BRANCH=$2
MAKE_COMMAND=${3:-"-k PGOPTIONS='-c optimizer=on' installcheck-world"}

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

	[ -d ${ARTIFACT_DIR}/$GPDB_SHA ] ||	mkdir ${ARTIFACT_DIR}/$GPDB_SHA

	[ -f ${ARTIFACT_DIR}/$GPDB_SHA/bin_gpdb.tar.gz ] ||	build_gpdb ${GPDB_VERSION}

	test_gpdb
}

main
