; IOReadRepeat#
[MeasureIOReadRepeat#]
Measure=Plugin
Plugin=UsageMonitor
Alias=IORead
Blacklist=#IgnoreProcesses#
Whitelist=#OnlyProcesses#
Percent=0
Index=Repeat#
Rollup=#GroupProcesses#
Substitute="":"#LANG_USAGE_MONITOR_NOT_AVAILABLE#"
Disabled=#Disabled#

[MeasureIOReadRepeat#ForScaling]
Measure=Calc
Formula=MeasureIOReadRepeat#
