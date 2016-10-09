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
Sheet 1 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 1400 3150 1600 1450
U 57F22416
F0 "Sheet57F22415" 60
F1 "SectionCamera.sch" 60
F2 "FIFO_PUSH" O R 3000 3350 60 
F3 "SPI_CLOCK" O R 3000 3500 60 
F4 "SPI_DATA" O R 3000 3650 60 
$EndSheet
$Sheet
S 4100 3150 1550 1400
U 57F22424
F0 "SectionCommBuffer" 60
F1 "SectionCommBuffer.sch" 60
F2 "SPI_CLOCK_IN" I L 4100 3500 60 
F3 "SPI_DATA_IN" I L 4100 3650 60 
F4 "FIFO_PUSH" I L 4100 3350 60 
F5 "FIFO_POP" O R 5650 3750 60 
F6 "DATA_READY" O R 5650 3900 60 
F7 "OUTPUT_ENABLE" O R 5650 4050 60 
F8 "SPI_CLOCK_OUT" O R 5650 4200 60 
F9 "SPI_DATA_OUT" O R 5650 4350 60 
$EndSheet
$Sheet
S 7000 3150 1550 1400
U 57F22450
F0 "SectionMainControl" 60
F1 "SectionMainControl.sch" 60
F2 "SPI_CLOCK" O L 7000 4200 60 
F3 "SPI_DATA_IN" I L 7000 4350 60 
F4 "FIFO_DATA_READY" I L 7000 3900 60 
F5 "FIFO_ENABLE" O L 7000 4050 60 
F6 "FORWARD" O L 7000 3400 60 
F7 "REVERSE" O L 7000 3550 60 
F8 "STEERING" O L 7000 3250 60 
F9 "FIFO_POP" O L 7000 3750 60 
$EndSheet
$Sheet
S 1400 1200 2100 1400
U 57F22472
F0 "SectionPower" 60
F1 "SectionPower.sch" 60
F2 "MOTOR_A1" I R 3500 1750 60 
F3 "MOTOR_A2" I R 3500 1900 60 
F4 "MOTOR_B1" I R 3500 2150 60 
F5 "MOTOR_B2" I R 3500 2300 60 
F6 "STEERING" I R 3500 1500 60 
$EndSheet
$Comp
L +5V #PWR01
U 1 1 57F9FA64
P 1900 5800
F 0 "#PWR01" H 1900 5650 50  0001 C CNN
F 1 "+5V" H 1900 5940 50  0000 C CNN
F 2 "" H 1900 5800 50  0000 C CNN
F 3 "" H 1900 5800 50  0000 C CNN
	1    1900 5800
	1    0    0    -1  
$EndComp
$Comp
L C C_BULK_4
U 1 1 57F9FCC5
P 3500 6250
F 0 "C_BULK_4" H 3525 6350 50  0000 L CNN
F 1 "10-100uF" H 3525 6150 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 3538 6100 50  0001 C CNN
F 3 "" H 3500 6250 50  0000 C CNN
	1    3500 6250
	1    0    0    -1  
$EndComp
$Comp
L C C_BULK_5
U 1 1 57F9FD03
P 4000 6250
F 0 "C_BULK_5" H 4025 6350 50  0000 L CNN
F 1 "10-100uF" H 4025 6150 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 4038 6100 50  0001 C CNN
F 3 "" H 4000 6250 50  0000 C CNN
	1    4000 6250
	1    0    0    -1  
$EndComp
$Comp
L C C_BULK_6
U 1 1 57F9FF08
P 4500 6250
F 0 "C_BULK_6" H 4525 6350 50  0000 L CNN
F 1 "10-100uF" H 4525 6150 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 4538 6100 50  0001 C CNN
F 3 "" H 4500 6250 50  0000 C CNN
	1    4500 6250
	1    0    0    -1  
$EndComp
$Comp
L C C_BULK_7
U 1 1 57F9FF52
P 5050 6250
F 0 "C_BULK_7" H 5075 6350 50  0000 L CNN
F 1 "10-100uF" H 5075 6150 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 5088 6100 50  0001 C CNN
F 3 "" H 5050 6250 50  0000 C CNN
	1    5050 6250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 57FA0021
