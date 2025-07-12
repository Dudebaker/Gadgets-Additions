; SensorRepeat#
[MeasureSensorRepeat#Name]
Group=HWiNFO
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=Label#HWiNFOSensorRepeat#Index#
RegExpsubstitute=1
Substitute="^0$":"Not found"

[MeasureSensorRepeat#CheckExists]
Group=HWiNFO
Measure=String
String=[MeasureSensorRepeat#Name]
IfMatch=^Not found$
IfMatchAction=[!DisableMeasureGroup HWiNFOSensorRepeat#][!SetVariable SensorRepeat#MinValue "999999"][!SetVariable SensorRepeat#MaxValue "0"][!SetOption MeterSensorRepeat#Name FontColor "#HWiNFOWarnColor#"][!SetOption MeterSensorRepeat#Name Text "Index #HWiNFOSensorRepeat#Index# not found"][!Redraw]
IfNotMatchAction=[!EnableMeasureGroup HWiNFOSensorRepeat#][!SetOption MeterSensorRepeat#Name FontColor "#HWiNFOSensorRepeat#NameColor#"][!Redraw]
IfMatchMode=1
DynamicVariables=1

[MeasureSensorRepeat#NameOverride]
Group=HWiNFO|HWiNFOSensorRepeat#
Measure=String
String=#HWiNFOSensorRepeat#Name#
IfMatch=^$
IfMatchAction=[!SetOption MeterSensorRepeat#Name Text "[MeasureSensorRepeat#Name]:"][!DisableMeasure MeasureSensorRepeat#NameOverride]
IfNotMatchAction=[!SetOption MeterSensorRepeat#Name Text "#HWiNFOSensorRepeat#Name#:"][!DisableMeasure MeasureSensorRepeat#NameOverride]
IfMatchMode=1

[MeasureSensorRepeat#ValueCurrentRaw]
Group=HWiNFO|HWiNFOSensorRepeat#
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=ValueRaw#HWiNFOSensorRepeat#Index#
Substitute="No":"0", "Yes":"1","Nein":"0", "Ja":"1"

[MeasureSensorRepeat#ValueCurrentNumeric]
Group=HWiNFO|HWiNFOSensorRepeat#
Measure=Calc
Formula=[MeasureSensorRepeat#ValueCurrentRaw]
IfEqualValue=0
IfEqualAction=[!SetVariable SensorRepeat#MaxValue "0"][!SetVariable SensorRepeat#MinValue "999999"]
IfAboveValue=#SensorRepeat#MaxValue#
IfAboveAction=[!SetVariable SensorRepeat#MaxValue [MeasureSensorRepeat#ValueCurrentNumeric]]
IfBelowValue=#SensorRepeat#MinValue#
IfBelowAction=[!SetVariable SensorRepeat#MinValue [MeasureSensorRepeat#ValueCurrentNumeric]]
DynamicVariables=1

[MeasureSensorRepeat#Unit]
Group=HWiNFO|HWiNFOSensorRepeat#
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=SOFTWARE\HWiNFO64\VSB
RegValue=Value#HWiNFOSensorRepeat#Index#
RegExpsubstitute=1
Substitute="(.*) (.*)":"\2","\.":"","^0+(?!$)":"","0":"","Yes":"","No":"","Ja":"","Nein":""

[MeasureSensorRepeat#ValueMin]
Group=HWiNFO|HWiNFOSensorRepeat#
Measure=Calc
Formula=#SensorRepeat#MinValue#
IfEqualValue=0
IfEqualAction=[!SetVariable SensorRepeat#MinValue [MeasureSensorRepeat#ValueCurrentNumeric]]
DynamicVariables=1

[MeasureSensorRepeat#ValueMax]
Group=HWiNFO|HWiNFOSensorRepeat#
Measure=Calc
Formula=#SensorRepeat#MaxValue#
DynamicVariables=1

[MeasureSensorRepeat#ValueAverage]
Group=Ping1|HWiNFOSensorRepeat#
Measure=Script
ScriptFile=#@#Scripts/GetAverageValue.lua
MeasureName=MeasureSensorRepeat#ValueCurrentRaw
ReturnDirectly=true
RoundValue=#HWiNFOSensorRepeat#Decimals#