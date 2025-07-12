; EntryRepeat#
[MeterSeparatorMarketRepeat#]
Meter=Image
MeterStyle=StyleDefault | StyleDisabled | StyleScale | StyleLoadingHide | StyleSeparator | StyleEarthquakesSeparator | StyleEarthquakesSeparatorRepeat#

[MeterEntryRepeat#Region]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleEntryTitle | StyleLoadingHide
MeasureName=MeasureEarthquakesEntryRepeat#Region
Y=7r

[MeterEntryRepeat#Date]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleEntryDate | StyleLoadingHide
MeasureName=MeasureEarthquakesEntryRepeat#DateUpdated

[MeterEntryRepeat#Magnitude]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleLoadingHide
Text=Magnitude:
Y=0R

[MeterEntryRepeat#MagnitudeValue]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleValue | StyleEntryEarthquakValues | StyleLoadingHide
MeasureName=MeasureEarthquakesEntryRepeat#Magnitude

[MeterEntryRepeat#Depth]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleLoadingHide
Text=Depth:

[MeterEntryRepeat#DepthValue]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleValue | StyleEntryEarthquakValues | StyleLoadingHide
MeasureName=MeasureEarthquakesEntryRepeat#DepthCalcKmMiles
DynamicVariables=1
Text=%1 #Unit#

[MeterEntryRepeat#Distance]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleLoadingHide
Text=Distance:

[MeterEntryRepeat#DistanceValue]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleValue | StyleEntryEarthquakValues | StyleLoadingHide
MeasureName=MeasureEarthquakesEntryRepeat#DistanceCalcKmMiles
Text=%1 #Unit#

[MeterEntryRepeat#ScaleFix]
Meter=Image
Solidcolor=0,0,0,0
MeterStyle=StyleSection1EntryRepeat# | StyleLoadingHide
X=([MeterEntryRepeat#Region:X] * #Scale#)
Y=([MeterEntryRepeat#Region:Y] * #Scale#)
W=((#Width# - 20) * #Scale#)
H=(#HeightEntry# * #Scale#)
LeftMouseUpAction=[https://www.emsc-csem.org/Earthquake_information/earthquake.php?id=[MeasureEarthquakesEntryRepeat#Id]]
MouseOverAction=[!SetOption MeterEntryRepeat#Region FontColor "255,255,255,255"][!UpdateMeter MeterEntryRepeat#Region][!Redraw]
MouseLeaveAction=[!SetOption MeterEntryRepeat#Region FontColor ""][!UpdateMeter MeterEntryRepeat#Region][!Redraw]
DynamicVariables=1
ToolTipText=[MeasureEarthquakesEntryRepeat#Region]

[MeterEntryRepeat#Globe]
Meter=Image
ImageName=#@#Images\Earthquakes\globe.png
MeterStyle=StyleDefault | StyleScale | StyleLoadingHide
X=(#Width# - 25)
Y=[MeterEntryRepeat#Region:Y]
W=14
H=14

[MeterEntryRepeat#GlobeScaleFix]
Meter=Image
Solidcolor=0,0,0,0
MeterStyle=StyleSection1EntryRepeat# | StyleLoadingHide
X=([MeterEntryRepeat#Globe:X] * #Scale#)
Y=([MeterEntryRepeat#Globe:Y] * #Scale#)
W=([MeterEntryRepeat#Globe:W] * #Scale#)
H=([MeterEntryRepeat#Globe:H] * #Scale#)
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables ImageURL "https://static1.emsc.eu/Images/EVID_V2/[MeasureEarthquakesEntryRepeat#Id_3char]/[MeasureEarthquakesEntryRepeat#Id_4char]/[MeasureEarthquakesEntryRepeat#Id]/[MeasureEarthquakesEntryRepeat#Id].global.jpg" "#VarPath#"][!WriteKeyValue Variables EntryViewsTitle "[MeasureEarthquakesEntryRepeat#DateUpdated]" "#VarPath#"]#tmpViews#
MouseOverAction=[!SetOption MeterEntryRepeat#Globe ImageAlpha "192"][!UpdateMeter MeterEntryRepeat#Globe][!Redraw]
MouseLeaveAction=[!SetOption MeterEntryRepeat#Globe ImageAlpha "255"][!UpdateMeter MeterEntryRepeat#Globe][!Redraw]
ToolTipText=Show in globe / regional / local view

[MeterEntryRepeat#Maps]
Meter=Image
ImageName=#@#Images\Earthquakes\maps.png
MeterStyle=StyleDefault | StyleScale | StyleLoadingHide
X=(#Width# - 25)
Y=([MeterEntryRepeat#Region:Y] + 15)
W=14
H=14

[MeterEntryRepeat#MapsScaleFix]
Meter=Image
Solidcolor=0,0,0,0
MeterStyle=StyleSection1EntryRepeat# | StyleLoadingHide
X=([MeterEntryRepeat#Maps:X] * #Scale#)
Y=([MeterEntryRepeat#Maps:Y] * #Scale#)
W=([MeterEntryRepeat#Maps:W] * #Scale#)
H=([MeterEntryRepeat#Maps:H] * #Scale#)
DynamicVariables=1
LeftMouseUpAction=[#Maps#[MeasureEarthquakesEntryRepeat#Lat],[MeasureEarthquakesEntryRepeat#Long]]
MouseOverAction=[!SetOption MeterEntryRepeat#Maps ImageAlpha "192"][!UpdateMeter MeterEntryRepeat#Maps][!Redraw]
MouseLeaveAction=[!SetOption MeterEntryRepeat#Maps ImageAlpha "255"][!UpdateMeter MeterEntryRepeat#Maps][!Redraw]
ToolTipText=Show in google maps