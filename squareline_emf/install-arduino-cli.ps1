# Installs arduino-cli and ESP32 core for squareline_emf
$ErrorActionPreference = 'Stop'
$dest = Join-Path $env:LOCALAPPDATA 'Programs\arduino-cli'

function Ensure-ArduinoCli {
    $cmd = Get-Command arduino-cli -ErrorAction SilentlyContinue
    if ($cmd) { return $cmd.Source }

    # Skip winget/MSI — org policy on this machine blocks it (exit 1625).
    Write-Host 'Downloading portable arduino-cli 1.2.2...'
    New-Item -ItemType Directory -Force -Path $dest | Out-Null
    $zip = Join-Path $env:TEMP 'arduino-cli.zip'
    curl.exe -L -o $zip 'https://github.com/arduino/arduino-cli/releases/download/v1.2.2/arduino-cli_1.2.2_Windows_64bit.zip'
    Expand-Archive -Path $zip -DestinationPath $dest -Force
    Remove-Item $zip -Force

    $userPath = [Environment]::GetEnvironmentVariable('Path', 'User')
    if ($userPath -notlike "*$dest*") {
        [Environment]::SetEnvironmentVariable('Path', "$dest;$userPath", 'User')
    }
    $env:Path = "$dest;$env:Path"
    return (Join-Path $dest 'arduino-cli.exe')
}

$installPath = Ensure-ArduinoCli
Write-Host "arduino-cli: $installPath"
& $installPath version

Write-Host 'Updating board index...'
& $installPath core update-index

Write-Host 'Installing ESP32 core 2.0.17 (matches sketch.yaml)...'
& $installPath core install esp32:esp32@2.0.17

Write-Host 'Done. Restart Cursor/terminal so PATH updates apply.'
