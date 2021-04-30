EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Conn_01x05_Female J2
U 1 1 607EDFB4
P 7950 5650
F 0 "J2" H 7978 5626 50  0000 L CNN
F 1 "BME280" H 7978 5535 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 7950 5650 50  0001 C CNN
F 3 "~" H 7950 5650 50  0001 C CNN
	1    7950 5650
	-1   0    0    1   
$EndComp
Text GLabel 10300 4650 2    50   Input ~ 0
3v3
Text GLabel 8150 4900 2    50   Input ~ 0
3v3
Wire Wire Line
	7950 5750 8150 5750
Text GLabel 8150 5550 2    50   Input ~ 0
SDA
Text GLabel 8150 5650 2    50   Input ~ 0
SCL
Text GLabel 10300 5450 2    50   Input ~ 0
SDA
Text GLabel 10300 5350 2    50   Input ~ 0
SCL
$Comp
L Connector:Conn_01x02_Female J3
U 1 1 608BC0B0
P 7350 4100
F 0 "J3" H 7378 4076 50  0000 L CNN
F 1 "Battery" H 7378 3985 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7350 4100 50  0001 C CNN
F 3 "~" H 7350 4100 50  0001 C CNN
	1    7350 4100
	-1   0    0    1   
$EndComp
$Comp
L Switch:SW_SPST SW1
U 1 1 608B439C
P 7900 4100
F 0 "SW1" H 7900 4335 50  0000 C CNN
F 1 "Power Switch" H 7900 4244 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7900 4100 50  0001 C CNN
F 3 "~" H 7900 4100 50  0001 C CNN
	1    7900 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 4100 7550 4100
Wire Wire Line
	7550 4000 7550 3800
Wire Wire Line
	7550 3800 8150 3800
Wire Wire Line
	8150 3800 8150 4100
Wire Wire Line
	8150 4100 8100 4100
Wire Notes Line
	7000 3550 7000 4400
Wire Notes Line
	7000 4400 8350 4400
Wire Notes Line
	8350 4400 8350 3550
Wire Notes Line
	8350 3550 7000 3550
Text Notes 7100 3650 0    50   ~ 0
Optional Battery Switch
Wire Notes Line
	7000 5300 7000 6250
Wire Notes Line
	7000 6250 8550 6250
Wire Notes Line
	8550 6250 8550 5300
Wire Notes Line
	8550 5300 7000 5300
Text Notes 7050 6200 0    50   ~ 0
BME Temperature, Pressure & \nHumidity Breakout
Wire Notes Line
	7000 4500 7000 5250
Wire Notes Line
	7000 5250 8550 5250
Wire Notes Line
	8550 5250 8550 4500
Wire Notes Line
	8550 4500 7000 4500
Text Notes 7100 5200 0    50   ~ 0
MAX6675 Thermocouple
Text GLabel 8150 4800 2    50   Input ~ 0
SCK
Text GLabel 8150 4700 2    50   Input ~ 0
CS
Text GLabel 8150 4600 2    50   Input ~ 0
SO
Text GLabel 10300 5050 2    50   Input ~ 0
SCK
Text GLabel 10300 5250 2    50   Input ~ 0
CS
Text GLabel 10300 4850 2    50   Input ~ 0
SO
Wire Wire Line
	9200 5850 9050 5850
$Comp
L LOLIN32:lolin32_lite_V1.00 U1
U 1 1 6082C592
P 9750 5250
F 0 "U1" H 9750 6115 50  0000 C CNN
F 1 "lolin32_lite_V1.00" H 9750 6024 50  0000 C CNN
F 2 "lolin32:lolin32_lite" H 9350 6000 50  0001 C CNN
F 3 "" H 9350 6000 50  0001 C CNN
	1    9750 5250
	1    0    0    -1  
