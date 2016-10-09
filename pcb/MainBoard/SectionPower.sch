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
Sheet 5 5
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
L CONN_01X02 P6
U 1 1 57FA5437
P 1500 4800
F 0 "P6" H 1500 4950 50  0000 C CNN
F 1 "Arduino battery" V 1600 4800 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 1500 4800 50  0001 C CNN
F 3 "" H 1500 4800 50  0000 C CNN
	1    1500 4800
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X02 P4
U 1 1 57FA567B
P 1500 2200
F 0 "P4" H 1500 2350 50  0000 C CNN
F 1 "Motor battery" V 1600 2200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 1500 2200 50  0001 C CNN
F 3 "" H 1500 2200 50  0000 C CNN
	1    1500 2200
	-1   0    0    1   
$EndComp
$Comp
L OnOffDoubleSwitch SW1
U 1 1 57FA574D
P 3300 3400
F 0 "SW1" H 3700 3050 60  0000 C CNN
F 1 "OnOffDoubleSwitch" V 2900 3450 60  0000 C CNN
F 2 "OnOffDoubleSwitch:OnOffDoubleSwitch" H 3300 3400 60  0001 C CNN
F 3 "" H 3300 3400 60  0000 C CNN
	1    3300 3400
	1    0    0    -1  
$EndComp
$Comp
L DcDcConverter DCDC1
U 1 1 57FA5796
P 5500 2250
F 0 "DCDC1" H 5500 1950 60  0000 C CNN
F 1 "DC-DC 12V up" H 5500 2550 60  0000 C CNN
F 2 "DcDcAdjustableUp:DcDcAdjustableUp" H 5500 2250 60  0001 C CNN
F 3 "" H 5500 2250 60  0000 C CNN
	1    5500 2250
	1    0    0    -1  
$EndComp
$Comp
L DcDcConverter DCDC2
U 1 1 57FA57FB
P 5500 3350
F 0 "DCDC2" H 5500 3050 60  0000 C CNN
F 1 "DC-DC 5V down" H 5500 3650 60  0000 C CNN
F 2 "DcDcAdjustableDown:DcDcAdjustableDown" H 5500 3350 60  0001 C CNN
F 3 "" H 5500 3350 60  0000 C CNN
	1    5500 3350
	1    0    0    -1  
$EndComp
$Comp
L DcDcConverter DCDC3
U 1 1 57FA5842
P 5500 4850
F 0 "DCDC3" H 5500 4550 60  0000 C CNN
F 1 "DC-DC 5V up" H 5500 5150 60  0000 C CNN
F 2 "DcDc5VUp:DcDc5VUp" H 5500 4850 60  0001 C CNN
F 3 "" H 5500 4850 60  0000 C CNN
	1    5500 4850
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky D1
U 1 1 57FA59CE
P 2150 2150
F 0 "D1" H 2150 2250 50  0000 C CNN
F 1 "D_Schottky" H 2150 2050 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 2150 2150 50  0001 C CNN
F 3 "" H 2150 2150 50  0000 C CNN
	1    2150 2150
	-1   0    0    1   
$EndComp
$Comp
L D_Schottky D2
U 1 1 57FA5A89
P 2150 4750
F 0 "D2" H 2150 4850 50  0000 C CNN
F 1 "D_Schottky" H 2150 4650 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 2150 4750 50  0001 C CNN
F 3 "" H 2150 4750 50  0000 C CNN
	1    2150 4750
	-1   0    0    1   
$EndComp
Wire Wire Line
	1700 2150 2000 2150
Wire Wire Line
	1700 4750 2000 4750
Wire Wire Line
	2300 4750 3300 4750
Wire Wire Line
	3300 4750 3300 4000
Wire Wire Line
	2300 2150 3300 2150
Wire Wire Line
	3300 2150 3300 2800
Wire Wire Line
	3500 2800 3500 2150
Wire Wire Line
	1900 2450 1900 2250
Wire Wire Line
	1900 2250 1700 2250
Wire Wire Line
	4650 3450 5050 3450
NoConn ~ 3100 2800
Wire Wire Line
	5050 3250 4850 3250
Wire Wire Line
	1700 4850 1900 4850
Wire Wire Line
	1900 4850 1900 4950
