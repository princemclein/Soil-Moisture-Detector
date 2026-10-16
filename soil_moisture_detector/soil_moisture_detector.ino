#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd;

const int sensorPin = A0;

const int redLED = 8;
const int yellow = 9;
const int greenLED = 10;
const int buzzer = 7;

int moistureValue = 0;
int dryThreshold = 700;
int wetThreshold = 500;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");

  lcd.setCursor(0, 1);
  lcd.print("Detector Ready");

delay(1500);
lcd.clear();
}

void loop() {
  moistureValue = analogRead(sensorPin);
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moistureValue);
  lcd.print("    ");

  Serial.print("Moisture Reading: ");
  Serial.println(moistureValue);

  if (moistureValue >= dryThreshold) {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite(yellow, LOW);

    tone(buzzer, 2500);

    lcd.setCursor(0, 1);
    lcd.print("Status: DRY     ");

    Serial.println("Soil is Dry!");

  } else if (moistureValue <= wetThreshold) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(yellow, LOW);

    noTone(buzzer);

    lcd.setCursor(0, 1);
    lcd.print("Status: WET     ");

    Serial.println("Soil is Wet");

  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);x`
    digitalWrite(yellow, HIGH);

    noTone(buzzer);

    lcd.setCursor(0, 1);
    lcd.print("Status: MODERATE");

    Serial.println("Soil is Moderate");
  }

  delay(1000);
}
