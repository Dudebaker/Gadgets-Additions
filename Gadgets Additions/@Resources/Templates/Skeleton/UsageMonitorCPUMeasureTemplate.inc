; CPURepeat#
[MeasureCPURepeat#]
Measure=Plugin
Plugin=UsageMonitor
Alias=CPU
Blacklist=#IgnoreProcesses#
Whitelist=#OnlyProcesses#
Percent=1
Index=Repeat#
Rollup=#GroupProcesses#
Substitute="":"#LANG_USAGE_MONITOR_NOT_AVAILABLE#"
Disabled=#Disabled#

[MeasureCPURepeat#ForScaling]
Measure=Calc
Formula=MeasureCPU1
