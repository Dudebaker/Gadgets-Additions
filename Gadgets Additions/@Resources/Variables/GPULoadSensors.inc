[Variables]
;
; HWiNFO Variables
; 
; Note:
; You can change these values directly through the HWiNFO Shared Memory Viewer (HWiNFO Monitor Settings skin -> Show Sensors).
; Otherwise enter them here, all three needed HWiNFO values per sensor have a dash (-) in the name.
; 
; Note2 (only for the first 6 sensors!):
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
HWiNFOSensor01Name=
HWiNFOSensor01Decimals=0
HWiNFOSensor01-SensorId=0xe0001800
HWiNFOSensor01-SensorInstance=0x0
HWiNFOSensor01-EntryId=0x7000000
; Sensor02
HWiNFOSensor02Name=
HWiNFOSensor02Decimals=0
HWiNFOSensor02-SensorId=0xe0001800
HWiNFOSensor02-SensorInstance=0x0
HWiNFOSensor02-EntryId=0x7000001
; Sensor03
HWiNFOSensor03Name=
HWiNFOSensor03Decimals=0
HWiNFOSensor03-SensorId=0xe0001800
HWiNFOSensor03-SensorInstance=0x0
HWiNFOSensor03-EntryId=0x7000002
; Sensor04
HWiNFOSensor04Name=
HWiNFOSensor04Decimals=0
HWiNFOSensor04-SensorId=0xe0001800
HWiNFOSensor04-SensorInstance=0x0
HWiNFOSensor04-EntryId=0x5000001
; Sensor05
HWiNFOSensor05Name=
HWiNFOSensor05Decimals=0
HWiNFOSensor05-SensorId=0xe0001800
HWiNFOSensor05-SensorInstance=0x0
HWiNFOSensor05-EntryId=0x1000000
; Sensor06
HWiNFOSensor06Name=
HWiNFOSensor06Decimals=0
HWiNFOSensor06-SensorId=0xe0001800
HWiNFOSensor06-SensorInstance=0x0
HWiNFOSensor06-EntryId=0x100000a
;
; Compute entries
;
; Compute0
HWiNFOCompute0-SensorId=0xe0001800
HWiNFOCompute0-SensorInstance=0x0
HWiNFOCompute0-EntryId=0x7000020
; Compute1
HWiNFOCompute1-SensorId=0xe0001800
HWiNFOCompute1-SensorInstance=0x0
HWiNFOCompute1-EntryId=0x7000021
; Compute2
HWiNFOCompute2-SensorId=0xe0001800
HWiNFOCompute2-SensorInstance=0x0
HWiNFOCompute2-EntryId=0x700001e
; Compute3
HWiNFOCompute3-SensorId=0xe0001800
HWiNFOCompute3-SensorInstance=0x0
HWiNFOCompute3-EntryId=0x700001f
; Compute4
HWiNFOCompute4-SensorId=0xe0002000
HWiNFOCompute4-SensorInstance=0x0
HWiNFOCompute4-EntryId=0x700002e
;
; VideoDecode entries
;
; VideoDecode0
HWiNFOVideoDecode0-SensorId=0xe0001800
HWiNFOVideoDecode0-SensorInstance=0x0
HWiNFOVideoDecode0-EntryId=0x700000a
; VideoDecode1
HWiNFOVideoDecode1-SensorId=0xe0001800
HWiNFOVideoDecode1-SensorInstance=0x0
HWiNFOVideoDecode1-EntryId=0x700000b
; VideoDecode2
HWiNFOVideoDecode2-SensorId=0xe0002000
HWiNFOVideoDecode2-SensorInstance=0x0
HWiNFOVideoDecode2-EntryId=0x700000c
; VideoDecode3
HWiNFOVideoDecode3-SensorId=0xe0002000
HWiNFOVideoDecode3-SensorInstance=0x0
HWiNFOVideoDecode3-EntryId=0x700000d
; VideoDecode4
HWiNFOVideoDecode4-SensorId=0xe0002000
HWiNFOVideoDecode4-SensorInstance=0x0
HWiNFOVideoDecode4-EntryId=0x700000e
;
; VideoEncode entries
;
; VideoEncode0
HWiNFOVideoEncode0-SensorId=0xe0001800
HWiNFOVideoEncode0-SensorInstance=0x0
HWiNFOVideoEncode0-EntryId=0x7000014
; VideoEncode1
HWiNFOVideoEncode1-SensorId=0xe0001800
HWiNFOVideoEncode1-SensorInstance=0x0
HWiNFOVideoEncode1-EntryId=0x7000015
; VideoEncode2
HWiNFOVideoEncode2-SensorId=0xe0001800
HWiNFOVideoEncode2-SensorInstance=0x0
HWiNFOVideoEncode2-EntryId=0x7000016
; VideoEncode3
HWiNFOVideoEncode3-SensorId=0xe0001800
HWiNFOVideoEncode3-SensorInstance=0x0
HWiNFOVideoEncode3-EntryId=0x7000017
; VideoEncode4
HWiNFOVideoEncode4-SensorId=0xe0002000
HWiNFOVideoEncode4-SensorInstance=0x0
HWiNFOVideoEncode4-EntryId=0x7000018
;
; Infos read by the Shared Memory Viewer
;
[HWiNFO-Config-General]
HWiNFOSensor01=Sensor 1
HWiNFOSensor02=Sensor 2
HWiNFOSensor03=Sensor 3
HWiNFOSensor04=Sensor 4
[HWiNFO-Config-Seperated]
HWiNFOSensor05=Sensor 5
HWiNFOSensor06=Sensor 6
[HWiNFO-Config-Compute]
HWiNFOCompute0=Compute 0 (%)
HWiNFOCompute1=Compute 1 (%)
HWiNFOCompute2=Compute 2 (%)
HWiNFOCompute3=Compute 3 (%)
HWiNFOCompute4=Compute 4 (%)
[HWiNFO-Config-VideoDecode]
HWiNFOVideoDecode0=VideoDecode 0 (%)
HWiNFOVideoDecode1=VideoDecode 1 (%)
HWiNFOVideoDecode2=VideoDecode 2 (%)
HWiNFOVideoDecode3=VideoDecode 3 (%)
HWiNFOVideoDecode4=VideoDecode 4 (%)
[HWiNFO-Config-VideoEncode]
HWiNFOVideoEncode0=VideoEncode 0 (%)
HWiNFOVideoEncode1=VideoEncode 1 (%)
HWiNFOVideoEncode2=VideoEncode 2 (%)
HWiNFOVideoEncode3=VideoEncode 3 (%)
HWiNFOVideoEncode4=VideoEncode 4 (%)