$EndComp
Text GLabel 10350 4250 2    50   Input ~ 0
S13
Text GLabel 10300 4950 2    50   Input ~ 0
S23
Text GLabel 10300 5150 2    50   Input ~ 0
S5
Text GLabel 10300 5850 2    50   Input ~ 0
S13
Text GLabel 10300 5750 2    50   Input ~ 0
S15
Text GLabel 10300 5650 2    50   Input ~ 0
S2
Text GLabel 10300 5550 2    50   Input ~ 0
S0
Text GLabel 10300 4750 2    50   Input ~ 0
S22
Text GLabel 9200 4650 0    50   Input ~ 0
SVP
Text GLabel 9200 4750 0    50   Input ~ 0
SVN
Text GLabel 9200 4850 0    50   Input ~ 0
SEN
Text GLabel 9200 4950 0    50   Input ~ 0
S34
Text GLabel 9200 5050 0    50   Input ~ 0
S35
Text GLabel 9200 5150 0    50   Input ~ 0
S32
Text GLabel 9200 5250 0    50   Input ~ 0
S33
Text GLabel 9200 5350 0    50   Input ~ 0
S25
Text GLabel 9200 5450 0    50   Input ~ 0
S26
Text GLabel 9200 5550 0    50   Input ~ 0
S27
Text GLabel 9200 5650 0    50   Input ~ 0
S14
Text GLabel 9200 5750 0    50   Input ~ 0
S12
Text GLabel 9200 4250 0    50   Input ~ 0
S12
$Comp
L Connector:Conn_01x12_Female J4
U 1 1 608E5182
P 9400 3650
F 0 "J4" H 9428 3626 50  0000 L CNN
F 1 "Spare2" H 9428 3535 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x12_P2.54mm_Vertical" H 9400 3650 50  0001 C CNN
F 3 "~" H 9400 3650 50  0001 C CNN
	1    9400 3650
	1    0    0    -1  
$EndComp
Text GLabel 9200 4150 0    50   Input ~ 0
S14
Text GLabel 9200 4050 0    50   Input ~ 0
S27
Text GLabel 9200 3950 0    50   Input ~ 0
S26
Text GLabel 9200 3850 0    50   Input ~ 0
S25
Text GLabel 9200 3750 0    50   Input ~ 0
S33
Text GLabel 9200 3650 0    50   Input ~ 0
S32
Text GLabel 9200 3550 0    50   Input ~ 0
S35
Text GLabel 9200 3450 0    50   Input ~ 0
S34
Text GLabel 9200 3350 0    50   Input ~ 0
SEN
Text GLabel 9200 3250 0    50   Input ~ 0
SVN
Text GLabel 9200 3150 0    50   Input ~ 0
SVP
$Comp
L Connector:Conn_01x07_Female J5
U 1 1 608DF885
P 10150 3950
F 0 "J5" H 10042 4435 50  0000 C CNN
F 1 "Spare1" H 10042 4344 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x07_P2.54mm_Vertical" H 10150 3950 50  0001 C CNN
F 3 "~" H 10150 3950 50  0001 C CNN
	1    10150 3950
	-1   0    0    -1  
$EndComp
Text GLabel 10350 3650 2    50   Input ~ 0
S22
Text GLabel 10350 3950 2    50   Input ~ 0
S0
Text GLabel 10350 4050 2    50   Input ~ 0
S2
Text GLabel 10350 4150 2    50   Input ~ 0
S15
Text GLabel 10350 3850 2    50   Input ~ 0
S5
Text GLabel 10350 3750 2    50   Input ~ 0
S23
$Comp
L power:GND #PWR0103
U 1 1 608C1DF2
P 8250 5000
F 0 "#PWR0103" H 8250 4750 50  0001 C CNN
F 1 "GND" H 8255 4827 50  0000 C CNN
F 2 "" H 8250 5000 50  0001 C CNN
F 3 "" H 8250 5000 50  0001 C CNN
	1    8250 5000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Female J1
U 1 1 607ED4FA
P 7950 4800
F 0 "J1" H 7978 4826 50  0000 L CNN
F 1 "Thermocouple" H 7978 4735 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 7950 4800 50  0001 C CNN
F 3 "~" H 7950 4800 50  0001 C CNN
	1    7950 4800
	-1   0    0    1   
$EndComp
Wire Wire Line
	8150 5000 8250 5000
Text GLabel 8150 5850 2    50   Input ~ 0
3v3
$Comp
L power:GND #PWR0102
U 1 1 608C180F
P 8400 5950
F 0 "#PWR0102" H 8400 5700 50  0001 C CNN
F 1 "GND" V 8405 5777 50  0000 C CNN
F 2 "" H 8400 5950 50  0001 C CNN
F 3 "" H 8400 5950 50  0001 C CNN
	1    8400 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 5750 8400 5950
$Comp
L power:GND #PWR0101
U 1 1 608C0DBF
P 9050 6000
F 0 "#PWR0101" H 9050 5750 50  0001 C CNN
F 1 "GND" H 9055 5827 50  0000 C CNN
F 2 "" H 9050 6000 50  0001 C CNN
F 3 "" H 9050 6000 50  0001 C CNN
	1    9050 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 5850 9050 6000
Wire Wire Line
	8150 5750 8400 5750
Connection ~ 8150 5750
NoConn ~ 8150 5450
$EndSCHEMATC
