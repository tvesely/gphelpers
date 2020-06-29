package prepareimage

import (
	"syscall"

	"github.com/blang/vfs"
)

type ImagePrepInterface interface {
	Run() error
}

type PrepRootUser struct {
	Fs vfs.Filesystem
}

type App struct {
}

var _ ImagePrepInterface = &PrepRootUser{}

var AnsibleHostsFile = `[tpcds-gp4k]
localhost

[tpcds-gp4k:vars]
ansible_connection=local
ansible_python_interpreter="{{ansible_playbook_python}}"
`

func (p *PrepRootUser) Run() error {
	// This folder will exist even if a volume isn't mounted on it, so
	// it can be used as ephemeral storage.
	err := p.createTpcdsFolder()
	if err != nil {
		return err
	}
	return p.initializeAnsible()
}

func (p *PrepRootUser) createTpcdsFolder() error {
	// Make sure that the requested permissions are respected
	// Note: untested
	syscall.Umask(0)
	return p.Fs.Mkdir("/tpcds", 0777)
}

func (p *PrepRootUser) initializeAnsible() error {
	err := p.Fs.Mkdir("/etc/ansible", 0755)
	if err != nil {
		return err
	}

	err = vfs.WriteFile(p.Fs, "/etc/ansible/hosts", []byte(AnsibleHostsFile), 0744)
	if err != nil {
		return err
	}
	return nil
}

type PrepAdminUser struct{}

var _ ImagePrepInterface = &PrepAdminUser{}

func (p *PrepAdminUser) Run() error {
	panic("implement me")
}
