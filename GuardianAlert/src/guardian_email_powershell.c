
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define YOUR_EMAIL "mdlulijonas@gmail.com"
#define GMAIL_APP_PASSWORD "tvzm qwky vvfe snpx"

void send_email_powershell() {
    printf("📧 SENDING EMAIL USING POWERSHELL\n");
    printf("   To: %s\n", YOUR_EMAIL);
    printf("   Using app password: %s\n", GMAIL_APP_PASSWORD);
    
    // Create proper PowerShell script
    system("echo $Username = 'mdlulijonas@gmail.com' > send_email.ps1");
    system("echo $Password = 'tvzm qwky vvfe snpx' >> send_email.ps1");
    system("echo $To = 'mdlulijonas@gmail.com' >> send_email.ps1");
    system("echo $Subject = '🚨 EMERGENCY ALERT - Guardian System' >> send_email.ps1");
    system("echo $Body = '🚨 EMERGENCY ALERT!\\n\\nI need immediate assistance!\\n\\n📍 Location: -25.767111, 28.215611\\n🗺️ Maps: https://maps.google.com/?q=-25.767111,28.215611\\n\\nTime: Immediate\\n\\nThis is an automated alert from your Guardian System.' >> send_email.ps1");
    system("echo $SmtpServer = 'smtp.gmail.com' >> send_email.ps1");
    system("echo $Port = 587 >> send_email.ps1");
    system("echo $SecurePassword = ConvertTo-SecureString $Password -AsPlainText -Force >> send_email.ps1");
    system("echo $Credential = New-Object System.Management.Automation.PSCredential $Username, $SecurePassword >> send_email.ps1");
    system("echo Send-MailMessage -From $Username -To $To -Subject $Subject -Body $Body -SmtpServer $SmtpServer -Port $Port -UseSsl -Credential $Credential >> send_email.ps1");
    
    printf("   📤 Executing PowerShell email script...\n");
    system("powershell -ExecutionPolicy Bypass -File send_email.ps1");
    
    printf("   ✅ Email sent via PowerShell!\n");
    
    // Clean up
    remove("send_email.ps1");
    printf("\n");
}

int main() {
    system("cls");
    printf("==============================================\n");
    printf("🚨 EMAIL ALERT SYSTEM WITH APP PASSWORD\n");
    printf("==============================================\n");
    printf("📧 To: %s\n", YOUR_EMAIL);
    printf("🔐 Using Gmail App Password\n");
    printf("==============================================\n\n");
    
    send_email_powershell();
    
    printf("🎯 EMAIL SHOULD BE SENT AUTOMATICALLY!\n");
    printf("💡 Check your inbox at %s\n\n", YOUR_EMAIL);
    
    system("pause");
    return 0;
}