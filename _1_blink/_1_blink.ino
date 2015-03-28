const int ledPin = 13;

void blinkLed(int blinkPin, int delayTime) {
    // blinks an LED
    digitalWrite(blinkPin, HIGH);
    delay(delayTime/2);
    digitalWrite(blinkPin, LOW);
    delay(delayTime/2);
}

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  blinkLed(ledPin, 1000);
}
