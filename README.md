# Automated Dam Prototype
## Project Description
The "Automated Dam Prototype with Monitoring and Warning Systems" is an innovative engineering project that showcases an automated system designed to regulate water flow through a dam while providing real-time monitoring and warning capabilities. This project combines elements of electronics, automation, and user interface design to create a functional and educational prototype.
## Features
* **Automated Water Gate Control :** The prototype includes an automated water gate system that opens and closes based on predefined water level thresholds.
*  **Real-time Monitoring :** The system is equipped with water level and temperature sensors that continuously monitor the dam's conditions. These measurements are displayed on an LCD screen.
*  **User Control Interface :** An intuitive user interface is incorporated, allowing operators to manually open and close the water gate as needed. The user interface is facilitated by a combination of buttons and switches.
*  **Warning Systems :** When the water gate is open, warning lights and a sound alarm are activated to alert nearby personnel and residents of the potential hazard.
*  **Gate Open Time Display :** A seven-segment display prominently shows the duration for which the water gate has remained open. This feature aids in tracking and managing the gate's operation over time.
*  **Automated Control Logic :** The prototype's microcontroller is programmed with intelligent control logic that autonomously opens and closes the water gate at predefined intervals. This automation reduces the need for constant manual intervention and ensures efficient water flow management.
## Technical Componenets
- **Microcontroller (PIC16F18877) :** The PIC16F18877 serves as the brain of the system, executing control logic, reading sensor data, and managing device operations.
- **Water Level Sensor :** Potentiometers are used to simulate water level sensors. These potentiometer provide data to the microcontroller, allowing it to make decisions based on water level thresholds.
- **Temperature Sensors :** Potentiometers are used to simulate temperature values. These values can be adjusted manually to test the system's response to temperature changes.
- **DC Motor for Gate Operation :** A DC motor is employed to open and close the dam gate. The microcontroller controls the motor's direction and duration to manage water flow. The periodic gate opening and closing done through the Timer0 inturrept of the microcontroller.
- **User Interface :** A user interface consists of,
  - LCD Display: Provides real-time data on water level and temperature.
  - Seven-Segment Display: Indicates the duration for which the gate remains open.
  - Push Button: Allows manual operation of the gate, triggering external interrupts.
  - LEDs: Indicate water level conditions (medium, low, maximum).
- **Warning System :** Warning lights and a buzzer are activated when the gate is open,  The buzzer is controlled through the microcontroller. Buzzer operation is done by Timer3 interrupts.
## Conclusion
This project demonstrates the integration of various components and microcontroller-based control in a real-world application. It showcases expertise in hardware design, microcontroller programming, sensor integration, and safety protocols for dam operation.
