-- Colorizes Text
-- Two options:
-- 	- Random colors each time the lua gets called (MinRGB and MaxRGB work as limiting the random number 0-255)
-- 	- Constant colors based on the byte value (MinRGB and MaxRGB work as modulos)
-- @version 1.0.0
-- @autor 	Dudebaker
-- @license Creative Commons Attribution-Noncommercial-Share Alike 3.0 License
 
function Initialize()
	Count 			  = SELF:GetOption('Count', 1)
	MeasureName 	  = SELF:GetOption('MeasureName', "Measure")
	MeterPrefix 	  = SELF:GetOption('MeterPrefix', "Meter")
	MeterNamePostfix  = SELF:GetOption('MeterNamePostfix', "Name")
	MeterValuePostfix = SELF:GetOption('MeterValuePostfix', "Value")
	ConsistentColor	  = tonumber(SELF:GetOption('ConsistentColor', 1))
	AlphaRGB   	  	  = tonumber(SELF:GetOption('AlphaRGB', 255))
	MinRGB 			  = tonumber(SELF:GetOption('MinRGB', 128))
	MaxRGB 			  = tonumber(SELF:GetOption('MaxRGB', 255))
	
	StringsColors = {}
	table.insert(StringsColors, {string = SELF:GetOption('DefaultText', "N/A"), 
								 color  = SELF:GetOption('DefaultColor', "255,204,0,")})
end

function Update()
	for i=1,Count do
		-- We have to use the measure since the meter doesn't return the string value (why? don't know...)
		String 	   = SKIN:GetMeasure(MeasureName .. i):GetStringValue()
		Color 	   = getColorForString(String, ConsistentColor)

		Meter 	   = SKIN:GetMeter(MeterPrefix .. i .. MeterValuePostfix)
		MeterColor = Meter:GetOption('FontColor', '0,0,0,0')

		if(MeterColor ~= Color) then
			SKIN:Bang("!SetOption", MeterPrefix .. i .. MeterValuePostfix, "FontColor", Color .. AlphaRGB)
			SKIN:Bang("!SetOption", MeterPrefix .. i .. MeterNamePostfix, "FontColor", Color .. AlphaRGB)		
			SKIN:Bang("!SetOption", MeterPrefix .. i .. "Background", "SolidColor", Color .. "32")
			SKIN:Bang("!UpdateMeter", MeterPrefix .. i .. "Background")
		end
	end
end

-- Generates a color for a string and stores it in a table
-- @param 	string str 		String to convert
-- @param 	int     		0 for random-, 1 for consistent-color
-- @return 	string 			RGB String (ex. 32,128,64,)
function getColorForString(str, consistentColor)
	for i = 1, #StringsColors do
		if StringsColors[i].string == str then
			-- Return the cached entry
			return StringsColors[i].color
		end
	end

	if consistentColor == 1 then
		Color = getConsistentColor(str)
	else
		Color = math.random(MinRGB,MaxRGB) .. "," .. 
			    math.random(MinRGB,MaxRGB) .. "," .. 
				math.random(MinRGB,MaxRGB) .. ","
	end

	table.insert(StringsColors, {string = str, color = Color})

	-- Return the count of the table (=the new generated index)
	return StringsColors[#StringsColors].color
end

-- Get a consistent color from a given string
-- @param 	string str 		String to convert
-- @return 	string 			RGB String (ex. 32,128,64,)
function getConsistentColor(str)
	-- Multiplier to get evened out substrings for 3 parts (red, green, blue)
	LengthMultiplier = math.ceil(str:len()/3)
	Color = ""

	-- Go through RGB
	for i = 0, 2 do
		-- Get the evened out substring
		Part 	  = str:sub(i*LengthMultiplier,LengthMultiplier*(i+1))
		Length    = Part:len()
		PartColor = 0

		-- Go through each character and add up the byte values
		for j = 1, Length do
			PartColor = PartColor + Part:byte(j, j)
		end

		if PartColor > MaxRGB then
			PartColor = PartColor % MaxRGB
		elseif PartColor < MinRGB then
			PartColor = PartColor % MinRGB
		end

		if PartColor > 255 then
			PartColor = PartColor % math.random(128,255)
		end	

		Color = Color .. PartColor .. ","
	end	

	return Color
end