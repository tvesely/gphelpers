#!/usr/bin/env bash

set -ex

cp /vagrant/files/resolv.conf /etc/resolv.conf

## install epel
yum --enablerepo=extras install epel-release -y

yum install man ed git ntp rsync unzip curl wget sysstat python-pip gcc postgresql postgresql-devel python-devel libffi-devel openssl-devel gdb strace lsof psmisc -y

# If there was a previous run of gpdb init, delete the clusters
if [ -f /gpdb_init_finished ]; then
    killall postgres && echo "Killed Postgres..." || echo "No postgres processes killed"
fi

if [ -f /vagrant/files/jdk-*.rpm ]; then
    yum install /vagrant/files/jdk-*.rpm -y
fi

cat  <<EOF > /tmp/hosts.new
127.0.0.1  localhost localhost.localdomain localhost4 localhost4.localdomain4
::1         localhost localhost.localdomain localhost6 localhost6.localdomain6
EOF

# Setup networking to match networking seen in some customer environments
if [ $HOSTNAME == 'sdw2.gpdb.local' ]; then
    echo -e "DEVICE=lo:hostname\nIPADDR=192.168.99.102\nNETMASK=255.255.255.255\nONBOOT=yes\nNAME=lo:hostname" > /etc/sysconfig/network-scripts/ifcfg-lo:hostname
    chmod 644 /etc/sysconfig/network-scripts/ifcfg-lo:hostname
    ifup lo:hostname
else
    echo -e "192.168.99.102 via 192.168.64.102 dev eth1" > /etc/sysconfig/network-scripts/route-eth1
    chmod 644 /etc/sysconfig/network-scripts/route-eth1
    service network restart
fi

cat <<EOF > /tmp/hosts.new

192.168.64.100 mdw.gpdb.local mdw
192.168.64.101 sdw1.gpdb.local sdw1
192.168.99.102 sdw2.gpdb.local sdw2
EOF

mv /tmp/hosts.new /etc/hosts

# Set up gpadmin and keys for GPDB install
getent passwd gpadmin || useradd gpadmin

if [ ! -f /vagrant/ssh/id_rsa ]; then

    [ -f /vagrant/ssh/ ] || mkdir /vagrant/ssh
    ssh-keygen -t rsa -b 4096 -a 100 -f /vagrant/ssh/id_rsa -N ''
fi

