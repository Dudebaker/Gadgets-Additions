; IOWriteRepeat#
[MeasureIOWriteRepeat#]
Measure=Plugin
Plugin=UsageMonitor
Alias=IOWrite
Blacklist=#IgnoreProcesses#
Whitelist=#OnlyProcesses#
Percent=0
Index=Repeat#
Rollup=#GroupProcesses#
Substitute="":"#LANG_USAGE_MONITOR_NOT_AVAILABLE#"
Disabled=#Disabled#

[MeasureIOWriteRepeat#ForScaling]
Measure=Calc
Formula=MeasureIOWriteRepeat#
