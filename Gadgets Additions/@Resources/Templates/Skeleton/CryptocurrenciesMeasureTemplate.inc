; MarketRepeat# Measures
[MeasureMarketRepeat#]
Measure=WebParser
DynamicVariables=1
URL=#URLApi##MarketRepeat##
RegExp=#RegExpMarket#
UpdateRate=#RefreshRate#
UserAgent=#UserAgent#
Header=Authorization: Bearer #APIKey#
Disabled=#Disabled#

[MeasureMarketRepeat#Name]
Measure=WebParser
URL=[MeasureMarketRepeat#]
StringIndex=1
RegExp=#RegExpName#
StringIndex2=1
Substitute="":"loading"
UpdateRate=#RefreshRate#

[MeasureMarketRepeat#Symbol]
Measure=WebParser
URL=[MeasureMarketRepeat#]
StringIndex=1
RegExp=#RegExpSymbol#
StringIndex2=1
Substitute="":"generic"
UpdateRate=#RefreshRate#
FinishAction=[!SetVariable MarketRepeat#IconURL #URLIcon#[MeasureStringCase:Lower('[&MeasureMarketRepeat#Symbol]')]#URLIconPostfix#][!EnableMeasure MeasureMarketRepeat#Icon][!DisableMeasure MeasureMarketRepeat#Symbol]
DynamicVariables=1

[MeasureMarketRepeat#Icon]
Measure=WebParser
DynamicVariables=1
URL=#MarketRepeat#IconURL#
Download=1
Substitute="":"#@#Images\Backgrounds\downloading.png"
DownloadFile=MarketRepeat#.png
Disabled=1
UpdateRate=#RefreshRate#+1
UserAgent=#UserAgent#
FinishAction=[!UpdateMeter MeterMarketRepeat#BaseIcon][!Redraw][!DisableMeasure MeasureMarketRepeat#Icon]

[MeasureMarketRepeat#Price]
Measure=WebParser
URL=[MeasureMarketRepeat#]
StringIndex=1
RegExp=#RegExpPrice#
StringIndex2=1
Substitute="":"0.00"
UpdateRate=#RefreshRate#

[MeasureMarketRepeat#PriceForScaling]
Measure=Calc
DynamicVariables=1
Formula=MeasureMarketRepeat#Price

[MeasureMarketRepeat#Change]
Measure=WebParser
URL=[MeasureMarketRepeat#]
StringIndex=1
RegExp=#RegExpChange#
StringIndex2=1
UpdateRate=#RefreshRate#

[MeasureMarketRepeat#ChangeForScaling]
Measure=Calc
DynamicVariables=1
Formula=MeasureMarketRepeat#Change
IfBelowValue=0
IfBelowAction=[!SetOption MeterMarketRepeat#ChangePercentValue FontColor "#FontColorMarketDown#"][!SetOption MeterMarketRepeat#ChangeValue FontColor "#FontColorMarketDown#"][!Redraw]
IfAboveValue=0
IfAboveAction=[!SetOption MeterMarketRepeat#ChangePercentValue FontColor "#FontColorMarketUp#"][!SetOption MeterMarketRepeat#ChangeValue FontColor "#FontColorMarketUp#"][!Redraw]

[MeasureMarketRepeat#Volume]
Measure=WebParser
URL=[MeasureMarketRepeat#]
StringIndex=1
RegExp=#RegExpVolume#
StringIndex2=1
Substitute="":"0.00"
UpdateRate=#RefreshRate#

[MeasureMarketRepeat#VolumeForScaling]
Measure=Calc
DynamicVariables=1
Formula=MeasureMarketRepeat#Volume/1000000
Disabled=((#CountSection1# < 1) ? 1 : 0)