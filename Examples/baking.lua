require 'loadobj'
require 'rasterization'

function sumNeighborsRGBA(x,y,img)
	local i,j
	
	local red,green,blue,alpha=0,0,0,0
	local sum=0
	
	local mw,mh=img:width(), img:height()
	
	for i=x-1,x+1,1 do
		for j=y-1,y+1,1 do
			if i>=0 and i<mw and j>=0 and j<mh then
				local c=img:get(i,j)
				if c.w>0 then
					alpha=alpha+c.w
					red=red+c.x
					green=green+c.y
					blue=blue+c.z
					sum=sum+1
				end
			end
		end
	end
	
	if sum==0 then return anl.SRGBA(0,0,0,0) end
	
	return anl.SRGBA(red/sum, green/sum, blue/sum, alpha/sum)
end

function sumNeighbors(x,y,img)
	local i,j
	
	local total=0
	local sum=0
	
	local mw,mh=img:width(), img:height()
	
	for i=x-1,x+1,1 do
		for j=y-1,y+1,1 do
			if i>=0 and i<mw and j>=0 and j<mh then
				local c=img:get(i,j)

				if c>0 then
					total=total+c
					sum=sum+1
				end
			end
		end
	end
	
	if sum==0 then return 0 end
	
	return total/sum
end

function padImage(img, padding)
	local mw,mh=img:width(), img:height()
	local temp=anl.CArray2Drgba(mw,mh)
	
	local x,y
	local count
	
	for count=1,padding,1 do
		for x=0,mw-1,1 do
			for y=0,mh-1,1 do
				local c=img:get(x,y)
				
				if c.w==0 then
					local sum=sumNeighborsRGBA(x,y,img)
					temp:set(x,y,sum)
				else
					temp:set(x,y,c)
				end
				
				
			end
		end
		
		--copyImage(img,temp)
		img:copyFrom(temp)
		
	end
end

function padArray(img, padding)
	local mw,mh=img:width(), img:height()
	local temp=anl.CArray2Dd(mw,mh)
	
	local x,y
	local count
	
	for count=1,padding,1 do
		for x=0,mw-1,1 do
			for y=0,mh-1,1 do
				local c=img:get(x,y)
				
				if c==0 then
					local sum=sumNeighbors(x,y,img)
					temp:set(x,y,sum)
				else
					temp:set(x,y,c)
				end
				
				
			end
		end
		
		--copyImage(img,temp)
		img:copyFrom(temp)
		
	end
end

function bakeModelImplicit(filename, img, f, padding)
	local obj=loadOBJ(filename)
	
	print("Num verts: "..(#obj.verts))
	print("Num texcoords: "..(#obj.uvs))
	print("Num faces: "..(#obj.faces))
	
	local numfaces=#obj.faces
	local c	
	for c=1,numfaces,1 do
		local face=obj.faces[c]
		local d
		local verts={}
		for d=1,#face.v,1 do
			local facevd=face.v[d]
			local facetd=face.t[d]
			if facevd==nil then print("Facevd==nil @ face "..c.." vert "..d) end
			if facetd==nil then print("Facetd==nil @ face "..c.." vert "..d) end
			
			if obj.uvs[facetd]==nil then print("No uvs for facetd "..facetd.." face "..c.." vert "..d) end
			
			
			verts[d]=
			{
				x=obj.verts[facevd].x, 
				y=obj.verts[facevd].y, 
				z=obj.verts[facevd].z, 
				u=obj.uvs[facetd].u, 
				v=1-obj.uvs[facetd].v
			}
		end
		rasterizeFace(verts[1], verts[2], verts[3], img, f)
		
	end
	print("Done rasterizing, padding image")
	
	obj=nil
	if padding>0 then padArray(img, padding) end
	print("Done")
end

function bakeModelRGBA(filename, img, f, padding)
	local obj=loadOBJ(filename)
	
	print("Num verts: "..(#obj.verts))
	print("Num texcoords: "..(#obj.uvs))
	print("Num faces: "..(#obj.faces))
	
	local numfaces=#obj.faces
	local c	
	for c=1,numfaces,1 do
		local face=obj.faces[c]
		local d
		local verts={}
		for d=1,#face.v,1 do
			local facevd=face.v[d]
			local facetd=face.t[d]
			if facevd==nil then print("Facevd==nil @ face "..c.." vert "..d) end
			if facetd==nil then print("Facetd==nil @ face "..c.." vert "..d) end
			
			if obj.uvs[facetd]==nil then print("No uvs for facetd "..facetd.." face "..c.." vert "..d) end
			
			
			verts[d]=
			{
				x=obj.verts[facevd].x, 
				y=obj.verts[facevd].y, 
				z=obj.verts[facevd].z, 
				u=obj.uvs[facetd].u, 
				v=1-obj.uvs[facetd].v
			}
		end
		rasterizeFace(verts[1], verts[2], verts[3], img, f)
		
	end
	print("Done rasterizing, padding image")
	
	obj=nil
	if padding>0 then padImage(img, padding) end
	print("Done")
end	