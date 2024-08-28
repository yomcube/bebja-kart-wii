@echo off
SETLOCAL EnableDelayedExpansion

git clone https://github.com/MelgMKW/Pulsar.git Pulsar
move CW Pulsar
cd BKW_
move BKW ..\Pulsar
move /Y PulsarEngine\Race\200cc.cpp ..\Pulsar\PulsarEngine\Race\200cc.cpp
cd ..\Pulsar

del /F /Q /S build
mkdir build

SET "ENGINE=.\KamekInclude"
set "GAMESOURCE=.\GameSource"
SET "PULSAR=.\PulsarEngine"
SET "BKW=.\BKW"

:: Change this as necessary depending on where you put CodeWarrior
SET "CC=CW\mwcceppc.exe"

:: Riivolution Destination (change as necessary)
SET "RIIVO="

:: Compiler flags and folder
SET CFLAGS=-I- -i %ENGINE% -i %GAMESOURCE% -i %PULSAR% -i %BKW% ^
  -opt all -inline auto -enum int -proc gekko -fp hard -sdata 0 -sdata2 0 -maxerrors 1 -func_align 4 %cwDWARF%
SET DEFINE=

if "!CC!" == "" (
    echo You need to specify the path to CodeWarrior by setting the CC variable
    exit /b 1
)

:: CPP Sources
SET CPPFILES=
for /R %BKW% %%f in (*.cpp) do SET "CPPFILES=%%f !CPPFILES!"
for /R %PULSAR% %%f in (*.cpp) do SET "CPPFILES=%%f !CPPFILES!"

:: Compile CPP
%CC% %CFLAGS% -c -o "build/kamek.o" "%ENGINE%\kamek.cpp"

SET OBJECTS=

set _stderr=stderr.txt
FOR %%H IN (%CPPFILES%) DO (
    set f=%%H
    echo !f:%CD%\=!

    %CC% %CFLAGS% %DEFINE% -stderr -c -o "build/%%~nH.o" "%%H" 2>> %_stderr%
    SET "OBJECTS=build/%%~nH.o !OBJECTS!"
)
type %_stderr%

:: https://stackoverflow.com/a/1199839
FOR /F "usebackq" %%A IN ('%_stderr%') DO set size=%%~zA
if %size% GTR 2 (
    echo Fatal error. Compilation aborted.
    exit /b 1
)

:: Link
echo Linking... %time%
".\KamekLinker\Kamek.exe" "build/kamek.o" %OBJECTS% %debug% -dynamic -externals="%GAMESOURCE%/symbols.txt" -versions="%GAMESOURCE%/versions.txt" -output-combined=build\Code.pul

:end
ENDLOCAL