mkdir -p /usr/local/bin/venvtool
cp ./scripts/venvtool.sh /usr/local/bin/venvtool
cp ./out/venvtool /usr/local/bin/venvtool

echo alias venvtool='"source /usr/local/bin/venvtool/venvtool.sh"' >> /etc/profile