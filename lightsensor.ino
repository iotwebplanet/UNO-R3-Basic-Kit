

//This program for led brightness according to light of the room

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPin = A0;  // Analog input pin that the LDR is attached to
const int ledPin = 9; // Analog output pin that the LED is attached to

//basic value
int sensorValue = 0;        // value read ldr sensor
int brightness = 0;        // value output to the PWM (analog out)

void setup() {
  // serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value of LDR :
  sensorValue = analogRead(analogInPin);
  
  // mapping it to the range of the sensor: i used 1K resistor
// .      map(valuetobemap, min_value, max-value,  maped_min_value, mapped_max_value)
  
  brightness = map(sensorValue, 0, 750, 0, 255);
  
  // change the analog out value:
  analogWrite(ledPin, brightness);

  // print the results to the serial monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(brightness);

  
  // after the last reading:
  delay(2);
}
