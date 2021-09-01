/*********
My Youtube Channel  : http://www.youtube.com/mkmeorg
If you use this code or personalize it etc- please consider sharing it back with the world via the forum at http://www.mkme.org/forum
Website, Forum http://mkme.org
Chat with Me: Discord http://mkme.org/discord
Store http://mkme.org/store
Buy a parts kit on my store: https://store.mkme.org/?product=diy-engine-doctor-esp32-egt-engine-tuning-temp-kit  
  
Some code adapted from Rui Santos at https://RandomNerdTutorials.com
Check out his site and give him some support

Eric used Martins Library here: https://github.com/MartinL1/BMP280_DEV#bmp280_dev_library

Adafruit library just refused to work on my ESP32 - the settings below are reading yay!    

Completely working with BMP280 now!!!  
Humidity display removed
Excess serial debugging is left in place here so others can add code as they want for IO etc

  
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

#include <BMP280_DEV.h>  
// Added these defines myself from code I cound for ESP32 cam here: https://3iinc.xyz/blog/how-to-use-i2c-sensor-bme280-with-esp32cam/
#define I2C_SDA 4 
#define I2C_SCL 16
TwoWire I2CSensors = TwoWire(0);  //not sure if this is actually needed :)  
float temperature, pressure, altitude;            // Create the temperature, pressure and altitude variables
BMP280_DEV bmp280(4, 16);                        // Instantiate (create) a BMP280 object and set-up for I2C operation on pins SDA: A6, SCL: A7



// Name the Network SSID and give it a password if you desire 
const char* ssid     = "EngineDoctor";
const char* password = "";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);

  
String readBMP280Temperature() {
  // Read temperature as Celsius (the default)
  float t = (temperature);
  if (isnan(t)) {    
    Serial.println("Failed to read from BMP280 sensor!");
    return "";
  }
  else {
    Serial.print("BMP Temp   C   ");
    Serial.println(t);
    return String(t);
  }
}


String readBMP280Pressure() {
  float p = (pressure);
  if (isnan(p)) {
    Serial.println("Failed to read from BMP280 sensor!");
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

  I2CSensors.begin(I2C_SDA, I2C_SCL, 100000);
    bmp280.begin(BMP280_I2C_ALT_ADDR);
  // Serial port for debugging purposes
  Serial.begin(115200);                           // Initialise the serial port
  //bmp280.begin();                                 // Default initialisation, place the BMP280 into SLEEP_MODE 
  bmp280.setTimeStandby(TIME_STANDBY_2000MS);     // Set the standby time to 2 seconds
  bmp280.startNormalConversion();                 // Start BMP280 continuous conversion in NORMAL_MODE




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
  if (bmp280.getMeasurements(temperature, pressure, altitude))    // Check if the measurement is complete
  {
    Serial.print(temperature);                    // Display the results    
    Serial.print(F("*C   "));
    Serial.print(pressure);    
    Serial.print(F("hPa   "));
    Serial.print(altitude);
    Serial.println(F("m"));  
  }
  
}

//This work is licensed under a Creative Commons Attribution-NonCommercial 4.0 International License. https://creativecommons.org/licenses/by-nc/4.0/ See comments in main code for more info
