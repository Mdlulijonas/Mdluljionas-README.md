cat > guardian_setup_guide.c << 'EOF'
#include <stdio.h>
#include <windows.h>
#include <time.h>

#define YOUR_WHATSAPP "+27650924171"
#define YOUR_SMS "+27699795153"

int main() {
    system("cls");
    
    printf("==================================================\n");
    printf("🚨 REAL ALERT SYSTEM SETUP GUIDE\n");
    printf("==================================================\n");
    printf("📱 YOUR NUMBERS: %s (WhatsApp), %s (SMS)\n", YOUR_WHATSAPP, YOUR_SMS);
    printf("==================================================\n\n");
    
    printf("🔧 TO SEND REAL ALERTS, YOU NEED:\n\n");
    
    printf("1. 📞 TWILIO ACCOUNT (Free Tier):\n");
    printf("   • Visit: https://www.twilio.com/try-twilio\n");
    printf("   • Sign up for free account\n");
    printf("   • Get $15-20 free credit for testing\n\n");
    
    printf("2. 🔑 API CREDENTIALS:\n");
    printf("   • Account SID\n");
    printf("   • Auth Token\n");
    printf("   • Twilio phone number\n\n");
    
    printf("3. 💰 COST ESTIMATE:\n");
    printf("   • SMS: ~$0.0075 per message\n");
    printf("   • WhatsApp: ~$0.005 per message\n");
    printf("   • Free tier covers many test messages\n\n");
    
    printf("4. 🚀 QUICK START:\n");
    printf("   • Replace API credentials in the code\n");
    printf("   • Compile with: gcc -lcurl -lwinmm\n");
    printf("   • Test with small credit first\n\n");
    
    printf("5. 🌐 ALTERNATIVES:\n");
    printf("   • TextLocal, Clickatell, MessageBird\n");
    printf("   • South African providers: BulkSMS, Clickatell SA\n\n");
    
    printf("Press SPACE to simulate test alert, or any other key to exit...\n");
    
    if(getch() == ' ') {
        printf("\n🚨 SIMULATION: If APIs were configured:\n");
        printf("   ✅ WhatsApp sent to: %s\n", YOUR_WHATSAPP);
        printf("   ✅ SMS sent to: %s\n", YOUR_SMS);
        printf("   📍 Location: Your current area\n");
        printf("   💬 Message: Emergency alert with live location\n");
    }
    
    printf("\nVisit: https://www.twilio.com/docs/sms/quickstart/c\n");
    printf("For complete C implementation guide.\n");
    
    return 0;
}
EOF

gcc -o guardian_setup.exe guardian_setup_guide.c -lwinmm
./guardian_setup.exe