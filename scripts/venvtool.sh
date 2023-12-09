for arg in "$@"
do
    case $arg in

	-h|--help)
	~/.local/bin/venvtool/venvtool -h
    ;;

	-i|--init)
    venvPath=$2
	~/.local/bin/venvtool/venvtool -i $venvPath
    ;;
    
    -c|--create)
	venvName=$2
	~/.local/bin/venvtool/venvtool -c $venvName
    ;;

    -l|--list)
	~/.local/bin/venvtool/venvtool -l
    ;;

    -a|--activate)
	venvName=$2
	activatePath=$(~/.local/bin/venvtool/venvtool -a $venvName)
    source $activatePath
    ;;

    -d|--deactivate)
    deactivate
    ;;

    -r|--remove)
	venvName=$2
	~/.local/bin/venvtool/venvtool -r $venvName
    ;;

    esac
done
