
SETLOCAL EnableDelayedExpansion
@echo off
cls
::del build\*.o
del Code.pul

SET "debug="
SET "cwDWARF="
if "%1" equ "-d" SET "debug=-debug -map=^"MAP.txt^" -readelf=^"C:\MinGW\bin\readelf.exe^""
if "%1" equ "-d" SET "cwDWARF=-g"


:: Destination (change as necessary)
SET "SOURCE=Pulsar"
SET "RIIVO=build\Riivolution\Pulsar"
SET "ENGINE=KamekInclude"
SET "CREATOR=PulsarPackCreator\Resources"
echo %RIIVO%


:: CPP compilation settings
SET CC="C:\Users\tomcu\Documents\CW\PowerPC_EABI_Tools\Command_Line_Tools\mwcceppc.exe"
SET CFLAGS=-I- -i "KamekInclude" -i "GameSource" -i "GameSource/MarioKartWii" -i PulsarEngine -i BKW ^
  -opt all -inline auto -enum int -fp hard -sdata 0 -sdata2 0 -maxerrors 1 -func_align 4 %cwDWARF%
SET DEFINE=

:: CPP Sources
SET CPPFILES=
for /R BKW %%f in (*.cpp) do SET "CPPFILES=%%f !CPPFILES!"
SET OBJECTS=
FOR %%H IN (%CPPFILES%) DO (
	set f=%%H
	echo !f:%CD%\=!
	%CC% %CFLAGS% %DEFINE% -c -o "build/%%~nH.o" "%%H"
	SET "OBJECTS=build/%%~nH.o !OBJECTS!"
)

:: Compile CPP
%CC% %CFLAGS% -c -o "build/kamek.o" "%ENGINE%\kamek.cpp"

for /R PulsarEngine %%f in (*.cpp) do SET "CPPFILES=%%f !CPPFILES!"

SET OBJECTS=
FOR %%H IN (%CPPFILES%) DO (
	rem set f=%%H
	rem echo !f:%CD%\=!
	rem %CC% %CFLAGS% %DEFINE% -c -o "build/%%~nH.o" "%%H"
	SET "OBJECTS=build/%%~nH.o !OBJECTS!"
)

:: Link
echo Linking... %time%
"KamekLinker\bin\Debug\net7.0\Kamek.exe" "build/kamek.o" %OBJECTS% %debug% -dynamic -externals="GameSource/symbols.txt" -versions="GameSource/versions.txt" -output-combined=build\Code.pul -map="MAP.txt"

if %Errorlevel% equ 0 (
	echo Copying binaries...
	copy build\*.pul %CD%
	copy Code.pul C:\Dolphin\Load\Riivolution\BKW\Binaries
	::copy Code.pul Binaries
	echo Binaries copied
)

:end
ENDLOCAL