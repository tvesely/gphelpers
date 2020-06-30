/*
 Copyright 2020 Taylor Vesely <dreddor@dreddor.net>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

package cmd

import (
	"os"
	"os/exec"

	"github.com/spf13/cobra"
	ctllog "sigs.k8s.io/controller-runtime/pkg/log"
)

func init() {
	rootCmd.AddCommand(start)
}

var start = &cobra.Command{
	Use:   "start",
	Short: "start a TPC-DS job",
	Long:  `start a TPC-DS job`,
	RunE: func(cmd *cobra.Command, args []string) error {
		return runJob()
	},
}

func runJob() error {
	log := ctllog.Log.WithName("runJob")

	cmd := exec.Command("ansible-playbook", "/home/gpadmin/workspace/ansible/tpc-ds-gpdb.yaml", "-v")
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stdout
	cmd.Env = os.Environ()
	cmd.Env = append(cmd.Env, "LD_LIBRARY_PATH=/usr/local/greenplum-db/lib")

	err := cmd.Run()
	if err != nil {
		log.Error(err, "ansible returned error")
	}

	log.Info("TPC-DS job finished. Shutting down.")
	return nil
}
