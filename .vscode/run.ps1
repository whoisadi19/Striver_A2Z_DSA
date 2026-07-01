# C++ DSA Automated Runner Script
# Usage:
#   .\run.ps1                 <- Automatically runs the most recently modified .cpp file
#   .\run.ps1 C++/demo.cpp    <- Runs a specific C++ file

param (
    [string]$File = ""
)

# Set console encoding to UTF-8
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8

# 1. Resolve Target C++ File
$targetFile = $null
$useAutoDetect = [string]::IsNullOrEmpty($File)

if (-not $useAutoDetect) {
    # If they passed a file that is clearly a text file, JSON, markdown, etc. (e.g., active document was input.txt)
    if ($File.EndsWith(".txt") -or $File.EndsWith(".json") -or $File.EndsWith(".md")) {
        $useAutoDetect = $true
    } else {
        # Try to find the specified file
        $checkPath = $File
        if (-not $checkPath.EndsWith(".cpp")) {
            $checkPath = $checkPath + ".cpp"
        }
        
        if (Test-Path $checkPath) {
            $targetFile = Get-Item -Path $checkPath
        } else {
            # Try recursive search for the leaf file name
            $leafName = Split-Path $checkPath -Leaf
            $search = Get-ChildItem -Path . -Filter $leafName -Recurse
            if ($search.Count -gt 0) {
                $targetFile = $search[0]
            } else {
                # Could not find it, fall back to auto-detecting
                $useAutoDetect = $true
            }
        }
    }
}

if ($useAutoDetect) {
    # Find most recently modified C++ file in the current directory and subdirectories
    $cppFiles = Get-ChildItem -Path . -Filter "*.cpp" -Recurse | Sort-Object LastWriteTime -Descending
    if ($cppFiles.Count -eq 0) {
        Write-Host "[ERROR] No .cpp files found in the workspace." -ForegroundColor Red
        Exit 1
    }
    $targetFile = $cppFiles[0]
}

$fileFullPath = $targetFile.FullName
$fileDir = Split-Path $fileFullPath
$fileBaseName = [System.IO.Path]::GetFileNameWithoutExtension($targetFile.Name)
$exePath = Join-Path $fileDir "$fileBaseName.exe"
$inputPath = Join-Path $fileDir "input.txt"
$outputPath = Join-Path $fileDir "output.txt"

# 2. Ensure input.txt and output.txt exist in the same folder
if (-not (Test-Path $inputPath)) {
    New-Item -Path $inputPath -ItemType File -Force | Out-Null
}
if (-not (Test-Path $outputPath)) {
    New-Item -Path $outputPath -ItemType File -Force | Out-Null
}

$compileStopwatch = [System.Diagnostics.Stopwatch]::StartNew()

# Compile command executed directly - standard error output will go straight to the console!
& g++ -O2 -std=c++17 -Wall -Wshadow -Wno-unused-result $fileFullPath -o $exePath

$compileStopwatch.Stop()

if ($LASTEXITCODE -ne 0) {
    Write-Host "[ERROR] Compilation Failed!" -ForegroundColor Red
    # Clean up exe if it somehow got created
    if (Test-Path $exePath) { Remove-Item $exePath -ErrorAction SilentlyContinue }
    Exit 1
}

# 4. Check if Input is Empty for Redirection Decision
$inputContent = Get-Content -Raw $inputPath
$hasInput = $null -ne $inputContent -and $inputContent.Trim().Length -gt 0

Write-Host "[+] Compilation Success! Running $($targetFile.Name)..." -ForegroundColor Green
Write-Host ""

$runStopwatch = [System.Diagnostics.Stopwatch]::StartNew()

if ($hasInput) {
    # Run with redirection, capturing output via standard pipeline
    $output = Get-Content -Raw $inputPath | & $exePath
    $runStopwatch.Stop()
    
    # Save output to output.txt
    $output | Out-File -FilePath $outputPath -Encoding utf8
    
    # Display Output
    if ($output) {
        $output | ForEach-Object { Write-Host $_ }
    } else {
        Write-Host "[Program completed with no output]" -ForegroundColor DarkGray
    }
} else {
    $runStopwatch.Stop()
    # Run interactively (no capture, standard console I/O)
    $runStopwatch.Start()
    & $exePath
    $runStopwatch.Stop()
}

$exitCode = $LASTEXITCODE

# 5. Output Summary / Execution Stats
$timeElapsed = $runStopwatch.Elapsed.TotalMilliseconds
$timeFormatted = "{0:N2}" -f $timeElapsed

Write-Host ""
if ($exitCode -eq 0) {
    Write-Host "Time: $timeFormatted ms" -ForegroundColor Gray
} else {
    Write-Host "[!] Program exited with non-zero Exit Code: $exitCode" -ForegroundColor Red
    Write-Host "Time: $timeFormatted ms" -ForegroundColor Gray
}

# Clean up executable to keep the workspace clean
if (Test-Path $exePath) {
    # Give a tiny buffer for file handles to release
    Start-Sleep -Milliseconds 50
    Remove-Item $exePath -ErrorAction SilentlyContinue | Out-Null
}
