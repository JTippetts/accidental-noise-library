local N = 10
local ave = 0
local times = 1000000
for i = 0, N do

	local obj = Set_get() 


	local t0 = os.clock()
	for i=1,times do
		obj:set(i)
		if(obj:get() ~= i)then
			error("failed")
		end
	end
	local dt = os.clock()-t0
	if i~=0 then
	 ave = ave + dt
	end

end

print('Luabind access (average elapsed time):',ave/N)