/*

 INA169 Breakout Board Example Code
 By: Shawn Hymel
 SparkFun Electronics
 Date: November 12, 2013

 Description:

 This sketch shows how to use the SparkFun INA169 Breakout
 Board. As current passes through the shunt resistor (Rs), a
 voltage is generated at the Vout pin. Use an analog read and
 some math to determine the current.

 Hardware connections:
 
 Uno Pin    INA169 Board    Function
 
 +5V        VCC             Power supply
 GND        GND             Ground
 A0         VOUT            Analog voltage measurement

 VIN+ and VIN- need to be connected inline with the positive
 DC power rail of a load (e.g. an Arduino, an LED, etc.).

 License:

 "THE BEER-WARE LICENSE" (Revision 42):
 As long as you retain this notice you can do whatever you want
 with this stuff. If we meet some day, and you think this stuff
 is worth it, you can buy me a beer in return.

 */

// Constants
int sensorPin = A0;  // Input pin for measuring Vout from INA169
int rs = 10;         // Shunt resistor value (in Ohms)
int voltageRef = 5;  // Reference voltage for analog read (VCC)

// Global Variables
float sensorValue;   // Variable to store value from analog read
float current;       // Calculated current value

void setup() {
  
  // Initialize serial monitor
  Serial.begin(9600);
  
}

void loop() {
  
  // Read a value from the INA169 board
  sensorValue = analogRead(sensorPin);
  
  // Remap the ADC value into a voltage number (5V reference)
  sensorValue = (sensorValue * voltageRef) / 1023;
  
  // Follow the equation given by the INA169 datasheet to
  // determine the current flowing through RS. Assume RL = 10k
  // Is = (Vout x 1k) / (RS x RL)
  current = sensorValue / (10 * rs);
  
  // Output value (in Amps) to the serial monitor to 4 decimal
  // places
  Serial.print(current, 3);
  Serial.println(" A");
  
  // Delay program for a few milliseconds
  delay(500);
  
}