NoConn ~ 3100 4000
$Comp
L GND #PWR044
U 1 1 57FA5F2E
P 5950 4950
F 0 "#PWR044" H 5950 4700 50  0001 C CNN
F 1 "GND" H 5950 4800 50  0000 C CNN
F 2 "" H 5950 4950 50  0000 C CNN
F 3 "" H 5950 4950 50  0000 C CNN
	1    5950 4950
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X06 P3
U 1 1 57FA5F7A
P 8200 2100
F 0 "P3" H 8200 2450 50  0000 C CNN
F 1 "Motor controller" V 8300 2100 50  0000 C CNN
F 2 "MotorController:MotorController" H 8200 2100 50  0001 C CNN
F 3 "" H 8200 2100 50  0000 C CNN
	1    8200 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 2150 8000 2150
Wire Wire Line
	8000 2050 7150 2050
Text HLabel 8000 1850 0    60   Input ~ 0
MOTOR_A1
Text HLabel 8000 1950 0    60   Input ~ 0
MOTOR_A2
Text HLabel 8000 2250 0    60   Input ~ 0
MOTOR_B1
Text HLabel 8000 2350 0    60   Input ~ 0
MOTOR_B2
$Comp
L +5V #PWR045
U 1 1 57FA637B
P 5950 4750
F 0 "#PWR045" H 5950 4600 50  0001 C CNN
F 1 "+5V" H 5950 4890 50  0000 C CNN
F 2 "" H 5950 4750 50  0000 C CNN
F 3 "" H 5950 4750 50  0000 C CNN
	1    5950 4750
	1    0    0    -1  
$EndComp
$Comp
L C C_PWR_1
U 1 1 57FA6974
P 3700 2300
F 0 "C_PWR_1" H 3725 2400 50  0000 L CNN
F 1 "C" H 3725 2200 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D6.3_L11.2_P2.5" H 3738 2150 50  0001 C CNN
F 3 "" H 3700 2300 50  0000 C CNN
	1    3700 2300
	1    0    0    -1  
$EndComp
$Comp
L C C_PWR_3
U 1 1 57FA6C6F
P 3800 4800
F 0 "C_PWR_3" H 3825 4900 50  0000 L CNN
F 1 "C" H 3825 4700 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D6.3_L11.2_P2.5" H 3838 4650 50  0001 C CNN
F 3 "" H 3800 4800 50  0000 C CNN
	1    3800 4800
	1    0    0    -1  
$EndComp
$Comp
L C C_PWR_4
U 1 1 57FA6CEF
P 4250 4800
F 0 "C_PWR_4" H 4275 4900 50  0000 L CNN
F 1 "C" H 4275 4700 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D6.3_L11.2_P2.5" H 4288 4650 50  0001 C CNN
F 3 "" H 4250 4800 50  0000 C CNN
	1    4250 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 4950 5050 4950
Connection ~ 3800 4950
Connection ~ 4250 4950
Wire Wire Line
	3500 4000 3500 4650
Wire Wire Line
	3500 4650 5050 4650
Connection ~ 3800 4650
Wire Wire Line
	5050 4650 5050 4750
Connection ~ 4250 4650
$Comp
L C C_PWR_2
U 1 1 57FA7057
P 4200 2300
F 0 "C_PWR_2" H 4225 2400 50  0000 L CNN
F 1 "C" H 4225 2200 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D6.3_L11.2_P2.5" H 4238 2150 50  0001 C CNN
F 3 "" H 4200 2300 50  0000 C CNN
	1    4200 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 2150 5050 2150
Connection ~ 3700 2150
Connection ~ 4200 2150
Wire Wire Line
	1900 2450 5050 2450
Connection ~ 3700 2450
Wire Wire Line
	4650 2450 4650 3450
Connection ~ 4200 2450
Connection ~ 4650 2450
Wire Wire Line
	4850 3250 4850 2150
Connection ~ 4850 2150
Wire Wire Line
	5050 2450 5050 2350
Wire Wire Line
	5950 2350 7150 2350
Wire Wire Line
	7150 2350 7150 2050
$Comp
L CONN_01X03 P5
U 1 1 57FA753C
P 8200 3250
F 0 "P5" H 8200 3450 50  0000 C CNN
F 1 "Steering connector" V 8300 3250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03" H 8200 3250 50  0001 C CNN
F 3 "" H 8200 3250 50  0000 C CNN
	1    8200 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 3250 8000 3250
Wire Wire Line
	5950 3450 7150 3450
Wire Wire Line
	7150 3450 7150 3350
Wire Wire Line
	7150 3350 8000 3350
Text HLabel 8000 3150 0    60   Input ~ 0
STEERING
$EndSCHEMATC