make > $null 2>&1
Get-Content ../test/in | ForEach-Object {./cpp.out $_} > ../test/out

$outFile = "../test/out"
$ansFile = "../test/ans"

if ((Test-Path -Path $outFile)) {
    if (Compare-Object -ReferenceObject (Get-Content $ansFile) -DifferenceObject (Get-Content $outFile)) {
        Write-Host "Failed" -ForegroundColor Red
        Compare-Object -ReferenceObject (Get-Content $ansFile) -DifferenceObject (Get-Content $outFile) | Out-File ../test/err
    } else {
        Write-Host "Passed" -ForegroundColor Green
    }
} else {
    Write-Host "Output file does not exist" -ForegroundColor Red
}