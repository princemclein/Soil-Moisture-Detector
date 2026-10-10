const int sensorPin = A0;
const int greenLED = 8;
const int redLED = 9;

int moistureValue = 0;
int threshold = 500;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  moistureValue = analogRead(sensorPin);

  Serial.print("Moisture Reading: ");
  Serial.println(moistureValue);

  if (moistureValue < threshold) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);

    Serial.println("Soil is Wet");
  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);

    Serial.println("Soil is Dry");
  }

  delay(1000);
}