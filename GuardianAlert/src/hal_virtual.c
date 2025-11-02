#include "hal.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

// Virtual hardware state
typedef struct {
    int gps_fix;
    double latitude;
    double longitude;
    float speed;
    int network_status;
    int battery_level;
} VirtualHardware;

static VirtualHardware vhw = {0};
static int uart_call_count = 0;

void hal_init() {
    printf("🔄 [VIRTUAL HAL] Initializing simulated hardware...\n");
    vhw.gps_fix = 1;
    vhw.latitude = 40.7128;
    vhw.longitude = -74.0060;
    vhw.speed = 75.5;
    vhw.network_status = 1;
    vhw.battery_level = 85;
    printf("✅ [VIRTUAL HAL] Hardware ready: GPS=%d, Network=%d, Battery=%d%%\n",
           vhw.gps_fix, vhw.network_status, vhw.battery_level);
}

void hal_delay(int milliseconds) {
    printf("⏰ [VIRTUAL HAL] Delaying %d ms\n", milliseconds);
    usleep(milliseconds * 1000);
}

void uart_send(const char* data) {
    printf("📤 [VIRTUAL UART] TX: %s", data);
    uart_call_count++;
}

int uart_receive(char* buffer, int buffer_size) {
    printf("📥 [VIRTUAL UART] RX check (call #%d)\n", uart_call_count);
    
    // Simulate different responses based on what was sent
    if (uart_call_count == 1) {  // Response to "AT"
        snprintf(buffer, buffer_size, "OK\r\n");
    }
    else if (uart_call_count == 2) {  // Response to "AT+CGNSINF"
        time_t now = time(NULL);
        struct tm* tm_info = localtime(&now);
        char timestamp[20];
        strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", tm_info);
        
        snprintf(buffer, buffer_size, 
                 "+CGNSINF: 1,1,%s,%.4f,%.4f,100.5,%.1f,180,1,2.1,1.8,0.9\r\n",
                 timestamp, vhw.latitude, vhw.longitude, vhw.speed);
    }
    else if (uart_call_count == 3) {  // Response to "AT+CMGS"
        snprintf(buffer, buffer_size, "> ");
    }
    else {
        buffer[0] = '\0';
        return 0;
    }
    
    printf("📨 [VIRTUAL UART] RX: %s", buffer);
    return strlen(buffer);
}

// Additional virtual hardware controls
void virtual_set_gps(double lat, double lon, float speed) {
    vhw.latitude = lat;
    vhw.longitude = lon;
    vhw.speed = speed;
    printf("🎯 [VIRTUAL GPS] Set to: %.6f, %.6f, %.1f km/h\n", lat, lon, speed);
}

void virtual_set_battery(int level) {
    vhw.battery_level = level;
    printf("🔋 [VIRTUAL BATTERY] Set to: %d%%\n", level);
}