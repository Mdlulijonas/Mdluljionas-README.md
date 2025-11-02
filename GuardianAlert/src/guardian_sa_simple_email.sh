
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define YOUR_EMAIL "mdlulijonas@gmail.com"
#define GMAIL_APP_PASSWORD "tvzm qwky vvfe snpx"

void send_email_powershell() {
    printf("📧 SENDING EMAIL USING POWERSHELL\n");
    printf("   To: %s\n", YOUR_EMAIL);
    
    // Create PowerShell script to send email
    char ps_script[2048];
    snprintf(ps_script, sizeof(ps_script),
             "$Username = 'mdlulijonas@gmail.com'\\n"
             "$Password = '%s'\\n"
             "$To = 'mdlulijonas@gmail.com'\\n"
             "$Subject = '🚨 EMERGENCY ALERT - Guardian System'\\n"
             "$Body = '🚨 EMERGENCY ALERT!\\n\\nI need immediate assistance!\\n\\n📍 Location: -25.767111, 28.215611\\n🗺️ Maps: https://maps.google.com/?q=-25.767111,28.215611\\n\\nTime: Immediate\\n\\nThis is an automated alert from your Guardian System.'\\n"
             "$SmtpServer = 'smtp.gmail.com'\\n"
             "$Port = 587\\n"
             "$SecurePassword = ConvertTo-SecureString $Password -AsPlainText -Force\\n"
             "$Credential = New-Object System.Management.Automation.PSCredential $Username, $SecurePassword\\n"
             "Send-MailMessage -From $Username -To $To -Subject $Subject -Body $Body -SmtpServer $SmtpServer -Port $Port -UseSsl -Credential $Credential\\n",
             GMAIL_APP_PASSWORD);
    
    // Save PowerShell script
    FILE *ps_file = fopen("send_email.ps1", "w");
    if (ps_file) {
        fprintf(ps_file, "%s", ps_script);
        fclose(ps_file);
    }
    
    printf("   📤 Executing PowerShell email script...\\n");
    system("powershell -ExecutionPolicy Bypass -File send_email.ps1");
    
    printf("   ✅ Email sent via PowerShell!\\n");
    
    // Clean up
    remove("send_email.ps1");
    printf("\\n");
}

int main() {
    system("cls");
    printf("==============================================\\n");
    printf("🚨 EMAIL ALERT SYSTEM WITH APP PASSWORD\\n");
    printf("==============================================\\n");
    printf("📧 To: %s\\n", YOUR_EMAIL);
    printf("🔐 Using Gmail App Password\\n");
    printf("==============================================\\n\\n");
    
    send_email_powershell();
    
    printf("🎯 EMAIL SHOULD BE SENT AUTOMATICALLY!\\n");
    printf("💡 Check your inbox at %s\\n\\n", YOUR_EMAIL);
    
    system("pause");
    return 0;
}
