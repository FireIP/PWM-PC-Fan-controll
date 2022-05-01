EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "jeu. 02 avril 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Regulator_Linear:L7806 U1
U 1 1 609D8957
P 3600 1250
F 0 "U1" H 3600 1492 50  0000 C CNN
F 1 "L7806" H 3600 1401 50  0000 C CNN
F 2 "KiCadFootprints:TO-220-3_Horizontal_TabUp_SK_95_25" H 3625 1100 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 3600 1200 50  0001 C CNN
	1    3600 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 1250 3900 2150
Wire Wire Line
	3800 4150 4000 4150
$Comp
L Device:R R8
U 1 1 609FF471
P 4800 3150
F 0 "R8" V 4593 3150 50  0001 C CNN
F 1 "220 Ω" V 4685 3150 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4730 3150 50  0001 C CNN
F 3 "~" H 4800 3150 50  0001 C CNN
	1    4800 3150
	0    -1   1    0   
$EndComp
Wire Wire Line
	4500 3150 4650 3150
Wire Wire Line
	4950 3150 4950 5250
Wire Wire Line
	4950 5250 2500 5250
Wire Wire Line
	2500 5250 2500 5050
Wire Wire Line
	3100 4950 4000 4950
Wire Wire Line
	4000 4950 4000 4150
Connection ~ 4000 4150
Wire Wire Line
	2500 4350 2500 3350
Wire Wire Line
	2500 4450 2450 4450
Wire Wire Line
	2450 4450 2450 3250
Wire Wire Line
	2400 4550 2500 4550
Wire Wire Line
	2350 4650 2500 4650
Wire Wire Line
	2500 4750 2300 4750
Wire Wire Line
	3600 1550 2600 1550
Wire Wire Line
	2600 1550 2600 1250
Connection ~ 3600 1550
$Comp
L Device:R_POT RV1
U 1 1 60A16061
P 4750 3750
F 0 "RV1" H 4680 3704 50  0000 R CNN
F 1 "R_POT" H 4680 3795 50  0000 R CNN
F 2 "KiCadFootprints:Potentiometer_Alps_RK09L_Double_Horizontal_Edge_mount" H 4750 3750 50  0001 C CNN
F 3 "~" H 4750 3750 50  0001 C CNN
	1    4750 3750
	-1   0    0    1   
$EndComp
Wire Wire Line
	2250 4850 2500 4850
$Comp
L Transistor_FET:IRLZ34N Q2
U 1 1 60A255E3
P 1950 3450
F 0 "Q2" H 2155 3496 50  0000 L CNN
F 1 "IRL520NPBF" H 2155 3405 50  0000 L CNN
F 2 "KiCadFootprints:TO-220-3_Horizontal_TabUp_SK_95_25" H 2200 3375 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/irlz34npbf.pdf?fileId=5546d462533600a40153567206892720" H 1950 3450 50  0001 L CNN
	1    1950 3450
	-1   0    0    -1  
$EndComp
$Comp
L Motor:Fan_Tacho M2
U 1 1 609E8874
P 1850 2850
F 0 "M2" H 2008 2846 50  0000 L CNN
F 1 "Fan_Tacho" H 2008 2755 50  0000 L CNN
F 2 "Connector:FanPinHeader_1x03_P2.54mm_Vertical" H 1850 2760 50  0001 C CNN
F 3 "http://www.hardwarecanucks.com/forum/attachments/new-builds/16287d1330775095-help-chassis-power-fan-connectors-motherboard-asus_p8z68.jpg" H 1850 2760 50  0001 C CNN
	1    1850 2850
	1    0    0    -1  
$EndComp
$Comp
L Transistor_FET:IRLZ34N Q1
U 1 1 60A45CA5
P 1250 3550
F 0 "Q1" H 1455 3596 50  0000 L CNN
F 1 "IRL520NPBF" H 1455 3505 50  0000 L CNN
F 2 "KiCadFootprints:TO-220-3_Horizontal_TabUp_SK_95_25" H 1500 3475 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/irlz34npbf.pdf?fileId=5546d462533600a40153567206892720" H 1250 3550 50  0001 L CNN
	1    1250 3550
	-1   0    0    -1  
