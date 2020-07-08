#!/bin/bash

sudo /home/gpadmin/docker_scripts/start_sshd.sh
ssh-keygen -t rsa -N "" -f /home/gpadmin/.ssh/id_rsa
cat /home/gpadmin/.ssh/id_rsa.pub >> /home/gpadmin/.ssh/authorized_keys
chmod 600 /home/gpadmin/.ssh/authorized_keys
source /usr/local/greenplum-db/greenplum_path.sh
make -C ~/workspace/gpdb/gpAux/gpdemo/
sleep infinity
