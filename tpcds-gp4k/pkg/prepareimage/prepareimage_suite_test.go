package prepareimage_test

import (
	"testing"

	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
)

func TestPrepareimage(t *testing.T) {
	RegisterFailHandler(Fail)
	RunSpecs(t, "Prepareimage Suite")
}
