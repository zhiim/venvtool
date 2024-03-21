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
cmake --build .
```

The compiled program will appear in the `out` folder.

Install venvtool with script.


```shell
# in Linux
source install.sh
# in Windows
./install.ps1
```

Then restart terminal.

## Usage

venvtool should be initiated with a path to put all venvs, or you can use default path.

```shell
venvtool -i /path/to/put/venv
```

```shell
venvtool -h

a tool to manage venvs like conda
Usage:
  venvtool [OPTION...]

  -h, --help          Print usage
  -i, --init arg      initiate venvtool with a path where all venvs will be
                      stored
  -l, --list          List all existing venvs
  -c, --create arg    Create a new venv
  -r, --remove arg    Remove an venv
  -a, --activate arg  Activate an venv
  -d, --deactivate    Deactivate an venv
```

## Uninstallation

Remove venvtool

```shell
# in Linux
rm -rf ~/.local/bin/venvtool
# in Windows
rm $env:appdata\venvtool
```

Remove venvs

```shell
rm /path/to/put/venvs
```
