# create the directory where venvtool will be placed
mkdir -p ~/.local/bin/venvtool

# copy venvtool into that newly created directory 
cp ./scripts/venvtool.sh ~/.local/bin/venvtool
cp ./out/venvtool ~/.local/bin/venvtool

# set venvtool alias, so you can use venvtool command to run venvtool.sh
if [ -n "$ZSH_VERSION" ]; then
   # assume Zsh
    echo alias venvtool='"source ~/.local/bin/venvtool/venvtool.sh"' >> ~/.zshrc
    source ~/.zshrc
elif [ -n "$BASH_VERSION" ]; then
   # assume Bash
    echo alias venvtool='"source ~/.local/bin/venvtool/venvtool.sh"' >> ~/.bashrc
    source ~/.bashrc
fi
