ARG baseImage="golang:1.14"
FROM ${baseImage} as runnerbuilder

WORKDIR /workspace
# Copy the Go Modules manifests
COPY tpcds-gp4k/go.mod go.mod
COPY tpcds-gp4k/go.sum go.sum
# cache deps before building and copying source so that we don't need to re-download as much
# and so that source changes don't invalidate our downloaded layer
RUN go mod download

COPY tpcds-gp4k/Makefile ./

# Build tools
RUN make tools

# Copy the go source
COPY tpcds-gp4k/cmd/ cmd/
COPY tpcds-gp4k/pkg/ pkg/
COPY tpcds-gp4k/main.go ./

# Build
RUN make

FROM golang:1.14 as objcache
COPY --from=runnerbuilder /root/.cache /root/.cache
COPY --from=runnerbuilder /go/pkg/mod /go/pkg/mod
COPY --from=runnerbuilder /workspace/bin/cobra  /workspace/bin/cobra
COPY --from=runnerbuilder /workspace/bin/ginkgo /workspace/bin/ginkgo
COPY --from=runnerbuilder /workspace/bin/golangci-lint /workspace/bin/golangci-lint

FROM gcr.io/gp-kubernetes/ubuntu-gpdb-ent:latest as tpcds-gp4k

RUN export DEBIAN_FRONTEND=noninteractive; \
    apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y --no-install-recommends \
      gcc \
      git \
      make \
      python3-pip \
      python3-setuptools && \
    pip3 install ansible psycopg2-binary --no-cache-dir && \
    apt-get remove -y noop; \
    apt-get autoremove -y && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

COPY --from=runnerbuilder /workspace/bin/tpcds-gp4k /tpcds-gp4k

RUN /tpcds-gp4k prepare-image

USER gpadmin
WORKDIR /home/gpadmin

RUN mkdir workspace
COPY --chown=gpadmin:gpadmin ansible/ /home/gpadmin/workspace/ansible/
RUN git clone https://github.com/tvesely/TPC-DS workspace/TPC-DS

ENTRYPOINT /tpcds-gp4k start
