#include "voice_engine.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIGGERS 3
static const char* voice_triggers[MAX_TRIGGERS] = {
    "help me",
    "Thusang", 
    "Sizani"
};

static int voice_sensitivity = 85;

void voice_engine_init() {
    printf("🎤 [VOICE] Initializing with triggers: 'help me', 'Thusang', 'Sizani'\n");
    printf("🎤 [VOICE] Sensitivity: %d%%\n", voice_sensitivity);
    srand(time(NULL));
}

int voice_engine_process(const char* audio_input) {
    printf("🎤 [VOICE] Processing: %s\n", audio_input);
    
    for(int i = 0; i < MAX_TRIGGERS; i++) {
        if(strstr(audio_input, voice_triggers[i]) != NULL) {
            printf("✅ [VOICE] TRIGGERED: '%s'\n", voice_triggers[i]);
            return i + 1;
        }
    }
    return 0;
}

void voice_engine_set_sensitivity(int sensitivity) {
    voice_sensitivity = sensitivity;
    printf("🎤 [VOICE] Sensitivity set to: %d%%\n", sensitivity);
}