; EntryRepeat#
[MeasureRSSReaderEntryRepeat#]
Measure=WebParser
URL=[MeasureRSSReader]
StringIndex=1
RegExp=(?siU)<entry.*>(.*)<\/entry>
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
RegExp=(?siU)<#TagEntryLink#.*href="(.*)".\/>
StringIndex2=1
RegExpSubstitute=1
Substitute="":"#LANG_LOADING#","(?i)<[^>]*> ":"","<!\[CDATA\[":"","\]\]>":"","<p>":"","</p>":""
UpdateRate=#RefReshRate#

[MeasureRSSReaderEntryRepeat#Date]
Measure=WebParser
URL=[MeasureRSSReaderEntryRepeat#]
StringIndex=1
RegExp=(?siU)<#TagEntryDate#.*>(....-..-..).*<\/.*>
StringIndex2=1
Substitute="":"#LANG_LOADING#"
UpdateRate=#RefReshRate#
FinishAction=[!EnableMeasureGroup EntryRepeat#DateFormat][!UpdateMeasureGroup EntryRepeat#DateFormat]

[MeasureRSSReaderEntryRepeat#Time]
Measure=WebParser
URL=[MeasureRSSReaderEntryRepeat#]
StringIndex=1
RegExp=(?siU)<#TagEntryDate#.*>.*(..:..:..).*<\/.*>
StringIndex2=1
Substitute="":"#LANG_LOADING#"
UpdateRate=#RefReshRate#
FinishAction=[!EnableMeasureGroup EntryRepeat#DateFormat][!UpdateMeasureGroup EntryRepeat#DateFormat]

[MeasureRSSReaderEntryRepeat#DateFormatted]
Measure=Time
Group=EntryRepeat#DateFormat
TimeStamp=[MeasureRSSReaderEntryRepeat#Date] [MeasureRSSReaderEntryRepeat#Time]
TimeStampFormat="%Y-%m-%d %H:%M:%S"
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
OnUpdateAction=[!DisableMeasureGroup EntryRepeat#DateFormat]

[MeasureRSSReaderEntryRepeat#Description]
Measure=WebParser
URL=[MeasureRSSReaderEntryRepeat#]
StringIndex=1
RegExp=(?siU)<#TagEntryDescription#.*>(.*)<\/#TagEntryDescription#>
StringIndex2=1
DecodeCharacterReference=1
RegExpSubstitute=1
Substitute="":"#LANG_LOADING#","(?i)<[^>]*> ":"","<!\[CDATA\[":"","\]\]>":"","<p>":"","</p>":"","<p>":"","</p>":"","<tr>":"","</tr>":"","<td>":"","</td>":"","&#32;":"","/u/":"","<!-- SC_OFF -->":"","(?i)<[^>]*>":"","\[link\]":"","\[comments\]":"","&#39;":""
UpdateRate=#RefReshRate#