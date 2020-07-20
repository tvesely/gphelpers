# syntax = docker/dockerfile:experimental
ARG greenplumBuilderBaseImage="ubuntu:18.04"
FROM ${greenplumBuilderBaseImage} as greenplum-builder

USER root
WORKDIR /

RUN export DEBIAN_FRONTEND=noninteractive; \
    apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y --no-install-recommends \
      bison \
      ccache \
      cmake \
      flex \
      gcc \
      g++ \
      git \
      libaprutil1-dev \
      libbz2-dev \
      libcurl4-gnutls-dev \
      libevent-dev \
      liblz4-dev \
      libperl-dev \
      libpython-dev \
      libreadline-dev \
      libssl-dev \
      libssl-dev \
      libuv1-dev \
      libxml2-dev \
      libxml2-utils \
      libyaml-dev \
      libzstd-dev \
      make \
      net-tools \
      openssh-server \
      python \
      python3-pip \
      python3-setuptools \
      sudo \
      xsltproc \
      zlib1g-dev && \
    pip3 install ansible psycopg2-binary --no-cache-dir && \
    groupadd -g 1000 gpadmin -f && \
    useradd gpadmin -u 1000 -g gpadmin -m -p '*' -G tty -s /bin/bash && \
      echo "gpadmin ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers || \
      echo "gpadmin already exists" && \
    apt-get autoremove -y && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

USER gpadmin
WORKDIR /home/gpadmin

RUN rm -rf /home/gpadmin/build/ && \
    mkdir -p /home/gpadmin/build

ENV PATH="/usr/lib/ccache:${PATH}"
COPY --chown=gpadmin:gpadmin ansible/ /home/gpadmin/ansible

ARG gpdb_version="master"
ENV GPDB_VERSION=${gpdb_version}
ARG gpdb_repo="https://github.com/greenplum-db/gpdb"
ENV GPDB_REPO=${gpdb_repo}
RUN --mount=type=cache,target=/home/gpadmin/.ccache,uid=1000,gid=1000 \
    cd ansible && \
    ccache -z && \
    CPPFLAGS=-I/home/gpadmin/build/include \
    LDFLAGS=-L/home/gpadmin/build/lib \
      ansible-playbook -i ./docker_build_gpdb_hosts.ini ./build_gpdb.yaml -v && \
    ccache -s

FROM greenplum-for-kubernetes:latest as gp4k-image
USER root
RUN rm -rf /usr/local/greenplum-db*rf /usr/local/greenplum-db*

USER gpadmin
WORKDIR /home/gpadmin

COPY --from=greenplum-builder --chown=gpadmin:gpadmin /home/gpadmin/build/greenplum-db /usr/local/greenplum-db
COPY --from=greenplum-builder --chown=gpadmin:gpadmin /home/gpadmin/build/lib/ /usr/local/greenplum-db/lib/
COPY --from=greenplum-builder --chown=gpadmin:gpadmin /home/gpadmin/build/include/ /usr/local/greenplum-db/include/
RUN sed -i 's/^GPHOME=.*$/GPHOME="\/usr\/local\/greenplum-db"/g' /usr/local/greenplum-db/greenplum_path.sh


FROM ubuntu:18.04
RUN export DEBIAN_FRONTEND=noninteractive; \
    apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y --no-install-recommends \
         python \
         libapr1 \
         libaprutil1 \
         krb5-multidev \
         libcurl3-gnutls \
         libcurl4 \
         libevent-2.1.6 \
         libuv1 \
         libxml2 \
         libyaml-0-2 \
         locales \
         make \
         openssh-client \
         openssh-server \
         perl \
         rsync \
         zip \
         net-tools \
         less \
         iproute2 \
         iputils-ping \
         sudo && \
    groupadd -g 1000 gpadmin && \
    useradd gpadmin -u 1000 -g gpadmin -m -p '*' -G tty -s /bin/bash && \
    echo "gpadmin ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers && \
    locale-gen en_US.utf8 && \
    apt-get autoremove -y && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

USER gpadmin
WORKDIR /home/gpadmin

COPY --from=greenplum-builder --chown=gpadmin:gpadmin /home/gpadmin/build/greenplum-db /usr/local/greenplum-db
COPY --from=greenplum-builder --chown=gpadmin:gpadmin /home/gpadmin/build/lib/ /usr/local/greenplum-db/lib/
COPY --from=greenplum-builder --chown=gpadmin:gpadmin /home/gpadmin/build/include/ /usr/local/greenplum-db/include/
RUN sed -i 's/^GPHOME=.*$/GPHOME="\/usr\/local\/greenplum-db"/g' /usr/local/greenplum-db/greenplum_path.sh
COPY --from=greenplum-builder --chown=gpadmin:gpadmin /home/gpadmin/workspace/gpdb /home/gpadmin/workspace/gpdb
COPY docker_scripts/ /home/gpadmin/docker_scripts

ENTRYPOINT /home/gpadmin/docker_scripts/run_gpdb.sh
