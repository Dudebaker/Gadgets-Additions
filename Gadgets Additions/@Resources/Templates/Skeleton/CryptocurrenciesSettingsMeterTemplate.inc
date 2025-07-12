; MarketRepeat#
[MeterSettingsMarketRepeat#Frame]
Meter=Image
MeterStyle=StyleDefault | StyleDisabled | StyleFrame
H=50

[MeterSettingsMarketRepeat#Title]
Meter=String
MeterStyle=StyleDefault | StyleDisabled | StyleFrameTitle
Text=Currency Repeat#

[MeterMarketRepeat#]
Meter=String
MeterStyle=StyleDefault | StyleDisabled | StyleFrameText
Text=#LANG_CRYPTOCURRENCIES_SETTINGS_CRYPTO#
ToolTipTitle=#LANG_CRYPTOCURRENCIES_SETTINGS_CRYPTO_TOOLTIP_TITLE#
ToolTipText=#LANG_CRYPTOCURRENCIES_SETTINGS_CRYPTO_TOOLTIP_DESC#

[MeterMarketRepeat#Value]
Meter=String
MeterStyle=StyleDefault | StyleDisabled | StyleFrameTextInput | StyleFrameTextInputMedium
Text=#MarketRepeat##
LeftMouseUpAction=[!CommandMeasure MeasureMarketRepeat# "ExecuteBatch 1"]
MiddleMouseUpAction=[!WriteKeyValue Variables MarketRepeat# "bitcoin" "#VarPath#"]#Regenerate#[!Refresh]

[MeasureMarketRepeat#]
Measure=Plugin
Plugin=InputText
FontFace=Seqoe UI
StringStyle=Italic
MeterStyle=StyleDefault | StyleDisabled | StyleFrameText
X=[MeterMarketRepeat#Value:X]
Y=[MeterMarketRepeat#Value:Y]
W=[MeterMarketRepeat#Value:W]
H=[MeterMarketRepeat#Value:H]
DefaultValue=#MarketRepeat##
Command1=[!WriteKeyValue Variables MarketRepeat# "$UserInput$" "#VarPath#"]#Regenerate#[!Refresh]

[MeterMarketRepeat#NumOfDecimals]
Meter=String
MeterStyle=StyleDefault | StyleDisabled | StyleFrameText
Text=#LANG_SETTINGS_DECIMALS#
ToolTipTitle=#LANG_SETTINGS_DECIMALS_TOOLTIP_TITLE#
ToolTipText=#LANG_SETTINGS_DECIMALS_TOOLTIP_DESC#

[MeterMarketRepeat#NumOfDecimalsValue]
Meter=String
MeterStyle=StyleDefault | StyleDisabled | StyleFrameTextInput
Text=#MarketRepeat#NumOfDecimals#
LeftMouseUpAction=[!CommandMeasure MeasureMarketRepeat#NumOfDecimals "ExecuteBatch 1"]
MiddleMouseUpAction=[!WriteKeyValue Variables MarketRepeat#NumOfDecimals "2" "#VarPath#"][!RefreshGroup Cryptocurrencies][!Refresh]

[MeasureMarketRepeat#NumOfDecimals]
Measure=Plugin
Plugin=InputText
FontFace=Seqoe UI
StringStyle=Italic
InputNumber=1
InputLimit=2
X=[MeterMarketRepeat#NumOfDecimalsValue:X]
Y=[MeterMarketRepeat#NumOfDecimalsValue:Y]
W=[MeterMarketRepeat#NumOfDecimalsValue:W]
H=[MeterMarketRepeat#NumOfDecimalsValue:H]
DefaultValue=#MarketRepeat#NumOfDecimals#
Command1=[!WriteKeyValue Variables MarketRepeat#NumOfDecimals "$UserInput$" "#VarPath#"][!RefreshGroup Cryptocurrencies][!Refresh]

[MeterMarketRepeat#NumOfDecimalsPlus]
Meter=Image
MeterStyle=StyleDefault | StyleMarketRepeat#NumOfDecimals
ImageName=#@#Images\Buttons\add.png
X=([MeterScaleValue:X] - 37)
Y=([MeterMarketRepeat#NumOfDecimalsValue:Y] + 2)
W=13
H=13
LeftMouseUpAction=[!WriteKeyValue Variables MarketRepeat#NumOfDecimals (Clamp((#MarketRepeat#NumOfDecimals#+1),0,10)) "#VarPath#"][!RefreshGroup Cryptocurrencies][!Refresh]
ToolTipText=#LANG_SETTINGS_INCREASE#

[MeterMarketRepeat#NumOfDecimalsMinus]
Meter=Image
MeterStyle=StyleDefault | StyleMarketRepeat#NumOfDecimals
ImageName=#@#Images\Buttons\remove.png
X=([MeterScaleValue:X] - 19)
Y=([MeterMarketRepeat#NumOfDecimalsValue:Y] + 2)
W=13
H=13
LeftMouseUpAction=[!WriteKeyValue Variables MarketRepeat#NumOfDecimals (Clamp((#MarketRepeat#NumOfDecimals#-1),0,10)) "#VarPath#"][!RefreshGroup Cryptocurrencies][!Refresh]
ToolTipText=#LANG_SETTINGS_DECREASE#
