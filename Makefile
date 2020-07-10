GPDB_VERSION ?= master
GPDB_REPO ?= https://github.com/greenplum-db/gpdb
GP4K_IMAGE_NAME ?= greenplum-for-kubernetes

all: gpdb-docker

clean:
	docker rmi gpdb-build-objcache

gpdb-cache-init:
	if [ "$(shell docker images gpdb-build-objcache -q)" = "" ]; then \
		DOCKER_BUILDKIT=1 BUILDKIT_PROGRESS=plain docker build --build-arg gpdb_version='master' --target=greenplum-builder -f Dockerfile -t gpdb-build-objcache .; \
	fi;

gpdb-docker: gpdb-cache-init
	DOCKER_BUILDKIT=1 BUILDKIT_PROGRESS=plain docker build --build-arg gpdb_version=${GPDB_VERSION} --build-arg gpdb_repo=${GPDB_REPO} --build-arg greenplumBuilderBaseImage=gpdb-build-objcache:latest -f Dockerfile -t greenplum-db:${GPDB_VERSION} .

run-gpdb: gpdb-docker
	docker run -d -it greenplum-db:${GPDB_VERSION}

gp4k-image:
	DOCKER_BUILDKIT=1 BUILDKIT_PROGRESS=plain docker build --build-arg gpdb_version=${GPDB_VERSION} --build-arg gpdb_repo=${GPDB_REPO} --build-arg greenplumBuilderBaseImage=gpdb-build-objcache:latest --target=gp4k-image -f Dockerfile -t ${GP4K_IMAGE_NAME}:${GPDB_VERSION} .

gp4k-image-push:
	docker push ${GP4K_IMAGE_NAME}:${GPDB_VERSION}
