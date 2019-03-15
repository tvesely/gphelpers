#!/bin/bash
set -ex

GIT_REPO=$1
GIT_BRANCH=$2
MAKE_COMMAND=${3:-"-k PGOPTIONS='-c optimizer=on' installcheck-world"}

GP5X_DOCKER_BUILD_IMAGE="pivotaldata/centos-gpdb-dev:7-gcc6.2-llvm3.7"
GP5X_DOCKER_TEST_IMAGE="pivotaldata/centos-gpdb-dev:7-gcc6.2-llvm3.7"
GP6X_DOCKER_BUILD_IMAGE="pivotaldata/gpdb6-centos7-build:latest"
GP6X_DOCKER_TEST_IMAGE="pivotaldata/gpdb6-centos7-test:latest"

TEMP_GPDB_DOCKER_REPO=/tmp/gpdb_temp_docker_repo_$$

ARTIFACT_DIR=/tmp/artifacts
GPADDON_TEMP_REPO=/tmp/gpaddon_temp_docker_repo

export CLOUDSDK_CORE_PROJECT=data-gp-releng

function finish {
  rm -rf ${TEMP_GPDB_DOCKER_REPO}
}

build_gpdb() {
    GPDB_VERSION=$1

	if [ -d ${GPADDON_TEMP_REPO} ]; then
		rm -rf ${GPADDON_TEMP_REPO}
	fi

	git clone git@github.com:pivotal/gp-addon ${GPADDON_TEMP_REPO}

    
    if [ "${GPDB_VERSION}" -eq "5" ]; then
        DOCKER_BUILD_IMAGE=${GP5X_DOCKER_BUILD_IMAGE}
        pushd ${GPADDON_TEMP_REPO}
            git checkout 5X_STABLE
        popd

    elif [ "${GPDB_VERSION}" -eq "6" ]; then
        gsutil -m cp gs://gp-internal-artifacts/centos7/{sigar,lib,python}* ${ARTIFACT_DIR}

        LIBQUICKLZ_RPM=$(basename `ls $ARTIFACT_DIR/libquicklz-1*.rpm`)
        LIBQUICKLZ_DEVEL_RPM=$(basename `ls $ARTIFACT_DIR/libquicklz-devel*.rpm`)
        LIBSIGAR_RPM=$(basename `ls $ARTIFACT_DIR/sigar*.targz`)
        PYTHON_TGZ=$(basename `ls $ARTIFACT_DIR/python*.tar.gz`)

        DOCKER_BUILD_IMAGE=${GP6X_DOCKER_BUILD_IMAGE}
    fi


	docker pull ${DOCKER_BUILD_IMAGE}


	docker run -it --rm \
	  -v ${TEMP_GPDB_DOCKER_REPO}:/gpdb_repo \
	  -v ${GPADDON_TEMP_REPO}:/gpaddon_src \
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
    if [ "${GPDB_VERSION}" -eq "5" ]; then
        DOCKER_TEST_IMAGE=${GP5X_DOCKER_TEST_IMAGE}
    elif [ "${GPDB_VERSION}" -eq "6" ]; then
        DOCKER_TEST_IMAGE=${GP6X_DOCKER_TEST_IMAGE}
    fi

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
	trap finish EXIT

	if [ -d ${TEMP_GPDB_DOCKER_REPO} ]; then
		rm -rf ${TEMP_GPDB_DOCKER_REPO}
	fi

	git clone ${GIT_REPO} ${TEMP_GPDB_DOCKER_REPO}
	pushd ${TEMP_GPDB_DOCKER_REPO}
	  git checkout ${GIT_BRANCH}
      git submodule update --init --recursive
	  GPDB_SHA=$(git rev-parse HEAD)
      GPDB_VERSION=$(expr "`./getversion`" : "\(^[0-9]\)\.[0-9]\+\.[0-9]\+")
	popd


	[ -d ${ARTIFACT_DIR} ] || mkdir ${ARTIFACT_DIR}

	[ -d ${ARTIFACT_DIR}/$GPDB_SHA ] ||	mkdir ${ARTIFACT_DIR}/$GPDB_SHA

	[ -f ${ARTIFACT_DIR}/$GPDB_SHA/bin_gpdb.tar.gz ] ||	build_gpdb ${GPDB_VERSION}

	test_gpdb
}

main
