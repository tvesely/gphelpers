GP4X_DOCKER_RUN_IMAGE="pivotaldata/centos-gpdb-dev:6"
GP5X_DOCKER_BUILD_IMAGE="pivotaldata/centos-gpdb-dev:7-gcc6.2-llvm3.7"
GP5X_DOCKER_TEST_IMAGE="pivotaldata/centos-gpdb-dev:7-gcc6.2-llvm3.7"
GP6X_DOCKER_BUILD_IMAGE="pivotaldata/gpdb6-centos7-build:latest"
GP6X_DOCKER_TEST_IMAGE="pivotaldata/gpdb6-centos7-test:latest"
GP7X_DOCKER_BUILD_IMAGE="pivotaldata/gpdb6-centos7-build:latest"
GP7X_DOCKER_TEST_IMAGE="pivotaldata/gpdb6-centos7-test:latest"

TEMP_GPDB_DOCKER_REPO=/tmp/gpdb_temp_docker_repo_$$
TEMP_GPADDON_REPO=/tmp/gpaddon_temp_docker_repo_$$

ARTIFACT_DIR=/tmp/artifacts

export CLOUDSDK_CORE_PROJECT=data-gp-releng

GPDB_DEB_DIRECTORY=${HOME}/platform/gpdb/debs/
GPDB_RPM_DIRECTORY=${HOME}/platform/gpdb/rpms/
GP4K_DIRECTORY=${HOME}/platform/gp4k/
GPDB_4X_ZIP_DIRECTORY=${HOME}/platform/gpdb/zip/

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
          if [ ! "$FASTCLONE" == "true" ]; then
              git submodule update --init --recursive
          fi
          GPDB_SHA=$(git rev-parse HEAD)
          GPDB_VERSION=$(./getversion | perl -lane '/^([0-9])\.[0-9]+\.[0-9]+/; print $1')
          ORCA_TAG=$(perl -lane 'next unless /ORCA_TAG:\s+(.*)$/; print $1;' ./concourse/tasks/compile_gpdb.yml)
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
        CONFIGURE_FLAGS="--enable-debug-extensions ${CONFIGURE_FLAGS}"
    elif [ "${GPDB_VERSION}" -eq "7" ]; then
        DOCKER_BUILD_IMAGE=${GP7X_DOCKER_BUILD_IMAGE}
        DOCKER_TEST_IMAGE=${GP7X_DOCKER_TEST_IMAGE}

        CLOUDSDK_CORE_PROJECT=${CLOUDSDK_CORE_PROJECT} \
          gsutil \
            -m cp gs://gp-internal-artifacts/centos7/{sigar,lib,python}* \
            ${ARTIFACT_DIR}

        LIBQUICKLZ_RPM=$(basename `ls $ARTIFACT_DIR/libquicklz-1*.rpm`)
        LIBQUICKLZ_DEVEL_RPM=$(basename `ls $ARTIFACT_DIR/libquicklz-devel*.rpm`)
        LIBSIGAR_RPM=$(basename `ls $ARTIFACT_DIR/sigar*.targz`)
        PYTHON_TGZ=$(basename `ls $ARTIFACT_DIR/python*.tar.gz`)
        CONFIGURE_FLAGS="--enable-debug-extensions ${CONFIGURE_FLAGS}"
    fi

}

get_pivnet_token() {
    # This lets the author use his credstore without setting magic stuff
    # by using even more magic.
    if [ -f ${HOME}/deployments/credstore/credstore.bash ]; then

        # for privacy!
        set +x
            source ${HOME}/deployments/credstore/credstore.bash
            PIVNET_API_TOKEN=`passgetstring web/network.pivotal.io uaa_api_tokens`
        set -x
    fi

    if [ "${PIVNET_API_TOKEN}" == "" ]; then
        echo "Must set PIVNET_API_TOKEN to download from pivnet"
        exit 1
    fi
}

pivnet_login() {
    if [ ! "${PIVNET_LOGGED_IN}" == "true" ]; then
        get_pivnet_token

        pivnet login --api-token=${PIVNET_API_TOKEN}
    fi

    PIVNET_LOGGED_IN="true"
}

