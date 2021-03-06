[Variables]
;
; HWiNFO Variables
; 
; Note:
; You can change these values directly through the HWiNFO Shared Memory Viewer (HWiNFO Monitor Settings skin -> Show Sensors).
; Otherwise enter them here, all three needed HWiNFO values per sensor have a dash (-) in the name.
; 
; Note2:
; Set the decimals to show (0,1,2,3,...).
; Set the name to anything you like, it's only used for been displayed in this sensor-row
; Leave the name blank to use the returned name of the HWiNFO Sensor.
;  
; Note3:
; The colors can be changed in the variables-file.
; The colors have to be in another file, otherwise they would show up in the Shared Memory Viewer and only confuse people.
;
;
; Sensor01
HWiNFOSensor01Name=CPU PKG Power
HWiNFOSensor01Decimals=0
HWiNFOSensor01-SensorId=0xf0000501
HWiNFOSensor01-SensorInstance=0x0
HWiNFOSensor01-EntryId=0x5000000
; Sensor02
HWiNFOSensor02Name=CPU Core Power
HWiNFOSensor02Decimals=0
HWiNFOSensor02-SensorId=0xf0000501
HWiNFOSensor02-SensorInstance=0x0
HWiNFOSensor02-EntryId=0x5000009
; Sensor03
HWiNFOSensor03Name=SoC Power
HWiNFOSensor03Decimals=0
HWiNFOSensor03-SensorId=0xf0000501
HWiNFOSensor03-SensorInstance=0x0
HWiNFOSensor03-EntryId=0x500000a
; Sensor04
HWiNFOSensor04Name=Core Voltaeg
HWiNFOSensor04Decimals=2
HWiNFOSensor04-SensorId=0xf0000501
HWiNFOSensor04-SensorInstance=0x0
HWiNFOSensor04-EntryId=0x2000000
; Sensor05
HWiNFOSensor05Name=
HWiNFOSensor05Decimals=0
HWiNFOSensor05-SensorId=0xe0002000
HWiNFOSensor05-SensorInstance=0x0
HWiNFOSensor05-EntryId=0x5000000
; Sensor06
HWiNFOSensor06Name=GPU TDP
HWiNFOSensor06Decimals=0
HWiNFOSensor06-SensorId=0xe0002000
HWiNFOSensor06-SensorInstance=0x0
HWiNFOSensor06-EntryId=0x80000fa
; Sensor07
HWiNFOSensor07Name=GPU Power Limit
HWiNFOSensor07Decimals=0
HWiNFOSensor07-SensorId=0xe0002000
HWiNFOSensor07-SensorInstance=0x0
HWiNFOSensor07-EntryId=0x800000b
; Sensor08
HWiNFOSensor08Name=
HWiNFOSensor08Decimals=0
HWiNFOSensor08-SensorId=0xf0000300
HWiNFOSensor08-SensorInstance=0x0
HWiNFOSensor08-EntryId=0x7000010
; Sensor09
HWiNFOSensor09Name=
HWiNFOSensor09Decimals=0
HWiNFOSensor09-SensorId=0xf0ec0502
HWiNFOSensor09-SensorInstance=0x0
HWiNFOSensor09-EntryId=0x1000001
; Sensor10
HWiNFOSensor10Name=
HWiNFOSensor10Decimals=1
HWiNFOSensor10-SensorId=0xf3000002
HWiNFOSensor10-SensorInstance=0x0
HWiNFOSensor10-EntryId=0x1000002
; Sensor11
HWiNFOSensor11Name=
HWiNFOSensor11Decimals=1
HWiNFOSensor11-SensorId=0xf3000002
HWiNFOSensor11-SensorInstance=0x0
HWiNFOSensor11-EntryId=0x1000003
; Sensor12
HWiNFOSensor12Name=SSD Windows
HWiNFOSensor12Decimals=1
HWiNFOSensor12-SensorId=0xf0000100
HWiNFOSensor12-SensorInstance=0x2
HWiNFOSensor12-EntryId=0x1000001
; Sensor13
HWiNFOSensor13Name=SSD Games
HWiNFOSensor13Decimals=1
HWiNFOSensor13-SensorId=0xf0000100
HWiNFOSensor13-SensorInstance=0x3
HWiNFOSensor13-EntryId=0x1000001
; Sensor14
HWiNFOSensor14Name=SSD Apps
HWiNFOSensor14Decimals=1
HWiNFOSensor14-SensorId=0xf0000100
HWiNFOSensor14-SensorInstance=0x0
HWiNFOSensor14-EntryId=0x1000001
; Sensor15
HWiNFOSensor15Name=HDD Data
HWiNFOSensor15Decimals=1
HWiNFOSensor15-SensorId=0xf0000100
HWiNFOSensor15-SensorInstance=0x1
HWiNFOSensor15-EntryId=0x1000000
; Sensor16
HWiNFOSensor16Name=
HWiNFOSensor16Decimals=1
HWiNFOSensor16-SensorId=0xf0008665
HWiNFOSensor16-SensorInstance=0x0
HWiNFOSensor16-EntryId=0x1000001
; Sensor17
HWiNFOSensor17Name=
HWiNFOSensor17Decimals=0
HWiNFOSensor17-SensorId=0xf0008665
HWiNFOSensor17-SensorInstance=0x0
HWiNFOSensor17-EntryId=0x3000004
; Sensor18
HWiNFOSensor18Name=
HWiNFOSensor18Decimals=2
HWiNFOSensor18-SensorId=0xf0008665
HWiNFOSensor18-SensorInstance=0x0
HWiNFOSensor18-EntryId=0x2000002
; Sensor19
HWiNFOSensor19Name=
HWiNFOSensor19Decimals=2
HWiNFOSensor19-SensorId=0xf0008665
HWiNFOSensor19-SensorInstance=0x0
HWiNFOSensor19-EntryId=0x2000003
; Sensor20
HWiNFOSensor20Name=
HWiNFOSensor20Decimals=2
HWiNFOSensor20-SensorId=0xf0008665
HWiNFOSensor20-SensorInstance=0x0
HWiNFOSensor20-EntryId=0x2000007
;
; Infos read by the Shared Memory Viewer
;
[HWiNFO-Config-Sensors]
HWiNFOSensor01=Sensor01
HWiNFOSensor02=Sensor02
HWiNFOSensor03=Sensor03
HWiNFOSensor04=Sensor04
HWiNFOSensor05=Sensor05
HWiNFOSensor06=Sensor06
HWiNFOSensor07=Sensor07
HWiNFOSensor08=Sensor08
HWiNFOSensor09=Sensor09
HWiNFOSensor10=Sensor10
HWiNFOSensor11=Sensor11
HWiNFOSensor12=Sensor12
HWiNFOSensor13=Sensor13
HWiNFOSensor14=Sensor14
HWiNFOSensor15=Sensor15
HWiNFOSensor16=Sensor16
HWiNFOSensor17=Sensor17
HWiNFOSensor18=Sensor18
HWiNFOSensor19=Sensor19
HWiNFOSensor20=Sensor20
