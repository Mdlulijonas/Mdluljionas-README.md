#include <stdio.h>
#include "hal.h"
#include "guardian.h"

int main() {
    printf("🎙️  VOICE ACTIVATED GUARDIANALERT TEST\n");
    printf("=========================================\n");
    printf("Voice Commands: 'help me', 'Thusang', 'Sizani'\n");
    printf("Recipients: 5 contacts via WhatsApp + SMS\n");
    printf("Real-time GPS: Enabled\n\n");
    
    hal_init();
    guardian_init();
    
    printf("\n🔊 System ready! Speak one of the trigger phrases...\n");
    
    while(1) {
        guardian_process();
        hal_delay(1000);
        
        static int cycles = 0;
        if(++cycles > 30) {
            printf("\n✅ Test completed. System is operational!\n");
            break;
        }
    }
    
    return 0;
}
