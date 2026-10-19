//Smart light Sensor, Using grove light sensor and the LED

const int lightSensorPin = A0; //light snesor is connectd to A0
const int ledPin = 3; // LED pin is assignd to D3
const int lightThreshold = 100; //lower than this value its dark and the light will come on 

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); //Debugging the project 
  Serial.println("Smart light is starting....."); // Message printed to the serial monitor 
}

void loop() {


  //turn led on when the light level is below the threshold (i.e dark)
  if (lightValue < lightThreshold ) {
    digitalWrite(ledPin, HIGH); // turn LED on
    Serial.println("LED is on - Its Dark");
  } 
  else {
    digitalWrite(ledPin, LOW);// turn LED off
    Serial.println("LED is off - Its bright");
  }

  
}
