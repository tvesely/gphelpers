#!/bin/bash
set -ex

SCRIPT_DIR=$(dirname $0)
source ${SCRIPT_DIR}/common.sh

GIT_REPO=$1
GIT_BRANCH=$2

main() {
    setup_helper_environment

	[ -d ${ARTIFACT_DIR}/$GPDB_SHA ] ||	mkdir ${ARTIFACT_DIR}/$GPDB_SHA

    GPDB_BUILD_ARTIFACT=${ARTIFACT_DIR}/${GPDB_SHA}/bin_gpdb.tar.gz
	[ -f ${GPDB_BUILD_ARTIFACT} ] || build_gpdb ${GPDB_VERSION}

    cp ${GPDB_BUILD_ARTIFACT} $SCRIPT_DIR/gpdb_vagrant/files/
    pushd ${SCRIPT_DIR}/gpdb_vagrant
        vagrant up --provision
    popd
}

main
