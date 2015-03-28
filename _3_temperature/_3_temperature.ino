// Declare our fixed values
const int sensorPin = A0;
const float VInDegreeC = 0.010;
const float VOffset = 0.500;

float calculateVoltage(int rawValue) {
  // Calculate the voltage corresponding to the raw value
  float voltageV = rawValue * 5.0;
  voltageV = voltageV / 1024.0;
  
  // return the voltage value
  return voltageV;
}

float calculateTemperatureC(float voltageT) { 
  // calculate the temperature in C from the voltage
  // First, adjust for the offset
  // Units: Volts = Volts - Volts
  float voltsAdjusted = (voltageT - VOffset);
  
  // Next, determine how many degrees Celsius this represents
  // Units: Celsius = Volts * (Celsius / Volts)
  float temperatureC = voltsAdjusted * (1/VInDegreeC);
  
  // return the temperature
  return temperatureC;
}

void setup() {
  // initialize serial port
  Serial.begin(9600);
}

void loop() {
  // read the raw sensor value (0-1023)
  int sensorValue = analogRead(sensorPin);
  
  // Determine the voltage (0-5V) from the sensor value
  float voltageLoop = calculateVoltage(sensorValue);
  
  // Determine the Temperature in C from the voltage
  float temperatureLoop = calculateTemperatureC(voltageLoop);
  
  // Display the voltage and the temperature
  Serial.print(voltageLoop);
  Serial.print("V:    ");
  Serial.print(temperatureLoop);
  Serial.println("C");
  
  // Wait one second between readings
  delay(1000);
}
