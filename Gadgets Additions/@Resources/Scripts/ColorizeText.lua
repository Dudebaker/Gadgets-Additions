-- Colorizes Text
-- Two options:
-- 	- Random colors each time the lua gets called (MinRGB and MaxRGB work as limiting the random number 0-255)
-- 	- Constant colors based on the byte value (MinRGB and MaxRGB work as modulos)
-- @version 1.0.3
-- @autor 	Dudebaker
-- @license Creative Commons Attribution-Noncommercial-Share Alike 3.0 License
 
function Initialize()
	Count 				= tonumber(SELF:GetOption('Count', 1))
	MeasureName 		= SELF:GetOption('MeasureName', "Measure")
	MeterPrefix 		= SELF:GetOption('MeterPrefix', "Meter")
	MeterNamePostfix	= SELF:GetOption('MeterNamePostfix', "Name")
	MeterValuePostfix	= SELF:GetOption('MeterValuePostfix', "Value")
	ConsistentColor		= tonumber(SELF:GetOption('ConsistentColor', 1))
	AlphaRGB			= tonumber(SELF:GetOption('AlphaRGB', 255))
	MinRGB				= tonumber(SELF:GetOption('MinRGB', 128))
	MaxRGB				= tonumber(SELF:GetOption('MaxRGB', 255))
	
	StringsColors = {}
	table.insert(StringsColors,	{	string = SELF:GetOption('DefaultText', "N/A"), 
									color  = SELF:GetOption('DefaultColor', "255,204,0,")})
		
	-- Add predefined colors
	--table.insert(StringsColors,{string="explorer",color="255,255,255,"})
	--table.insert(StringsColors,{string="Rainmeter",color="255,255,255,"})
	--table.insert(StringsColors,{string="chrome",color="255,255,255,"})
end
 
function Update()
	local i
	local color

	for i = 1, Count do
		color = getColorForString(SKIN:GetMeasure(MeasureName .. i):GetStringValue(), ConsistentColor)
		
		if(color .. AlphaRGB ~= SKIN:GetMeter(MeterPrefix .. i .. MeterValuePostfix):GetOption('FontColor', '0,0,0,0')) then
			SKIN:Bang("!SetOption", MeterPrefix .. i .. MeterValuePostfix, "FontColor", color .. AlphaRGB)
			SKIN:Bang("!SetOption", MeterPrefix .. i .. MeterNamePostfix, "FontColor", color .. AlphaRGB)		
			SKIN:Bang("!SetOption", MeterPrefix .. i .. "Background", "SolidColor", color .. "32")
			SKIN:Bang("!UpdateMeter", MeterPrefix .. i .. "Background")
		end
	end
end

-- Generates a color for a string and stores it in a table
-- @param 	string str 		String to convert
-- @param 	int 			0 for random-, 1 for consistent-color
-- @return 	string 			RGB String (ex. 32,128,64,)
function getColorForString(str, consistentColor)
	local i

	for i = 1, #StringsColors do
		if StringsColors[i].string == str then
			-- Return the cached entry
			return StringsColors[i].color
		end
	end

	local color

	if consistentColor == 1 then
		color = getConsistentColor(str)
	else
		color = math.random(MinRGB,MaxRGB) .. "," .. 
				math.random(MinRGB,MaxRGB) .. "," .. 
				math.random(MinRGB,MaxRGB) .. ","
	end

	table.insert(StringsColors, {string = str, color = color})

	return color
end

-- Get a consistent color from a given string
-- @param 	string str 		String to convert
-- @return 	string 			RGB String (ex. 32,128,64,)
function getConsistentColor(str)
	local lengthMultiplier
	-- Multiplier to get evened out substrings for 3 parts (red, green, blue)
	lengthMultiplier = math.ceil(str:len()/3)

	local color	
	color = ""

	local i
	local part
	local length
	local partColor
	local j	

	-- Go through RGB
	for i = 0, 2 do
		-- Get the evened out substring
		part 		= str:sub(i*lengthMultiplier,lengthMultiplier*(i+1))
		length 		= part:len()
		partColor 	= 0

		-- Go through each character and add up the byte values
		for j = 1, length do
			partColor = partColor + part:byte(j, j)
		end

		if partColor > MaxRGB then
			partColor = partColor % MaxRGB
		end

		if partColor > 255 then
			partColor = partColor % math.random(128,255)
		end	

		color = color .. partColor .. ","
	end	

	return color
end