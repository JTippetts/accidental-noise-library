-- Rasterization

require 'class'

Edge=class(function(self, x1, y1, p1, x2, y2, p2)
	if y1 < y2 then
		self.p1=p1
		self.x1=x1
		self.y1=y1
		self.p2=p2
		self.x2=x2
		self.y2=y2
	else
		self.p1=p2
		self.x1=x2
		self.y1=y2
		self.p2=p1
		self.x2=x1
		self.y2=y1
	end
end)

function drawTriangle(x1,y1,p1, x2,y2,p2, x3,y3,p3, img, func)
	local X1=math.floor(x1)
	local Y1=math.floor(y1)
	local X2=math.floor(x2)
	local Y2=math.floor(y2)
	local X3=math.floor(x3)
	local Y3=math.floor(y3)
	
	local edges={
		Edge(X1,Y1,p1, X2,Y2,p2),
		Edge(X2,Y2,p2, X3,Y3,p3),
		Edge(X3,Y3,p3, X1,Y1,p1)
	}
	
	local maxLength=0
	local longEdge=0
	
	local i
	for i=1,3,1 do
		local length=edges[i].y2 - edges[i].y1
		if length>maxLength then
			maxLength=length
			longEdge=i
		end
	end
	
	local shortEdge1=(longEdge % 3)+1
	local shortEdge2=(longEdge+1) %3 + 1
	
	drawSpansBetweenEdges(edges[longEdge], edges[shortEdge1], img, func)
	drawSpansBetweenEdges(edges[longEdge], edges[shortEdge2], img, func)
end

Span=class(function(self, x1, p1, x2,p2)
	if x1<x2 then
		self.p1=p1
		self.x1=x1
		self.p2=p2
		self.x2=x2
	else
		self.p1=p2
		self.x1=x2
		self.p2=p1
		self.x2=x1
	end
end)

function interpPoint(p1, p2, t)
	return {x=p1.x+t*(p2.x-p1.x), y=p1.y+t*(p2.y-p1.y), z=p1.z+t*(p2.z-p1.z)}
end

function drawSpansBetweenEdges(e1, e2, img, func)
	local e1ydiff=(e1.y2-e1.y1)
	if e1ydiff==0 then return end
	
	local e2ydiff=(e2.y2-e1.y1)
	if e2ydff==0 then return end
	
	local e1xdiff = (e1.x2-e1.x1)
	local e2xdiff = (e2.x2-e2.x1)
	
	local factor1 = (e2.y1-e1.y1)/e1ydiff
	local factorStep1 = 1.0 / e1ydiff
	local factor2 = 0
	local factorStep2 = 1.0 / e2ydiff
	
	local y
	for y=e2.y1, e2.y2-1, 1 do
		local span=Span(e1.x1 + math.floor(e1xdiff*factor1), interpPoint(e1.p1, e1.p2, factor1), e2.x1+math.floor(e2xdiff*factor2), interpPoint(e2.p1, e2.p2, factor2))
		drawSpan(span, y, img, func)
		
		factor1=factor1+factorStep1
		factor2=factor2+factorStep2
	end
end

function drawSpan(span, y, img, func)
	local xdiff=span.x2-span.x1
	if xdiff==0 then return end
	
	local factor=0
	local factorStep=1.0 / xdiff
	local x
	for x=span.x1, span.x2-1, 1 do
		--setPixel(x,y, interpPoint(span.p1, span.p2, factor))
		local p=interpPoint(span.p1, span.p2, factor)
		img:set(x,y, func:get(p.x, p.y, p.z))
		factor=factor+factorStep
	end
end

function rasterizeFace(vert1, vert2, vert3, img, func)
	local mw,mh=img:width(), img:height()
	
	drawTriangle(vert1.u*(mw-1), vert1.v*(mh-1),  vert1, vert2.u*(mw-1), vert2.v*(mh-1), vert2, vert3.u*(mw-1), vert3.v*(mh-1), vert3, img, func)
end


--------------------

-- New rasterization stuff

function orient2d(a,b,c)
	return (b.u-a.u)*(c.v-a.v) - (b.v-a.v)*(c.u-a.u)
end

function rasterizeFace2(v0,v1,v2,img,func)
	local minu=math.min(v0.u,v1.u,v2.u)
	local maxu=math.max(v0.u,v1.u,v2.u)
	local minv=math.min(v0.v,v1.v,v2.v)
	local maxv=math.max(v0.v,v1.v,v2.v)
	
	minu=math.floor(math.max(minu,0))
	maxu=math.floor(math.min(maxu,img:width()-1))
	minv=math.floor(math.max(minv,0))
	maxv=math.floor(math.min(maxv,img:height()-1))
	
	print(minu..","..minv.."->"..maxu..","..maxv)
	--print(v0.u..","..v0.v)
	
	local p={x=0,y=0,z=0,u=0,v=0}
	local u,v
	
	local U={u=v1.u-v0.u, v=v1.v-v0.v, x=v1.x-v0.x, y=v1.y-v0.y, z=v1.z-v0.z}
	local V={u=v2.u-v0.u, v=v2.v-v0.v, x=v2.x-v0.x, y=v2.y-v0.y, z=v2.z-v0.z}
	
	for v=minv,maxv,1 do
		for u=minu,maxu,1 do
			p.u=u
			p.v=v
			--[[local w0,w1=bary2d(v0,v1,v2,p)
			local w2=w0+w1
			if w0>=0 and w1>=0 and w2<=1 then
				p.x=v0.x + w0*U.x + w1*V.x
				p.y=v0.y + w0*U.y + w1*V.y
				p.z=v0.z + w0*U.z + w1*V.z
				img:set(u,v,func:get(p.x,p.y,p.z))
			end]]
			
			local w0=orient2d(v1,v2,p)
			local w1=orient2d(v2,v0,p)
			local w2=orient2d(v0,v1,p)
			local sum=w0+w1+w2
			w0=w0/sum
			w1=w1/sum
			w2=w2/sum
			
			
			if w0>=0 and w1>=0 and w2>=0 then
				p.x=(w0*v0.x + w1*v1.x + w2*v2.x)
				p.y=(w0*v0.y + w1*v1.y + w2*v2.y)
				p.z=(w0*v0.z + w1*v1.z + w2*v2.z)
				--print(p.x..","..p.y..","..p.z)
				img:set(p.u, p.v, func:get(p.x,p.y,p.z))
			end
			
			
		end
	end
	
end


