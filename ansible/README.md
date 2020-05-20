# TPC-DS data loading for Postgres

The playbook `tpc-ds.yaml` runs two ansible roles, generate_postgres_database and
load_tpcds_data. 

## [generate_postgres_database](roles/generate_postgres_database)

 * Initializes a Postgres at `postgres_install_path` if it does not already exist.
 * If defined by the group_vars, creates user-specified tablespaces and databases
 * Sets gucs defined by group_vars

See the [README](roles/generate_postgres_database/README.md) for more details.

## [load_tpcds_data](roles/load_tpcds_data)

 * Generates TPC-DS data with the user specified scale
 * Loads the data into the databases specified by the group_vars

See the [README](roles/load_tpcds_data/README.md) for more details.

## Prerequisites:

 * ansible 2.9.0+
 * Postgres 12.x +

## Quick start:

```shell
pip install ansible
```

Just run this to load TPC-DS data into the `postgres` database:

```shell
ansible-playbook --ask-become-pass -e @group_vars/minimal_config.yaml -e postgres_install_path=</path/to/postgres/installation> -e postgres_database_path=</path/to/postgres/data/directory> -e datagen_scale=<tpcds data generation scale factor> -e postgres_user=<postgres user> tpc-ds.yaml
```

If you are comparing zedstore with heap storage, first compile and install Postgres using the [zedstore branch](https://github.com/greenplum-db/postgres/tree/zedstore) then invoke ansible with the following command:

```shell
ansible-playbook --ask-become-pass -e @group_vars/minimal_zedstore.yaml -e postgres_install_path=</path/to/postgres/installation> -e postgres_database_path=</path/to/postgres/data/directory> -e datagen_scale=<tpcds data generation scale factor> -e postgres_user=<postgres user> tpc-ds.yaml
```

More detailed configurations can be found in the following locations:

[group_vars/vagrant_workstation.yaml](group_vars/vagrant_workstation.yaml)

[group_vars/precision_7910.yaml](group_vars/precision_7910.yaml)

[group_vars/precision_3431.yaml](group_vars/precision_3431.yaml)


## Provosion a GCP workstaion with a Postgres database

Edit file /etc/ansible/ansible.cfg to include roles from the [envsetup repo](https://github.com/dreddor/envsetup/tree/tpc-ds-gen)
```
# Paths to search for roles, colon separated
roles_path = ~/.ansible/roles:/usr/share/ansible/roles:/etc/ansible/roles:~/deployments/envsetup/roles
```

Set some env variables, refer to [set-secrets.sh.template](set-secrets.sh.template)
```
source set-secrets.sh
```

Run ansible playbook from the Makefile
```
make
```

To destroy the workstation
```
make clean
```
