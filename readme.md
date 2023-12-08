# venvtool

A simple tool used to manage Python venv.

It can be used to create, remove, list, activate and deactivate venv.

## Installation

Download or clone this repo.

```shell
git clone
```

Compile it.

```shell
mkdir build
cd build
cmake ..
make
```

The compiled program will appear in the `out` folder.

In Linux, run `install.sh`

```shell
bash install.sh
source /etc/profile
```

In Windows, creat a new folder, put `out/venvtool.exe` and `scripts/venvtool.ps1` in it. Then add path of this folder into 

## Usage

```shell
venvtool [OPTION...]

  -c, --create arg    Create a new venv
  -l, --list          List all existing venvs
  -a, --activate arg  Activate an venv
  -d, --deactivate    Deactivate an venv
  -r, --remove arg    Remove an venv
  -h, --help          Print usage
```