P 1900 6750
F 0 "#PWR02" H 1900 6500 50  0001 C CNN
F 1 "GND" H 1900 6600 50  0000 C CNN
F 2 "" H 1900 6750 50  0000 C CNN
F 3 "" H 1900 6750 50  0000 C CNN
	1    1900 6750
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR03
U 1 1 57FA4438
P 900 6000
F 0 "#PWR03" H 900 5850 50  0001 C CNN
F 1 "+5V" H 900 6140 50  0000 C CNN
F 2 "" H 900 6000 50  0000 C CNN
F 3 "" H 900 6000 50  0000 C CNN
	1    900  6000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 57FA447E
P 900 6300
F 0 "#PWR04" H 900 6050 50  0001 C CNN
F 1 "GND" H 900 6150 50  0000 C CNN
F 2 "" H 900 6300 50  0000 C CNN
F 3 "" H 900 6300 50  0000 C CNN
	1    900  6300
	1    0    0    -1  
$EndComp
$Comp
L C C_NOT_1
U 1 1 57FA44C4
P 900 6150
F 0 "C_NOT_1" H 925 6250 50  0000 L CNN
F 1 "0.1uF" H 925 6050 50  0000 L CNN
F 2 "Capacitors_SMD:C_1206_HandSoldering" H 938 6000 50  0001 C CNN
F 3 "" H 900 6150 50  0000 C CNN
	1    900  6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 6100 5050 6100
Connection ~ 3500 6100
Connection ~ 3000 6100
Connection ~ 2450 6100
Wire Wire Line
	1900 6400 5050 6400
Connection ~ 2450 6400
Connection ~ 3000 6400
Connection ~ 3500 6400
Connection ~ 4000 6100
Connection ~ 4500 6100
Connection ~ 4000 6400
Connection ~ 4500 6400
Wire Wire Line
	3000 3650 4100 3650
Wire Wire Line
	3000 3500 4100 3500
Wire Wire Line
	3000 3350 4100 3350
Wire Wire Line
	5650 3750 7000 3750
Wire Wire Line
	5650 3900 7000 3900
Wire Wire Line
	5650 4050 7000 4050
Wire Wire Line
	5650 4200 7000 4200
Wire Wire Line
	5650 4350 7000 4350
Wire Wire Line
	7000 3250 6600 3250
Wire Wire Line
	6600 3250 6600 1500
Wire Wire Line
	6600 1500 3500 1500
Wire Wire Line
	7000 3400 6450 3400
Wire Wire Line
	6450 3400 6450 1750
Wire Wire Line
	6450 1750 3500 1750
Wire Wire Line
	7000 3550 6300 3550
Wire Wire Line
	6300 3550 6300 1900
Wire Wire Line
	6300 1900 3500 1900
NoConn ~ 3500 2150
NoConn ~ 3500 2300
$Comp
L CP C_BULK_1
U 1 1 57FA3E62
P 1900 6250
F 0 "C_BULK_1" H 1925 6350 50  0000 L CNN
F 1 "10-100uF" H 1925 6150 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D6.3_L11.2_P2.5" H 1938 6100 50  0001 C CNN
F 3 "" H 1900 6250 50  0000 C CNN
	1    1900 6250
	1    0    0    -1  
$EndComp
$Comp
L CP C_BULK_2
U 1 1 57FA450D
P 2450 6250
F 0 "C_BULK_2" H 2475 6350 50  0000 L CNN
F 1 "10-100uF" H 2475 6150 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D6.3_L11.2_P2.5" H 2488 6100 50  0001 C CNN
F 3 "" H 2450 6250 50  0000 C CNN
	1    2450 6250
	1    0    0    -1  
$EndComp
$Comp
L CP C_BULK_3
U 1 1 57FA45D2
P 3000 6250
F 0 "C_BULK_3" H 3025 6350 50  0000 L CNN
F 1 "10-100uF" H 3025 6150 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D6.3_L11.2_P2.5" H 3038 6100 50  0001 C CNN
F 3 "" H 3000 6250 50  0000 C CNN
	1    3000 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 5800 1900 6100
Wire Wire Line
	1900 6400 1900 6750
$EndSCHEMATC