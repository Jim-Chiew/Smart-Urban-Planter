# Smart-Urban-Planter
Monitor the conditions like moisture, temperature and light for urban farming.

## Background:  
This is a project for my Applied Electronics module. I was task to design and build a Smart Urban Planter (SUP).  

The requirements are as follows:
1. LED 1 will light up when the device sense darkness.
2. LED 2 will light up when the device sense higher temperature than normal.
3. LED 3 will light when the water level indicator is abnormal.
4. LCD will display Temperature Sensor’s reading

My own enhancements to the project:
* Toggle different readings in LCD.
* Display which LED is on in LCD.

## The Build:
**Equipment & Materials:**  
|Meterials | Quantity |
|----------|----------|
|Arduino uno | 1 |
|LED       | 3 (red, yellow, green)|
|Light Dependent Resistor (LDR)| 1 |
|Liquid Crystal Display (LCD) | 1 |
|Temperature Sensor (TMP36) | 1 |
|Resistor | 7 (4 220ohm, 2 10Kohm, 1 10Mohm)|
|Potentiometer | 1 |
|Capacitive Sensor (single exposed Wire) | 1 |
|Tactile Switch | 1 |

**Schematic & Diagram:**  
LED and LCD uses 220ohm resistors. R1 is 10Mohm. R2 is 10Kohm. LDR uses 10Kohm to ground.
![Schematic Diagram](/Images%20and%20Diagrams/Schematic%20diagram.png)  
![Components Diagram](/Images%20and%20Diagrams/Components%20Layout.png)  

**Block Diagram**  
I feel that I could have done batter on the block diagram. I felt that my personal enhancement was good enough to score me enough point to get a good grade, and as such i kind of slack off on the diagram.   
![Block Diagram](/Images%20and%20Diagrams/Block%20daigram%20of%20Program.png)

## Images:
![Build](/Images%20and%20Diagrams/SUP%20PNG.png)
![All LED On](/Images%20and%20Diagrams/all%20led.png)
![Green LED](/Images%20and%20Diagrams/g%20led.png)
![Red LED](/Images%20and%20Diagrams/r%20led.png)
![Yellow and Red LED](/Images%20and%20Diagrams/y%20r%20led.png)
![Demo](/Images%20and%20Diagrams/Demo.gif)

## References:
https://create.arduino.cc/projecthub/rowan07/make-a-simple-led-circuit-ce8308  
https://docs.arduino.cc/learn/electronics/lcd-displays  
https://arduinogetstarted.com/tutorials/arduino-light-sensor  
https://www.tutorialspoint.com/arduino/arduino_temperature_sensor.htm#:~:text=The%20Temperature%20Sensor%20LM35%20series,proportional%20to%20the%20Centigrade%20temperature.  
https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button  

