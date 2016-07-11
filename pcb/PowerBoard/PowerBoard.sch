EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:DcDcConverter
LIBS:OnOffDoubleSwitch
LIBS:PowerBoard-cache
EELAYER 25 0
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
L DcDcConverter DCDC1
U 1 1 57825ED4
P 4050 1450
F 0 "DCDC1" H 4050 1150 60  0000 C CNN
F 1 "DC-DC 12V up" H 4050 1750 60  0000 C CNN
F 2 "DcDcAdjustableUp:DcDcAdjustableUp" H 4050 1450 60  0001 C CNN
F 3 "" H 4050 1450 60  0000 C CNN
	1    4050 1450
	1    0    0    -1  
$EndComp
$Comp
L DcDcConverter DCDC2
U 1 1 57825F5F
P 4050 2750
F 0 "DCDC2" H 4050 2450 60  0000 C CNN
F 1 "DC-DC 5V down" H 4050 3050 60  0000 C CNN
F 2 "DcDcAdjustableDown:DcDcAdjustableDown" H 4050 2750 60  0001 C CNN
F 3 "" H 4050 2750 60  0000 C CNN
	1    4050 2750
	1    0    0    -1  
$EndComp
$Comp
L DcDcConverter DCDC3
U 1 1 57825FC2
P 4050 4050
F 0 "DCDC3" H 4050 3750 60  0000 C CNN
F 1 "DC-DC 5V up" H 4050 4350 60  0000 C CNN
F 2 "DcDc5VUp:DcDc5VUp" H 4050 4050 60  0001 C CNN
F 3 "" H 4050 4050 60  0000 C CNN
	1    4050 4050
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P1
U 1 1 57826186
P 1050 1400
F 0 "P1" H 1050 1550 50  0000 C CNN
F 1 "Motor battery" V 1150 1400 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 1050 1400 50  0001 C CNN
F 3 "" H 1050 1400 50  0000 C CNN
	1    1050 1400
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X02 P3
U 1 1 578263CD
P 1050 4000
F 0 "P3" H 1050 4150 50  0000 C CNN
F 1 "Arduino battery" V 1150 4000 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 1050 4000 50  0001 C CNN
F 3 "" H 1050 4000 50  0000 C CNN
	1    1050 4000
	-1   0    0    1   
$EndComp
$Comp
L OnOffDoubleSwitch SW1
U 1 1 57827880
P 2350 2600
F 0 "SW1" H 2750 2250 60  0000 C CNN
F 1 "OnOffDoubleSwitch" V 1950 2650 60  0000 C CNN
F 2 "OnOffDoubleSwitch:OnOffDoubleSwitch" H 2350 2600 60  0001 C CNN
F 3 "" H 2350 2600 60  0000 C CNN
	1    2350 2600
	1    0    0    -1  
$EndComp
NoConn ~ 2150 2000
NoConn ~ 2150 3200
Wire Wire Line
	2350 3950 2350 3200
Wire Wire Line
	2550 3200 2550 3950
Wire Wire Line
	2550 3950 3600 3950
$Comp
L D D2
U 1 1 57827A5D
P 1600 3950
F 0 "D2" H 1600 4050 50  0000 C CNN
F 1 "D" H 1600 3850 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 1600 3950 50  0001 C CNN
F 3 "" H 1600 3950 50  0000 C CNN
	1    1600 3950
	-1   0    0    1   
$EndComp
$Comp
L D D1
U 1 1 57827D22
P 1600 1350
F 0 "D1" H 1600 1450 50  0000 C CNN
F 1 "D" H 1600 1250 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 1600 1350 50  0001 C CNN
F 3 "" H 1600 1350 50  0000 C CNN
	1    1600 1350
	-1   0    0    1   
$EndComp
Wire Wire Line
	1250 4050 1450 4050
Wire Wire Line
	1450 4050 1450 4150
Wire Wire Line
	1450 4150 3600 4150
Wire Wire Line
	1250 1450 1450 1450
Wire Wire Line
	1450 1450 1450 1550
Wire Wire Line
	1450 1550 3600 1550
Wire Wire Line
	2350 1350 2350 2000
Wire Wire Line
	2550 2000 2550 1350
Wire Wire Line
	2550 1350 3600 1350
Wire Wire Line
	3400 1350 3400 2650
Wire Wire Line
	3400 2650 3600 2650
Connection ~ 3400 1350
Wire Wire Line
	3200 1550 3200 2850
Wire Wire Line
	3200 2850 3600 2850
Connection ~ 3200 1550
$Comp
L CONN_01X06 P2
U 1 1 57828111
P 5900 2050
F 0 "P2" H 5900 2400 50  0000 C CNN
F 1 "CONN_01X06" V 6000 2050 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06" H 5900 2050 50  0001 C CNN
F 3 "" H 5900 2050 50  0000 C CNN
	1    5900 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 1550 5000 1550
Wire Wire Line
	5000 1550 5000 4150
Wire Wire Line
	5000 4150 4500 4150
Wire Wire Line
	4500 2850 5000 2850
Connection ~ 5000 2850
Wire Wire Line
	5700 1800 5000 1800
Connection ~ 5000 1800
Wire Wire Line
	4700 2000 5700 2000
Connection ~ 5000 2000
Wire Wire Line
	5700 2200 5000 2200
Connection ~ 5000 2200
Wire Wire Line
	4500 1350 5150 1350
Wire Wire Line
	5150 1350 5150 1900
Wire Wire Line
	5150 1900 5700 1900
Wire Wire Line
	4500 2650 5150 2650
Wire Wire Line
	5150 2650 5150 2100
Wire Wire Line
	5150 2100 5700 2100
Wire Wire Line
	4500 3950 5300 3950
Wire Wire Line
	5300 3950 5300 2300
Wire Wire Line
	5300 2300 5700 2300
Wire Wire Line
	1250 3950 1450 3950
Wire Wire Line
	1750 3950 2350 3950
Wire Wire Line
	1250 1350 1450 1350
Wire Wire Line
	1750 1350 2350 1350
$Comp
L GND #PWR?
U 1 1 5783E56C
P 4700 2150
F 0 "#PWR?" H 4700 1900 50  0001 C CNN
F 1 "GND" H 4700 2000 50  0000 C CNN
F 2 "" H 4700 2150 50  0000 C CNN
F 3 "" H 4700 2150 50  0000 C CNN
	1    4700 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 2000 4700 2150
$EndSCHEMATC
