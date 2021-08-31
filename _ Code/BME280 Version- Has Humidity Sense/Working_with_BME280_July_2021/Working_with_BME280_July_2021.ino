/*********
 My Youtube Channel  : http://www.youtube.com/mkmeorg
If you use this code or personalize it etc- please consider sharing it back with the world via the forum at http://www.mkme.org/forum
Website, Forum http://mkme.org
Chat with Me: Discord http://mkme.org/discord
Store http://mkme.org/store
Buy a parts kit on my store: https://store.mkme.org/?product=diy-engine-doctor-esp32-egt-engine-tuning-temp-kit  
  
  
Some code adapted from Rui Santos at https://RandomNerdTutorials.com
Check out his site and give him some support- He's a really cool guy! 
  
  
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
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

/*#include <SPI.h>
#define BME_SCK 18
#define BME_MISO 19
#define BME_MOSI 23
#define BME_CS 5*/

// Added these defines myself from code I cound for ESP32 cam here: https://3iinc.xyz/blog/how-to-use-i2c-sensor-bme280-with-esp32cam/
#define I2C_SDA 4 
#define I2C_SCL 16
TwoWire I2CSensors = TwoWire(0);  //not sure if this is actually needed :)  
Adafruit_BME280 bme; //I2c Init 



// Not needed unless using SPI  
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

// Name the Network SSID and give it a password if you desire 
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
    Serial.print("BME Temp   C   ");
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

//Init I2 and report if unavailable - Works!!!!!!!!!!!!  

I2CSensors.begin(I2C_SDA, I2C_SCL, 100000);
// BME 280 (0x77 or 0x76 will be the address)
  if (!bme.begin(0x76, &I2CSensors))
  {
    Serial.println("Couldn't Find BME280 Sensor");
    while(1);
  }
  else
  {
    Serial.println("BME280 Sensor Found");
  }


 


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
    request->send_P(200, "text/plain", readBME280Temperature().c_str());
  });
  server.on ("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBME280Humidity().c_str());
  });
  server.on ("/pressure", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readBME280Pressure().c_str());
  });

  server.on ("/thermocouple", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readthermocouple().c_str());
  });

  // Start server
  server.begin();
}
 
void loop(){
  
}
