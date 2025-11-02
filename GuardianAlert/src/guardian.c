#include "guardian.h"
#include "hal.h"
#include "voice_engine.h"
#include "live_data.h"
#include "alert_system.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int sms_count = 0;
static int voice_activation_enabled = 1;

void guardian_init() {
    printf("[Guardian] Initializing Enhanced Voice Alert System...\n");
    uart_send("AT\n");
    voice_engine_init();   // assumed to be void
}

void guardian_process() {
    char buffer[256];

    // Handle UART input
    if (uart_receive(buffer, sizeof(buffer))) {
        printf("[UART RX] %s\n", buffer);
    }

    if (voice_activation_enabled) {
        // Simulate microphone input
        char simulated_audio[256];
        printf("\n🎤 Speak command (help me / Thusang / Sizani): ");

        if (fgets(simulated_audio, sizeof(simulated_audio), stdin) != NULL) {
            // Strip newline
            simulated_audio[strcspn(simulated_audio, "\n")] = 0;

            // Map voice input to a trigger_id
            int trigger_id = 0;
            if (strcasecmp(simulated_audio, "help me") == 0) {
                trigger_id = 1;
            } else if (strcasecmp(simulated_audio, "Thusang") == 0) {
                trigger_id = 2;
            } else if (strcasecmp(simulated_audio, "Sizani") == 0) {
                trigger_id = 3;
            }

            if (trigger_id > 0) {
                printf("\n🚨 EMERGENCY TRIGGERED BY VOICE!\n");

                LiveLocationData live_data;
                get_live_gps_data(&live_data);

                send_emergency_alerts(&live_data, trigger_id);

                sms_count += 10; // 5 WhatsApp + 5 SMS
                printf("[GuardianAlert] Total alerts sent: %d\n", sms_count);
            }
        }
    }
}

void guardian_trigger_panic() {
    printf("[GuardianAlert] Manual panic trigger...\n");
    LiveLocationData live_data;
    get_live_gps_data(&live_data);
    send_emergency_alerts(&live_data, 1); // Panic = "help me"
    sms_count += 10;
    printf("[GuardianAlert] Panic alerts sent, total: %d\n", sms_count);
}

int get_sms_count() {
    return sms_count;
}

void guardian_set_voice_activation(int enabled) {
    voice_activation_enabled = enabled;
    printf("[Guardian] Voice activation %s\n",
           enabled ? "ENABLED" : "DISABLED");
}

