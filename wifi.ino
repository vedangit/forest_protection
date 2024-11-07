// wifi.ino

#include "wifi.h"

//extern char* ssid = "MITWPU-GUEST";       // Wi-Fi SSID
//extern char* password = "Wpuguest@9192";  // Wi-Fi Password

SoftwareSerial espSerial(0, 1); // RX, TX for ESP8266

void setupWiFi() {
  espSerial.begin(115200); // Initialize ESP8266 communication
  delay(1000);
  
  espSerial.println("AT+RST");           // Reset the ESP8266 module
  delay(2000);
  espSerial.println("AT+CWMODE=1");      // Set ESP8266 to Station mode
  delay(1000);

  // Connect to Wi-Fi
  espSerial.print("AT+CWJAP=\"");
  espSerial.print(ssid);
  espSerial.print("\",\"");
  espSerial.print(password);
  espSerial.println("\"");
  delay(5000);
}

bool checkWiFiConnection() {
  // Check if ESP8266 is connected to Wi-Fi
  espSerial.println("AT+CWJAP?");
  delay(1000);

  String response = "";
  while (espSerial.available()) {
    response += (char)espSerial.read();
  }

  // If the response contains "OK", Wi-Fi is connected
  if (response.indexOf("OK") != -1) {
    Serial.println("Wi-Fi connected!");
    return true;
  } else {
    Serial.println("Wi-Fi connection failed.");
    return false;
  }
}

void loopWiFi() {
  // Placeholder for any tasks related to Wi-Fi you may want to add
}
