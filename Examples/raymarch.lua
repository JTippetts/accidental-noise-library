
-- Raymarch simple

function raymarch(img, module, domain, step, light)
	local w,h=img:width(), img:height()

	local len=math.sqrt(light.x*light.x+light.y*light.y+light.z*light.z)
	light.x=light.x/len
	light.y=light.y/len
	light.z=light.z/len

	local x,y,z
	for x=0,w-1,1 do
		for y=0,h-1,1 do
			local s=x/w
			local t=y/h
			local nx=domain.x0+s*(domain.x1-domain.x0)
			local ny=domain.y0+t*(domain.y1-domain.y0)
			for nz=domain.z0,domain.z1,step do
				local v=module:get(nx,ny,nz)
				if v>0 then
					local dx,dy,dz=module:get_dx(nx,ny,nz), module:get_dy(nx,ny,nz), module:get_dz(nx,ny,nz)
					local l=math.sqrt(dx*dx+dy*dy+dz*dz)
					dx=dx/l
					dy=dy/l
					dz=dz/l
					local d=dx*light.x+dy*light.y+dz*light.z
					d=d*0.5+0.5
					if d<0 then d=0 end
					if d>1 then d=1 end
					img:set(x,y,d)
					break
				end
			end
		end
	end
end

fbm1=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 3, 2, true)
fbm2=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 3, 2, true)
fbm3=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 3, 2, true)

ac1=anl.CImplicitAutoCorrect(fbm1, -0.5, 0.5)
ac2=anl.CImplicitAutoCorrect(fbm2, -0.5, 0.5)
ac3=anl.CImplicitAutoCorrect(fbm3, -0.5, 0.5)

rnd=anl.KISS()
rnd:setSeedTime()

fbm1:setSeed(rnd:get())
fbm2:setSeed(rnd:get())
fbm3:setSeed(rnd:get())

sphere=anl.CImplicitSphere(1.0, ac1, ac2, ac3)


sphere:setDerivSpacing(0.05)

img=anl.CArray2Dd()
img:resize(256, 256)

raymarch(img, sphere, {x0=-1.25, x1=1.25, y0=-1.25, y1=1.25, z0=-1.25, z1=1.25}, 0.01, {x=-3.5, y=3.5, z=-1.5})

anl.saveDoubleArray("img.png", img)
