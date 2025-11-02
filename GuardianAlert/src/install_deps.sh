#!/bin/bash

echo "📥 Installing dependencies for Live Guardian System..."
echo "====================================================="

# Install required packages using pacman (MINGW64)
echo "Installing development tools..."
pacman -S --noconfirm mingw-w64-x86_64-gcc
pacman -S --noconfirm mingw-w64-x86_64-curl
pacman -S --noconfirm mingw-w64-x86_64-portaudio
pacman -S --noconfirm make
pacman -S --noconfirm git

echo ""
echo "✅ Dependencies installed successfully!"
echo "💡 You may need to restart your terminal."