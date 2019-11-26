# What it does:

The playbook `tpc-ds.yaml` runs two tasks, gen_postgres_cluster and
tpc_ds_gen.gen_postgres_cluster starts a postgres cluster, creates
user-specified

tablespaces and databases, and sets GUCs.tpc_ds_gen currently generate data
with the user specified scale and load the data into the databases.#

Prerequisites:

ansible 2.9.0+

```shell
pip install ansible
```

Postgres 12.x +

Quick start:

Just run this to load TPC-DS data into the `postgres` database:

```shell
ansible-playbook -e @group_vars/minimal_config.yaml -e postgres_install_path=</path/to/postgres/installation> -e postgres_database_path=</path/to/postgres/data/directory> -e datagen_scale=<tpcds data generation scale factor> -e postgres_user=<postgres user> tpc-ds.yaml
```

If you are comparing zedstore with heap storage, first compile and install [zedstore branch](https://github.com/greenplum-db/postgres/tree/zedstore) and invoke ansible with the following command:

```shell
ansible-playbook -e @group_vars/minimal_zedstore.yaml -e postgres_install_path=</path/to/postgres/installation> -e postgres_database_path=</path/to/postgres/data/directory> -e datagen_scale=<tpcds data generation scale factor> -e postgres_user=<postgres user> tpc-ds.yaml
```


More detailed configurations can be found in the following locations:

[group_vars/vagrant_workstation.yaml](group_vars/vagrant_workstation.yaml)
[group_vars/precision_7910.yaml](group_vars/precision_7910.yaml)
[group_vars/precision_3431.yaml](group_vars/precision_3431.yaml)
