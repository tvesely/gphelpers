#!/bin/bash

instance_ip=$(gcloud compute instances list --project=${PROJECT} --filter="name='${INSTANCE_NAME}' zone:(${ZONE})" --format='get(networkInterfaces[0].accessConfigs[0].natIP)')

if [ "${instance_ip}" != "" ]; then
  gcloud compute instances delete pg-benchmark --project=${PROJECT} --zone=${ZONE}
  ssh-keygen -f ~/.ssh/known_hosts -R ${instance_ip}
fi
