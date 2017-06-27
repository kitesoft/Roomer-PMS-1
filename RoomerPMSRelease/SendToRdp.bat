@echo off
if "%2"=="" (
  goto ERROR
)
if "%1"=="" (
  goto ERROR
)

  REM Prepare a timestamp for the rename procedure below
  set Day=%Date:~0,2%
  set Mth=%Date:~3,2%
  set Yr=%Date:~6,4%
  set Hr=%TIME:~0,2%
  set Mi=%TIME:~3,2%

  REM Create a new name with the prepared timestamp - which will hold the older, current release
  set NewFileName=%1.%Day%%Mth%%Yr%T%Hr%%Mi%

  REM Create an FTP which includes the upgrade logic:
  REM 	1 - Upload EXE with the addition "_NEW" to the filename.
  REM   2 - Rename the old EXE to the old name plus the current timestamp in the format: yyyymmddThhnn.
  REM   3 - Rename the newly uploaded file to the correct EXE name.
  
  echo Open connection and log in...
  echo open 54.194.140.24> rdp.ftp
  echo RoomerExes>> rdp.ftp
  echo RwEqFdSa201706>> rdp.ftp
  echo binary>> rdp.ftp

  echo Prepare the upgrade logic...
  echo    1 - Upload EXE with the addition "_NEW" to the filename.
  echo put %2\%1 %1_New>> rdp.ftp

  echo    2 - Rename the old EXE to the old name plus the current timestamp in the format: yyyymmddThhnn.
  echo rename %1 %NewFileName%>> rdp.ftp

  echo    3 - Rename the newly uploaded file to the correct EXE name.
  echo rename %1_New %1>> rdp.ftp

  echo Now Disconnect and quit.
  echo disconnect>> rdp.ftp
  echo quit>> rdp.ftp
  
  REM Fire in the hole....
  ftp -i -s:rdp.ftp

  goto END 

:ERROR  
  echo    ------------------------------------------------------------------
  echo                                                                     .
  echo    Wrong syntax: Incorrect number of parameters
  echo                                                                     .
  echo    ------------------------------------------------------------------
  echo                                                                     .
  echo    Syntax: SendToRdp [filename] [directory]
  echo            where:
  echo                [filename]  is the name of the file being sent
  echo                [directory] is the directory of the file being sent
  echo                                                                     .
  echo    ------------------------------------------------------------------
  echo                                                                     .
  echo    Example: SendToRdp Roomer.exe Deployment
  echo    ------------------------------------------------------------------
  echo                                                                     .
  
:END