cp -r /vagrant/ssh /root/.ssh; chmod 700 /root/.ssh; chmod 600 /root/.ssh/*; chown -R root:root /root/.ssh
cp -r /root/.ssh /home/gpadmin/
cat /vagrant/ssh/id_rsa.pub >> /root/.ssh/authorized_keys
cat /vagrant/ssh/id_rsa.pub >> /home/gpadmin/.ssh/authorized_keys

chmod 700 /home/gpadmin/.ssh
chmod 600 /home/gpadmin/.ssh/*
chown -R gpadmin:gpadmin /home/gpadmin/.ssh

## sudo for gpadmin
cp /vagrant/files/gpadmin.sudoers /etc/sudoers.d/gpadmin

if [ -f /vagrant/files/greenplum-db*.zip ]; then
    cp /vagrant/files/greenplum-db*.zip /tmp/greenplum-db.zip
    unzip -o /tmp/greenplum-db.zip
    SKIP=`awk '/^__END_HEADER__/ {print NR + 1; exit 0; }' greenplum-db*.bin`
    GPDB_INSTALL_PATH=/usr/local/greenplum-db

    # Wipe out the previous installation
    if [ -d $GPDB_INSTALL_PATH ]; then
        rm -rf $GPDB_INSTALL_PATH
    fi

    # Install the version in the files directory
    mkdir $GPDB_INSTALL_PATH
    tail -n +${SKIP} greenplum-db*.bin | tar zxf - -C $GPDB_INSTALL_PATH
    chown -R gpadmin:gpadmin $GPDB_INSTALL_PATH
fi

if [ -f /vagrant/files/bin_gpdb.tar.gz ]; then
    cp /vagrant/files/bin_gpdb.tar.gz /tmp/bin_gpdb.tar.gz
    GPDB_DEV_BUILD_INSTALL_PATH=/usr/local/greenplum-db-devel
    # Wipe out the previous installation
    if [ -d $GPDB_DEV_BUILD_INSTALL_PATH ]; then
        rm -rf $GPDB_DEV_BUILD_INSTALL_PATH
    fi

    # Install the version in the files directory
    mkdir $GPDB_DEV_BUILD_INSTALL_PATH
    tar -xzf /tmp/bin_gpdb.tar.gz -C $GPDB_DEV_BUILD_INSTALL_PATH
    chown -R gpadmin:gpadmin $GPDB_DEV_BUILD_INSTALL_PATH
fi

## config gpadmin with gpdb settings
if [ "${GPDB_INSTALL_PATH}" != "" ]; then
    ## setup gphome
    sed "s,^GPHOME.*,GPHOME=${GPDB_INSTALL_PATH}," ${GPDB_INSTALL_PATH}/greenplum_path.sh > ${GPDB_INSTALL_PATH}/greenplum_path.sh.tmp
    mv ${GPDB_INSTALL_PATH}/greenplum_path.sh.tmp ${GPDB_INSTALL_PATH}/greenplum_path.sh

    cat <<EOF > /tmp/gpdb_profile
source ${GPDB_INSTALL_PATH}/greenplum_path.sh
export PGPORT=5432
export MASTER_DATA_DIRECTORY=/data/master/gpseg-1
export PGUSER=gpadmin
export PGDATABASE=gpadmin
export PGHOST=mdw.gpdb.local
EOF

    cp /tmp/gpdb_profile ~root/
    cp /tmp/gpdb_profile ~gpadmin/
    chown gpadmin:gpadmin ~gpadmin/gpdb_profile

    # Wipe out the previous installation
    rm -rf /data/primary
    rm -rf /data/mirror
    rm -rf /data/master
fi

if [ "${GPDB_DEV_BUILD_INSTALL_PATH}" != "" ]; then
    cat <<EOF > /tmp/gpdb_dev_profile
source ${GPDB_DEV_BUILD_INSTALL_PATH}/greenplum_path.sh
export PGPORT=15432
export MASTER_DATA_DIRECTORY=/data/master_dev/gpseg-1
export PGUSER=gpadmin
export PGDATABASE=gpadmin
export PGHOST=mdw.gpdb.local
EOF

    cp /tmp/gpdb_dev_profile ~root/
    cp /tmp/gpdb_dev_profile ~gpadmin/
    chown gpadmin:gpadmin ~gpadmin/gpdb_dev_profile

    # Wipe out previous installation
    rm -rf /data/primary_dev
    rm -rf /data/mirror_dev
    rm -rf /data/master_dev
fi

[ -d /data ] || mkdir /data
[ -d /data/primary ] || mkdir /data/primary
[ -d /data/mirror ] || mkdir /data/mirror
[ -d /data/master ] || mkdir /data/master

[ -d /data/primary_dev ] || mkdir /data/primary_dev
[ -d /data/mirror_dev ] || mkdir /data/mirror_dev
[ -d /data/master_dev ] || mkdir /data/master_dev

chown -R gpadmin:gpadmin /data/*

if [ ! -f /gpdb_init_finished ]; then
    ## setup sysctl.conf
    cat <<EOF >> /etc/sysctl.conf
kernel.shmmax = 500000000
kernel.shmmni = 4096
kernel.shmall = 4000000000
kernel.sem = 250 512000 100 2048
kernel.sysrq = 1
kernel.core_uses_pid = 1
kernel.msgmnb = 65536
kernel.msgmax = 65536
kernel.msgmni = 2048
net.ipv4.tcp_syncookies = 1
net.ipv4.ip_forward = 0
net.ipv4.conf.default.accept_source_route = 0
net.ipv4.tcp_tw_recycle = 1
net.ipv4.tcp_max_syn_backlog = 4096
net.ipv4.conf.all.arp_filter = 1
net.ipv4.ip_local_port_range = 1025 65535
net.core.netdev_max_backlog = 10000
net.core.rmem_max = 2097152
net.core.wmem_max = 2097152
EOF

fi

sysctl -p && echo "all good here"

## fix ssh
echo -e "\nStrictHostKeyChecking no\n" >> /etc/ssh/ssh_config
service sshd restart

touch /gpdb_init_finished
