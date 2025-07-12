; EntryRepeat#
[MeterSeparatorEntryRepeat#]
Meter=Image
MeterStyle=StyleDefault | StyleDisabled | StyleScale | StyleLoadingHide | StyleSeparator | StyleRSSSeparator | StyleRSSSeparatorRepeat#

[MeterEntryRepeat#Title]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleEntryTitle | StyleSection1EntryRepeat# | StyleLoadingHide
MeasureName=MeasureRSSReaderEntryRepeat#Title
Y=5r

[MeterEntryRepeat#Date]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleEntryDate | StyleSection1EntryRepeat# | StyleLoadingHide
MeasureName=MeasureRSSReaderEntryRepeat#DateUpdated

[MeterEntryRepeat#Description]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleEntryDescription | StyleSection1EntryRepeat# | StyleLoadingHide
MeasureName=MeasureRSSReaderEntryRepeat#Description

[MeterEntryRepeat#ScaleFix]
Meter=Image
Solidcolor=0,0,0,0
MeterStyle=StyleSection1EntryRepeat# | StyleLoadingHide
X=([MeterEntryRepeat#Title:X] * #Scale#)
Y=([MeterEntryRepeat#Title:Y] * #Scale#)
W=((#Width# - 20) * #Scale#)
H=(#HeightEntry# * #Scale#)
LeftMouseUpAction=[[MeasureRSSReaderEntryRepeat#Link]]
MouseOverAction=[!SetOption MeterEntryRepeat#Title FontColor "255,255,255,255"][!UpdateMeter MeterEntryRepeat#Title][!Redraw]
MouseLeaveAction=[!SetOption MeterEntryRepeat#Title FontColor ""][!UpdateMeter MeterEntryRepeat#Title][!Redraw]
DynamicVariables=1
ToolTipText=[MeasureRSSReaderEntryRepeat#Title]