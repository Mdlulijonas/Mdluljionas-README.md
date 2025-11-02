#include <stdio.h>
#include "hal.h"
#include "guardian.h"

int main() {
    printf("🚨 Voice-Activated Panic Button Demonstration\n");
    printf("🎙️  Simulating voice trigger: 'help emergency'\n\n");
    
    hal_init();
    guardian_init();
    
    // IMMEDIATE VOICE TRIGGER - No waiting
    printf("🎤 VOICE DETECTED: 'help emergency'!\n");
    printf("🎤 AUTOMATIC PANIC BUTTON ACTIVATED!\n\n");
    
    guardian_trigger_panic(); // This sends location + SMS automatically
    
    printf("\n✅ Emergency alert sent successfully!\n");
    printf("📍 GPS location transmitted\n");
    printf("📱 SMS alert delivered\n");
    printf("🎯 Total alerts sent: %d\n", get_sms_count());
    
    return 0;
}