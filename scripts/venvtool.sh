for arg in "$@"
do
    case $arg in

	-h|--help)
	/usr/local/bin/venvtool/venvtool -h
    ;;

    -c|--create)
	venvName=$2
	/usr/local/bin/venvtool/venvtool -c $venvName
    ;;

    -l|--list)
	/usr/local/bin/venvtool/venvtool -l
    ;;

    -a|--activate)
	venvName=$2
	activatePath=$(/usr/local/bin/venvtool/venvtool -a $venvName)
    source $activatePath
    ;;

    -d|--deactivate)
    deactivate
    ;;

    -r|--remove)
	venvName=$2
	/usr/local/bin/venvtool/venvtool -r $venvName
    ;;

    esac
done
