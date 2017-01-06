
call SignSpecific Roomer.exe

set target=s3://store.roomerdev.net
set awsprofile=--profile=dev
set awsregion=--region=eu-west-1

@REM AWSCLI\aws.exe configure<PRODIAM
set AWSCMD="aws.exe"
where /Q %AWSCMD%
if errorlevel 1 (
  Echo ERROR: AWS-CLI not found on path
  goto :EOF
)

echo .
set answer=
set /p answer="Type yes to start copying exe only to %target% ..."
if "%answer%"=="yes" (
  %AWSCMD% s3 %awsprofile% %awsregion% cp Roomer.exe %target%/Roomer.exe
  %AWSCMD% s3 %awsprofile% %awsregion% cp %target%/Roomer.exe %target%/roomer.exe
) else (
  echo Upload cancelled
)