$EndComp
$Comp
L Motor:Fan_Tacho M1
U 1 1 60A45CAB
P 1150 2950
F 0 "M1" H 1308 2946 50  0000 L CNN
F 1 "Fan_Tacho" H 1308 2855 50  0000 L CNN
F 2 "Connector:FanPinHeader_1x03_P2.54mm_Vertical" H 1150 2860 50  0001 C CNN
F 3 "http://www.hardwarecanucks.com/forum/attachments/new-builds/16287d1330775095-help-chassis-power-fan-connectors-motherboard-asus_p8z68.jpg" H 1150 2860 50  0001 C CNN
	1    1150 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1250 3100 2000
Wire Wire Line
	3100 2000 1850 2000
Wire Wire Line
	1150 2000 1150 2750
Wire Wire Line
	3100 1250 3300 1250
Wire Wire Line
	1850 2650 1850 2000
Connection ~ 1850 2000
Wire Wire Line
	1150 3350 1150 3250
Wire Wire Line
	1850 3250 1850 3150
Wire Wire Line
	1450 3550 3500 3550
Wire Wire Line
	1850 3650 1500 3650
Wire Wire Line
	1500 3650 1500 3750
Wire Wire Line
	1500 3750 1150 3750
Wire Wire Line
	1150 3750 800  3750
Wire Wire Line
	800  3750 800  1550
Wire Wire Line
	800  1550 2600 1550
Connection ~ 1150 3750
Connection ~ 2600 1550
$Comp
L Connector_Generic:Conn_02x06_Odd_Even USR-ES1_W5500
U 1 1 60A55844
P 5450 1550
F 0 "USR-ES1_W5500" H 5500 1967 50  0000 C CNN
F 1 "Conn_02x06_Odd_Even" H 5500 1876 50  0000 C CNN
F 2 "KiCadFootprints:USR-ES1_W5500_v2" H 5450 1550 50  0001 C CNN
F 3 "~" H 5450 1550 50  0001 C CNN
	1    5450 1550
	1    0    0    -1  
$EndComp
Text Label 5250 1350 2    50   ~ 0
G
Text Label 5250 1450 2    50   ~ 0
G
Text Label 5250 1550 2    50   ~ 0
MO
Text Label 5250 1650 2    50   ~ 0
SCK
Text Label 5250 1750 2    50   ~ 0
CS
Text Label 5250 1850 2    50   ~ 0
NT
Text Label 5750 1350 0    50   ~ 0
G
Text Label 5750 1450 0    50   ~ 0
V
Text Label 5750 1550 0    50   ~ 0
V
Text Label 5750 1650 0    50   ~ 0
NC
Text Label 5750 1750 0    50   ~ 0
RST
Text Label 5750 1850 0    50   ~ 0
MI
Wire Wire Line
	5050 1750 5250 1750
Wire Wire Line
	5250 1650 5100 1650
Wire Wire Line
	5100 1650 5100 4400
Wire Wire Line
	5100 4400 3500 4400
Wire Wire Line
	3500 4400 3500 3850
Wire Wire Line
	3500 3750 3450 3750
Wire Wire Line
	3450 4450 5750 4450
Wire Wire Line
	5750 4450 5750 1850
Wire Wire Line
	5250 1550 4700 1550
Wire Wire Line
	4700 1550 4700 1850
Wire Wire Line
	4700 1850 3400 1850
Wire Wire Line
	3400 3650 3500 3650
Wire Wire Line
	6150 2150 6150 1550
Wire Wire Line
	6150 1550 5750 1550
Wire Wire Line
	4600 1550 4600 1350
Wire Wire Line
	4600 1350 5250 1350
$Comp
L Sensor_Temperature:LM35-LP U3
U 1 1 60A674E7
P 6450 3050
F 0 "U3" H 6120 3096 50  0000 R CNN
F 1 "LM35-LP" H 6120 3005 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Horizontal" H 6500 2800 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm35.pdf" H 6450 3050 50  0001 C CNN
	1    6450 3050
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4500 3850 6050 3850
Wire Wire Line
	6050 3850 6050 3050
Wire Wire Line
	6450 2750 6450 2150
Wire Wire Line
	6450 2150 6150 2150
Connection ~ 6150 2150
Wire Wire Line
	6450 3350 6450 4150
Wire Wire Line
	6450 4150 6250 4150
