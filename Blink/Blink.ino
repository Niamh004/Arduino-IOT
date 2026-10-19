const int lightSensorPin = A0; //Light sensor is connected to A0
const int ledPin = 2; // LED pin is assignd to D2
const int lightThreshold = 150; //Fridge closed (No light)

void setup() {

  pinMode(ledPin, OUTPUT); //Sets led pin to output (Light on)
  Serial.begin(9600);//Debugging the project 
  Serial.println("fridge"); // Message printed to the serial monitor 

}

void loop() {
  int lightValue = analogRead(lightSensorPin);

  Serial.print("Light value is readng");
  Serial.println(lightValue);

  //turn led off when the light level is below the threshold (i.e door closed)
  if (lightValue < lightThreshold ) {
    digitalWrite(ledPin, LOW); // turn LED off
    Serial.println("LED is on - Fridge Closed");
  } 
  else {
    digitalWrite(ledPin, HIGH);// turn LED on
    Serial.println("LED is off - Fridge Open");
  }
  delay(100);
}
