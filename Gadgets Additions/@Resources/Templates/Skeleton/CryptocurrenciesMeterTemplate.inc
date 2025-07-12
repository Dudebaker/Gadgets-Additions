; MarketRepeat#
[MeterSeparatorMarketRepeat#]
Meter=Image
MeterStyle=StyleDefault | StyleDisabled | StyleScale | StyleLoadingHide | StyleSeparator | StyleMarketSeparator | StyleMarketSeparatorRepeat#

[MeterMarketRepeat#BaseIcon]
Meter=Image
MeterStyle=StyleDefault | StyleScale | StyleName | StyleMarketIcon | StyleLoadingHide
MeasureName=MeasureMarketRepeat#Icon
PreserveAspectRatio=1
Y=7r

[MeterMarketRepeat#BaseIconScaleFix]
Meter=Image
Solidcolor=0,0,0,0
X=([MeterMarketRepeat#BaseIcon:X] * #Scale#)
Y=([MeterMarketRepeat#BaseIcon:Y] * #Scale#)
W=((#Width# - 20) * #Scale#)
H=(63 * #Scale#)
LeftMouseUpAction=[#URLAsset##MarketRepeat##]
MouseOverAction=[!SetOption MeterMarketRepeat#Name FontColor #FontColorValueDefault#][!Update]
MouseLeaveAction=[!SetOption MeterMarketRepeat#Name FontColor ""][!Update]
DynamicVariables=1
ToolTipText=#LANG_CRYPTOCURRENCIES_OPEN# [MeasureMarketRepeat#Name] #LANG_CRYPTOCURRENCIES_IN_BROWSER#

[MeterMarketRepeat#Name]
Meter=String
MeasureName=MeasureMarketRepeat#Name
MeterStyle=StyleDefault | StyleScale | StyleName | StyleMarketName | StyleMarketNameWithIcon | StyleMarketNameWithTargetIcon | StyleLoadingHide

[MeterMarketRepeat#TargetIcon]
Meter=Image
MeterStyle=StyleDefault | StyleScale | StyleValue | StyleMarketIcon | StyleMarketIconTarget | StyleLoadingHide
MeasureName=MeasureMarketBaseIcon
PreserveAspectRatio=1

[MeterMarketRepeat#Price]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleMarketPriceTitle | StyleLoadingHide
Text=#LANG_CRYPTOCURRENCIES_PRICE#

[MeterMarketRepeat#PriceValue]
Meter=String
MeasureName=MeasureMarketRepeat#PriceForScaling
MeterStyle=StyleDefault | StyleScale | StyleValue | StyleMarketPrice | StyleLoadingHide
Text=%1 USD
NumOfDecimals=#MarketRepeat#NumOfDecimals#

[MeterMarketRepeat#Change]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleMarketChangeTitle | StyleLoadingHide
Text=#LANG_CRYPTOCURRENCIES_CHANGE_1D#

[MeterMarketRepeat#ChangePercentValue]
Meter=String
MeasureName=MeasureMarketRepeat#ChangeForScaling
MeterStyle=StyleDefault | StyleScale | StyleValue | StyleMarketChangeOwnMeters | StyleMarketChangeOwnMetersPercentCrypto | StyleLoadingHide

[MeterMarketRepeat#Volume]
Meter=String
MeterStyle=StyleDefault | StyleScale | StyleName | StyleMarketChangeTitle | StyleLoadingHide
Text=#LANG_CRYPTOCURRENCIES_VOLUME_1D#

[MeterMarketRepeat#VolumeValue]
Meter=String
MeasureName=MeasureMarketRepeat#VolumeForScaling
MeterStyle=StyleDefault | StyleScale | StyleValue | StyleMarketChangeOwnMeters | StyleMarketChangeOwnMetersVolume | StyleLoadingHide
Text=%1m USD
NumOfDecimals=0