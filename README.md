
<p align="center">
<b>ESP32 Engine Doctor</b><br>
Use your smartphone web browser to view engine performance and sensor data<br><br>
<br>🐦 <a href="https://twitter.com/mkmeorg">Twitter</a>
| 📺 <a href="https://www.youtube.com/mkmeorg">YouTube</a>
| 🌍 <a href="http://www.mkme.org">mkme.org</a><br>
<br>
Support this project and become a patron on <a href="https://www.patreon.com/EricWilliam">Patreon</a>.<br>
Chat: <a href="https://discord.gg/j9S4Fgv">Discord</a></b>!
</p>

# DIY ESP32 Engine monitoring for all internal combustion engines 
Engine Doc for all chainsaws, small engines and automotive.  

<img src="https://github.com/MKme/Engine-Doctor/blob/main/_%20photos/Schem.PNG"/>

## Use Case:
The original ideea is to use this for performance chainsaw tuning by monitoring the EGT (exhaust gas temp) or cylinder/head temp we have valuable information 
we can use to track/correlate our changes and even monitor saws with autotune or needs. 

<p align="center">
<img src="https://github.com/MKme/Engine-Doctor/blob/main/_%20photos/vlcsnap-2021-05-02-12h10m24s681.png" width="200"/>
</p>

## Description:

An ESP32 microcontroller with a high temp thermocouple interface you can mount in or stick to any surface you want to measure. 

The ESP32 makes its own Wifi AP (shows up as Engine Doctor wifi network) you can log in to with your phone- open any browser to the IP in the pic and it will graph the data real time asynchronously on the web page as long as its powered on.  

Also has a separate BME280 temp/baro and humidity sensor that will be in the box enclosure or you could remote mount it in an airbox or anywhere you desire.

Future Expansion- I may make a one-wire inductive tachometer pickup too which will be interrupt driven and may need amp circuit. All the spare GPIO are broken out on the PCB for this. 


<img src="https://github.com/MKme/Engine-Doctor/blob/main/_%20photos/PCB%20render.PNG"/>

## Parts:

Buy a kit here: https://store.mkme.org/?product_cat=custom


|     Component    | Source  |
| ---------- |----------------|
| ESP32 Wemos 32 Lite V1 | https://amzn.to/2QzS8t3
| MAX 6675 Thermocouple | https://amzn.to/3tyqds0
| BME280 | https://amzn.to/3x99uhg
| BMP280 (cheaper) | https://amzn.to/3kTSyYb


### Full video here:

TBD http://youtube.com/mkmeorg

### Assembly

- Solder BME 280- note SDC pin (furthest from VCC) is not used- Cut the pin or remove from header

- Use female headers (not supplied in kit) if you would like to make the components removeable



### Code

- Two flavours of code are now offered:

1.  BME280 Version- This has Temp, Pressure and HUMIDITY with Thermocouple

2.  BMP280 Version - This uses the cheaper BMP280 sensor without HUMIDITY

To upload the code you must install ESP32 board support- Google for tutorials

You must be using a fairly recent Arduino IDE to upload spiffs (the web page files)  

Set up your IDE using these settings for the board:

Upload the board (if you get any errors make sure you have installed the Adafruit libraries for the BMP or for BMP280: https://github.com/MartinL1/BMP280_DEV#bmp280_dev_library

Upload web page files Spiffs using the command "Tools> ESP32 Sketch Data Upload"




### How to Use It

- Install the thermocouple where you would like to monitor (use a magnet mount if desired) 

- Power on the EngineDoctor

- Connect to EngineDoctor Wifi with your phone or tablet (no password required)

- Open your web broswer to this url:  192.168.4.1

- Watch the live values in real time while you test/tune!

- Adjust the code if desired to alter the sample display rate (currently 1hz) 


### How I did things (reference) :


Export PCB Footprint to make a case in fusion: https://forum.kicad.info/t/kicad-to-dxf-or-dwg/7994/2

Make the case in fusion: https://www.youtube.com/watch?v=mhXUqtS4mDg&ab_channel=FixedUntilBroken

Make an awesome snap fit case - Thanks Noe! https://www.youtube.com/watch?v=VVmOtM60VWw&ab_channel=AdafruitIndustries


### ESP32 Pinout: 


<img src="https://github.com/MKme/ESP32/blob/main/Wemos%2032%20Lite%20Board/pics/Lolin32_pinout03.png"/>

<img src="https://github.com/MKme/ESP32/blob/main/Wemos%2032%20Lite%20Board/pics/2.jpg"/>
