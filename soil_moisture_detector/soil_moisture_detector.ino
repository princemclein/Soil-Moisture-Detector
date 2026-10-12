const int sensorPin = A0;

const int redLED = 8;
const int lightLED = 9;
const int greenLED = 10;
const int buzzer = 7;

int moistureValue = 0;
int dryThreshold = 700;
int wetThreshold = 500;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(lightLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  moistureValue = analogRead(sensorPin);

  Serial.print("Moisture Reading: ");
  Serial.println(moistureValue);

  if (moistureValue >= dryThreshold) {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(lightLED, LOW);
    tone(buzzer, 2000);

    Serial.println("Soil is Dry!");
  } else if (moistureValue <= wetThreshold) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(lightLED, LOW);
    noTone(buzzer);

    Serial.println("Soil is Wet");
  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(lightLED, HIGH);
    noTone(buzzer);

    Serial.println("Soil is Moderate");
  }

  delay(1000);
}