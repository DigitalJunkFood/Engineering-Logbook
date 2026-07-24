#include <Servo.h>
#include <SimpleDHT.h>

// for L293D/DC motor 
const int speedPin = 9;   // L293D Pin 1 
const int motorIn1 = 2;   // L293D Pin 2 
const int motorIn2 = 3;   // L293D Pin 7 
int pinDHT11 = 4; 

Servo servo1;
int pos = 0;

SimpleDHT11 dht11; 

void setup() { 
  pinMode(speedPin, OUTPUT); 
  pinMode(motorIn1, OUTPUT); 
  pinMode(motorIn2, OUTPUT);
  servo1.attach(10); 
  Serial.begin(9600); 
} 

void loop() { 
  Serial.println("========================="); 
  Serial.println("Reading DHT11....."); 
  
  byte temperature = 0; 
  byte humidity = 0; 
  byte data[40] = {0}; 
  
  // FIXED: Removed "return;". Sensor errors will no longer freeze the motor.
  if (dht11.read(pinDHT11, &temperature, &humidity, data) != 0) { 
    Serial.println("DHT Read Failed - Proceeding to motor sequence anyway."); 
  } else {
    // Print data only if read was successful
    Serial.print("Sample OK: "); 
    Serial.print((int)temperature); 
    Serial.print(" *C, "); 
    Serial.print((int)humidity); 
    Serial.println(" %"); 
  }

  // 1. Spin Forward at Full Speed 
  Serial.println("Motor: Forward");
  digitalWrite(motorIn1, HIGH); 
  digitalWrite(motorIn2, LOW); 
  analogWrite(speedPin, 255); 
  delay(3000); // 3-second delay
  
  // 2. Stop 
  Serial.println("Motor: Stopped");
  digitalWrite(motorIn1, LOW); 
  digitalWrite(motorIn2, LOW); 
  delay(2000); // 2-second delay

  // Move Servo
  Serial.println("Servo: Open");
  for (pos = 90; pos <= 190; pos += 1) {
  servo1.write(pos);
  delay(15);}
  Serial.println("Servo: Closed");
  for (pos = 190; pos >= 90; pos -= 1) {
  servo1.write(pos);
  delay(15);}
  
  // 3. Spin Backward at Full Speed 
  Serial.println("Motor: Backward");
  digitalWrite(motorIn1, LOW); 
  digitalWrite(motorIn2, HIGH); 
  analogWrite(speedPin, 255); 
  delay(3000); // 3-second delay
  
  // 4. Stop 
  Serial.println("Motor: Stopped");
  digitalWrite(motorIn1, LOW); 
  digitalWrite(motorIn2, LOW); 
  delay(5000); // 5-second delay
}
