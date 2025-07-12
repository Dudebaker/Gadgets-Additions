; MarketRepeat#
[MeterMarketRepeat#]
Meter=String
MeterStyle=StyleDefault | StyleDisabled | StyleFrameText
Text=#LANG_STOCKS_SETTINGS_STOCK# Repeat#
LeftMouseUpAction=[!CommandMeasure "MeasureMarketRepeat#" "ExecuteBatch 1"]
MiddleMouseUpAction=[!WriteKeyValue Variables MarketRepeat# ".DJIA" "#VarPath#"]#Regenerate#[!Refresh]
ToolTipTitle=#LANG_STOCKS_SETTINGS_STOCK_TOOLTIP_TITLE#
ToolTipText=#LANG_STOCKS_SETTINGS_STOCK_TOOLTIP_DESC#

[MeterMarketRepeat#Value]
Meter=String
MeterStyle=StyleDefault | StyleDisabled | StyleFrameTextInput | StyleFrameTextInputMedium
Text=#MarketRepeat##
LeftMouseUpAction=[!CommandMeasure "MeasureMarketRepeat#" "ExecuteBatch 1"]
MiddleMouseUpAction=[!WriteKeyValue Variables MarketRepeat# ".DJIA" "#VarPath#"]#Regenerate#[!Refresh]

[MeasureMarketRepeat#]
Measure=Plugin
Plugin=InputText
FontFace=Seqoe UI
StringStyle=Italic
MeterStyle=StyleDefault | StyleDisabled | StyleFrameText
X=[MeterSettingsMarketNamesFrame:X]
Y=[MeterMarketRepeat#Value:Y]
W=[MeterSettingsMarketNamesFrame:W]
H=[MeterMarketRepeat#Value:H]
DefaultValue=#MarketRepeat##
Command1=[!WriteKeyValue Variables MarketRepeat# "$UserInput$" "#VarPath#"]#Regenerate#[!Refresh]