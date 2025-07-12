; MarketRepeat#
[MeterSeparatorMarketRepeat#]
Meter=Image
MeterStyle=StyleDefault | StyleDisabled | StyleScale | StyleLoadingHide | StyleSeparator | StyleMarketSeparator | StyleMarketSeparatorRepeat#

[MeterMarketRepeat#IconBase]
Meter=Image
MeterStyle=StyleDefault | StyleScale | StyleDisabled | StyleName | StyleMarketIcon | StyleLoadingHide
MeasureName=MeasureMarketRepeat#IconBase
PreserveAspectRatio=1
Y=7r

[MeterMarketRepeat#IconBaseScaleFix]
Meter=Image
Solidcolor=0,0,0,0
MeterStyle=StyleSection1Entry1
X=([MeterMarketRepeat#IconBase:X] * #Scale#)
Y=([MeterMarketRepeat#IconBase:Y] * #Scale#)
W=((#Width# - 20) * #Scale#)
H=(48 * #Scale#)
LeftMouseUpAction=[https://www.cnbc.com/quotes/#MarketRepeat##]
MouseOverAction=[!SetOption MeterMarketRepeat#Name FontColor #FontColorValueDefault#][!Update]
MouseLeaveAction=[!SetOption MeterMarketRepeat#Name FontColor ""][!Update]
DynamicVariables=1
ToolTipText=#LANG_CURRENCIES_OPEN# [MeasureMarketRepeat#Name] #LANG_CURRENCIES_IN_BROWSER#

[MeterMarketRepeat#Name]
Meter=String
MeasureName=MeasureMarketRepeat#Name
MeterStyle=StyleDefault | StyleScale | StyleName | StyleMarketName | StyleMarketNameWithIcon | StyleMarketNameWithIconTarget | StyleLoadingHide

[MeterMarketRepeat#IconTarget]
Meter=Image
MeterStyle=StyleDefault | StyleScale | StyleDisabled | StyleValue | StyleMarketIcon | StyleMarketIconTarget | StyleLoadingHide
MeasureName=MeasureMarketRepeat#IconTarget
PreserveAspectRatio=1

[MeterMarketRepeat#Price]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleMarketPriceTitle | StyleLoadingHide
Text=#LANG_CURRENCIES_PRICE#

[MeterMarketRepeat#PriceValue]
Meter=String
MeasureName=MeasureMarketRepeat#Price
MeterStyle=StyleDefault | StyleScale | StyleValue | StyleMarketPrice | StyleLoadingHide
Text=%1 [MeasureMarketRepeat#CurrencyTarget]
DynamicVariables=1

[MeterMarketRepeat#Change]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleMarketChangeTitle | StyleLoadingHide
Text=#LANG_CURRENCIES_CHANGE#

[MeterMarketRepeat#ChangeValue]
Meter=String
MeasureName=MeasureMarketRepeat#Change
MeasureName2=MeasureMarketRepeat#ChangePercentForScaling
MeterStyle=StyleDefault | StyleScale | StyleValue | StyleMarketChangeCombined | StyleLoadingHide