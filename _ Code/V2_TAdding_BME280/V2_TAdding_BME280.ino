// this example is public domain. enjoy!
// https://learn.adafruit.com/thermocouple/




#include "max6675.h"
//Erics confirmed pins for the LOLIN 32 lite 
int thermoDO = 19;  //SO on MAX breakout 
int thermoCS = 5;  // CS on MAX 
int thermoCLK = 18; //SCK on MAX 
//MAX VCC to 3V on ESP32
//GND > GND 

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  Serial.begin(9600);

  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // basic readout test, just print the current temp
  
   Serial.print("C = "); 
   Serial.println(thermocouple.readCelsius());
   Serial.print("F = ");
   Serial.println(thermocouple.readFahrenheit());
 
   // For the MAX6675 to update, you must delay AT LEAST 250ms between reads!
   delay(1000);
}
