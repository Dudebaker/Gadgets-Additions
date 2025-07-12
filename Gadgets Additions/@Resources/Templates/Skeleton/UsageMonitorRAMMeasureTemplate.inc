; RAMRepeat#
[MeasureRAMRepeat#]
Measure=Plugin
Plugin=UsageMonitor
Alias=RAM
Blacklist=#IgnoreProcesses#
Whitelist=#OnlyProcesses#
Percent=0
Index=Repeat#
Rollup=#GroupProcesses#
Substitute="":"#LANG_USAGE_MONITOR_NOT_AVAILABLE#"
Disabled=#Disabled#

[MeasureRAMRepeat#ForScaling]
Measure=Calc
Formula=MeasureRAMRepeat#