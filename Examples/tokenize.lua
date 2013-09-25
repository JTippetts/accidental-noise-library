-- New framework to load an obj file

function string:tokenize()
	local token
	local tokens={}
	for token in string.gmatch(self, "[^%s]+") do
		table.insert(tokens, token)
	end
	return tokens
end

function string:split(delimiter)
	local result={}
	local from=1
	local delim_from, delim_to = string.find(self, delimiter, from)
	while delim_from do
		table.insert(result, string.sub(self, from, delim_from-1))
		from = delim_to +1
		delim_from, delim_to = string.find(self,delimiter,from)
	end
	table.insert(result, string.sub(self,from))
	return result
end
