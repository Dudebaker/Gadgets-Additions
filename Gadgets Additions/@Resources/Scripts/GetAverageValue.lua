-- GetAverageValue
-- @version 1.1.0
-- @autor 	Dudebaker
-- @license Creative Commons Attribution-Noncommercial-Share Alike 3.0 License
 
function Initialize()
	MeasureName 	 = SELF:GetOption('MeasureName', "Measure")
	MeterName 	 	 = SELF:GetOption('MeterName', "Meter")
	MeterTextPrefix  = SELF:GetOption('MeterTextPrefix', "Avg: ")
	MeterTextPostfix = SELF:GetOption('MeterTextPostfix', "unit")
	ReturnDirectly	 = SELF:GetOption('ReturnDirectly', "false")
	RoundValue		 = SELF:GetOption('RoundValue', "0")
	Total = 0
	Counter = 0
end
 
function Update()
	local value
	value = SKIN:GetMeasure(MeasureName):GetValue()

	if(value > 0) then
		Total = Total + value
		Counter = Counter + 1

		if(ReturnDirectly == "true") then
			return round(Total / Counter, RoundValue)
		else
			SKIN:Bang("!SetOption", MeterName, "Text", MeterTextPrefix .. round(Total / Counter, 0) .. MeterTextPostfix)
		end
	end
end

function round(num, numDecimalPlaces)
  local mult = 10^(numDecimalPlaces or 0)
  return math.floor(num * mult + 0.5) / mult
end