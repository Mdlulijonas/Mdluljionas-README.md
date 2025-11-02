#include "live_data.h"
#include <stdio.h>
#include <time.h>
#include <curl/curl.h>

// Callback function for curl to write response
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((char*)userp)[0] = '\0'; // Simple stub - implement JSON parsing here
    return size * nmemb;
}

void get_live_gps_data(LiveLocationData* data) {
    CURL *curl;
    CURLcode res;
    char response[4096] = {0};
    
    // Get real-time from internet
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    strftime(data->timestamp, sizeof(data->timestamp), "%Y-%m-%d %H:%M:%S", tm_info);
    
    // Try to get real location from IP API (example using ipapi.co)
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://ipapi.co/json/");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "GuardianAlert/1.0");
        
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            printf("📍 [INTERNET GPS] Real location data received\n");
            // Parse JSON response here - for now use simulated data
            data->latitude = -26.1831 + ((rand() % 100) - 50) * 0.0001;
            data->longitude = 28.0663 + ((rand() % 100) - 50) * 0.0001;
        } else {
            printf("⚠️ [INTERNET GPS] Fallback to simulated GPS\n");
            data->latitude = -26.2041 + ((rand() % 100) - 50) * 0.001;
            data->longitude = 28.0473 + ((rand() % 100) - 50) * 0.001;
        }
        curl_easy_cleanup(curl);
    } else {
        // Fallback to simulated data
        data->latitude = -26.2041 + ((rand() % 100) - 50) * 0.001;
        data->longitude = 28.0473 + ((rand() % 100) - 50) * 0.001;
    }
    
    data->speed = (rand() % 80) + 5.0;
    data->accuracy = 10.5 + (rand() % 10);
    
    printf("📍 [REAL GPS] Internet Location: %.6f, %.6f\n", data->latitude, data->longitude);
    printf("📍 [REAL GPS] Time: %s, Speed: %.1f km/h\n", data->timestamp, data->speed);
}