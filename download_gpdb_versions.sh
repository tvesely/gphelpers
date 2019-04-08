#!/bin/bash

set -xe

GPDB_5X_RPM_DIRECTORY=${HOME}/platform/gpdb/rpms/
GPDB_5X_VERSIONS='5.0.0 5.1.0 5.2.0 5.3.0 5.4.0 5.4.1 5.7.1 5.8.0 5.8.1 5.9.0 5.10.2 5.11.3 5.12.0 5.13.0 5.14.0 5.15.1 5.16.0 5.17.0 5.18.0'

pivnet_login() {
    source ${HOME}/deployments/credstore/credstore.bash
    pivnet login --api-token=`passgetstring web/network.pivotal.io uaa_api_tokens`
}

pivnet_download_5X() {
    SLUG=$1

    if [ ! -d ${GPDB_5X_RPM_DIRECTORY} ]; then
        mkdir -p ${GPDB_5X_RPM_DIRECTORY}
    fi

    if [ ! -f ${GPDB_5X_RPM_DIRECTORY}/greenplum-db-${SLUG}-rhel7-x86_64.rpm ]; then
        pushd ${GPDB_5X_RPM_DIRECTORY}
            pivnet download-product-files -p pivotal-gpdb -r ${SLUG} -g greenplum-db-${SLUG}-rhel7-x86_64.rpm
        popd
    fi
}


main() {
    pivnet_login
    for version in ${GPDB_5X_VERSIONS}; do
        pivnet_download_5X ${version}
    done
}

main
