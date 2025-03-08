# Opening and Running the Project in Arduino IDE

This document provides instructions on how to set up, connect hardware, and run the project using the Arduino IDE.

## Requirements
Before running the project, ensure that the following software and hardware are available:

- [Arduino IDE](https://www.arduino.cc/en/software) (for writing and uploading code)
- **Arduino Uno Board**
- **USB Cable** (for connecting Arduino to the computer)

## Hardware Connections
The following components must be connected as specified:

- **Arduino Uno Board**
- **Potentiometer**: Connect to A3.
- **Temperature Sensor (LM35)**: Connect to A2.
- **Push Button**: Connect to digital pin 2.
- **Buzzer**: Connect to digital pin 13.
- **LEDs**:
  - Red LED: Connect to pin 4.
  - Green LED: Connect to pin 5.
  - Blue LED: Connect to pin 6.
  - Single LED: Connect to A0.
- **Servo Motor**: Connect to pin 3.
- **LCD Display**:
  - RS: Pin 7
  - EN: Pin 8
  - D4: Pin 9
  - D5: Pin 10
  - D6: Pin 11
  - D7: Pin 12

## Opening the Project in Arduino IDE
Follow these steps to open the project in Arduino IDE:

1. Open **Arduino IDE**.
2. Click **File** > **Open**.
3. Select the provided Arduino sketch (`.ino` file) and click **Open**.

## Uploading and Running the Project
1. Connect the **Arduino Uno** to the computer via USB.
2. In **Arduino IDE**, go to **Tools** > **Board** and select **Arduino Uno**.
3. Go to **Tools** > **Port** and select the correct COM port.
4. Click **Verify** to compile the code.
5. Click **Upload** to upload the code to the Arduino board.

## Project Functionality
This project monitors temperature and controls LEDs, a servo motor, and a buzzer based on the temperature range set by the user:

- The **potentiometer** is used to set the temperature range.
- The **LCD** displays temperature values and system status.
- The **servo motor** moves based on temperature changes.
- The **LEDs** indicate different temperature levels:
  - **Blue LED**: Low temperature.
  - **Green LED**: Normal temperature.
  - **Red LED**: High temperature.
- The **buzzer** activates when the temperature exceeds the high threshold.
- The **single LED** blinks when the temperature is too high.

Following these steps will allow you to set up, connect, upload, and run the project in Arduino IDE successfully.

