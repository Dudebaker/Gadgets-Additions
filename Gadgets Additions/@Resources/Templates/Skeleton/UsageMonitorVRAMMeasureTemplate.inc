; VRAMRepeat#
[MeasureVRAMRepeat#]
Measure=Plugin
Plugin=UsageMonitor
Alias=VRAM
Blacklist=#IgnoreProcesses#
Whitelist=#OnlyProcesses#
Percent=0
Index=Repeat#
Rollup=#GroupProcesses#
Substitute="":"#LANG_USAGE_MONITOR_NOT_AVAILABLE#"
Disabled=#Disabled#

[MeasureVRAMRepeat#ForScaling]
Measure=Calc
Formula=MeasureVRAMRepeat#