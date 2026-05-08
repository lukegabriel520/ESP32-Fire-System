# ESP32 Fire System YOLOOOOO

This project is an ESP32-based fire alarm simulation sketch.

## What it does
- Reads an analog value from a potentiometer on GPIO 32.
- Maps that value to a simulated temperature range of 0-100°C.
- Prints the temperature to Serial Monitor (115200 baud).
- If the temperature is above 50°C, it treats it as a fire condition:
  - Turns on an LED (GPIO 4)
  - Plays alternating buzzer tones on GPIO 5
  - Prints a fire alert message
- If temperature is 50°C or below:
  - Turns the LED off
  - Stops buzzer output
  - Prints a "no fire" message

## Hardware pins used
- Potentiometer: GPIO 32
- LED: GPIO 4
- Buzzer: GPIO 5
- DHT22 Data Pin: GPIO 15

## Notes
- The current fire/no-fire logic uses the mapped potentiometer value as the temperature input.
- DHT22 is initialized in code, but temperature for trigger logic is currently simulated via potentiometer mapping.
