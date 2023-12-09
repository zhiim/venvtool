# create the directory where venvtool will be placed
mkdir -p /usr/local/bin/venvtool

# copy venvtool into that newly created directory 
cp ./scripts/venvtool.sh /usr/local/bin/venvtool
cp ./out/venvtool /usr/local/bin/venvtool

# set venvtool alias, so you can use venvtool command to run venvtool.sh
echo alias venvtool='"source /usr/local/bin/venvtool/venvtool.sh"' >> /etc/profile
