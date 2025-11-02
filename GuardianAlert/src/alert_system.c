#include "alert_system.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void send_emergency_alerts(LiveLocationData* data, int trigger_id) {
    char message[512];
    const char* trigger_phrase = "";

    switch(trigger_id) {
        case 1: trigger_phrase = "help me"; break;
        case 2: trigger_phrase = "Thusang"; break;
        case 3: trigger_phrase = "Sizani"; break;
    }

    snprintf(message, sizeof(message),
        "🚨 EMERGENCY ALERT!\n"
        "Trigger: %s\n"
        "Location: https://maps.google.com/?q=%.6f,%.6f\n"
        "Time: %s\n"
        "Speed: %.1f km/h\n"
        "Accuracy: %.1f meters\n"
        "Immediate response needed!",
        trigger_phrase,
        data->latitude,
        data->longitude,
        data->timestamp,
        data->speed,
        data->accuracy
    );

    printf("📤 [ALERT] SENDING TO 5 CONTACTS:\n");

    const char* contacts[] = {
        "+27123456789 (Family)",
        "+27987654321 (Friend)",
        "+27111222333 (Neighbor)",
        "+27444555666 (Colleague)",
        "+27890123456 (Emergency)"
    };

    for(int i = 0; i < 5; i++) {
        printf("   %d. 📱 WhatsApp to %s\n", i+1, contacts[i]);
        printf("   %d. 💬 SMS to %s\n", i+1, contacts[i]);
        usleep(200000);
    }

    printf("✅ [ALERT] 10 MESSAGES SENT (5 WhatsApp + 5 SMS)\n");
    printf("💬 Message Content:\n%s\n", message);
}