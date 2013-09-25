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


