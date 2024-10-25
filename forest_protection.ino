#include <Arduino.h>
#include "tempsensor.h"
#include "rfid.h"
#include "servo.h"
#include "flex.h"
//#include "wifi.h"
#define LED_PIN 7 // Define the pin for the LED

void setup() {
    // Call the setup functions for the sensors
    setupTemperatureSensor();
    setupRFID();
    setupServo();
    //setupWiFi();
    setupFlexSensor();
    pinMode(LED_PIN, OUTPUT);
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
