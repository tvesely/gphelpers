.PHONEY: cluster clean
all: cluster

cluster: gcp_inventory
	ansible-playbook -i gcp_inventory provision_gcp_instance.yaml -vvv

gcp_inventory:
	echo "[workstation_instances:vars]" > gcp_inventory
	echo "ansible_user=$(ANSIBLE_USER)" >> gcp_inventory
	echo "ansible_ssh_private_key_file=$(ANSIBLE_SSH_KEY_FILE)" >> gcp_inventory

clean:
	./delete_instance_if_exists.sh
	rm -f gcp_inventory
