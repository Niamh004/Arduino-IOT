#include <Wire.h>
#include "rgb_lcd.h"
#include <math.h>

rgb_lcd lcd;

const int sensorPin = A1;
const int lightSensorPin = A0; 
const int ledPin = 2; 
const int lightThreshold = 100; 

// Grove Temperature Sensor v1.3
const float BETA = 3975.0;
const float R0 = 10000.0;
const float T0 = 298.15; // 25 degrees Celsius in Kelvin

void setup() {
Serial.begin(9600);

lcd.begin(16, 2);
lcd.setRGB(0, 150, 255); // Blue backlight

lcd.setCursor(0, 0);
lcd.print("Temperature:");

pinMode(ledPin, OUTPUT);

}

void loop() {
int reading = analogRead(sensorPin);

// Avoid invalid readings
if (reading <= 0 || reading >= 1023) {
lcd.setCursor(0, 1);
lcd.print("Check sensor ");
delay(1000);
return;
}

// Convert analogue reading to thermistor resistance
float resistance = R0 * (1023.0 / reading - 1.0);

// Calculate temperature in Celsius
float temperatureK = 1.0 /
(1.0 / T0 + log(resistance / R0) / BETA);

float temperatureC = temperatureK - 273.15;

// Display temperature on LCD
lcd.setCursor(0, 1);
lcd.print(temperatureC, 1);
lcd.print((char)223); // Degree symbol
lcd.print("C ");

// Also show reading in Serial Monitor
Serial.print("Temperature: ");
Serial.print(temperatureC, 1);
Serial.println(" C");

delay(1000);
int lightValue = analogRead(lightSensorPin);

  Serial.print("Light sensor reading");
  Serial.println(lightValue);

  
  if (lightValue < lightThreshold ) {
    digitalWrite(ledPin, LOW); // turn LED off
    Serial.println("LED is on - Fridge Closed ");
  } 
  else {
    digitalWrite(ledPin, HIGH);// turn LED on
    Serial.println("LED is off - Fridge Open ");
  }
  delay(10);
}
