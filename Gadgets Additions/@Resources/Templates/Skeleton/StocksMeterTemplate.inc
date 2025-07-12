; MarketRepeat#
[MeterSeparatorMarketRepeat#]
Meter=Image
MeterStyle=StyleDefault | StyleDisabled | StyleScale | StyleLoadingHide | StyleSeparator | StyleMarketSeparator | StyleMarketSeparatorRepeat#

[MeterMarketRepeat#]
Meter=String
MeasureName=MeasureMarketRepeat#Name
MeterStyle=StyleDefault | StyleScale | StyleName | StyleMarketName | StyleMarketNameWithOnlyIconTarget | StyleLoadingHide
Y=7r

[MeterMarketRepeat#ScaleFix]
Meter=Image
Solidcolor=0,0,0,0
MeterStyle=StyleSection1Entry1 | StyleLoadingHide
X=([MeterMarketRepeat#:X] * #Scale#)
Y=([MeterMarketRepeat#:Y] * #Scale#)
W=((#Width# - 20) * #Scale#)
H=(48 * #Scale#)
LeftMouseUpAction=[https://www.cnbc.com/quotes/#MarketRepeat##]
MouseOverAction=[!SetOption MeterMarketRepeat# FontColor #FontColorValueDefault#][!Update]
MouseLeaveAction=[!SetOption MeterMarketRepeat# FontColor ""][!Update]
DynamicVariables=1
ToolTipTitle=[MeasureMarketRepeat#Name]
ToolTipText=#LANG_STOCKS_OPEN# #MarketRepeat## #LANG_STOCKS_IN_BROWSER#

[MeterMarketRepeat#Icon]
Meter=Image
MeterStyle=StyleDefault | StyleScale | StyleDisabled | StyleValue | StyleMarketIcon | StyleMarketIconTarget | StyleLoadingHide
MeasureName=MeasureMarketRepeat#Icon
PreserveAspectRatio=1

[MeterMarketRepeat#Price]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleMarketPriceTitle | StyleLoadingHide
Text=#LANG_STOCKS_PRICE#
Y=16r

[MeterMarketRepeat#PriceValue]
Meter=String
MeasureName=MeasureMarketRepeat#Price
MeterStyle=StyleDefault | StyleScale | StyleValue | StyleMarketPrice | StyleLoadingHide
Text=%1 [MeasureMarketRepeat#Currency]

[MeterMarketRepeat#Change]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleMarketChangeTitle | StyleLoadingHide
Text=#LANG_STOCKS_CHANGE#

[MeterMarketRepeat#ChangeValue]
Meter=String
MeasureName=MeasureMarketRepeat#Change
MeasureName2=MeasureMarketRepeat#ChangePercentForScaling
MeterStyle=StyleDefault | StyleScale | StyleValue | StyleMarketChangeCombined | StyleLoadingHide