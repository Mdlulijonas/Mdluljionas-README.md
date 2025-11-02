cat > guardian_email.c << 'EOF'
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define YOUR_EMAIL "mdlulijonas@gmail.com"

void send_simple_email() {
    printf("🚨 SENDING EMAIL ALERT TO %s\n\n", YOUR_EMAIL);
    
    printf("Method 1: Using Windows built-in email\n");
    system("start mailto:mdlulijonas@gmail.com?subject=🚨%20EMERGENCY%20ALERT&body=🚨%20EMERGENCY%20ALERT%21%0A%0ALocation%3A%20-25.767111%2C28.215611%0AGoogle%20Maps%3A%20https%3A%2F%2Fmaps.google.com%2F%3Fq%3D-25.767111%2C28.215611%0A%0AImmediate%20assistance%20needed%21");
    
    printf("✅ Email client opened with pre-filled message!\n");
    printf("💡 Just press SEND in your email client\n\n");
}

void send_gmail_direct() {
    printf("Method 2: Direct Gmail compose\n");
    
    char gmail_url[1024];
    snprintf(gmail_url, sizeof(gmail_url),
             "start https://mail.google.com/mail/?view=cm&fs=1&to=%s&su=🚨%%20EMERGENCY%%20ALERT&body=🚨%%20EMERGENCY%%20ALERT%%21%%0A%%0ALocation%%3A%%20-25.767111%%2C28.215611%%0AGoogle%%20Maps%%3A%%20https%%3A%%2F%%2Fmaps.google.com%%2F%%3Fq%%3D-25.767111%%2C28.215611%%0A%%0AImmediate%%20assistance%%20needed%%21",
             YOUR_EMAIL);
    
    system(gmail_url);
    printf("✅ Gmail compose window opened!\n");
    printf("💡 Press SEND in Gmail\n\n");
}

int main() {
    system("cls");
    printf("==============================================\n");
    printf("🚨 EMAIL ALERT SYSTEM FOR %s\n", YOUR_EMAIL);
    printf("==============================================\n\n");
    
    send_simple_email();
    
    printf("Press any key for Gmail method...");
    system("pause >nul");
    
    send_gmail_direct();
    
    printf("🎯 BOTH METHODS WORK IMMEDIATELY!\n");
    printf("📧 Email will be sent to: %s\n\n", YOUR_EMAIL);
    
    system("pause");
    return 0;
}
EOF