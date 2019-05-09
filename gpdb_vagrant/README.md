# How to start vagrant env
- copy greenplum-db-version.zip to gphelpers/vagrant/files/
- copy jdk rpm to files/

# Use enterprise build that has not been packaged for release
- copy bin_gpdb.tar.gz to gphelpers/vagrant/files

# This will perform the following tasks
- Launches VMs mdw, sdw1, and sdw2
- installs gpdb from greenplum-db-version.zip file
- installs gpdb from bin_gpdb.tar.gz file

Both versions, (release and dev) will be installed in parallel,
so you can run a release version and a dev version on the same
VMs
