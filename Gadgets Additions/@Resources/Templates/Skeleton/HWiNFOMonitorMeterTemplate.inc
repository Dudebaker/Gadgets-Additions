; SensorRepeat#
[MeterSensorRepeat#Name]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleSensorName | StyleSection1Entry1 | StyleLoadingHide
Text=#LANG_LOADING#
FontColor=#HWiNFOSensorRepeat#NameColor#
Y=17r

[MeterSensorRepeat#Value]
Meter=String
MeasureName=MeasureSensorRepeat#ValueCurrentNumeric
MeasureName2=MeasureSensorRepeat#Unit
MeasureName3=MeasureSensorRepeat#ValueMin
MeasureName4=MeasureSensorRepeat#ValueMax
MeasureName5=MeasureSensorRepeat#ValueAverage
MeterStyle=StyleDefault | StyleScale | StyleValue | StyleSensorValue | StyleSection1Entry1 | StyleLoadingHide
FontColor=#HWiNFOSensorRepeat#ValueColor#
NumOfDecimals=#HWiNFOSensorRepeat#Decimals#

[MeterSensorRepeat#Hover]
Meter=Image
MeterStyle=StyleDefault | StyleDisabled | StyleLoadingHide
SolidColor=0,0,0,1
X=([MeterSensorRepeat#Name:X] * #Scale#)
Y=([MeterSensorRepeat#Name:Y] * #Scale#)
W=((#Width# - 20) * #Scale#)
H=([MeterSensorRepeat#Name:H] * #Scale#)
MouseOverAction=[!HideMeter MeterSensorRepeat#Name][!SetOption MeterSensorRepeat#Value W (#Width#-20)][!SetOption MeterSensorRepeat#Value Text "↓%3  ↑%4  ~%5 %2"][!UpdateMeter MeterSensorRepeat#Value][!Redraw]
MouseLeaveAction=[!ShowMeter MeterSensorRepeat#Name][!SetOption MeterSensorRepeat#Value W ""][!SetOption MeterSensorRepeat#Value Text ""][!UpdateMeter MeterSensorRepeat#Value][!Redraw]
