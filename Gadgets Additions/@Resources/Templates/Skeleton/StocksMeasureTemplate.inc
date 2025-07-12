; MarketRepeat# Measures
[MeasureMarketRepeat#]
Measure=WebParser
DynamicVariables=1
URL=#URLPrefix##MarketRepeat##
UserAgent=#UserAgent#
Header=Accept: text/html
Header2=Accept_Encoding: gzip, deflate, br
Header3=Accept_Language: en-US
Header4=Connection: close
Header5=Dnt: 1
Header6=Host: www.CNBC.com
Header7=Referer: https://wwww.google.com
RegExp=#RegExpMarket#
UpdateRate=#RefreshRate#
Disabled=#Disabled#

[MeasureMarketRepeat#Name]
Measure=WebParser
URL=[MeasureMarketRepeat#]
StringIndex=1
RegExp=#RegExpName#
StringIndex2=1
DecodeCharacterReference=1
Substitute="":"#LANG_LOADING#"
FinishAction=[!EnableMeasure MeasureMarketRepeat#NameOverride][!UpdateMeasure MeasureMarketRepeat#NameOverride][!DisableMeasure MeasureMarketRepeat#Name]
UpdateRate=#RefreshRate#

[MeasureMarketRepeat#NameOverride]
Group=MarketRepeat#
Measure=String
String=#MarketRepeat#NameOverride#
IfMatch=^$
IfMatchAction=[!SetOption MeterMarketRepeat# Text "[MeasureMarketRepeat#Name]"][!DisableMeasure MeasureMarketRepeat#NameOverride]
IfNotMatchAction=[!SetOption MeterMarketRepeat# Text "#MarketRepeat#NameOverride#"][!DisableMeasure MeasureMarketRepeat#NameOverride]
IfMatchMode=1
OnUpdateAction=[!DisableMeasure MeasureMarketRepeat#NameOverride]
Disabled=1

[MeasureMarketRepeat#Price]
Measure=WebParser
URL=[MeasureMarketRepeat#]
StringIndex=1
RegExp=#RegExpPrice#
StringIndex2=1
Substitute="":"0.00"
UpdateRate=#RefreshRate#

[MeasureMarketRepeat#Change]
Measure=WebParser
URL=[MeasureMarketRepeat#]
StringIndex=1
RegExp=#RegExpChange#
StringIndex2=1
Substitute="":"0.00","+":"","-":"","UNCH":"0.00"
UpdateRate=#RefreshRate#

[MeasureMarketRepeat#ChangePercent]
Measure=WebParser
URL=[MeasureMarketRepeat#]
StringIndex=1
RegExp=#RegExpChangePercent#
StringIndex2=1
Substitute="":"0.00","%":""
UpdateRate=#RefreshRate#

[MeasureMarketRepeat#ChangePercentForScaling]
Measure=Calc
Formula=MeasureMarketRepeat#ChangePercent
IfBelowValue=0
IfBelowAction=[!SetOption MeterMarketRepeat#ChangeValue FontColor "#FontColorMarketDown#"][!Redraw]
IfAboveValue=0
IfAboveAction=[!SetOption MeterMarketRepeat#ChangeValue FontColor "#FontColorMarketUp#"][!Redraw]

[MeasureMarketRepeat#Currency]
Measure=WebParser
URL=[MeasureMarketRepeat#]
StringIndex=1
RegExp=#RegExpCurrency#
StringIndex2=1
UpdateRate=#RefreshRate#
FinishAction=[!SetVariable MarketRepeat#IconURL #URLIcon#[MeasureStringCase:Lower('[&MeasureMarketRepeat#Currency]')]#URLIconPostfix#][!EnableMeasure MeasureMarketRepeat#Icon][!DisableMeasure MeasureMarketRepeat#Currency]

[MeasureMarketRepeat#Icon]
Measure=WebParser
DynamicVariables=1
URL=#MarketRepeat#IconURL#
Download=1
Substitute="":"#@#Images\Backgrounds\downloading.png"
DownloadFile=MarketRepeat#Base.png
Disabled=1
UpdateRate=#RefreshRate#+1
UserAgent=#UserAgent#
FinishAction=[!UpdateMeter MeterMarketRepeat#Icon][!Redraw][!DisableMeasure MeasureMarketRepeat#Icon]
OnDownloadErrorAction=[!SetOption MeterMarketRepeat#Icon MeasureName MeasureMarketGenericIcon][!UpdateMeter MeterMarketRepeat#Icon][!Redraw][!DisableMeasure MeasureMarketRepeat#Icon]