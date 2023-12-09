$venvPath="$env:appdata\venvtool"

# create the directory where venvtool will be placed
New-Item -ItemType "directory" -Path $venvPath

# copy venvtool into that newly created directory 
Copy-Item .\out\venvtool.exe -Destination $venvPath
Copy-Item .\scripts\venvtool.ps1 -Destination $venvPath

# set venvtool alias in powershell's profile, so you can use venvtool command
# to run venvtool.ps1
Write-Output "New-Alias -Name venvtool -Value $venvPath\venvtool.ps1" >> $Profile
