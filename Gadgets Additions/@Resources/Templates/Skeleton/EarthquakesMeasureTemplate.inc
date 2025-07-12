; EntryRepeat#
[MeasureEarthquakesEntryRepeat#]
Measure=WebParser
URL=#URL#
RegExp=(?siU)"properties": {(.*)}
StringIndex=1
UpdateRate=#RefReshRate#
UserAgent=#UserAgent#
Disabled=#Disabled#

[MeasureEarthquakesEntryRepeat#Region]
Measure=WebParser
URL=[MeasureEarthquakesEntryRepeat#]
StringIndex=1
RegExp=(?siU)"flynn_region": "(.*)",
StringIndex2=1
Substitute="":"loading..."
UpdateRate=#RefReshRate#

[MeasureEarthquakesEntryRepeat#Id]
Measure=WebParser
URL=[MeasureEarthquakesEntryRepeat#]
StringIndex=1
RegExp=(?siU)"source_id": "(.*)",
StringIndex2=1
UpdateRate=#RefReshRate#

[MeasureEarthquakesEntryRepeat#Id_3char]
Measure=WebParser
URL=[MeasureEarthquakesEntryRepeat#]
StringIndex=1
RegExp=(?siU)"source_id": "(...).*",
StringIndex2=1
UpdateRate=#RefReshRate#

[MeasureEarthquakesEntryRepeat#Id_4char]
Measure=WebParser
URL=[MeasureEarthquakesEntryRepeat#]
StringIndex=1
RegExp=(?siU)"source_id": "(....).*",
StringIndex2=1
UpdateRate=#RefReshRate#

[MeasureEarthquakesEntryRepeat#Lat]
Measure=WebParser
URL=[MeasureEarthquakesEntryRepeat#]
StringIndex=1
RegExp=(?siU)"lat": (.*),
StringIndex2=1
Substitute="":"0"
UpdateRate=#RefReshRate#
FinishAction=[!UpdateMeasure MeasureEarthquakesEntryRepeat#LatDiffInRad]

[MeasureEarthquakesEntryRepeat#LatDiffInRad]
Measure=Calc
DynamicVariables=1
Formula=(Rad(([MeasureEarthquakesEntryRepeat#Lat] - #OwnLat#)))
UpdateDivider=-1

[MeasureEarthquakesEntryRepeat#Long]
Measure=WebParser
URL=[MeasureEarthquakesEntryRepeat#]
StringIndex=1
RegExp=(?siU)"lon": (.*),
StringIndex2=1
Substitute="":"0"
UpdateRate=#RefReshRate#
FinishAction=[!UpdateMeasure MeasureEarthquakesEntryRepeat#LongDiffInRad]

[MeasureEarthquakesEntryRepeat#LongDiffInRad]
Measure=Calc
DynamicVariables=1
Formula=(Rad(([MeasureEarthquakesEntryRepeat#Long] - #OwnLong#)))
UpdateDivider=-1
OnUpdateAction=[!UpdateMeasure MeasureEarthquakesEntryRepeat#DistanceCalcHaversine]

[MeasureEarthquakesEntryRepeat#DistanceCalcHaversine]
Measure=Calc
DynamicVariables=1
Formula=(Sin([MeasureEarthquakesEntryRepeat#LatDiffInRad]/2) * Sin([MeasureEarthquakesEntryRepeat#LatDiffInRad]/2) + Cos(Rad(#OwnLat#)) * Cos(Rad([MeasureEarthquakesEntryRepeat#Lat])) * Sin([MeasureEarthquakesEntryRepeat#LongDiffInRad]/2) * Sin([MeasureEarthquakesEntryRepeat#LongDiffInRad]/2))
UpdateDivider=-1
OnUpdateAction=[!UpdateMeasure MeasureEarthquakesEntryRepeat#Distance]

[MeasureEarthquakesEntryRepeat#Distance]
Measure=Calc
DynamicVariables=1
Formula=(6371 * (2 * Atan2(Sqrt([MeasureEarthquakesEntryRepeat#DistanceCalcHaversine]), Sqrt(1-[MeasureEarthquakesEntryRepeat#DistanceCalcHaversine]))))
UpdateDivider=-1
OnUpdateAction=[!UpdateMeasure MeasureEarthquakesEntryRepeat#DistanceCalcKmMiles]

[MeasureEarthquakesEntryRepeat#DistanceCalcKmMiles]
Measure=Calc
DynamicVariables=1
Formula=([MeasureEarthquakesEntryRepeat#Distance] - (([MeasureEarthquakesEntryRepeat#Distance] - [MeasureEarthquakesEntryRepeat#Distance] * 0.621371) * #UseMiles#))
IfAboveValue=#WarnDistance#
IfAboveAction=[!SetOption MeterEntryRepeat#DistanceValue FontColor "#FontColorEarthquakeValues#"][!UpdateMeter MeterEntryRepeat#DistanceValue][!Redraw]
IfBelowValue=#WarnDistance#
IfBelowAction=[!SetOption MeterEntryRepeat#DistanceValue FontColor "255,0,0,255"][!UpdateMeter MeterEntryRepeat#DistanceValue][!Redraw]
UpdateDivider=-1

[MeasureEarthquakesEntryRepeat#Depth]
Measure=WebParser
URL=[MeasureEarthquakesEntryRepeat#]
StringIndex=1
RegExp=(?siU)"depth": (.*),
StringIndex2=1
Substitute="":"0"
UpdateRate=#RefReshRate#
FinishAction=[!UpdateMeasure MeasureEarthquakesEntryRepeat#DepthCalcKmMiles]

[MeasureEarthquakesEntryRepeat#DepthCalcKmMiles]
Measure=Calc
DynamicVariables=1
Formula=([MeasureEarthquakesEntryRepeat#Depth] - (([MeasureEarthquakesEntryRepeat#Depth] - [MeasureEarthquakesEntryRepeat#Depth] * 0.621371) * #UseMiles#))
UpdateDivider=-1

[MeasureEarthquakesEntryRepeat#Magnitude]
Measure=WebParser
URL=[MeasureEarthquakesEntryRepeat#]
StringIndex=1
RegExp=(?siU)"mag": (.*),
StringIndex2=1
Substitute="M":"","m":"","L":"","l":"","B":"","b":"","D":"","d":"","S":"","s":"","W":"","w":""," ":"","":"0"
UpdateRate=#RefReshRate#

[MeasureEarthquakesEntryRepeat#MagnitudeNumeric]
Measure=Calc
Formula=[MeasureEarthquakesEntryRepeat#Magnitude]
DynamicVariables=1
IfAboveValue=#WarnMagnitude#
IfAboveAction=[!SetOption MeterEntryRepeat#MagnitudeValue FontColor "255,0,0,255"][!UpdateMeter MeterEntryRepeat#MagnitudeValue][!Redraw]
IfBelowValue=#WarnMagnitude#
IfBelowAction=[!SetOption MeterEntryRepeat#MagnitudeValue FontColor "#FontColorEarthquakeValues#"][!UpdateMeter MeterEntryRepeat#MagnitudeValue][!Redraw]

[MeasureEarthquakesEntryRepeat#Date]
Measure=WebParser
URL=[MeasureEarthquakesEntryRepeat#]
StringIndex=1
RegExp=(?siU)"time": "(.*)\.
StringIndex2=1
Substitute="T":" "
UpdateRate=#RefReshRate#
FinishAction=[!EnableMeasureGroup EntryRepeat#DateFormat][!UpdateMeasureGroup EntryRepeat#DateFormat]

[MeasureEarthquakesEntryRepeat#DateFormatted]
Measure=Time
Group=EntryRepeat#DateFormat
TimeStamp=[MeasureEarthquakesEntryRepeat#Date]
TimeStampFormat=%Y-%m-%d %H:%M:%S
Format=%#c
DynamicVariables=1
Disabled=1
UpdateDivider=-1

[MeasureEarthquakesEntryRepeat#DateUpdated]
Measure=Time
Group=EntryRepeat#DateFormat
TimeStamp=([MeasureEarthquakesEntryRepeat#DateFormatted:TimeStamp] + [MeasureCalcTimeZoneTotalDiff:])
TimeStampLocale=#DateTimeLocalID#
FormatLocale=#DateTimeLocalID#
Format=#DateTimeFormat#
DynamicVariables=1
Disabled=1
UpdateDivider=-1
OnUpdateAction=[!DisableMeasureGroup EntryRepeat#DateFormat]