pivnet_download_gpdb_4X() {
    SLUG=$1

    if [ ! -d ${GPDB_4X_ZIP_DIRECTORY} ]; then
        mkdir -p ${GPDB_4X_ZIP_DIRECTORY}
    fi

    if [ ! -f ${GPDB_4X_ZIP_DIRECTORY}/greenplum-db-${SLUG}*.zip ]; then
        pivnet_login
        pushd ${GPDB_4X_ZIP_DIRECTORY}
            pivnet download-product-files -p pivotal-gpdb -r ${SLUG} -g greenplum-db-${SLUG}*rhel5*.zip
        popd
    fi
}

pivnet_download_gpdb() {
    SLUG=$1
    DOWNLOAD_MAJOR_VERSION=$(echo $SLUG | perl -lane '/^([0-9])\.[0-9]+\.[0-9]+/; print $1')

    if [ "${DOWNLOAD_MAJOR_VERSION}" == "6" ]; then
        PLATFORMS="rhel7-x86_64 ubuntu18.04-amd64"
    else
        PLATFORMS="rhel7-x86_64"
    fi

    for PLATFORM in $PLATFORMS; do
        pivnet_download_gpdb_platform ${SLUG} ${PLATFORM}
    done
}

pivnet_download_gpdb_platform() {
    SLUG=$1
    PLATFORM=$2

    if [ ${PLATFORM} == "rhel7-x86_64" ]; then
        if [ ! -d ${GPDB_RPM_DIRECTORY} ]; then
            mkdir -p ${GPDB_RPM_DIRECTORY}
        fi

        if [ ! -f ${GPDB_RPM_DIRECTORY}/greenplum-db-${SLUG}-rhel7-x86_64.rpm ]; then
            pivnet_login
            pushd ${GPDB_RPM_DIRECTORY}
                pivnet download-product-files -p pivotal-gpdb -r ${SLUG} -g greenplum-db-${SLUG}-rhel7-x86_64.rpm
            popd
        fi
    elif [ ${PLATFORM} == "ubuntu18.04-amd64" ]; then
        [ -d ${GPDB_DEB_DIRECTORY} ] || mkdir -p ${GPDB_DEB_DIRECTORY}

        if [ ! -f ${GPDB_DEB_DIRECTORY}/greenplum-db-${SLUG}-ubuntu18.04-amd64.deb ]; then
            pivnet_login
            pushd ${GPDB_DEB_DIRECTORY}
                pivnet download-product-files -p pivotal-gpdb -r ${SLUG} -g greenplum-db-${SLUG}-ubuntu18.04-amd64.deb || echo "Version ${SLUG} for ${PLATFORM} unavailable"
            popd
        fi
    fi
}

pivnet_download_gp4k() {
    SLUG=$1
    local VERSION_DIR=${GP4K_DIRECTORY}/$SLUG

    mkdir -p ${VERSION_DIR}

    if [ ! -f ${VERSION_DIR}/greenplum-for-kubernetes-v${SLUG}.tar.gz ]; then
        pivnet_login
        pushd ${VERSION_DIR}
            pivnet download-product-files -p greenplum-for-kubernetes -r ${SLUG} -g greenplum-for-kubernetes-v${SLUG}.tar.gz
        popd
    fi

    if [ ! -d ${VERSION_DIR}/greenplum-for-kubernetes-v${SLUG} ]; then
        pushd ${VERSION_DIR}
            tar -xzf greenplum-for-kubernetes-v${SLUG}.tar.gz
        popd
    fi

    docker load -i ${VERSION_DIR}/greenplum-for-kubernetes-v${SLUG}/images/greenplum-for-kubernetes
    docker load -i ${VERSION_DIR}/greenplum-for-kubernetes-v${SLUG}/images/greenplum-operator
}

setup_helper_environment() {
    [ -d ${ARTIFACT_DIR} ] || mkdir ${ARTIFACT_DIR}

    make_temp_docker_repos
    set_docker_images
}

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
	  -e ORCA_TAG=${ORCA_TAG} \
	  -e CONFIGURE_FLAGS="--enable-cassert ${CONFIGURE_FLAGS}" \
	  -e BLD_TARGETS="clients loaders" \
	  -e OUTPUT_ARTIFACT_DIR=gpdb_artifacts/${GPDB_SHA} \
	  ${DOCKER_BUILD_IMAGE} \
	  bash -c "mkdir /gpAux_ext/ &&
				cp -R /gpdb_repo gpdb_src &&
				gpdb_src/concourse/scripts/sync_tools.bash &&
				gpdb_src/concourse/scripts/compile_gpdb.bash"
}

