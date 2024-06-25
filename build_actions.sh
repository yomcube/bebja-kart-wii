CC=wine CW/mwcceppc.exe
CFLAGS="-I- -i KamekInclude -i GameSource -i \"GameSource/MarioKartWii\" -i PulsarEngine -i BKW -opt all -inline auto -enum int -fp hard -sdata 0 -sdata2 0 -maxerrors 1 -func_align 4"
CPPFILES=""

mkdir build
$CC $CFLAGS -c -o "build/kamek.o" "$ENGINE/kamek.cpp"

OBJECTS=
for f in BKW/**.cpp; do
	$CC $CFLAGS -c -o "build/${f%.cpp}.o" "$f"
 	OBJECTS="$OBJECTS ${f%.cpp}"
done
for f in PulsarEngine/*.cpp PulsarEngine/**/*.cpp; do
 	$CC $CFLAGS -c -o "build/${f%.cpp}.o" "$f"
	OBJECTS="$OBJECTS ${f%.cpp}"
done
echo "Linking..."
dotnet "KamekLinker/bin/Release/net7.0/Kamek.exe" "build/kamek.o" $OBJECTS -dynamic -externals="GameSource/symbols.txt" -versions="GameSource/versions.txt" -output-combined=build/Code.pul
