; EntryRepeat#
[MeasureRSSReaderEntryRepeat#]
Measure=WebParser
URL=[MeasureRSSReader]
StringIndex=1
RegExp=(?siU)<item.*>(.*)<\/item>
StringIndex2=1
UpdateRate=#RefReshRate#
Disabled=#Disabled#

[MeasureRSSReaderEntryRepeat#Title]
Measure=WebParser
URL=[MeasureRSSReaderEntryRepeat#]
StringIndex=1
RegExp=(?siU)<#TagEntryTitle#.*>(.*)<\/.*>
StringIndex2=1
DecodeCharacterReference=1
RegExpSubstitute=1
Substitute="":"#LANG_LOADING#","(?i)<[^>]*> ":"","<!\[CDATA\[":"","\]\]>":"","<p>":"","</p>":""
UpdateRate=#RefReshRate#

[MeasureRSSReaderEntryRepeat#Link]
Measure=WebParser
URL=[MeasureRSSReaderEntryRepeat#]
StringIndex=1
RegExp=(?siU)<#TagEntryLink#.*>(.*)<\/.*>
StringIndex2=1
RegExpSubstitute=1
Substitute="":"#LANG_LOADING#","(?i)<[^>]*> ":"","<!\[CDATA\[":"","\]\]>":"","<p>":"","</p>":""
UpdateRate=#RefReshRate#

[MeasureRSSReaderEntryRepeat#Date]
Measure=WebParser
URL=[MeasureRSSReaderEntryRepeat#]
StringIndex=1
RegExp=(?siU)<#TagEntryDate#.*>(...\, .. ... .... ..\:..).*<\/.*>
StringIndex2=1
RegExpSubstitute=1
Substitute="":"#LANG_LOADING#","(?i)<[^>]*> ":"","<!\[CDATA\[":"","\]\]>":"","<p>":"","</p>":""
UpdateRate=#RefReshRate#
FinishAction=[!EnableMeasureGroup EntryRepeat#DateFormat][!UpdateMeasureGroup EntryRepeat#DateFormat]

[MeasureRSSReaderEntryRepeat#DateFormatted]
Measure=Time
Group=EntryRepeat#DateFormat
TimeStamp=[MeasureRSSReaderEntryRepeat#Date]
TimeStampFormat="%a, %d %B %Y %H:%M"
FormatLocale=#DateTimeLocalID#
Format=%#c
DynamicVariables=1
Disabled=1
UpdateDivider=-1

[MeasureRSSReaderEntryRepeat#DateUpdated]
Measure=Time
Group=EntryRepeat#DateFormat
TimeStamp=([MeasureRSSReaderEntryRepeat#DateFormatted:TimeStamp] + [MeasureCalcTimeZoneTotalDiff:])
TimeStampLocale=#DateTimeLocalID#
FormatLocale=#DateTimeLocalID#
Format=#DateTimeFormat#
DynamicVariables=1
Disabled=1
UpdateDivider=-1
RegExpSubstitute=1
Substitute="(\w+):00":"\1"
OnUpdateAction=[!DisableMeasureGroup EntryRepeat#DateFormat]

[MeasureRSSReaderEntryRepeat#Description]
Measure=WebParser
URL=[MeasureRSSReaderEntryRepeat#]
StringIndex=1
RegExp=(?siU)<#TagEntryDescription#.*>(.*)<\/#TagEntryDescription#>
StringIndex2=1
DecodeCharacterReference=1
RegExpSubstitute=1
Substitute="":"#LANG_LOADING#","(?i)<[^>]*> ":"","<!\[CDATA\[":"","\]\]>":"","<p>":"","</p>":"","<p>":"","</p>":""
UpdateRate=#RefReshRate#