$Comp
L Connector:Conn_01x06_Female J1
U 1 1 60A70F0A
P 6450 4750
F 0 "J1" H 6478 4726 50  0000 L CNN
F 1 "Conn_01x06_Female" H 6478 4635 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Horizontal" H 6450 4750 50  0001 C CNN
F 3 "~" H 6450 4750 50  0001 C CNN
	1    6450 4750
	1    0    0    1   
$EndComp
Wire Wire Line
	6250 4150 6250 4450
Connection ~ 6250 4150
Wire Wire Line
	6250 4550 5950 4550
Wire Wire Line
	5950 4550 5950 2150
Connection ~ 5950 2150
Wire Wire Line
	5950 2150 6150 2150
Wire Wire Line
	6250 4650 5750 4650
Wire Wire Line
	5750 4650 5750 4450
Connection ~ 5750 4450
Wire Wire Line
	6250 4750 3400 4750
Wire Wire Line
	3400 4750 3400 3650
Wire Wire Line
	6250 4850 5100 4850
Wire Wire Line
	5100 4850 5100 4400
Connection ~ 5100 4400
Wire Wire Line
	6250 4950 5200 4950
Wire Wire Line
	5200 4950 5200 3650
Wire Wire Line
	5200 3650 4500 3650
Wire Wire Line
	2400 3150 2400 4550
Wire Wire Line
	2350 3050 2350 4650
Wire Wire Line
	4500 3250 4600 3250
Wire Wire Line
	4600 3250 4600 1700
Wire Wire Line
	850  1700 850  2950
Wire Wire Line
	4500 3350 4550 3350
Wire Wire Line
	4550 3350 4550 1800
Wire Wire Line
	4550 1800 2950 1800
Wire Wire Line
	1550 1800 1550 2850
$Comp
L Device:R R9
U 1 1 60A5446A
P 2950 1950
F 0 "R9" H 3020 1996 50  0000 L CNN
F 1 "10 kΩ" H 3020 1905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2880 1950 50  0001 C CNN
F 3 "~" H 2950 1950 50  0001 C CNN
	1    2950 1950
	1    0    0    -1  
$EndComp
Connection ~ 2950 1800
Wire Wire Line
	2950 1800 1550 1800
$Comp
L Device:R R10
U 1 1 60A58BB9
P 3250 1850
F 0 "R10" H 3320 1896 50  0000 L CNN
F 1 "10 kΩ" H 3320 1805 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3180 1850 50  0001 C CNN
F 3 "~" H 3250 1850 50  0001 C CNN
	1    3250 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  1700 3250 1700
Connection ~ 3250 1700
Wire Wire Line
	3250 1700 4600 1700
Wire Wire Line
	2950 2100 3250 2100
Wire Wire Line
	3250 2100 3250 2000
Wire Wire Line
	3250 2000 4200 2000
Wire Wire Line
	4200 2000 4200 2150
Connection ~ 3250 2000
$Comp
L Transistor_FET:IRLZ34N Q3
U 1 1 60A4181D
P 1500 4700
F 0 "Q3" H 1705 4746 50  0000 L CNN
F 1 "IRL520NPBF" H 1705 4655 50  0000 L CNN
F 2 "KiCadFootprints:TO-220-3_Horizontal_TabUp_SK_95_25" H 1750 4625 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/irlz34npbf.pdf?fileId=5546d462533600a40153567206892720" H 1500 4700 50  0001 L CNN
	1    1500 4700
	-1   0    0    -1  
$EndComp
$Comp
L Motor:Fan_Tacho M3
U 1 1 60A41823
P 1400 4100
F 0 "M3" H 1558 4096 50  0000 L CNN
F 1 "Fan_Tacho" H 1558 4005 50  0000 L CNN
F 2 "Connector:FanPinHeader_1x03_P2.54mm_Vertical" H 1400 4010 50  0001 C CNN
F 3 "http://www.hardwarecanucks.com/forum/attachments/new-builds/16287d1330775095-help-chassis-power-fan-connectors-motherboard-asus_p8z68.jpg" H 1400 4010 50  0001 C CNN
	1    1400 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 3900 1400 2000
Wire Wire Line
	1150 2000 1400 2000
Connection ~ 1400 2000
Wire Wire Line
	1400 2000 1850 2000
Wire Wire Line
	1400 4500 1400 4400
