// set up the pin we will read data from and the variable we'll store it in
const int sensorPin = A0;
int sensorValue = 0;

void setup() {
  // initialize the Serial port (computer connection)
  Serial.begin(9600);
}

void loop() {
  // Read the value of the sensor pin
  sensorValue = analogRead(sensorPin);
  
  // Print the sensor value to the Serial port
  Serial.println(sensorValue);
  
  // Wait 100 milliseconds (1/10 second) before looping
  delay(100);
}
