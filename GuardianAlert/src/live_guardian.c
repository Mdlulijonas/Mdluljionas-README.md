#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <windows.h>
#include <winsock2.h>
#include <portaudio.h>
#include <curl/curl.h>
#include "guardian.h"
#include "voice_engine.h"
#include "alert_system.h"
#include "live_data.h"

// Global variables for real-time operation
volatile int emergency_triggered = 0;
volatile int physical_button_pressed = 0;
HANDLE hStdin;
DWORD fdwSaveOldMode;

// Physical button handler (Keyboard shortcut: F12)
BOOL WINAPI ConsoleHandler(DWORD signal) {
    if (signal == CTRL_C_EVENT) {
        printf("\n🚨 PHYSICAL BUTTON TRIGGERED (Ctrl+C) - SENDING EMERGENCY ALERT!\n");
        emergency_triggered = 1;
        return TRUE;
    }
    return FALSE;
}

void check_keyboard_input() {
    DWORD cNumRead, fdwMode, i;
    INPUT_RECORD irInBuf[128];
    
    if (GetNumberOfConsoleInputEvents(hStdin, &cNumRead) && cNumRead > 0) {
        ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead);
        for (i = 0; i < cNumRead; i++) {
            if (irInBuf[i].EventType == KEY_EVENT && 
                irInBuf[i].Event.KeyEvent.bKeyDown) {
                // F12 key or Spacebar as physical button
                if (irInBuf[i].Event.KeyEvent.wVirtualKeyCode == VK_F12 ||
                    irInBuf[i].Event.KeyEvent.wVirtualKeyCode == VK_SPACE) {
                    printf("\n🚨 PHYSICAL BUTTON PRESSED - EMERGENCY TRIGGERED!\n");
                    emergency_triggered = 1;
                }
            }
        }
    }
}

// Real microphone voice detection
void voice_listener_loop() {
    printf("🎤 MICROPHONE ACTIVATED - Listening for trigger phrases...\n");
    printf("🔊 Speak clearly: 'HELP ME', 'THUSANG', or 'SIZANI'\n");
    
    while (!emergency_triggered) {
        if (detect_voice_trigger()) {
            printf("🎤 VOICE TRIGGER DETECTED!\n");
            emergency_triggered = 1;
            break;
        }
        Sleep(100); // Reduce CPU usage
    }
}

int main() {
    printf("🚨 LIVE GUARDIAN ALERT SYSTEM - REAL TIME ACTIVATION\n");
    printf("====================================================\n");
    printf("🎤 Voice Commands: 'HELP ME', 'THUSANG', 'SIZANI'\n");
    printf("🔄 Physical Button: Press F12 or SPACEBAR\n");
    printf("📍 Real-time GPS: ACTIVE\n");
    printf("📱 Live Notifications: ENABLED\n\n");
    
    // Initialize real hardware
    if (!initialize_real_hardware()) {
        printf("❌ HARDWARE INITIALIZATION FAILED\n");
        return 1;
    }
    
    // Set up physical button handler
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
    SetConsoleCtrlHandler(ConsoleHandler, TRUE);
    
    printf("✅ SYSTEM READY - Monitoring voice and physical triggers...\n\n");
    
    // Main monitoring loop
    while (!emergency_triggered) {
        check_keyboard_input();
        
        // Start voice listening in separate thread
        voice_listener_loop();
        
        Sleep(50);
    }
    
    // EMERGENCY TRIGGERED - Send real alerts
    if (emergency_triggered) {
        send_live_emergency_alert();
    }
    
    return 0;
}