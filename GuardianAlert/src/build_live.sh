#!/bin/bash

echo "🔨 Building Live Guardian Alert System with Real Hardware..."
echo "=========================================================="

# Check for required dependencies
if ! command -v gcc &> /dev/null; then
    echo "❌ GCC compiler not found. Please install MinGW-w64"
    exit 1
fi

if ! pkg-config --exists libcurl &> /dev/null; then
    echo "⚠️  libcurl not found. Attempting to continue anyway..."
fi

# Compile the real system
echo "📦 Compiling source files..."
gcc -o guardian_live_real.exe \
    live_guardian.c \
    live_data.c \
    voice_engine.c \
    alert_system.c \
    internet_gps.c \
    guardian.c \
    machine_trigger.c \
    -lcurl -lwinmm -lws2_32 -lportaudio \
    -DREAL_HARDWARE -DLIVE_GPS -DVOICE_RECOGNITION \
    -O2 -Wno-deprecated-declarations

echo ""
if [ -f "guardian_live_real.exe" ]; then
    echo "✅ BUILD SUCCESSFUL!"
    echo "🚀 Run with: ./guardian_live_real.exe"
    echo ""
    echo "📋 System Features:"
    echo "   🎤 Real microphone listening"
    echo "   📍 Live GPS coordinates" 
    echo "   📱 Real WhatsApp/SMS alerts"
    echo "   ⌨️  Physical button (F12/Spacebar)"
else
    echo "❌ BUILD FAILED!"
    echo "💡 Try installing dependencies first."
fi