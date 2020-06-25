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
	"github.com/spf13/cobra"
	ctllog "sigs.k8s.io/controller-runtime/pkg/log"
)

func init() {
	rootCmd.AddCommand(prepImage)
}

var prepImage = &cobra.Command{
	Use:   "prepare-image",
	Short: "prepare a tpcds-gp4k container image",
	Long:  `prepare a tpcds-gp4k container image to run in Docker or Kubernetes`,
	RunE: func(cmd *cobra.Command, args []string) error {
		return prepImageRun()
	},
}

func prepImageRun() error {
	log := ctllog.Log.WithName("prepare-image")

	log.Info("preparing container image")
	return nil
}
