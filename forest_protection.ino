#include <Arduino.h>
#include "tempsensor.h"
#include "rfid.h"
#include "servo.h"
#include "flex.h"
#include "wifi.h"
#define LED_PIN 7 // Define the pin for the LED

void setup() {
    // Call the setup functions for the sensors
    Serial.begin(115200);

    setupTemperatureSensor();
    setupRFID();
    setupServo();
    //setupWiFi();
    setupFlexSensor();
    pinMode(LED_PIN, OUTPUT);

   // Serial.begin(115200);

  // Set up Wi-Fi connection
  setupWiFi();

  // Check if Wi-Fi is connected
  if (checkWiFiConnection()) {
    Serial.println("Wi-Fi is connected.");
    // Proceed with further tasks
  } else {
    Serial.println("Wi-Fi is not connected. Please check your Wi-Fi credentials.");
    // Handle the error, maybe restart or enter a fallback mode
  }
}

void loop() {

  //loopWiFi();
    // Read temperature and humidity
    float temperature = readTemperature();
    float humidity = readHumidity();
    digitalWrite(LED_PIN, HIGH);
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" *C ");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // Read and print the card UID
    readCardUID();

    delay(1000); // Delay to prevent spamming the output

    int flexValue = readFlexSensor();
    Serial.print("Flex Sensor Value: ");
    Serial.println(flexValue);

    //Set a threshold for tree cutting detection
    int threshold = 300; // Adjust this value based on your testing
    if (isTreeCutDetected(flexValue, threshold)) {
       Serial.println("Tree cutting detected!");
        //Implement actions if needed
    }

    delay(1000); // Delay for readability
}
