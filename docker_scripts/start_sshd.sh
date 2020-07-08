#!/bin/bash

rm -f /etc/ssh/ssh_host_rsa_key
ssh-keygen -f /etc/ssh/ssh_host_rsa_key -N '' -t rsa
mkdir -p /var/run/sshd
/usr/sbin/sshd
