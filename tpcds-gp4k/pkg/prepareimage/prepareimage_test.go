package prepareimage_test

import (
	"errors"
	"os"

	"github.com/blang/vfs"
	"github.com/blang/vfs/memfs"
	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
	"github.com/tvesely/gphelpers/tpcds-gpdb/pkg/prepareimage"
)

var _ = Describe("Prepareimage", func() {
	When("initializing the root user", func() {
		var (
			fakeFs  vfs.Filesystem
			subject *prepareimage.PrepRootUser
			runErr  error
		)
		BeforeEach(func() {
			fakeFs = memfs.Create()
			Expect(fakeFs.Mkdir("/etc/", 0755)).To(Succeed())
			subject = &prepareimage.PrepRootUser{
				Fs: fakeFs,
			}
		})
		JustBeforeEach(func() {
			runErr = subject.Run()
		})
		It("succeeds", func() {
			Expect(runErr).NotTo(HaveOccurred())
		})
		It("creates the tpcds directory", func() {
			stat, err := fakeFs.Stat("/tpcds")
			Expect(err).NotTo(HaveOccurred())
			Expect(stat.Mode()).To(Equal(os.FileMode(0777)))
		})

		It("creates the ansible directory", func() {
			stat, err := fakeFs.Stat("/etc/ansible/")
			Expect(err).NotTo(HaveOccurred())
			Expect(stat.Mode()).To(Equal(os.FileMode(0755)))
		})
		It("initializes the hosts file", func() {
			stat, err := fakeFs.Stat("/etc/ansible/hosts")
			Expect(err).NotTo(HaveOccurred())
			Expect(stat.Mode()).To(Equal(os.FileMode(0744)))
			hostsBytes, err := vfs.ReadFile(fakeFs, "/etc/ansible/hosts")
			Expect(err).NotTo(HaveOccurred())
			Expect(hostsBytes).To(Equal([]byte(prepareimage.AnsibleHostsFile)))
		})
		When("making the tpcds directory fails", func() {
			BeforeEach(func() {
				dummyfs := vfs.Dummy(errors.New("create tpcds failed"))
				subject.Fs = dummyfs
			})
			It("returns an error", func() {
				Expect(runErr).To(MatchError("create tpcds failed"))
			})
		})
		When("making the ansible directory fails", func() {
			BeforeEach(func() {
				Expect(fakeFs.Remove("/etc")).To(Succeed())
			})
			It("returns an error", func() {
				Expect(runErr).To(MatchError("mkdir /etc/ansible: file does not exist"))
			})
		})
		When("making the ansible hosts file fails", func() {
			BeforeEach(func() {
				subject.Fs = &FakeFilesystem{OpenFileErr: errors.New("file error")}
			})
			It("returns an error", func() {
				Expect(runErr).To(MatchError("file error"))
			})
		})
	})
})

type FakeFilesystem struct {
	OpenFileErr error
}

func (f *FakeFilesystem) PathSeparator() uint8 {
	panic("implement me")
}

func (f *FakeFilesystem) OpenFile(name string, flag int, perm os.FileMode) (vfs.File, error) {
	return nil, f.OpenFileErr
}

func (f *FakeFilesystem) Remove(name string) error {
	panic("implement me")
}

func (f *FakeFilesystem) Rename(oldpath, newpath string) error {
	panic("implement me")
}

func (f *FakeFilesystem) Mkdir(name string, perm os.FileMode) error {
	return nil
}

func (f *FakeFilesystem) Stat(name string) (os.FileInfo, error) {
	panic("implement me")
}

func (f *FakeFilesystem) Lstat(name string) (os.FileInfo, error) {
	panic("implement me")
}

func (f *FakeFilesystem) ReadDir(path string) ([]os.FileInfo, error) {
	panic("implement me")
}

var _ vfs.Filesystem = &FakeFilesystem{}
