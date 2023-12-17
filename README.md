# Digital Clock Project

This project implements a digital clock using an Arduino Uno R3 and a 7-segment display. The clock is based on a 24-hour format and can be used in real-world scenarios, such as in railways.

## Components Used
- Arduino Uno R3
- 7-segment display
- Buzzer

## Pin Configuration
- `DISP_LATCH` (Pin 4) - The pin controlling the display latch.
- `DISP_CLK` (Pin 7) - The pin controlling the display clock.
- `DISP_DATA` (Pin 8) - The pin for display data.
- `BUZZER` (Pin 3) - The pin to enable the speaker.

## Code Overview
The Arduino code (`digital_clock.ino`) contains the logic for displaying the time on the 7-segment display. The clock uses a 24-hour format and includes a buzzer for certain conditions.

## Usage
1. Connect the Arduino Uno R3 to the 7-segment display and buzzer according to the specified pin configuration.
2. Upload the `digital_clock.ino` code to the Arduino board.
3. Power on the system.

## Code Explanation
- The `dispNum` function converts numbers to segment bits required for display.
- The `setup` function initializes the pin modes and sets up the timer.
- The `loop` function continuously displays the time on the 7-segment display, updating every second.
- The buzzer is enabled under specific conditions, and the clock resets at midnight.
