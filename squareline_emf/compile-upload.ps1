# Compile and upload squareline_emf via arduino-cli
$ErrorActionPreference = 'Stop'
$sketchDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$fqbn = 'esp32:esp32:esp32s3:UploadSpeed=921600,USBMode=hwcdc,CDCOnBoot=cdc,MSCOnBoot=default,DFUOnBoot=default,UploadMode=default,CPUFreq=240,FlashMode=qio,FlashSize=16M,PartitionScheme=app3M_fat9M_16MB,DebugLevel=none,PSRAM=opi,LoopCore=1,EventsCore=1,EraseFlash=none,JTAGAdapter=default,ZigbeeMode=default'

$cli = Get-Command arduino-cli -ErrorAction SilentlyContinue
if (-not $cli) {
    $fallback = Join-Path $env:LOCALAPPDATA 'Programs\arduino-cli\arduino-cli.exe'
    if (-not (Test-Path $fallback)) {
        Write-Error 'arduino-cli not found. Run install-arduino-cli.ps1 first.'
    }
    $cliPath = $fallback
} else {
    $cliPath = $cli.Source
}

Write-Host 'Compiling...'
& $cliPath compile --fqbn $fqbn --clean $sketchDir
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host 'Uploading...'
& $cliPath upload --fqbn $fqbn -p COM3 $sketchDir
# Change COM3 to your port if needed: arduino-cli board list
