; CustomRepeat#
[MeasureCustomRepeat#]
Measure=Plugin
Plugin=UsageMonitor
Category=#CustomCategory#
Counter=#CustomCounter#
Blacklist=#IgnoreProcesses#
Whitelist=#OnlyProcesses#
Percent=#CustomPercent#
Index=Repeat#
Rollup=#GroupProcesses#
Substitute="":"#LANG_USAGE_MONITOR_NOT_AVAILABLE#"
Disabled=#Disabled#

[MeasureCustomRepeat#ForScaling]
Measure=Calc
Formula=MeasureCustomRepeat#
