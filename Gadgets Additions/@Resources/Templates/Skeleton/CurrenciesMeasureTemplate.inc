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
Substitute="":"loading","\u002F":" / "
UpdateRate=#RefreshRate#

[MeasureMarketRepeat#CurrencyBase]
Measure=WebParser
URL=[MeasureMarketRepeat#]
StringIndex=1
RegExp=#RegExpFrom#
StringIndex2=1
Substitute="":"generic"
UpdateRate=#RefreshRate#
FinishAction=[!SetVariable MarketRepeat#IconBaseURL #URLIcon#[MeasureStringCase:Lower('[&MeasureMarketRepeat#CurrencyBase]')]#URLIconPostfix#][!EnableMeasure MeasureMarketRepeat#IconBase][!DisableMeasure MeasureMarketRepeat#CurrencyBase]

[MeasureMarketRepeat#IconBase]
Measure=WebParser
DynamicVariables=1
URL=#MarketRepeat#IconBaseURL#
Download=1
Substitute="":"#@#Images\Backgrounds\downloading.png"
DownloadFile=MarketRepeat#Base.png
Disabled=1
UpdateRate=#RefreshRate#+1
UserAgent=#UserAgent#
FinishAction=[!UpdateMeter MeterMarketRepeat#IconBase][!Redraw][!DisableMeasure MeasureMarketRepeat#IconBase]
OnDownloadErrorAction=[!SetOption MeterMarketRepeat#IconBase MeasureName MeasureMarketGenericIcon][!UpdateMeter MeterMarketRepeat#IconBase][!Redraw][!DisableMeasure MeasureMarketRepeat#IconBase]

[MeasureMarketRepeat#CurrencyTarget]
Measure=WebParser
URL=[MeasureMarketRepeat#]
StringIndex=1
RegExp=#RegExpTo#
StringIndex2=1
UpdateRate=#RefreshRate#
FinishAction=[!SetVariable MarketRepeat#IconTargetURL #URLIcon#[MeasureStringCase:Lower('[&MeasureMarketRepeat#CurrencyTarget]')]#URLIconPostfix#][!EnableMeasure MeasureMarketRepeat#IconTarget][!DisableMeasure MeasureMarketRepeat#CurrencyTarget]

[MeasureMarketRepeat#IconTarget]
Measure=WebParser
DynamicVariables=1
URL=#MarketRepeat#IconTargetURL#
Download=1
Substitute="":"#@#Images\Backgrounds\downloading.png"
DownloadFile=MarketRepeat#Target.png
Disabled=1
UpdateRate=#RefreshRate#+1
UserAgent=#UserAgent#
FinishAction=[!UpdateMeter MeterMarketRepeat#IconTarget][!Redraw][!DisableMeasure MeasureMarketRepeat#IconTarget]
OnDownloadErrorAction=[!SetOption MeterMarket2IconTarget MeasureName MeasureMarketGenericIcon][!UpdateMeter MeterMarket2IconTarget][!Redraw][!DisableMeasure MeasureMarket2IconTarget]

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
Substitute="UNCH":"","":"0.00","+":"","-":""
UpdateRate=#RefreshRate#

[MeasureMarketRepeat#ChangePercent]
Measure=WebParser
URL=[MeasureMarketRepeat#]
StringIndex=1
RegExp=#RegExpChangePercent#
StringIndex2=1
Substitute="UNCH":"","":"0.00","%":""
UpdateRate=#RefreshRate#

[MeasureMarketRepeat#ChangePercentForScaling]
Measure=Calc
Formula=MeasureMarketRepeat#ChangePercent
IfBelowValue=0
IfBelowAction=[!SetOption MeterMarketRepeat#ChangeValue FontColor "#FontColorMarketDown#"][!Redraw]
IfAboveValue=0
IfAboveAction=[!SetOption MeterMarketRepeat#ChangeValue FontColor "#FontColorMarketUp#"][!Redraw]