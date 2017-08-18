[Variables]
; Settings
HideHistory=0
HidePeakGrey=1
HidePeakColored=1
HideBand=0
ImgWidth=72.5
ImgHeight=340
RMSAttack=10
RMSDecay=333
RMSGain=2
FFTSize=1024
FFTAttack=15
FFTDecay=333
; Design Variables
VolumeBarWidth=2
ScrollVolumeSteps=2
FontName=Calibri
FontColorVolumeActive=255,255,255
VolumeBarColor=128,128,128,128
SettingsActiveColor=128,128,128,255
; Fix Variables
FontSize=12
borderSize=1
padding=(#borderSize# * 2)
mtrBr1=(#padding# + #borderSize#)
mtrBr2=(#mtrBr1# + #borderSize#)
mtrBr3=(#mtrBr2# + #borderSize#)
mtrBg=(#mtrBr3# + #borderSize#)
Width=(#ImgWidth# * 2 + #padding# + #mtrBg# * 2)
Height=(#ImgHeight# + #padding# + #mtrBg# * 2)
mtrEQLeft=#mtrBg#
mtrEQRightY=#mtrBg#
mtrEQRightX=(#Width# / 2 - #borderSize#)
UpdateDeviceAndPercentageAndBar=5
; Output
LastKnownOutput=Lautsprecher Klinke
