switch ($args[0]) {
    {($_ -eq '-h') -or ($_ -eq '--help')} {
        .\venvtool.exe -h
    }

    {($_ -eq '-c') -or ($_ -eq '--create')} {
        $venvName = $args[1]
        .\venvtool.exe -c $venvName
    }

    {($_ -eq '-l') -or ($_ -eq '--list')} {
        Write-Output $args[0]
        .\venvtool.exe -l
    }

    {($_ -eq '-a') -or ($_ -eq '--activate')} {
        $venvName = $args[1]
        $activatePath = .\out\venvtool.exe -a $venvName
        . $activatePath
    }

    {($_ -eq '-d') -or ($_ -eq '--deactivate')} {
        deactivate
    }

    {($_ -eq '-r') -or ($_ -eq '--remove')} {
        $venvName = $args[1]
        .\venvtool.exe -r $venvName
    }
}
