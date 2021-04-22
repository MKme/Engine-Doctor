/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.








I dunno wtf- iphone keeps disconnecting now- upgraded esp32 core and no change.  Was working fine an hour ago.  
  
*********/
#include "max6675.h"
//Erics confirmed pins for the LOLIN 32 lite 
int thermoDO = 19;  //SO on MAX breakout 
int thermoCS = 17;  // CS on MAX // ERIC moved from 5 to 17 as 5 seems to be used on BME below for CS 
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
#else
  #include <Arduino.h>
  #include <ESP8266WiFi.h>
  #include <Hash.h>
  #include <ESPAsyncTCP.h>
  #include <ESPAsyncWebServer.h>
  #include <FS.h>
#endif
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

/*#include <SPI.h>
#define BME_SCK 18
#define BME_MISO 19
#define BME_MOSI 23
#define BME_CS 5*/

Adafruit_BME280 bme; // I2C
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

// Replace with your network credentials
const char* ssid     = "EngineDoctor";
const char* password = "";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

String readBME280Temperature() {
  // Read temperature as Celsius (the default)
  float t = bme.readTemperature();
  // Convert temperature to Fahrenheit
  //t = 1.8 * t + 32;
  if (isnan(t)) {    
    Serial.println("Failed to read from BME280 sensor!");
    return "";
  }
  else {
    Serial.println(t);
    return String(t);
  }
}

String readBME280Humidity() {
  float h = bme.readHumidity();
  if (isnan(h)) {
    Serial.println("Failed to read from BME280 sensor!");
    return "";
  }
  else {
    Serial.println(h);
    return String(h);
  }
}

String readBME280Pressure() {
  float p = bme.readPressure() / 100.0F;
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
  // Serial port for debugging purposes
  Serial.begin(115200);


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


/*

 
  server.on ("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBME280Temperature().c_str());
  });
  server.on ("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBME280Humidity().c_str());
  });
  server.on ("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBME280Pressure().c_str());
  });

*/

 
  server.on ("/thermocouple", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readthermocouple().c_str());
  });

  // Start server
  server.begin();
}
 
void loop(){
  
}
