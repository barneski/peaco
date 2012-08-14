// Testing the Range Sensor

int distPin = 3; // Digital Pin 3

void setup() {
  pinMode(distPin, INPUT);
  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  int value = digitalRead(distPin);
  Serial.println(value);
  delay(500);
}
