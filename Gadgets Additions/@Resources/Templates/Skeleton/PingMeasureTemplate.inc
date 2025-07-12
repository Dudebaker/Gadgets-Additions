; PingRepeat#
[MeasurePingRepeat#StartStop]
Measure=Calc
DynamicVariables=1
Formula=#PingRepeat#Started#
IfEqualValue=0
IfEqualAction=[!HideMeterGroup PingRepeat#][!ShowMeterGroup PingRepeat#Started][!DisableMeasure MeasurePingRepeat#Value][!SetVariable PingRepeat#DownValue 0][!SetVariable PingRepeat#MaxValue 0][!SetVariable PingRepeat#GraphBaseValue 0][!SetVariable PingRepeat#Started 1][!SetOption MeterPingRepeat#Start ImageName "#@#Images\Buttons\stop.png"][!SetOption MeterPingRepeat#StartScaleFix ToolTipText "#LANG_PING_STOP#"][!EnableMeasureGroup PingRepeat#][!DisableMeasure MeasurePingRepeat#StartStop]
IfAboveValue=0
IfAboveAction=[!ShowMeterGroup PingRepeat#][!HideMeterGroup PingRepeat#Started][!EnableMeasure MeasurePingRepeat#Value][!SetVariable PingRepeat#Started 0][!SetOption MeterPingRepeat#Start ImageName "#@#Images\Buttons\start.png"][!SetOption MeterPingRepeat#StartScaleFix ToolTipText "#LANG_PING_START#"][!DisableMeasure MeasurePingRepeat#Numeric][!DisableMeasureGroup PingRepeat#][!SetVariable PingRepeat#DownValue 0][!SetVariable PingRepeat#MaxValue 0][!SetVariable PingRepeat#GraphBaseValue 0][!DisableMeasure MeasurePingRepeat#StartStop]
Disabled=1
Disabled=#Disabled#

[MeasurePingRepeat#]
Group=PingRepeat#
Measure=Plugin
Plugin=PingPlugin
DynamicVariables=1
DestAddress=#PingRepeat#Input#
UpdateRate=#RefreshRate#
Timeout=#Timeout#
TimeoutValue=-1
OnChangeAction=[!EnableMeasure MeasurePingRepeat#Numeric]
Disabled=1

[MeasurePingRepeat#Numeric]
Measure=Calc
Formula=[MeasurePingRepeat#]
DynamicVariables=1
IfEqualValue=-1
IfEqualAction=[!EnableMeasure MeasurePingRepeat#DownWrite][!SetOption MeterPingRepeat#Graph LineColor "#FontColorDown#"][!SetOption MeterPingRepeat#LatencyCurrentValue FontColor "#FontColorDown#"][!SetOption MeterPingRepeat#LatencyCurrentValue Text "#LANG_PING_TIMEOUT#"][!EnableMeasure MeasurePingRepeat#DownCounter][!Redraw]
IfAboveValue=-1
IfAboveAction=[!SetOption MeterPingRepeat#Graph LineColor "#FontColorNameDefault#"][!SetOption MeterPingRepeat#LatencyCurrentValue FontColor "#FontColorValueDefault#"][!SetOption MeterPingRepeat#LatencyCurrentValue Text "%1ms"][!Redraw]
Disabled=1

[MeasurePingRepeat#DownWrite]
Measure=Script
ScriptFile=#@#Scripts/ReadWriteFile.lua
FilePath=LogPing.txt
Mode=a
Write=1
AddDate=1
Content=Host: #PingRepeat#Input# #LANG_PING_TIMEOUT# (>#Timeout#s)
MeasureName=PingRepeat#
Disabled=1
DynamicVariables=1
OnUpdateAction=[!DisableMeasure MeasurePingRepeat#DownWrite]

[MeasurePingRepeat#Average]
Group=PingRepeat#
Measure=Script
ScriptFile=#@#Scripts/GetAverageValue.lua
MeasureName=MeasurePingRepeat#Numeric
MeterName=MeterPingRepeat#AverageValue
MeterTextPrefix="#LANG_PING_AVERAGE#: "
MeterTextPostfix=ms
UpdateDivider=#RefreshRate#
Disabled=1

[MeasurePingRepeat#DownCounter]
Measure=Calc
DynamicVariables=1
Formula=(#PingRepeat#DownValue#+1)
OnUpdateAction=[!SetVariable PingRepeat#DownValue [MeasurePingRepeat#DownCounter]][!DisableMeasure MeasurePingRepeat#DownCounter]
Disabled=1

[MeasurePingRepeat#Max]
Group=PingRepeat#
Measure=Calc
DynamicVariables=1
Formula=[MeasurePingRepeat#]
IfAboveValue=#PingRepeat#MaxValue#
IfAboveAction=[!SetVariable PingRepeat#MaxValue [MeasurePingRepeat#]]
Disabled=1

[MeasurePingRepeat#GraphBasePing]
Group=PingRepeat#
Measure=Calc
DynamicVariables=1
Formula=[MeasurePingRepeat#]
IfAboveValue=((#PingRepeat#GraphBaseValue#+1)*2)
IfAboveAction=[!SetVariable PingRepeat#GraphBaseValue [MeasurePingRepeat#GraphBasePing]]
IfBelowValue=((#PingRepeat#GraphBaseValue#+1)/2)
IfBelowAction=[!SetVariable PingRepeat#GraphBaseValue [MeasurePingRepeat#GraphBasePing]]
Disabled=1

[MeasurePingRepeat#GraphBasePingChangePercent]
Group=PingRepeat#
Measure=Calc
MinValue=0
MaxValue=100
DynamicVariables=1
Formula=([MeasurePingRepeat#]/(#PingRepeat#GraphBaseValue#+0.01)*100)-50
Disabled=1