$Comp
L Connector:TestPoint TP_Tacho_3
U 1 1 60A752C3
P 1100 4100
F 0 "TP_Tacho_3" H 1158 4218 50  0000 L CNN
F 1 "TestPoint" H 1158 4127 50  0000 L CNN
F 2 "TestPoint:TestPoint_THTPad_2.0x2.0mm_Drill1.0mm" H 1300 4100 50  0001 C CNN
F 3 "~" H 1300 4100 50  0001 C CNN
	1    1100 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R11
U 1 1 60A76E9F
P 950 4100
F 0 "R11" H 1020 4146 50  0000 L CNN
F 1 "10 kΩ" H 1020 4055 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 880 4100 50  0001 C CNN
F 3 "~" H 950 4100 50  0001 C CNN
	1    950  4100
	0    -1   -1   0   
$EndComp
Connection ~ 1100 4100
Wire Wire Line
	800  4100 700  4100
Wire Wire Line
	700  4100 700  2100
Wire Wire Line
	700  2100 2950 2100
Connection ~ 2950 2100
Wire Wire Line
	3450 3750 3450 4450
Wire Wire Line
	2300 4750 2300 2950
Wire Wire Line
	2250 2750 2250 4850
$Comp
L Device:R R2
U 1 1 609FD25C
P 3200 3450
F 0 "R2" V 2993 3450 50  0001 C CNN
F 1 "220 Ω" V 3085 3450 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3130 3450 50  0001 C CNN
F 3 "~" H 3200 3450 50  0001 C CNN
	1    3200 3450
	0    -1   1    0   
$EndComp
Wire Wire Line
	2200 2850 2200 3450
Wire Wire Line
	2200 4700 1700 4700
Wire Wire Line
	1850 3650 1850 4900
Wire Wire Line
	1850 4900 1400 4900
Connection ~ 1850 3650
Text Label 3900 1250 0    50   ~ 0
6V
Text Label 3300 1250 2    50   ~ 0
12V
Text Label 6250 4950 2    50   ~ 0
CS_SD
$Comp
L Display_Character:KCSC02-105 U2
U 1 1 60A5A098
P 2800 4650
F 0 "U2" H 2800 5317 50  0000 C CNN
F 1 "KCSC02-105" H 2800 5226 50  0000 C CNN
F 2 "Display_7Segment:Sx39-1xxxxx" H 2800 4050 50  0001 C CNN
F 3 "http://www.kingbright.com/attachments/file/psearch/000/00/00/KCSC02-105(Ver.9A).pdf" H 2300 5125 50  0001 L CNN
	1    2800 4650
	1    0    0    -1  
$EndComp
Connection ~ 4100 4150
Connection ~ 3400 3650
Connection ~ 4200 2150
Connection ~ 3800 1550
Wire Wire Line
	4000 4150 4100 4150
Wire Wire Line
	3800 1550 4600 1550
Wire Wire Line
	3600 1550 3800 1550
Wire Wire Line
	3500 2850 2200 2850
Wire Wire Line
	3400 1850 3400 3650
Wire Wire Line
	3050 2750 2250 2750
$Comp
L Device:R R1
U 1 1 609FAEB6
P 3200 2750
F 0 "R1" V 2993 2750 50  0001 C CNN
F 1 "220 Ω" V 3085 2750 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3130 2750 50  0001 C CNN
F 3 "~" H 3200 2750 50  0001 C CNN
	1    3200 2750
	0    1    1    0   
$EndComp
Wire Wire Line
	3350 2750 3500 2750
Wire Wire Line
	2300 2950 3050 2950
Wire Wire Line
	3050 3050 2350 3050
Wire Wire Line
	3050 3150 2400 3150
Wire Wire Line
	2450 3250 3050 3250
Wire Wire Line
	2500 3350 3050 3350
Wire Wire Line
	3350 3350 3500 3350
Wire Wire Line
	3500 3250 3350 3250
Wire Wire Line
	3350 3150 3500 3150
Wire Wire Line
	3500 3050 3350 3050
Wire Wire Line
	3350 2950 3500 2950
$Comp
L Device:R R7
U 1 1 609FDAEB
P 3200 3350
F 0 "R7" V 2993 3350 50  0001 C CNN
F 1 "220 Ω" V 3085 3350 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3130 3350 50  0001 C CNN
F 3 "~" H 3200 3350 50  0001 C CNN
	1    3200 3350
	0    -1   1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 609FDA42
