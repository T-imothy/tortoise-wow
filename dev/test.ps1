param([switch]$Full)
$ErrorActionPreference='Stop'
$devCmd='C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\VsDevCmd.bat'
$lines=& $env:ComSpec /d /s /c "`"$devCmd`" -arch=x64 -host_arch=x64 >nul && set"
if($LASTEXITCODE -ne 0){throw 'Compiler environment failed'}
foreach($line in $lines){
    $index=$line.IndexOf('=')
    if($index -gt 0){Set-Item -LiteralPath ('Env:'+$line.Substring(0,$index)) -Value $line.Substring($index+1)}
}
$env:PATH=(Join-Path $env:VCToolsInstallDir 'bin/Hostx64/x64')+';'+(Join-Path $env:WindowsSdkDir ('bin/'+$env:WindowsSDKVersion.TrimEnd('\')+'/x64'))+';'+$env:PATH
$cmake='C:\Program Files\CMake\bin\cmake.exe'
$ctest='C:\Program Files\CMake\bin\ctest.exe'
$ninja='C:/Users/root/AppData/Local/vcpkg/downloads/tools/perl/5.42.2.1/c/bin/ninja.exe'
$repo=(Resolve-Path (Join-Path $PSScriptRoot '..')).Path
$build=Join-Path $repo 'build/tests'
$source=Join-Path $repo 'tests/architecture'
& $cmake -S $source -B $build -G Ninja "-DCMAKE_MAKE_PROGRAM=$ninja" -DCMAKE_BUILD_TYPE=Release
if($LASTEXITCODE -ne 0){throw 'Test configure failed'}
if($Full){
    & $cmake --build $build --parallel 2
    if($LASTEXITCODE -ne 0){throw 'Full regression build failed'}
    & $ctest --test-dir $build --output-on-failure
    if($LASTEXITCODE -ne 0){throw 'Full regression failed'}
    exit 0
}
& $cmake --build $build --parallel 2 --target AhBotChatDispatchTest AhBotMarketTest AuctionSettlementTest AuctionStockOwnershipTest AuctionOwnerNotificationTest TrainerPurchaseTest SoapCommandLifecycleTest ModuleTaxiCacheRefreshTest NativeModuleCommandPermissionTest
if($LASTEXITCODE -ne 0){throw 'Test build failed'}
& $ctest --test-dir $build --output-on-failure -R '^(AhBotChatDispatchTest|AhBotMarketTest|AuctionSettlementTest|AuctionStockOwnershipTest|AuctionOwnerNotificationTest|TrainerPurchaseTest|SoapCommandLifecycleTest|ModuleTaxiCacheRefreshTest|NativeModuleCommandPermissionTest)$'
if($LASTEXITCODE -ne 0){throw 'Regression failed'}
