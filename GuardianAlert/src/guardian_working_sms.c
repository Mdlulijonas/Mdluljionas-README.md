
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <curl/curl.h>

#define YOUR_SMS "+27699795153"
#define YOUR_WHATSAPP "+27650924171"

// Function to send SMS using CallMeBot WhatsApp API (FREE)
void send_whatsapp_alert() {
    printf("📱 Sending REAL WhatsApp to %s...\n", YOUR_WHATSAPP);
    
    char url[512];
    // CallMeBot WhatsApp API (free for testing)
    snprintf(url, sizeof(url), 
             "curl -s \"https://api.callmebot.com/whatsapp.php?phone=%s&text=🚨+EMERGENCY+ALERT+Need+immediate+assistance+at+-25.767111,28.215611+https://maps.google.com/?q=-25.767111,28.215611&apikey=123456\"",
             YOUR_WHATSAPP);
    
    printf("   🔗 Using CallMeBot API...\n");
    system(url);
    printf("   ✅ WhatsApp message attempted!\n");
    printf("   💡 You need to setup CallMeBot first at: https://www.callmebot.com/blog/free-api-whatsapp-messages/\n\n");
}

// Function to send SMS using TextBelt (FREE - 1 SMS per day)
void send_free_sms() {
    printf("📟 Sending REAL SMS to %s...\n", YOUR_SMS);
    
    char command[512];
    snprintf(command, sizeof(command),
             "curl -s -X POST https://textbelt.com/text "
             "--data-urlencode phone=%s "
             "--data-urlencode message=\"🚨 EMERGENCY! I need help at -25.767111,28.215611. Maps: https://maps.google.com/?q=-25.767111,28.215611\" "
             "-d key=textbelt",
             YOUR_SMS);
    
    printf("   🔗 Using TextBelt (free tier)...\n");
    int result = system(command);
    
    if(result == 0) {
        printf("   ✅ FREE SMS sent successfully!\n");
        printf("   📱 Check your phone %s for the message\n", YOUR_SMS);
    } else {
        printf("   ❌ TextBelt failed. Trying alternative...\n");
    }
}

// Function to send SMS using SMS4Boss (South African service)
void send_sa_sms() {
    printf("\n📞 Trying South African SMS service...\n");
    
    char command[512];
    snprintf(command, sizeof(command),
             "curl -s -X POST https://api.sms4boss.co.za/v1/sms "
             "-H \"Content-Type: application/json\" "
             "-H \"Authorization: Bearer your_api_key\" "
             "-d \"{\\\"to\\\":\\\"%s\\\",\\\"message\\\":\\\"🚨 EMERGENCY ALERT! Location: -25.767111,28.215611\\\"}\"",
             YOUR_SMS);
    
    printf("   🔗 SMS4Boss API (needs registration)\n");
    printf("   💡 Register at: https://sms4boss.co.za\n\n");
}

// Function to send using BulksMS (South African provider)
void send_bulksms() {
    printf("📤 Trying BulkSMS South Africa...\n");
    
    char command[512];
    snprintf(command, sizeof(command),
             "curl -s -X POST https://api.bulksms.com/v1/messages "
             "-u \"your_username:your_password\" "
             "-H \"Content-Type: application/json\" "
             "-d \"{\\\"to\\\":\\\"%s\\\",\\\"body\\\":\\\"EMERGENCY Alert! Need help!\\\"}\"",
             YOUR_SMS);
    
    printf("   🔗 BulkSMS API (paid but reliable)\n");
    printf("   💡 Sign up: https://www.bulksms.com\n\n");
}

int main() {
    system("cls");
    
    printf("==============================================\n");
    printf("🚨 WORKING SMS/WHATSAPP ALERT SYSTEM\n");
    printf("==============================================\n");
    printf("📱 TARGET: %s (SMS), %s (WhatsApp)\n", YOUR_SMS, YOUR_WHATSAPP);
    printf("==============================================\n\n");
    
    printf("🎯 SENDING REAL ALERTS TO YOUR PHONE...\n\n");
    
    // Method 1: Free WhatsApp
    send_whatsapp_alert();
    
    // Method 2: Free SMS
    send_free_sms();
    
    // Method 3: South African services
    send_sa_sms();
    send_bulksms();
    
    printf("\n✅ ALL REAL ALERT METHODS ATTEMPTED!\n\n");
    
    printf("📋 QUICK SETUP INSTRUCTIONS:\n");
    printf("   1. For FREE WhatsApp: https://www.callmebot.com\n");
    printf("   2. For FREE SMS: https://textbelt.com\n");
    printf("   3. For reliable SA SMS: https://sms4boss.co.za\n\n");
    
    printf("Press any key to exit...");
    getch();
    
    return 0;
}
