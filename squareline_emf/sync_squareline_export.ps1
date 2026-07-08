# Copy SquareLine export and fix image pixel formats for LVGL 16-bit.
$ErrorActionPreference = "Stop"
$Sketch = Split-Path -Parent $MyInvocation.MyCommand.Path
$ExportUi = "C:\Users\58418\Documents\2026UCL\Dissertation\EXPORTUI"

if (-not (Test-Path $ExportUi)) {
    Write-Host "EXPORTUI not found: $ExportUi"
    Write-Host "Edit this script if your SquareLine export path is different."
    exit 1
}

$files = @(
    "images\ui_img_backgroundpage2_png.c",
    "images\ui_img_3_png.c",
    "screens\ui_detect.c",
    "ui.h"
)

foreach ($rel in $files) {
    $src = Join-Path $ExportUi $rel
    $dst = Join-Path $Sketch $rel
    if (Test-Path $src) {
        Copy-Item $src $dst -Force
        Write-Host "Copied $rel"
    }
}

python (Join-Path $Sketch "tools\convert_sq_alpha_img.py")
Write-Host "Done. Rebuild and upload the sketch."
