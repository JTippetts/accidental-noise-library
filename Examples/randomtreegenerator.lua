function buildRandomGenerator(levels, nameprefix,seed)
	local s="local b=anl.CTreeContainer()\n"
	s=s.."local rnd=anl.KISS()\n rnd:setSeedTime() \n"
	local rnd=anl.KISS()
	rnd:setSeed(seed)
	
	local nodes=
	{
		-- Constant
		function(name, level)
			s=s.."b:constant(\""..name.."\","..rnd:get01()..") \n"
		end,
		
		-- Cellular
		function(name, level)
			s=s.."b:cellularGenerator(\""..name.."Gen\""..","..rnd:getRange(anl.EUCLID, anl.LEASTAXIS)..") \n"
			s=s.."b:cellular(\""..name.."\",\""..name.."Gen\""..","..(rnd:get01()*2-1)..","..(rnd:get01()*2-1)..","..(rnd:get01()*2-1)..","..(rnd:get01()*2-1)..") \n"
		end,
		
		-- Voronoi
		function(name, level)
			s=s.."b:cellularGenerator(\""..name.."Gen\""..","..rnd:getRange(anl.EUCLID, anl.LEASTAXIS)..")"
			s=s.."b:voronoi(\""..name.."\",\""..name.."Gen\""..") \n"
		end,
		
		-- Fractal
		function(name, level)
			s=s.."b:fractal(\""..name.."frac\","..rnd:getRange(anl.FBM, anl.DECARPENTIERSWISS)..","..rnd:getRange(anl.VALUE, anl.SIMPLEX)
			s=s..","..rnd:getRange(anl.LINEAR, anl.QUINTIC)..","..rnd:getRange(1,8)..","..(rnd:get01()*4+0.1)..","
			if rnd:getRange(1,10)<=5 then s=s.."true" else s=s.."true" end
			s=s..") \n"
			
			s=s.."b:autoCorrect(\""..name.."\",\""..name.."frac\",-1,1) \n"
		end,
		
		
		-- Branch nodes
		--Blend
		function(name, level)
			generateNode(name..'A', level-1)
			generateNode(name..'B', level-1)
			generateNode(name..'C', level-1)
			s=s.."b:blend(\""..name.."\",\""..name..'A'.."\",\""..name..'B'.."\",\""..name..'C'.."\") \n"
		end,
		
		-- Select
		function(name, level)
			generateNode(name..'A', level-1)
			generateNode(name..'B', level-1)
			generateNode(name..'C', level-1)
			generateNode(name..'D', level-1)
			generateNode(name..'E', level-1)
			s=s.."b:select(\""..name.."\",\""..name..'A'.."\",\""..name..'B'.."\",\""..name..'C'.."\",\""..name..'D'.."\",\""..name..'E'.."\") \n"
		end,
		
		-- Unary Math
		function(name, level)
			generateNode(name..'A', level-1)
			s=s.."b:math(\""..name.."\","..rnd:getRange(anl.COS, anl.EASEQUINTIC)..",\""..name..'A'.."\",0) \n"
		end,
		
		-- Binary Math
		function(name, level)
			generateNode(name..'A', level-1)
			generateNode(name..'B', level-1)
			s=s.."b:math(\""..name.."\","..rnd:getRange(anl.COS, anl.EASEQUINTIC)..",\""..name..'A'.."\",\""..name..'B'.."\") \n"
		end,
		
		-- Translate Domain
		function(name, level)
			local tx,ty,tz=false,false,false
			if rnd:getRange(1,10)<=5 then tx=true end
			if rnd:getRange(1,10)<=5 then ty=true end
			if rnd:getRange(1,10)<=5 then tz=true end
			
			generateNode(name..'A', level-1)
			
			if tx then generateNode(name..'B', level-1) end
			if ty then generateNode(name..'C', level-1) end
			if tz then generateNode(name..'D', level-1) end
			
			s=s.."b:translateDomain(\""..name.."\",\""..name..'A'.."\","
			if tx then s=s.."\""..name..'B'.."\"," else s=s.."0," end
			if ty then s=s.."\""..name..'C'.."\"," else s=s.."0," end
			if tz then s=s.."\""..name..'C'.."\"" else s=s.."0" end
			
			s=s..") \n"
		end
	}
	
	function generateNode(name, level)
		if level<=1 then nodes[rnd:getRange(1,4)](name, level-1)
		else nodes[rnd:getRange(5,#nodes)](name, level-1)
		end
	end
	
	generateNode(nameprefix, levels)
	s=s.."b:setSeedAll(rnd:get())\n"
	s=s.."return b, b:getImplicitModule(\""..nameprefix.."\")\n"
	
	local chunk,error=loadstring(s)
	if not chunk then print(s) return end

	local c,m = chunk()
	
	return s,c,m
end
