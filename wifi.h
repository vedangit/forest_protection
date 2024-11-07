// wifi.h

#ifndef WIFI_H
#define WIFI_H

#include <SoftwareSerial.h>

// Wi-Fi credentials (could be moved to a separate config file)
extern char* ssid = "MITWPU-GUEST";       // Wi-Fi SSID
extern char* password = "Wpuguest@9192";

// Software serial for ESP8266
extern SoftwareSerial espSerial;

void setupWiFi();  // Function to setup Wi-Fi connection
bool checkWiFiConnection();  // Function to setup Wi-Fi connection
void loopWiFi();   // Placeholder function for additional Wi-Fi tasks

#endif  // WIFI_H
