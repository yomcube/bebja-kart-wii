@echo off
SETLOCAL EnableDelayedExpansion

mkdir BKW_
move * BKW_

git clone https://github.com/MelgMKW/Pulsar.git

cd BKW_
move BKW ..\Pulsar
move CW ..\Pulsar
move PulsarEngine\Race\200cc.cpp ..\Pulsar\PulsarEngine\Race\200cc.cpp
cd ..\Pulsar

del /F /Q build
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
FOR %%H IN (%CPPFILES%) DO (
    ::echo "Compiling %%H..."
    %CC% %CFLAGS% %DEFINE% -c -o "build/%%~nH.o" "%%H"
    SET "OBJECTS=build/%%~nH.o !OBJECTS!"
)

:: Link
echo Linking... %time%
".\KamekLinker\Kamek.exe" "build/kamek.o" %OBJECTS% %debug% -dynamic -externals="%GAMESOURCE%/symbols.txt" -versions="%GAMESOURCE%/versions.txt" -output-combined=build\Code.pul

if %ErrorLevel% equ 0 if NOT "!RIIVO!" == "" (
    xcopy /Y build\*.pul "%RIIVO%\Binaries" /i /q
    echo Binaries copied
)

:end
ENDLOCAL