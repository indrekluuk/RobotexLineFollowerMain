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
LIBS:arduino
LIBS:camera_ov7670
LIBS:tft_1.8inch
LIBS:levelshifter_74hc4050d
LIBS:shiftregister_74hc595
LIBS:fifo_74hc40105
LIBS:shiftregister_74hc165
LIBS:notgate_74hc04
LIBS:DcDcConverter
LIBS:OnOffDoubleSwitch
LIBS:MainBoard-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 5
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
L arduino_mini ARD2
U 1 1 57FA863B
P 5000 3400
F 0 "ARD2" H 5550 2450 70  0000 C CNN
F 1 "arduino_mini" H 5750 2350 70  0000 C CNN
F 2 "arduino:arduino_mini" H 5000 3350 60  0001 C CNN
F 3 "" H 5000 3400 60  0000 C CNN
	1    5000 3400
	1    0    0    -1  
$EndComp
NoConn ~ 4850 2250
NoConn ~ 4300 4700
NoConn ~ 4300 4600
NoConn ~ 5700 4200
NoConn ~ 5700 4100
NoConn ~ 4300 3000
NoConn ~ 5150 2250
$Comp
L +5V #PWR040
U 1 1 57FA8701
P 5000 2250
F 0 "#PWR040" H 5000 2100 50  0001 C CNN
F 1 "+5V" H 5000 2390 50  0000 C CNN
F 2 "" H 5000 2250 50  0000 C CNN
F 3 "" H 5000 2250 50  0000 C CNN
	1    5000 2250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR041
U 1 1 57FA8717
P 5000 4950
F 0 "#PWR041" H 5000 4700 50  0001 C CNN
F 1 "GND" H 5000 4800 50  0000 C CNN
F 2 "" H 5000 4950 50  0000 C CNN
F 3 "" H 5000 4950 50  0000 C CNN
	1    5000 4950
	1    0    0    -1  
$EndComp
Text HLabel 6500 2750 2    60   Output ~ 0
SPI_CLOCK
Text HLabel 6500 2850 2    60   Input ~ 0
SPI_DATA_IN
Wire Wire Line
	5700 2750 6500 2750
Wire Wire Line
	5700 2850 6500 2850
Text HLabel 6500 3350 2    60   Input ~ 0
FIFO_DATA_READY
Text HLabel 6500 3250 2    60   Output ~ 0
FIFO_POP
Text HLabel 6500 3150 2    60   Output ~ 0
FIFO_ENABLE
Wire Wire Line
	5700 3150 6500 3150
Wire Wire Line
	5700 3250 6500 3250
Text HLabel 6500 3450 2    60   Output ~ 0
FORWARD
Text HLabel 6500 3700 2    60   Output ~ 0
REVERSE
Wire Wire Line
	5700 3450 6500 3450
Wire Wire Line
	5700 3700 6500 3700
Text HLabel 6500 3900 2    60   Output ~ 0
STEERING
Wire Wire Line
	5700 3900 6500 3900
NoConn ~ 4300 3200
NoConn ~ 4300 3300
NoConn ~ 4300 3400
NoConn ~ 4300 3500
NoConn ~ 4300 3600
NoConn ~ 4300 3700
NoConn ~ 4300 3800
NoConn ~ 4300 3900
NoConn ~ 5700 4000
NoConn ~ 5700 3800
NoConn ~ 5700 2950
Wire Wire Line
	5700 3350 6500 3350
NoConn ~ 5700 3050
$EndSCHEMATC
