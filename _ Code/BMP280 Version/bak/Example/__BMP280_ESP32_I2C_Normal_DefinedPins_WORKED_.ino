//////////////////////////////////////////////////////////////////////////////////////////////////////////
// BMP280_DEV - ESP32, I2C Communications, Default Configuration, Normal Conversion, User-Defined Pins
//////////////////////////////////////////////////////////////////////////////////////////////////////////

//Eric modded and used Martins Library here: https://github.com/MartinL1/BMP280_DEV#bmp280_dev_library

//Adafruit library just refused to work on my ESP32 - the settigns below are reading yay!    


#include <BMP280_DEV.h>                           // Include the BMP280_DEV.h library
 #define I2C_SDA 4 
#define I2C_SCL 16
TwoWire I2CSensors = TwoWire(0);  //not sure if this is actually needed :) 
 
float temperature, pressure, altitude;            // Create the temperature, pressure and altitude variables
BMP280_DEV bmp280(4, 16);                        // Instantiate (create) a BMP280 object and set-up for I2C operation on pins SDA: A6, SCL: A7

void setup() 
{
  Wire.begin();
    I2CSensors.begin(I2C_SDA, I2C_SCL, 100000);
    bmp280.begin(BMP280_I2C_ALT_ADDR);
 
  Serial.begin(115200);                           // Initialise the serial port
  //bmp280.begin();                                 // Default initialisation, place the BMP280 into SLEEP_MODE 
  bmp280.setTimeStandby(TIME_STANDBY_2000MS);     // Set the standby time to 2 seconds
  bmp280.startNormalConversion();                 // Start BMP280 continuous conversion in NORMAL_MODE
}

void loop() 
{
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
