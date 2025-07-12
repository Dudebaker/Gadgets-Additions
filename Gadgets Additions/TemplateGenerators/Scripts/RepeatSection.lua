-- RepeatSection v1.2
-- LICENSE: Creative Commons Attribution-Non-Commercial-Share Alike 3.0
-- Author: alatsombath from 'Ocean', 'Generate Bands' skin
-- Author2: Dudebaker (modified the original version)

function Initialize()
  local index, section, gsub, readFile = 1, {}, string.gsub, io.input(SKIN:ReplaceVariables(SELF:GetOption("ReadFile"))):read("*all")
  local substitution, lowerLimit, upperLimit = SELF:GetOption("Substitution"), SELF:GetNumberOption("LowerLimit") + 1, SELF:GetNumberOption("UpperLimit") + 1
  local evenString, oddString = SELF:GetOption("EvenString", ""), SELF:GetOption("OddString", "")
  local searchString, searchStringAppend, searchStringPrepend = SELF:GetOption("SearchString", ""), SELF:GetOption("SearchStringAppend", ""), SELF:GetOption("SearchStringPrepend", "")

  local tmpAppend, tmpPrepend

  for i = lowerLimit, upperLimit do
    section[index] = gsub(readFile, substitution, i-1)

    if isempty(evenString) and not isempty(oddString) then
      if i % 2 == 0 then
        section[index] = gsub(section[index], evenString, oddString)
      else
        section[index] = gsub(section[index], oddString, evenString)
      end
    end

    if i > 2 then
      if not isempty(searchString) and (not isempty(searchStringAppend) or not isempty(searchStringPrepend)) then
        tmpAppend = searchString
        tmpPrepend = ""

        for j = 1, i-2 do
          tmpAppend = tmpAppend .. searchStringAppend
        end

        for j = 1, i-2 do
          tmpPrepend = tmpPrepend .. searchStringPrepend
        end

        tmpPrepend = tmpPrepend .. searchString

        if not isempty(searchStringAppend) then
          section[index] = gsub(section[index], searchString, tmpAppend)
        end

        if not isempty(searchStringPrepend) then
          section[index] = gsub(section[index], searchString, tmpPrepend)
        end
      end
    end

    index = index + 1
  end
  
  local utf16BomHandler = dofile(SKIN:MakePathAbsolute("Scripts\\utf16BomHandler.lua"))
  utf16BomHandler.write(SKIN:ReplaceVariables(SELF:GetOption("WriteFile")), table.concat(section, "\n\n"))
  
  --local file = io.open(SKIN:ReplaceVariables(SELF:GetOption("WriteFile")), "w")
  --local BOM = '\239\187\191'
  --file:write(BOM)
  --file:write(table.concat(section, "\n\n"))
  --file:close()

  --SKIN:Bang('!Log', 'Created ' .. SELF:GetOption("WriteFile"))
end

function isempty(s)
  return s == nil or s == ''
end