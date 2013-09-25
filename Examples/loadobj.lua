-- Load OBJ

require 'tokenize'

function loadOBJ(name)
	local data={}
	
	data.verts={}
	data.uvs={}
	data.faces={}
	data.normals={}
	
	local line
	
	local curvert=1
	local curuv=1
	local curface=1
	local curnormal=1
	
	for line in io.lines(name) do
		local tokens=string.tokenize(line)
		
		-- Check first token
		if tokens[1] then
			if tokens[1]=="v" then
				-- Do a vertex
				data.verts[curvert]={x=tonumber(tokens[2]), y=tonumber(tokens[3]), z=tonumber(tokens[4])}
				curvert=curvert+1
			end
			
			if tokens[1]=="vt" then
				-- Do a tex coord
				data.uvs[curuv]={u=tonumber(tokens[2]), v=tonumber(tokens[3])}
				curuv=curuv+1
			end
			
			if tokens[1]=="vn" then
				data.normals[curnormal]={x=tonumber(tokens[2]), y=tonumber(tokens[3]), z=tonumber(tokens[4])}
				curnormal=curnormal+1
			end
			
			if tokens[1]=="f" then
				-- Do a face
				if #tokens>5 then
					print("Error: Too many verts in face")
					return
				end
				
				local c
				data.faces[curface]={}
				data.faces[curface].v={}
				data.faces[curface].t={}
				data.faces[curface].n={}
				for c=2,#tokens,1 do
					local indices=string.split(tokens[c],"/")
					local v,t,n
					if #indices==1 then
						v=tonumber(indices[1])
						t=nil
						n=nil
					elseif #indices==2 then
						v=tonumber(indices[1])
						t=tonumber(indices[2])
						n=nil
					else
						v=tonumber(indices[1])
						t=tonumber(indices[2])
						n=tonumber(indices[3])
					end
					
					data.faces[curface].v[c-1]=v
					data.faces[curface].t[c-1]=t
					data.faces[curface].n[c-1]=n
				end
				curface=curface+1
			end
		end
	end
	
	-- Finished, returnd ata
	return data
end

function saveOBJ(data, name)
	out=io.open(name,"w")
	-- Save verts
	local c
	for c=1,#data.verts,1 do
		out:write("v "..data.verts[c].x.." "..data.verts[c].y.." "..data.verts[c].z.."\n")
	end
	
	for c=1,#data.uvs,1 do
		out:write("vt "..data.uvs[c].u.." "..data.uvs[c].v.."\n")
	end
	
	for c=1,#data.normals,1 do
		out:write("vn "..data.normals[c].x.." " ..data.normals[c].y.." "..data.normals[c].z.."\n")
	end
	
	for c=1,#data.faces,1 do
		out:write("f ")
		local d
		for d=1,#data.faces[c].v,1 do
			out:write(""..data.faces[c].v[d].." ")
			if data.faces[c].t[d] then
				out:write("".."/"..data.faces[c].t[d])
				if data.faces[c].n[d] then
					out:write("".."/"..data.faces[c].n[d])
				end
			end
		end
		out:write("\n")
	end
	
	out:close()
end
