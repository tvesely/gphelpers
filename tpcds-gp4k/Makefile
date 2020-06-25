# Image URL to use all building/pushing image targets
INSTANCE_IMAGE ?= tpcds-gp4k
INSTANCE_TAG ?= latest

.PHONEY: run all docker-build

all: tpcds-gp4k

tpcds-gp4k: ./bin/tpcds-gp4k

./bin/tpcds-gp4k: test
	CGO_ENABLED=0 GOOS=linux GOARCH=amd64 GO111MODULE=on go build -a -o ./bin/tpcds-gp4k main.go

docker-build:
	docker build -f Dockerfile -t ${INSTANCE_IMAGE}:${INSTANCE_TAG} ..

docker-push:
	docker push ${INSTANCE_IMAGE}:${INSTANCE_TAG}

run:
	docker run --rm -d ${INSTANCE_IMAGE}:${INSTANCE_TAG}

deploy: docker-build docker-push
	kubectl apply -f tpcds-gp4k.yaml

deploy-clean:
	kubectl delete -f tpcds-gp4k.yaml

test: lint
	go test ./... -coverprofile cover.out

lint: tools
	golangci-lint run --enable golint,gofmt

.PHONY: tools
tools: ${GOBIN}/ginkgo ${GOBIN}/golangci-lint ${GOBIN}/cobra

${GOBIN}/ginkgo:
	go install github.com/onsi/ginkgo/ginkgo

${GOBIN}/golangci-lint:
	go install github.com/golangci/golangci-lint/cmd/golangci-lint

${GOBIN}/cobra:
	go install github.com/spf13/cobra/cobra

