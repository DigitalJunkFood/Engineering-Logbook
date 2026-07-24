#include <Servo.h>
#include "DHT.h"

// Define Pins
#define DHTPIN 4 // DHT Sensor Data Pin
#define DHTTYPE DHT11 // Change to DHT22 if your sensor is white
const int speedPin = 9; // L293D Pin 1 (Speed)
const int motorIn1 = 2; // L293D Pin 2 (Direction)
const int motorIn2 = 3; // L293D Pin 7 (Direction)
const int servoPin = 10; // Servo Signal Pin

// Initialize Libraries
DHT dht(DHTPIN, DHTTYPE);
Servo coolingServo;

// Temperature Threshold to turn on the fan (in Celsius)
const float TEMP_THRESHOLD = 26.0; 

void setup() {
  Serial.begin(9600);
  dht.begin();
  coolingServo.attach(servoPin);
  
  pinMode(speedPin, OUTPUT);
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn2, OUTPUT);
  
  // Start with the fan turned off
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, LOW);
  analogWrite(speedPin, 0);
  coolingServo.write(90); // Center the servo
}

void loop() {
  delay(2000); // Wait 2 seconds between sensor readings

  float t = dht.readTemperature(); // Read temperature as Celsius

  // Check if reading failed
  if (isnan(t)) {
    Serial.println("Error: Could not read from DHT sensor!");
    return;
  }

  Serial.print("Current Temperature: ");
  Serial.print(t);
  Serial.println("°C");

  // Automated Environment Control Logic
  if (t >= TEMP_THRESHOLD) {
    Serial.println("Alert: High Temp! Activating cooling system...");
    
    // 1. Spin the Fan Forward at Full Speed
    digitalWrite(motorIn1, HIGH);
    digitalWrite(motorIn2, LOW);
    analogWrite(speedPin, 255); 
    
    // 2. Sweep the Servo to act as an oscillating vent
    coolingServo.write(30);
    delay(500);
    coolingServo.write(150);
    delay(500);
    
  } else {
    Serial.println("Temperature safe. System idle.");
    
    // Turn off the fan and center the servo vent
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, LOW);
    analogWrite(speedPin, 0);
    coolingServo.write(90);
  }
}