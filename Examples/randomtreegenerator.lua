function buildRandomGenerator(levels, nameprefix)
	local s="local b=anl.CTreeContainer()\n"
	s=s.."local rnd=anl.KISS()\n rnd:setSeedTime() \n"
	local rnd=anl.KISS()
	rnd:setSeedTime()
	
	local leaf=
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
			s=s.."b:fractal(\""..name.."\","..rnd:getRange(anl.FBM, anl.DECARPENTIERSWISS)..","..rnd:getRange(anl.VALUE, anl.WHITE)
			s=s..","..rnd:getRange(anl.NONE, anl.QUINTIC)..","..rnd:getRange(1,8)..","..(rnd:get01()*3+0.1)..","
			if rnd:getRange(1,10)<=5 then s=s.."true" else s=s.."false" end
			s=s..") \n"
		end,
	}

	local branch=
	{
		--Blend
		function(name, level)
			generateNode(name..'A', level-1)
			generateNode(name..'B', level-1)
			generateNode(name..'C', level-1)
			s=s.."b:blend(\""..name.."\",\""..name..'A'.."\",\""..name..'B'.."\",\""..name..'C'.."\") \n"
		end,
	}
	
	function generateNode(name, level)
		if level<=1 then leaf[rnd:getRange(1,#leaf)](name, level-1)
		else branch[rnd:getRange(1,#branch)](name, level-1)
		end
	end
	
	generateNode(nameprefix, levels)
	s=s.."b:setSeedAll(rnd:get())\n"
	s=s.."return b, b:getImplicitModule(\""..nameprefix.."\")\n"
	
	local c,m=assert(loadstring(s))()
	
	return s,c,m
end
