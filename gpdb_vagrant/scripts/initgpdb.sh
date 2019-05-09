#!/bin/bash
set -x

if [ -f /usr/local/greenplum-db/greenplum_path.sh ]; then

    source /usr/local/greenplum-db/greenplum_path.sh
    export PGDATABASE=gpadmin
    export PGHOST=mdw.gpdb.local
    export MASTER_DATA_DIRECTORY=/data/master/gpseg-1

    cp /vagrant/files/gpinitsystem_config ~gpadmin/
    cat /etc/hosts | egrep sdw.$ | awk '{print $2}' > ~gpadmin/hostfile
    chmod 775 ~gpadmin/gpinitsystem_config
    chown gpadmin:gpadmin ~gpadmin/*
    #sudo -u gpadmin source /usr/local/greenplum-db/greenplum_path.sh; gpinitsystem -a -c ~gpadmin/gpinitsystem_config
    su --login -c 'git config --global url."git@github.com:".insteadOf "https://github.com/"' gpadmin
    su --login -c "source ~/gpdb_profile; gpinitsystem -a -c ~gpadmin/gpinitsystem_config" gpadmin; echo "bypass error check"
fi

if [ -f /usr/local/greenplum-db-devel/greenplum_path.sh ]; then
    source /usr/local/greenplum-db-devel/greenplum_path.sh
    export PGDATABASE=gpadmin
    export PGHOST=mdw.gpdb.local
    export MASTER_DATA_DIRECTORY=/data/master/gpseg-1

    cp /vagrant/files/gpinitsystem_config_dev ~gpadmin/
    cat /etc/hosts | egrep sdw.$ | awk '{print $2}' > ~gpadmin/hostfile
    chmod 775 ~gpadmin/gpinitsystem_config_dev
    chown gpadmin:gpadmin ~gpadmin/*

    su --login -c 'git config --global url."git@github.com:".insteadOf "https://github.com/"' gpadmin
    su --login -c "source ~/gpdb_dev_profile; gpinitsystem -a -c ~gpadmin/gpinitsystem_config_dev" gpadmin; echo "bypass error check"
fi
