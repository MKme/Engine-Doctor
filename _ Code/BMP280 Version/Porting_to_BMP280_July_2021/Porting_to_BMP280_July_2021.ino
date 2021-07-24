/*********
  Some code adapted from Rui Santos at https://RandomNerdTutorials.com
  Check out his site and give him some support



I cannot get bmp to read

it is detected on scanner fine 
//Eric confirms BMP280 found at normal location 0x76 When using my modified I2C scanner 
  
*********/
#include "max6675.h"
//Erics confirmed pins for the LOLIN 32 lite 
int thermoDO = 19;  //SO on MAX breakout 
int thermoCS = 17;  // CS on MAX // ERIC moved from 5 to 17 
int thermoCLK = 18; //SCK on MAX 
//MAX VCC to 3V on ESP32
//GND > GND 

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

int thermotemp = 0;


// Import required libraries
#ifdef ESP32
  #include <WiFi.h>
  #include <ESPAsyncWebServer.h>
  #include <SPIFFS.h>
  #include <arduino.h>
#else
  #include <Arduino.h>
  #include <ESP8266WiFi.h>
  #include <Hash.h>
  #include <ESPAsyncTCP.h>
  #include <ESPAsyncWebServer.h>
  #include <FS.h>
#endif
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>



/*#include <SPI.h>
#define BME_SCK 18
#define BME_MISO 19
#define BME_MOSI 23
#define BME_CS 5*/

// Added these defines myself from code I cound for ESP32 cam here: https://3iinc.xyz/blog/how-to-use-i2c-sensor-bme280-with-esp32cam/
#define I2C_SDA 4 
#define I2C_SCL 16
TwoWire I2CSensors = TwoWire(0);  //not sure if this is actually needed :)  
Adafruit_BMP280 bmp; // use I2C interface
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();



// Name the Network SSID and give it a password if you desire 
const char* ssid     = "EngineDoctor";
const char* password = "";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

String readBMP280Temperature() {
  // Read temperature as Celsius (the default)
  float t = bmp.readTemperature();
  // Convert temperature to Fahrenheit
  //t = 1.8 * t + 32;
  if (isnan(t)) {    
    Serial.println("Failed to read from BME280 sensor!");
    return "";
  }
  else {
    Serial.print("BMP Temp   C   ");
    Serial.println(t);
    return String(t);
  }
}



String readBMP280Pressure() {
  sensors_event_t temp_event, pressure_event;
  bmp_temp->getEvent(&temp_event);
  bmp_pressure->getEvent(&pressure_event);

  Serial.print(F("Pressure = "));
  float p = (pressure_event.pressure);
    Serial.print(pressure_event.pressure);
  Serial.println(" hPa");
  if (isnan(p)) {
    Serial.println("Failed to read from BME280 sensor!");
    return "";
  }
  else {
    Serial.println(p);
    return String(p);
  }
}

String readthermocouple() {
  float thermocouple1 = thermocouple.readCelsius();
  if (isnan(thermocouple1)) {
    Serial.println("Failed to read from thermocouple sensor!");
    return "";
  }
  else {
    Serial.println(thermocouple1);
    return String(thermocouple1);
  }
}



void setup(){
    Wire.begin();
    I2CSensors.begin(I2C_SDA, I2C_SCL, 100000);
  // Serial port for debugging purposes
  Serial.begin(115200);

//Init I2 and report if unavailable - Works!!!!!!!!!!!!  

  Serial.println(F("BMP280 Sensor event test"));


  if (!bmp.begin(BMP280_ADDRESS_ALT, BMP280_CHIPID)) {

  //fix found here didnt fix it  http://www.skillbank.co.uk/arduino/NodeI2CSPI.htm
   //if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring or "
                      "try a different address!"));
    while (1) delay(10);
  }

 /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  bmp_temp->printSensorDetails();


    Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
thermotemp = thermocouple.readCelsius();
   Serial.print("C = "); 
   Serial.println(thermocouple.readCelsius());
   
 
   Serial.println(thermotemp);
   Serial.print("F = ");
   Serial.println(thermocouple.readFahrenheit());

  // Initialize SPIFFS
  if(!SPIFFS.begin()){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Connect to Wi-Fi
    WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  WiFi.setSleep(WIFI_PS_NONE);
 // server.begin();   // Dunno where this came from- commented out but no improvement much sad 



  // Route for root / web page
  server.on ("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html");
  });




 
  server.on ("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBMP280Temperature().c_str());
  });
  server.on ("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBMP280Pressure().c_str());
  });

  server.on ("/thermocouple", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readthermocouple().c_str());
  });

  // Start server
  server.begin();
}
 
void loop(){
  sensors_event_t temp_event, pressure_event;
  bmp_temp->getEvent(&temp_event);
  bmp_pressure->getEvent(&pressure_event);
  
  Serial.print(F("Temperature = "));
  Serial.print(temp_event.temperature);
  Serial.println(" *C");

  Serial.print(F("Pressure = "));
  Serial.print(pressure_event.pressure);
  Serial.println(" hPa");

}
