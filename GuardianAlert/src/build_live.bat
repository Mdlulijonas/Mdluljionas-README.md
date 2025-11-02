@echo off
echo Building Live Guardian Alert System with Real Hardware...

gcc -o guardian_live_real.exe live_guardian.c live_data.c voice_engine.c alert_system.c ^
    -lportaudio -lcurl -lwinmm -lws2_32 ^
    -DREAL_HARDWARE -DLIVE_GPS -DVOICE_RECOGNITION ^
    -O2 -Wno-deprecated-declarations

echo.
if exist guardian_live_real.exe (
    echo ✅ BUILD SUCCESSFUL!
    echo 🚀 Run: guardian_live_real.exe
) else (
    echo ❌ BUILD FAILED!
    echo Check dependencies: libcurl, portaudio
)
pause