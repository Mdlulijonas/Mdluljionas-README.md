#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "voice_engine.h"

void simulate_machine_audio_broadcast() {
    printf("\n🎙️ [MACHINE TRANSMITTER] ACTIVATING MULTI-TRIGGER BROADCAST\n");
    printf("📡 [MACHINE] Broadcasting audio: 'Thusang help sizani'\n");
    printf("📡 [MACHINE] Signal strength: EXCELLENT\n");
    printf("📡 [MACHINE] Connection: INTERNET-CONNECTED\n");
    printf("📡 [MACHINE] Transmission mode: SIMULTANEOUS TRIGGERS\n");
    
    // Simulate machine audio detection of all three phrases
    voice_engine_process_machine_audio("Thusang help sizani emergency situation");
    
    printf("✅ [MACHINE] Multi-trigger audio transmission complete\n");
    printf("🚨 [MACHINE] CRITICAL: Multiple emergency phrases detected!\n");
}