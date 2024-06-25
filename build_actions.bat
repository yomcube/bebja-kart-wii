set "CC=%CD%\CW\mwcceppc.exe"
SET CFLAGS=-I- -i "KamekInclude" -i "GameSource" -i "GameSource/MarioKartWii" -i PulsarEngine -i BKW -opt all -inline auto -enum int -fp hard -sdata 0 -sdata2 0 -maxerrors 1 -func_align 4
SET CPPFILES=

%CC% %CFLAGS% -c -o "build/kamek.o" "%ENGINE%\kamek.cpp"

for /R BKW %%f in (*.cpp) do SET "CPPFILES=%%f !CPPFILES!"
SET OBJECTS=
FOR %%H IN (%CPPFILES%) DO (
  set f=%%H
  echo !f:%CD%\=!
  %CC% %CFLAGS% -c -o "build/%%~nH.o" "%%H"
  SET "OBJECTS=build/%%~nH.o !OBJECTS!"
)

for /R PulsarEngine %%f in (*.cpp) do SET "CPPFILES=%%f !CPPFILES!"
SET OBJECTS=
FOR %%H IN (%CPPFILES%) DO (
  SET "OBJECTS=build/%%~nH.o !OBJECTS!"
)

echo Linking... %time%
"KamekLinker\bin\Debug\net7.0\Kamek.exe" "build/kamek.o" %OBJECTS% %debug% -dynamic -externals="GameSource/symbols.txt" -versions="GameSource/versions.txt" -output-combined=build\Code.pul

if %Errorlevel% equ 0 (
	echo Copying binaries...
	copy build\*.pul %CD%
	copy Code.pul C:\Dolphin\Load\Riivolution\BKW\Binaries
	::copy Code.pul Binaries
	echo Binaries copied
)

:end
ENDLOCAL
