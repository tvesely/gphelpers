gcp_inventory:
	echo "[new_instances:vars]" > gcp_inventory
	echo "ansible_user=$(ANSIBLE_USER)" >> gcp_inventory
	echo "ansible_ssh_private_key_file=$(ANSIBLE_SSH_KEY_FILE)" >> gcp_inventory

clean:
	./delete_instance_if_exists.sh
	rm -f gcp_inventory
