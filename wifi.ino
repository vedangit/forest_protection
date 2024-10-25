// // wifi.ino

// #include "wifi.h"

// // Replace with your network credentials
// const char* ssid = "Your_SSID";       // Wi-Fi SSID
// const char* password = "Your_Password"; // Wi-Fi Password

// void setupWiFi() {
//     Serial.println("Connecting to WiFi...");
//     WiFi.begin(ssid, password);

//     while (WiFi.status() != WL_CONNECTED) {
//         delay(1000);
//         Serial.print(".");
//     }

//     Serial.println("");
//     Serial.print("WiFi connected. IP address: ");
//     Serial.println(WiFi.localIP());
// }

// void loopWiFi() {
//     // Optional: Add any code to run in the loop for Wi-Fi tasks
// }
