
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

<img src="https://github.com/MKme/enginedoctor/blob/main/_%20photos/IMG_2200.jpg" width="200"/>

## Description:

An ESP32 microcontroller with a high temp thermocouple interface you can mount in or stick to any surface you want to measure. 

Also has a separate BME280 temp/baro and humidity sensor that will be in the box enclosure or you could remote mount it in an airbox or whatever. 

I may make a one-wire inductive tachometer pickup too which will be interrupt driven and may need amp circuit

The ESP32 makes its own Wifi AP you can log in to with your phone- open any browser to the IP in the pic and it will graph the data real time asynchronously on the web page as long as its powered on.  

<img src="https://github.com/MKme/Engine-Doctor/blob/main/_%20photos/PCB%20render.PNG"/>

## Parts:

Buy a kit here: https://store.mkme.org/?product_cat=custom

ESP32 Wemos 32 Lite V1 : https://amzn.to/2QzS8t3

MAX 6675 Thermocouple https://amzn.to/3tyqds0

BME280: https://amzn.to/3x99uhg


### Full video here:

TBD http://youtube.com/mkmeorg

## How to Use It

1. Turn on EngineDoctor

2. Connect to EngineDoctor Wifi (no password required)

3. Open your web broswer to this url:  192.158.4.1

5. Watch the live values in real tiem while you test/tune!



### How I did things (reference) :


Export PCB Footprint to make a case in fusion: https://forum.kicad.info/t/kicad-to-dxf-or-dwg/7994/2

Make the case in fusion: https://www.youtube.com/watch?v=mhXUqtS4mDg&ab_channel=FixedUntilBroken

Make an awesome snap fit case - Thanks Noe! https://www.youtube.com/watch?v=VVmOtM60VWw&ab_channel=AdafruitIndustries

### Pinout: 

<img src="https://github.com/MKme/ESP32/blob/main/Wemos%2032%20Lite%20Board/pics/Lolin32_pinout03.png"/>

<img src="https://github.com/MKme/ESP32/blob/main/Wemos%2032%20Lite%20Board/pics/2.jpg"/>
