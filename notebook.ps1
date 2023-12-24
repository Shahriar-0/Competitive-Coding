Get-ChildItem -Directory -Recurse | ForEach-Object {
    $path = Join-Path -Path $_.FullName -ChildPath '*.cpp'
    $templatePath = Join-Path -Path $_.FullName -ChildPath 'template.cpp'
    if ((Test-Path $_.FullName) -and (Test-Path $path) -and !(Test-Path $templatePath)) {
        Write-Host "Processing directory: $($_.FullName)"
        $relativePath = $_.FullName.TrimStart((Resolve-Path .).Path)
        notebook-generator $relativePath --output $relativePath/notebook.pdf --initials UTP --size 12 --columns 3 --paper a4paper --image ./in-silicon
    }
}