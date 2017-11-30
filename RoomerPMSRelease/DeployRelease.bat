@echo off
setlocal

if not exist "Deployment" mkdir Deployment

copy Roomer.exe Deployment
copy RoomerUpgradeDaemon.exe Deployment

call SignSpecific Deployment\Roomer.exe
call SignSpecific Deployment\RoomerUpgradeDaemon.exe

rem 2880 minutes = 48 hours
VersionXmlGenerator .\Deployment 2880 .\Deployment\Roomer.xml false
REM copy Roomer.xml Deployment


set AWSCMD="aws.exe"
where /Q %AWSCMD%
if errorlevel 1 (
  Echo ERROR: AWS-CLI not found on path
  goto :EOF
)

echo ======================================================================================================
type .\Deployment\Roomer.xml
echo ======================================================================================================
echo .
set answer=
set /p answer="Type yes to start copying to s3://roomerstore ..."
if "%answer%"=="yes" (
  %AWSCMD% s3 rm s3://roomerstore.com/Roomer.xml
  %AWSCMD% s3 sync Deployment s3://roomerstore.com
  %AWSCMD% s3 cp s3://roomerstore.com/Roomer.exe s3://roomerstore.com/roomer.exe
   
  call SendToRdp Roomer.exe Deployment
  
 ) else (
  echo Copying to S3 cancelled
)
endlocal

pause