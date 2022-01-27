--
-- Based on code provided by raiguard
--
function GetKey(name, key) return SKIN:GetMeter(name):GetOption(key) end
function Gsub(string, pattern, replacement) return string:gsub(pattern, replacement or '') end

-- Right-pads string 'str' to length 'len' with character 'char' (default = space)
string.rpad = function(str, len, char)
  if char == nil then char = ' ' end
  return str .. string.rep(char, len - #str)
end

-- Extended string.rpad; truncates string and adds an ellipsis if needed
string.rpadex = function(str, len, char)
  if #str > len then str = string.sub(str, 1, len - 3) .. '...' end
  return string.rpad(str, len, char)
end

-- Trims leading and trailing spaces from a string
string.trim = function(str)
  return string.gsub(str, '^%s*(.-)%s*$', '%1')
end

function ParseHWiNFORegOutput(sMeasureName)
  --
  -- This function parses HWiNFO registry info and displays it in the skin editor of choice.
  -- Based on code provided by raiguard and jsmorley.
  --
  local raw = SKIN:GetMeasure(sMeasureName):GetStringValue()
  local fileName = SKIN:GetVariable('@') .. 'Scripts/HWiNFOIndexList.txt'
  local output = ''

  -- match over each group as a whole
  local match_string = '    Sensor(%d-)    .-    (.-)\n    .-    .-    (.-)\n    .-    .-    (.-)\n    .-    .-    (.-)\n'
  for index, sensor, label, value, value_raw in raw:gmatch(match_string) do
    output = output
      .. string.rpad(index, 5)   .. ' '
      .. string.rpadex(string.trim(sensor), 50) .. ' '
      .. string.rpadex(string.trim(label), 40)  .. ' '
      .. value .. '\n'
  end

  if #output == 0 then
    -- no sensor entries; output error message
    output = 'HWiNFO Sensor Entry Index List\n\n'
      .. 'ERROR:  HWiNFO is not configured or is not running.\n'
      .. '        https://github.com/raiguard/ModernGadgets/wiki/HWiNFO-Configuration\n'
  else
    -- create document header/footer
    output = 'HWiNFO Sensor Entry Index List\n\n'
      .. string.rpad('Index', 5)     .. ' '
      .. string.rpad('Sensor', 50)   .. ' '
      .. string.rpad('Label', 40)    .. ' '
      .. 'Value'                     .. '\n'
      .. string.rep('-', 5)          .. ' '
      .. string.rep('-', 50)         .. ' '
      .. string.rep('-', 40)         .. ' '
      .. string.rep('-', 15)         .. '\n'
      .. output
  end

  -- write to the file
  local file = io.open(fileName, 'w')
  file:write(output)
  file:close()

  -- open the page in the browser
  SKIN:Bang('"' .. SKIN:GetVariable('CONFIGEDITOR') .. '" "' .. fileName .. '"')

  return
end
