@echo off
rem Your comment here - this line will be ignored during execution
setlocal

rem Set the path to your Python script
set "script_path=Project29/main.pyw"

rem Try to find the Python interpreter path using PowerShell
for /f "tokens=* USEBACKQ" %%F IN (`powershell -Command "Get-Command python | ForEach-Object { $_.Source }"`) DO (
    set "python_path=%%F"
)

rem Check if Python is installed
if not defined python_path (
    echo Python is not installed. Installing Python...

    rem Define the URL to the Python installer
    set "python_installer_url=https://www.python.org/ftp/python/3.9.1/python-3.9.1-amd64.exe"

    rem Define the path to the installer
    set "installer_path=%TEMP%\python_installer.exe"

    rem Download the Python installer using PowerShell
    powershell -Command "(New-Object Net.WebClient).DownloadFile('%python_installer_url%', '%installer_path%')"

    rem Install Python silently
    start /wait %installer_path% /quiet

    rem Clean up the installer
    del %installer_path%

    rem Try to find the Python interpreter path again
    for /f "tokens=* USEBACKQ" %%F IN (`powershell -Command "Get-Command python | ForEach-Object { $_.Source }"`) DO (
        set "python_path=%%F"
    )
)

rem Check if Python is now installed
if defined python_path (
    echo Python is installed at: %python_path%
    echo Running the script...
    %python_path% %script_path%
) else (
    echo Failed to install Python.
)

endlocal
