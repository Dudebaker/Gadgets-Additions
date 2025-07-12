; GPURepeat#
[MeasureGPURepeat#]
Measure=Plugin
Plugin=UsageMonitor
Alias=GPU
Blacklist=#IgnoreProcesses#
Whitelist=#OnlyProcesses#
Percent=0
MinValue=0.0
MaxValue=100.0
Index=Repeat#
Rollup=#GroupProcesses#
Substitute="":"#LANG_USAGE_MONITOR_NOT_AVAILABLE#"
Disabled=#Disabled#

[MeasureGPURepeat#ForScaling]
Measure=Calc
Formula=MeasureGPURepeat#
