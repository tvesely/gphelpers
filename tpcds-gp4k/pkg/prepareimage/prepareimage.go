package prepareimage

import (
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
	return p.initializeAnsible()
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
