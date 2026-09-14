param([switch]$ConfigureOnly, [switch]$Fresh, [switch]$BuildOnly, [switch]$WithoutBots, [switch]$Diagnostics, [int]$Workers=6)
$Bots=-not $WithoutBots
$BuildOnly=$true
if($WithoutBots){$BuildOnly=$true}
$CoreOnlyInModuleBuild=$false
$ProductionOptions=$true
$ErrorActionPreference='Stop'
$devCmd='C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\VsDevCmd.bat'
$environmentLines=& $env:ComSpec /d /s /c "`"$devCmd`" -arch=x64 -host_arch=x64 >nul && set"
if($LASTEXITCODE -ne 0){throw 'Compiler environment failed'}
foreach($line in $environmentLines){
    $separator=$line.IndexOf('=')
    if($separator -gt 0){Set-Item -LiteralPath ('Env:'+$line.Substring(0,$separator)) -Value $line.Substring($separator+1)}
}
# A host can supply both Path and PATH to cmd.exe. Ensure the imported VS
# tools win over a later inherited spelling when configuring a fresh cache.
$env:PATH=(Join-Path $env:VCToolsInstallDir 'bin/Hostx64/x64')+';'+(Join-Path $env:WindowsSdkDir ('bin/'+$env:WindowsSDKVersion.TrimEnd('\')+'/x64'))+';'+$env:PATH
$cmake='C:\Program Files\CMake\bin\cmake.exe'
$deps='C:/Users/root/Documents/Codex/2026-09-03/i-want-to-be-able-to/work/vcpkg-deps/vcpkg_installed/x64-windows'
$ninja='C:/Users/root/AppData/Local/vcpkg/downloads/tools/perl/5.42.2.1/c/bin/ninja.exe'
$source=(Resolve-Path (Join-Path $PSScriptRoot '..')).Path
$output='C:\Users\root\Desktop\WorkFolder\turtle'
$build=Join-Path $source 'build/local-core'
$module='disabled'
$lto='OFF'
if($ProductionOptions){$lto='ON'}
if($Bots){$build=Join-Path $source 'build/mantech-playerbots';$module='static'}
if($CoreOnlyInModuleBuild){$build=Join-Path $source 'build/mantech-playerbots';$module='disabled'}
$taskBinaryDirectory=Join-Path $build 'bin'
$taskConfigureOptions=@()
if($Fresh){$taskConfigureOptions+='--fresh'}
& $cmake @taskConfigureOptions -S $source -B $build -G Ninja "-DCMAKE_MAKE_PROGRAM=$ninja" "-DCMAKE_PREFIX_PATH=$deps" "-DBoost_ROOT=$deps" "-DBoost_DIR=$deps/share/boost" "-DACE_ROOT=$deps" -DCMAKE_BUILD_TYPE=Release "-DMANTECH_DEV_DIAGNOSTICS=$Diagnostics" "-DMANTECH_PROFILE_ALLOCATIONS=$Diagnostics" "-DBUILD_PLAYERBOTS=$Bots" -DBUILD_ELUNA=OFF -DENABLE_SOAP=ON -DMODULES=disabled -DMODULE_TORTOISEBOTS=disabled "-DMODULE_MANTECHPLAYERBOTS=$module" -DMODULE_MOD_PLAYERBOTS=disabled -DUSE_PCH=ON -DUSE_PCH_OLD=ON -DUSE_DISCORD_BOT=OFF -DUSE_EXTRACTORS=OFF "-DENABLE_LTO=$lto" "-DCMAKE_INSTALL_PREFIX=$output" "-DCMAKE_RUNTIME_OUTPUT_DIRECTORY=$taskBinaryDirectory"
if($LASTEXITCODE -ne 0){throw 'Configure failed'}
if(-not $ConfigureOnly){
    & $cmake --build $build --parallel $Workers -- -k 0
    if($LASTEXITCODE -ne 0){throw 'Build failed'}
}

if(-not $ConfigureOnly -and -not $BuildOnly){
    # Keep the user's local configs and databases intact when deploying a build.
    $taskRunning=Get-Process -Name mangosd,realmd -ErrorAction SilentlyContinue | Where-Object { $_.Path -and (Split-Path -Parent $_.Path) -eq $output }
    if($taskRunning){throw 'Turtle is running in the output folder; stop it cleanly before deploying this build.'}
    foreach($taskConfig in @(@('ahbot','modules/ManTechPlayerbots/cmangos-ahbot/ahbot.conf.dist.in'), @('aiplayerbot','modules/ManTechPlayerbots/playerbot/aiplayerbot.conf.dist.in'))){
        $taskTemplate=Join-Path $source $taskConfig[1]
        Copy-Item -LiteralPath $taskTemplate -Destination (Join-Path $output ($taskConfig[0]+'.conf.dist')) -Force
        $taskActive=Join-Path $output ($taskConfig[0]+'.conf')
        if(-not (Test-Path -LiteralPath $taskActive)){Copy-Item -LiteralPath $taskTemplate -Destination $taskActive}
    }
    foreach($name in @('mangosd.exe','realmd.exe')){
        Copy-Item -LiteralPath (Join-Path $taskBinaryDirectory $name) -Destination (Join-Path $output $name) -Force
    }
    New-Item -ItemType Directory -Path (Join-Path $output 'symbols') -Force | Out-Null
    foreach($name in @('mangosd.pdb','realmd.pdb')){
        Copy-Item -LiteralPath (Join-Path $taskBinaryDirectory $name) -Destination (Join-Path $output "symbols/$name") -Force
    }
    Copy-Item -Path (Join-Path $source 'sql/database_updates/*') -Destination (Join-Path $output 'sql/database_updates') -Recurse -Force
    Copy-Item -Path (Join-Path $source 'modules/TortoiseBots/data/sql/world/*') -Destination (Join-Path $output 'modules/TortoiseBots/data/sql/world') -Recurse -Force
    Copy-Item -Path (Join-Path $source 'modules/TortoiseBots/data/sql/char/*') -Destination (Join-Path $output 'modules/TortoiseBots/data/sql/character') -Recurse -Force
    Write-Output "Built and deployed Turtle to $output"
}
