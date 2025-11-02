#ifndef LIVE_DATA_H
#define LIVE_DATA_H

#include <stdbool.h>

// Real GPS structure
typedef struct {
    double latitude;
    double longitude;
    double speed;
    double accuracy;
    char timestamp[20];
    char address[128];
} live_gps_data_t;

// Real contact structure
typedef struct {
    char name[50];
    char phone[20];
    char type[20]; // "family", "friend", "emergency"
} live_contact_t;

// Real hardware functions
bool initialize_real_hardware(void);
bool get_live_gps_data(live_gps_data_t *gps);
bool detect_voice_trigger(void);
void send_live_emergency_alert(void);
bool send_whatsapp_alert(const char* number, const char* message);
bool send_sms_alert(const char* number, const char* message);

// Real contact management
extern live_contact_t live_contacts[];
extern int live_contact_count;

#endif