GP4X_DOCKER_RUN_IMAGE="pivotaldata/centos-gpdb-dev:6"
GP5X_DOCKER_BUILD_IMAGE="pivotaldata/centos-gpdb-dev:7-gcc6.2-llvm3.7"
GP5X_DOCKER_TEST_IMAGE="pivotaldata/centos-gpdb-dev:7-gcc6.2-llvm3.7"
GP6X_DOCKER_BUILD_IMAGE="pivotaldata/gpdb6-centos7-build:latest"
GP6X_DOCKER_TEST_IMAGE="pivotaldata/gpdb6-centos7-test:latest"

TEMP_GPDB_DOCKER_REPO=/tmp/gpdb_temp_docker_repo_$$
TEMP_GPADDON_REPO=/tmp/gpaddon_temp_docker_repo_$$

ARTIFACT_DIR=/tmp/artifacts


CLOUDSDK_CORE_PROJECT=data-gp-releng

function finish {
  rm -rf ${TEMP_GPDB_DOCKER_REPO}
  rm -rf ${TEMP_GPADDON_REPO}
}

make_temp_docker_repos() {
	trap finish EXIT

	if [ -d ${TEMP_GPDB_DOCKER_REPO} ]; then
		rm -rf ${TEMP_GPDB_DOCKER_REPO}
	fi

	git clone ${GIT_REPO} ${TEMP_GPDB_DOCKER_REPO}

	pushd ${TEMP_GPDB_DOCKER_REPO}
	  git checkout ${GIT_BRANCH}
      git submodule update --init --recursive
	  GPDB_SHA=$(git rev-parse HEAD)
      GPDB_VERSION=$(./getversion | perl -lane '/^([0-9])\.[0-9]+\.[0-9]+/; print $1')
	popd

	if [ -d ${TEMP_GPADDON_REPO} ]; then
		rm -rf ${TEMP_GPADDON_REPO}
	fi

	git clone git@github.com:pivotal/gp-addon ${TEMP_GPADDON_REPO}

}

set_docker_images() {
    if [ "${GPDB_VERSION}" -eq "4" ]; then
        DOCKER_BUILD_IMAGE="pivotaldata/centos-gpdb-dev:6"
        DOCKER_TEST_IMAGE="pivotaldata/centos-gpdb-dev:6"
    elif [ "${GPDB_VERSION}" -eq "5" ]; then
        DOCKER_BUILD_IMAGE=${GP5X_DOCKER_BUILD_IMAGE}
        DOCKER_TEST_IMAGE=${GP5X_DOCKER_TEST_IMAGE}
        pushd ${TEMP_GPADDON_REPO}
            git checkout 5X_STABLE
        popd
    elif [ "${GPDB_VERSION}" -eq "6" ]; then
        DOCKER_BUILD_IMAGE=${GP6X_DOCKER_BUILD_IMAGE}
        DOCKER_TEST_IMAGE=${GP6X_DOCKER_TEST_IMAGE}

        CLOUDSDK_CORE_PROJECT=${CLOUDSDK_CORE_PROJECT} \
          gsutil \
            -m cp gs://gp-internal-artifacts/centos7/{sigar,lib,python}* \
            ${ARTIFACT_DIR}

        LIBQUICKLZ_RPM=$(basename `ls $ARTIFACT_DIR/libquicklz-1*.rpm`)
        LIBQUICKLZ_DEVEL_RPM=$(basename `ls $ARTIFACT_DIR/libquicklz-devel*.rpm`)
        LIBSIGAR_RPM=$(basename `ls $ARTIFACT_DIR/sigar*.targz`)
        PYTHON_TGZ=$(basename `ls $ARTIFACT_DIR/python*.tar.gz`)
    fi

}

setup_helper_environment() {
    make_temp_docker_repos
    set_docker_images
}
