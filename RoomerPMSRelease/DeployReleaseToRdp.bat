@echo off
setlocal

@echo Preparing Roomer.exe for deployment to RDP...
if not exist "Deployment" mkdir Deployment

copy Roomer.exe Deployment

call SignSpecific Deployment\Roomer.exe

echo ======================================================================================================
dir .\Deployment\Roomer.exe
echo ======================================================================================================
echo .
set answer=
set /p answer="Type yes to start copying to Roomer RDP ..."
if "%answer%"=="yes" (
  call SendToRdp Roomer.exe Deployment
  
 ) else (
  echo Copying to Roomer RDP cancelled
)
endlocal

pause