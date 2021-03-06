-- Colorizes multiple Blocks
-- @version 1.0.2
-- @autor 	Dudebaker
-- @license Creative Commons Attribution-Noncommercial-Share Alike 3.0 License
 
function Initialize()
	Rows 				= tonumber(SELF:GetOption('Rows', 1))
	Columns				= tonumber(SELF:GetOption('Columns', 1))
	MeasurePrefix 		= SELF:GetOption('MeasurePrefix', "Measure")
	MeterRowPrefix 		= SELF:GetOption('MeterRowPrefix', "MeterRow")
	MeterRowColInfix	= SELF:GetOption('MeterRowColInfix', "Column")	
end

function Update()
	local i
	local j
	local color
	local count
	count = 0

	for i = 1, Rows do
		for j = 1, Columns do
			count = count + 1
			color = getRainbowColorForPercent(SKIN:GetMeasure(MeasurePrefix .. count):GetValue() * 100)

			if(color ~= SKIN:GetMeter(MeterRowPrefix .. i .. MeterRowColInfix .. j):GetOption('BarColor', '0,0,0,0')) then
				SKIN:Bang("!SetOption", MeterRowPrefix .. i .. MeterRowColInfix .. j, "BarColor", color)
			end
		end
	end
end

function getRainbowColorForPercent(value)
	-- RGB Source: https://www.ncl.ucar.edu/Document/Graphics/ColorTables/rainbow.shtml
	-- 188 Steps
	if value > 99 then
	    return "255,0,0," .. value
	elseif value > 98.5 then
	    return "255,12,0," .. value
	elseif value > 98 then
	    return "255,17,0," .. value
	elseif value > 97.5 then
	    return "255,21,0," .. value
	elseif value > 97 then
	    return "255,29,0," .. value
	elseif value > 96.5 then
	    return "255,34,0," .. value
	elseif value > 96 then
	    return "255,38,0," .. value
	elseif value > 95.5 then
	    return "255,51,0," .. value
	elseif value > 95 then
	    return "255,55,0," .. value
	elseif value > 94.5 then
	    return "255,59,0," .. value
	elseif value > 94 then
	    return "255,63,0," .. value
	elseif value > 93.5 then
	    return "255,76,0," .. value
	elseif value > 93 then
	    return "255,80,0," .. value
	elseif value > 92.5 then
	    return "255,85,0," .. value
	elseif value > 92 then
	    return "255,89,0," .. value
	elseif value > 91.5 then
	    return "255,97,0," .. value
	elseif value > 91 then
	    return "255,102,0," .. value
	elseif value > 90.5 then
	    return "255,106,0," .. value
	elseif value > 90 then
	    return "255,110,0," .. value
	elseif value > 89.5 then
	    return "255,119,0," .. value
	elseif value > 89 then
	    return "255,127,0," .. value
	elseif value > 88.5 then
	    return "255,131,0," .. value
	elseif value > 88 then
	    return "255,144,0," .. value
	elseif value > 87.5 then
	    return "255,148,0," .. value
	elseif value > 87 then
	    return "255,153,0," .. value
	elseif value > 86.5 then
	    return "255,161,0," .. value
	elseif value > 86 then
	    return "255,165,0," .. value
	elseif value > 85.5 then
	    return "255,170,0," .. value
	elseif value > 85 then
	    return "255,174,0," .. value
	elseif value > 84.5 then
	    return "255,178,0," .. value
	elseif value > 84 then
	    return "255,187,0," .. value
	elseif value > 83.5 then
	    return "255,191,0," .. value
	elseif value > 83 then
	    return "255,199,0," .. value
	elseif value > 82.5 then
	    return "255,212,0," .. value
	elseif value > 82 then
	    return "255,216,0," .. value
	elseif value > 81.5 then
	    return "255,221,0," .. value
	elseif value > 81 then
	    return "255,229,0," .. value
	elseif value > 80.5 then
	    return "255,233,0," .. value
	elseif value > 80 then
	    return "255,238,0," .. value
	elseif value > 79.5 then
	    return "255,242,0," .. value
	elseif value > 79 then
	    return "255,250,0," .. value
	elseif value > 78.5 then
	    return "255,255,0," .. value
	elseif value > 78 then
	    return "250,255,0," .. value
	elseif value > 77.5 then
	    return "246,255,0," .. value
	elseif value > 77 then
	    return "242,255,0," .. value
	elseif value > 76.5 then
	    return "225,255,0," .. value
	elseif value > 76 then
	    return "221,255,0," .. value
	elseif value > 75.5 then
	    return "212,255,0," .. value
	elseif value > 75 then
	    return "208,255,0," .. value
	elseif value > 74.5 then
	    return "203,255,0," .. value
	elseif value > 74 then
	    return "199,255,0," .. value
	elseif value > 73.5 then
	    return "191,255,0," .. value
	elseif value > 73 then
	    return "187,255,0," .. value
	elseif value > 72.5 then
	    return "182,255,0," .. value
	elseif value > 72 then
	    return "178,255,0," .. value
	elseif value > 71.5 then
	    return "165,255,0," .. value
	elseif value > 71 then
	    return "161,255,0," .. value
	elseif value > 70.5 then
	    return "153,255,0," .. value
	elseif value > 70 then
	    return "144,255,0," .. value
	elseif value > 69.5 then
	    return "140,255,0," .. value
	elseif value > 69 then
	    return "135,255,0," .. value
	elseif value > 68.5 then
	    return "131,255,0," .. value
	elseif value > 68 then
	    return "123,255,0," .. value
	elseif value > 67.5 then
	    return "119,255,0," .. value
	elseif value > 67 then
	    return "114,255,0," .. value
	elseif value > 66.5 then
	    return "110,255,0," .. value
	elseif value > 66 then
	    return "97,255,0," .. value
	elseif value > 65.5 then
	    return "93,255,0," .. value
	elseif value > 65 then
	    return "89,255,0," .. value
	elseif value > 64.5 then
	    return "76,255,0," .. value
	elseif value > 64 then
	    return "72,255,0," .. value
	elseif value > 63.5 then
	    return "67,255,0," .. value
	elseif value > 63 then
	    return "63,255,0," .. value
	elseif value > 62.5 then
	    return "55,255,0," .. value
	elseif value > 62 then
	    return "51,255,0," .. value
	elseif value > 61.5 then
	    return "46,255,0," .. value
	elseif value > 61 then
	    return "42,255,0," .. value
	elseif value > 60.5 then
	    return "29,255,0," .. value
	elseif value > 60 then
	    return "25,255,0," .. value
	elseif value > 59.5 then
	    return "21,255,0," .. value
	elseif value > 59 then
	    return "12,255,0," .. value
	elseif value > 58.5 then
	    return "8,255,0," .. value
	elseif value > 58 then
	    return "0,255,0," .. value
	elseif value > 57.5 then
	    return "0,255,8," .. value
	elseif value > 57 then
	    return "0,255,12," .. value
	elseif value > 56.5 then
	    return "0,255,16," .. value
	elseif value > 56 then
	    return "0,255,21," .. value
	elseif value > 55.5 then
	    return "0,255,25," .. value
	elseif value > 55 then
	    return "0,255,38," .. value
	elseif value > 54.5 then
	    return "0,255,42," .. value
	elseif value > 54 then
	    return "0,255,46," .. value
	elseif value > 53.5 then
	    return "0,255,55," .. value
	elseif value > 53 then
	    return "0,255,59," .. value
	elseif value > 52.5 then
	    return "0,255,63," .. value
	elseif value > 52 then
	    return "0,255,76," .. value
	elseif value > 51.5 then
	    return "0,255,80," .. value
	elseif value > 51 then
	    return "0,255,84," .. value
	elseif value > 50.5 then
	    return "0,255,89," .. value
	elseif value > 50 then
	    return "0,255,102," .. value
	elseif value > 49.5 then
	    return "0,255,106," .. value
	elseif value > 49 then
	    return "0,255,110," .. value
	elseif value > 48.5 then
	    return "0,255,114," .. value
	elseif value > 48 then
	    return "0,255,123," .. value
	elseif value > 47.5 then
	    return "0,255,127," .. value
	elseif value > 47 then
	    return "0,255,131," .. value
	elseif value > 46.5 then
	    return "0,255,135," .. value
	elseif value > 46 then
	    return "0,255,144," .. value
	elseif value > 45.5 then
	    return "0,255,152," .. value
	elseif value > 45 then
	    return "0,255,157," .. value
	elseif value > 44.5 then
	    return "0,255,170," .. value
	elseif value > 44 then
	    return "0,255,174," .. value
	elseif value > 43.5 then
	    return "0,255,178," .. value
	elseif value > 43 then
	    return "0,255,187," .. value
	elseif value > 42.5 then
	    return "0,255,191," .. value
	elseif value > 42 then
	    return "0,255,195," .. value
	elseif value > 41.5 then
	    return "0,255,199," .. value
	elseif value > 41 then
	    return "0,255,203," .. value
	elseif value > 40.5 then
	    return "0,255,212," .. value
	elseif value > 40 then
	    return "0,255,216," .. value
	elseif value > 39.5 then
	    return "0,255,225," .. value
	elseif value > 39 then
	    return "0,255,238," .. value
	elseif value > 38.5 then
	    return "0,255,242," .. value
	elseif value > 38 then
	    return "0,255,246," .. value
	elseif value > 37.5 then
	    return "0,255,255," .. value
	elseif value > 37 then
	    return "0,250,255," .. value
	elseif value > 36.5 then
	    return "0,246,255," .. value
	elseif value > 36 then
	    return "0,242,255," .. value
	elseif value > 35.5 then
	    return "0,233,255," .. value
	elseif value > 35 then
	    return "0,229,255," .. value
	elseif value > 34.5 then
	    return "0,225,255," .. value
	elseif value > 34 then
	    return "0,220,255," .. value
	elseif value > 33.5 then
	    return "0,216,255," .. value
	elseif value > 33 then
	    return "0,199,255," .. value
	elseif value > 32.5 then
	    return "0,195,255," .. value
	elseif value > 32 then
	    return "0,187,255," .. value
	elseif value > 31.5 then
	    return "0,182,255," .. value
	elseif value > 31 then
	    return "0,178,255," .. value
	elseif value > 30.5 then
	    return "0,174,255," .. value
	elseif value > 30 then
	    return "0,165,255," .. value
	elseif value > 29.5 then
	    return "0,161,255," .. value
	elseif value > 29 then
	    return "0,157,255," .. value
	elseif value > 28.5 then
	    return "0,152,255," .. value
	elseif value > 28 then
	    return "0,140,255," .. value
	elseif value > 27.5 then
	    return "0,135,255," .. value
	elseif value > 27 then
	    return "0,127,255," .. value
	elseif value > 26.5 then
	    return "0,119,255," .. value
	elseif value > 26 then
	    return "0,114,255," .. value
	elseif value > 25.5 then
	    return "0,110,255," .. value
	elseif value > 25 then
	    return "0,106,255," .. value
	elseif value > 24.5 then
	    return "0,97,255," .. value
	elseif value > 24 then
	    return "0,93,255," .. value
	elseif value > 23.5 then
	    return "0,89,255," .. value
	elseif value > 23 then
	    return "0,84,255," .. value
	elseif value > 22.5 then
	    return "0,72,255," .. value
	elseif value > 22 then
	    return "0,67,255," .. value
	elseif value > 21.5 then
	    return "0,63,255," .. value
	elseif value > 21 then
	    return "0,51,255," .. value
	elseif value > 20.5 then
	    return "0,46,255," .. value
	elseif value > 20 then
	    return "0,42,255," .. value
	elseif value > 19.5 then
	    return "0,38,255," .. value
	elseif value > 19 then
	    return "0,29,255," .. value
	elseif value > 18.5 then
	    return "0,25,255," .. value
	elseif value > 18 then
	    return "0,21,255," .. value
	elseif value > 17.5 then
	    return "0,16,255," .. value
	elseif value > 17 then
	    return "0,4,255," .. value
	elseif value > 16.5 then
	    return "0,0,255," .. value
	elseif value > 16 then
	    return "4,0,255," .. value
	elseif value > 15.5 then
	    return "12,0,255," .. value
	elseif value > 15 then
	    return "16,0,255," .. value
	elseif value > 14.5 then
	    return "25,0,255," .. value
	elseif value > 14 then
	    return "33,0,250," .. value
	elseif value > 13.5 then
	    return "36,0,245," .. value
	elseif value > 13 then
	    return "40,0,241," .. value
	elseif value > 12.5 then
	    return "43,0,236," .. value
	elseif value > 12 then
	    return "46,0,232," .. value
	elseif value > 11.5 then
	    return "55,0,223," .. value
	elseif value > 11 then
	    return "58,0,218," .. value
	elseif value > 10 then
	    return "60,0,214," .. value
	elseif value > 9 then
	    return "66,0,209," .. value
	elseif value > 8 then
	    return "68,0,204," .. value
	elseif value > 7 then
	    return "70,0,200," .. value
	elseif value > 6 then
	    return "76,0,191," .. value
	elseif value > 5 then
	    return "77,0,186," .. value
	elseif value > 4 then
	    return "78,0,182," .. value
	elseif value > 3 then
	    return "79,0,177," .. value
	elseif value > 2 then
	    return "84,0,168," .. value
	elseif value > 1 then
	    return "84,0,163," .. value
	else
	    return "84,0,159," .. value
	end
end