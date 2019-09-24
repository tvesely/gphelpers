#!/bin/bash

set -xe

source $(dirname $0)/common.sh

GPDB_6X_VERSIONS='6.0.0'
GPDB_5X_VERSIONS='5.0.0 5.1.0 5.2.0 5.3.0 5.4.0 5.4.1 5.7.1 5.8.0 5.8.1 5.9.0 5.10.2 5.11.3 5.12.0 5.13.0 5.14.0 5.15.1 5.16.0 5.17.0 5.18.0'
GPDB_4X_VERSIONS='4.3.10.0 4.3.11.1 4.3.11.2 4.3.11.3 4.3.12.0 4.3.13.0 4.3.17.0 4.3.30.4'

main() {
    for version in ${GPDB_4X_VERSIONS}; do
        pivnet_download_gpdb_4X ${version}
    done

    for version in ${GPDB_5X_VERSIONS}; do
        pivnet_download_gpdb ${version}
    done

    for version in ${GPDB_6X_VERSIONS}; do
        pivnet_download_gpdb ${version}
    done
}

main
