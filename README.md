
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

## Use Case:
The original ideea is to use this for performance chainsaw tuning by monitoring the EGT (exhaust gas temp) or cylinder/head temp we have valuable information 
we can use to track/correlate our changes and even monitor saws with autotune or needs. 

## Description:

An ESP32 microcontroller with a high temp thermocouple interface you can mount in or stick to any surface you want to measure. 

Also has a separate BME280 temp/baro and humidity sensor that will be in the box enclosure or you could remote mount it in an airbox or whatever. 

I may make a one-wire inductive tachometer pickup too which will be interrupt driven and may need amp circuit

The ESP32 makes its own Wifi AP you can log in to with your phone- open any browser to the IP in the pic and it will graph the data real time asynchronously on the web page as long as its powered on.  


##Parts:

Buy a kit here: http://store.mkme.org

ESP32 Wemos 32 Lite V1 : https://amzn.to/2QzS8t3

MAX 6675 Thermocouple https://amzn.to/3tyqds0

BME280: https://amzn.to/3x99uhg


### Full video here:

TBD 

Used Adafruit example code- seems to work fine if you change the default pins

Pinout: 

<img src="https://github.com/MKme/ESP32/blob/main/Wemos%2032%20Lite%20Board/pics/Lolin32_pinout03.png"/>

<img src="https://github.com/MKme/ESP32/blob/main/Wemos%2032%20Lite%20Board/pics/2.jpg"/>