P 3200 3250
F 0 "R6" V 2993 3250 50  0001 C CNN
F 1 "220 Ω" V 3085 3250 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3130 3250 50  0001 C CNN
F 3 "~" H 3200 3250 50  0001 C CNN
	1    3200 3250
	0    -1   1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 609FD913
P 3200 3150
F 0 "R5" V 2993 3150 50  0001 C CNN
F 1 "220 Ω" V 3085 3150 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3130 3150 50  0001 C CNN
F 3 "~" H 3200 3150 50  0001 C CNN
	1    3200 3150
	0    -1   1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 609FD653
P 3200 3050
F 0 "R4" V 2993 3050 50  0001 C CNN
F 1 "220 Ω" V 3085 3050 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3130 3050 50  0001 C CNN
F 3 "~" H 3200 3050 50  0001 C CNN
	1    3200 3050
	0    1    1    0   
$EndComp
$Comp
L Device:R R3
U 1 1 609FD4C1
P 3200 2950
F 0 "R3" V 2993 2950 50  0001 C CNN
F 1 "220 Ω" V 3085 2950 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3130 2950 50  0001 C CNN
F 3 "~" H 3200 2950 50  0001 C CNN
	1    3200 2950
	0    1    1    0   
$EndComp
Wire Wire Line
	3800 1550 3800 4150
$Comp
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 609D6D19
P 4000 3150
F 0 "A1" H 4000 2061 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 4000 1970 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 4000 3150 50  0001 C CIN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 4000 3150 50  0001 C CNN
	1    4000 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 5050 3100 4950
Connection ~ 3100 4950
$Comp
L NEB21R:NEB21R Vin1
U 1 1 60A562C1
P 2700 1050
F 0 "Vin1" V 2693 873 50  0000 R CNN
F 1 "NEB21R" V 2602 873 50  0000 R CNN
F 2 "NEB21R" H 2700 1050 50  0001 L BNN
F 3 "" H 2700 1050 50  0001 L BNN
F 4 "" H 2700 1050 50  0001 L BNN "MF"
F 5 "1217037" H 2700 1050 50  0001 L BNN "OC_FARNELL"
F 6 "97K6458" H 2700 1050 50  0001 L BNN "OC_NEWARK"
F 7 "NEB 21 R" H 2700 1050 50  0001 L BNN "MPN"
	1    2700 1050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3100 1250 2800 1250
Connection ~ 3100 1250
Wire Wire Line
	2700 1250 2600 1250
Connection ~ 2600 1250
NoConn ~ 4500 2550
NoConn ~ 4500 2650
NoConn ~ 4500 2950
NoConn ~ 5250 1850
NoConn ~ 3500 2650
NoConn ~ 3500 2550
NoConn ~ 4100 2150
NoConn ~ 5750 1650
NoConn ~ 5750 1750
Wire Wire Line
	4100 4150 4750 4150
Wire Wire Line
	4500 3750 4600 3750
Wire Wire Line
	4750 3600 4750 2150
Wire Wire Line
	4200 2150 4750 2150
Connection ~ 4750 2150
Wire Wire Line
	4750 2150 5950 2150
Wire Wire Line
	4750 3900 4750 4150
Connection ~ 4750 4150
Wire Wire Line
	4750 4150 6250 4150
Wire Wire Line
	5050 1750 5050 3450
Wire Wire Line
	5050 3450 4500 3450
Text Label 4500 3750 0    50   ~ 0
A6
Wire Wire Line
	2150 3450 2200 3450
Connection ~ 2200 3450
Wire Wire Line
	2200 3450 2200 4700
Wire Wire Line
	3500 3450 3350 3450
Wire Wire Line
	3050 3450 2550 3450
Wire Wire Line
	2550 3450 2550 3600
Wire Wire Line
	2550 3600 2150 3600
Wire Wire Line
	2150 3600 2150 4950
Wire Wire Line
	2150 4950 2500 4950
Wire Wire Line
	1100 4100 1100 5300
Wire Wire Line
	1100 5300 5300 5300
Wire Wire Line
	5300 5300 5300 3550
Wire Wire Line
	5300 3550 4500 3550
$EndSCHEMATC
