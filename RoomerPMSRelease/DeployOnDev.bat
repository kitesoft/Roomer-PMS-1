@echo off
setlocal

set target=s3://store.roomerdev.net
set awsprofile=--profile=dev
set awsregion=--region=eu-west-1

VersionXmlGenerator . 2880 .\Roomer.xml false

if not exist "Deployment" mkdir Deployment

copy Roomer.exe Deployment
copy RoomerUpgradeAgent.exe Deployment
copy RoomerUpgradeDaemon.exe Deployment
copy Roomer.xml Deployment

call SignSpecific Deployment\Roomer.exe
call SignSpecific Deployment\RoomerUpgradeAgent.exe
call SignSpecific Deployment\RoomerUpgradeDaemon.exe


set AWSCMD="aws.exe"
where /Q %AWSCMD%
if errorlevel 1 (
  Echo ERROR: AWS-CLI not found on path
  goto :EOF
)

echo .
set answer=
set /p answer="Type yes to start copying to %target% ..."
if "%answer%"=="yes" (
  %AWSCMD% s3 %awsprofile% %awsregion% rm %target%/Roomer.xml
  %AWSCMD% s3 %awsprofile% %awsregion% sync Deployment %target%
  %AWSCMD% s3 %awsprofile% %awsregion% cp %target%/Roomer.exe %target%/roomer.exe
 ) else (
  echo Copying to %target% cancelled
)
endlocal

pause