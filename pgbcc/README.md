# BCC tools for postgres debugging

Uses Liux eBPF to instrument Postgres using uprobes/kprobes

Ubuntu 18.04:

```bash
sudo apt-get -y install bison build-essential cmake flex git libedit-dev \
  libllvm6.0 llvm-6.0-dev libclang-6.0-dev python zlib1g-dev libelf-dev

git clone https://github.com/iovisor/bcc.git
mkdir bcc/build; cd bcc/build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr
make
sudo make install

pip install pyelftools
```
