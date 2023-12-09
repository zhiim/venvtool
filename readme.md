# venvtool

A simple tool used to manage Python venv.

It can be used to create, remove, list, activate and deactivate venv.

## Installation

Download or clone this repo.

```shell
git clone https://github.com/zhiim/venvtool.git
```

Compile it.

```shell
mkdir build
cd build
cmake ..
make
```

The compiled program will appear in the `out` folder.

1. In Linux

Run `install.sh`

```shell
bash install.sh
source /etc/profile
```

2. In Windows

Run `install.ps1`

```shell
./install.ps1
```

Then restart powershell.

## Usage

```shell
venvtool -h

a tool to manage venvs like conda
Usage:
  venvtool [OPTION...]

  -h, --help          Print usage
  -l, --list          List all existing venvs
  -c, --create arg    Create a new venv
  -r, --remove arg    Remove an venv
  -a, --activate arg  Activate an venv
  -d, --deactivate    Deactivate an venv
venvtool [OPTION...]

  -c, --create arg    Create a new venv
  -l, --list          List all existing venvs
  -a, --activate arg  Activate an venv
  -d, --deactivate    Deactivate an venv
  -r, --remove arg    Remove an venv
  -h, --help          Print usage
```
