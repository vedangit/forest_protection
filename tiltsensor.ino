#include <Wire.h>
#include <MPU6050.h>
#include "tiltsensor.h"

MPU6050 mpu;
float tiltThreshold = 15.0; // Define a tilt angle threshold for alert
bool isTilted = false;      // Track tilt status

void setupTiltSensor() {
  Wire.begin();
  mpu.initialize();

  // Check if MPU6050 is connected
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed!");
  } else {
    Serial.println("MPU6050 connected successfully.");
  }
}

void checkTilt() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  // Convert accelerometer readings to tilt angle
  float tiltAngle = atan2(ax, sqrt(ay * ay + az * az)) * 180 / PI;

  // Check if tilt angle exceeds the threshold
  if (tiltAngle > tiltThreshold) {
    if (!isTilted) {
      Serial.println("Tilt detected!");
      isTilted = true;
      // Additional alert code could go here, e.g., Blynk notification
    }
  } else {
    isTilted = false;
    
  }
}
