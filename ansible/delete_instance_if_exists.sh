#!/bin/bash

instance_ip=$(gcloud compute instances list --project=${ANSIBLE_GCP_PROJECT} --filter="name='${ANSIBLE_GCP_INSTANCE_NAME}' zone:(${ANSIBLE_GCP_ZONE})" --format='get(networkInterfaces[0].accessConfigs[0].natIP)')

if [ "${instance_ip}" != "" ]; then
  gcloud compute instances delete $ANSIBLE_GCP_INSTANCE_NAME --project=${ANSIBLE_GCP_PROJECT} --zone=${ANSIBLE_GCP_ZONE}
  ssh-keygen -f ~/.ssh/known_hosts -R ${instance_ip}
fi
