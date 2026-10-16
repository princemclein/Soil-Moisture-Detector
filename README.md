# Soil Moisture Detector 🌱

An Arduino-based electronics project that detects soil moisture levels and displays real-time sensor readings and soil conditions on a 16×2 I2C LCD. The system uses LED indicators and an audible buzzer alert to help identify when soil is dry, moderately moist, or wet.

## Features

- **Soil Moisture Detection** — Reads soil moisture levels using the YL-69 soil moisture sensor.
- **Real-Time LCD Display** — Displays sensor readings and the current soil condition on a 16×2 I2C LCD.
- **Three-Level Moisture Indication** — Classifies soil conditions as dry, moderate, or wet based on configured thresholds.
- **LED Indicators** — Uses three LEDs to indicate the detected soil condition.
- **Audible Alert** — Activates a buzzer when dry soil is detected.
- **Serial Monitor Output** — Prints moisture readings and soil status for monitoring and debugging.

## Components

- Arduino UNO
- YL-69 soil moisture sensor with LM393 interface board
- 16×2 I2C LCD
- 3 LEDs (red, yellow, and green)
- 3 × 220Ω resistors for the LEDs
- Active buzzer
- Breadboard
- Jumper wires
- Regulated 5V power supply

## How It Works

The YL-69 soil moisture sensor measures changes in electrical conductivity associated with the moisture content of the soil. Its interface board provides an analog signal that the Arduino reads and processes.

The Arduino compares the sensor reading against configured moisture thresholds to determine the soil condition. It then updates the LCD, activates the corresponding LED, and controls the buzzer.

| Soil Condition | LED Indicator | Buzzer |
|---|---|---|
| Dry | Red | ON |
| Moderate | Yellow | OFF |
| Wet | Green | OFF |

The current implementation uses the following default thresholds:

- **Dry:** Sensor reading ≥ 700
- **Moderate:** Sensor reading between 501 and 699
- **Wet:** Sensor reading ≤ 500

These thresholds may need adjustment depending on the sensor, soil type, and testing conditions.

## LCD Display

The 16×2 I2C LCD displays two lines of information:

- **First row:** Current soil moisture sensor reading
- **Second row:** Detected soil condition (DRY, MODERATE, or WET)

The LCD uses the `hd44780` library by Bill Perry with the `hd44780_I2Cexp` interface class.

## Purpose

This project was developed to apply practical knowledge of Arduino programming, analog sensor input, conditional logic, electronic output control, and I2C communication. It demonstrates how a microcontroller can monitor soil conditions and provide clear visual and audible feedback for basic plant-care applications.

## License

This project is intended for educational and personal learning purposes.
