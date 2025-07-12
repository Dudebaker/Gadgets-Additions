; PingRepeat#
[MeterSeparatorPingRepeat#]
Meter=Image
MeterStyle=StyleDefault | StyleDisabled | StyleScale | StyleLoadingHide | StyleSeparator | StylePingSeparator | StylePingSeparatorRepeat#

[MeterPingRepeat#Value]
Group=PingRepeat#
Meter=String
MeterStyle=StyleDefault | StyleScale | StylePingValue | StyleLoadingHide
Text=#PingRepeat#Input#
DynamicVariables=1
Y=6r

[MeterPingRepeat#ValueScaleFix]
Group=PingRepeat#
Meter=Image
Solidcolor=0,0,0,0
X=([MeterPingRepeat#Value:X] * #Scale#)
Y=(([MeterPingRepeat#Value:Y] + 1) * #Scale#)
W=([MeterPingRepeat#Value:W] * #Scale#)
H=([MeterPingRepeat#Value:H] * #Scale#)
LeftMouseUpAction=[!CommandMeasure MeasurePingRepeat#Value "ExecuteBatch 1"]
MiddleMouseUpAction=[!WriteKeyValue Variables PingRepeat#Input "google.com" "#@#Variables\Ping.inc"][!Refresh]
MouseOverAction=[!SetOption MeterPingRepeat#Value SolidColor "128,128,128,64"][!UpdateMeter MeterPingRepeat#Value][!Redraw]
MouseLeaveAction=[!SetOption MeterPingRepeat#Value SolidColor ""][!UpdateMeter MeterPingRepeat#Value][!Redraw]

[MeasurePingRepeat#Value]
Group=PingRepeat#
Measure=Plugin
Plugin=InputText
FontFace=Seqoe UI
StringStyle=Italic
X=[MeterPingRepeat#ValueScaleFix:X]
Y=[MeterPingRepeat#ValueScaleFix:Y]
W=[MeterPingRepeat#ValueScaleFix:W]
H=[MeterPingRepeat#ValueScaleFix:H]
DefaultValue=#PingRepeat#Input#
DynamicVariables=1
Command1=[!WriteKeyValue Variables PingRepeat#Input "$UserInput$" "#@#Variables\Ping.inc"][!Refresh]

[MeterPingRepeat#ValueStarted]
Group=PingRepeat#Started
Meter=String
MeterStyle=StyleDefault | StyleScale | StylePingValue | StyleLoadingHide
Text=#PingRepeat#Input#
DynamicVariables=1
Y=[MeterPingRepeat#Value:Y]
Hidden=1

[MeterPingRepeat#Start]
Meter=Image
MeterStyle=StyleDefault | StyleScale | StyleStart | StyleLoadingHide
Y=([MeterPingRepeat#Value:Y] - 1)

[MeterPingRepeat#StartScaleFix]
Meter=Image
Solidcolor=0,0,0,0
X=([MeterPingRepeat#Start:X] * #Scale#)
Y=([MeterPingRepeat#Start:Y] * #Scale#)
W=([MeterPingRepeat#Start:W] * #Scale#)
H=([MeterPingRepeat#Start:H] * #Scale#)
LeftMouseUpAction=[!EnableMeasure MeasurePingRepeat#StartStop]
MouseOverAction=[!SetOption MeterPingRepeat#Start ImageAlpha 192][!UpdateMeter MeterPingRepeat#Start][!Redraw]
MouseLeaveAction=[!SetOption MeterPingRepeat#Start ImageAlpha 255][!UpdateMeter MeterPingRepeat#Start][!Redraw]
ToolTipText=#LANG_PING_START#

[MeterPingRepeat#LatencyMax]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleLoadingHide
Text=#LANG_PING_MAX#:
Y=0R

[MeterPingRepeat#DowntimesValue]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleLoadingHide
Text=#LANG_PING_DOWN#: #PingRepeat#DownValue#
DynamicVariables=1
Y=0r
X=(#Width# / 2 - 28)
FontColor=192,0,0,255

[MeterPingRepeat#Current]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleLoadingHide
Text=#LANG_PING_CURRENT#:
Y=0r
X=(#Width# - 50)

[MeterPingRepeat#LatencyMaxValue]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleValue | StyleLoadingHide
Text=#PingRepeat#MaxValue#ms
DynamicVariables=1
StringAlign=Left
Y=0R
X=10

[MeterPingRepeat#AverageValue]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleLoadingHide
Text=#LANG_PING_AVERAGE#:
Y=0r
X=(#Width# / 2 - 28)
FontColor=0,128,192,255

[MeterPingRepeat#LatencyCurrentValue]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleValue | StyleLoadingHide
MeasureName=MeasurePingRepeat#Numeric
DynamicVariables=1
Text=%1ms

[MeterPingRepeat#GraphBackground]
Meter=Image
MeterStyle=StyleDefault | StyleScale | StyleGraphBackground | StyleLoadingHide

[MeterPingRepeat#Graph]
Group=PingRepeat#Started
Meter=Line
MeterStyle=StyleDefault | StyleScale | StyleGraph | StyleLoadingHide
MeasureName=MeasurePingRepeat#GraphBasePingChangePercent
Hidden=1

[MeterPingRepeat#GraphScaleFix]
Meter=Image
Solidcolor=0,0,0,0
X=([MeterPingRepeat#GraphBackground:X] * #Scale#)
Y=([MeterPingRepeat#GraphBackground:Y] * #Scale#)
W=([MeterPingRepeat#GraphBackground:W] * #Scale#)
H=([MeterPingRepeat#GraphBackground:H] * #Scale#)
LeftMouseDoubleClickAction=["#CURRENTPATH#\LogPing.txt"]
ToolTipText=#LANG_PING_OPEN_LOG#

[MeterPingRepeat#GraphPingUp]
Group=PingRepeat#Started
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleGraphPingUp | StyleLoadingHide
Hidden=1

[MeterPingRepeat#GraphPingBase]
Group=PingRepeat#Started
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleGraphPing | StyleLoadingHide
Text=#PingRepeat#GraphBaseValue#ms
DynamicVariables=1
Hidden=1

[MeterPingRepeat#GraphPingDown]
Group=PingRepeat#Started
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleGraphPingDown | StyleLoadingHide
Hidden=1