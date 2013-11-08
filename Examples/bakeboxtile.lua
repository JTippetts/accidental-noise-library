require 'baking'

function bakeBoxTileNormal(filename, width, height, func, spacing)
	local a=anl.CArray2Dd(width, height)
	bakeModelImplicit("cauldron.obj", a, func, 2)
	a:scaleToRange(0,1)
	
	local f=anl.CImplicitBufferFile(a)
	local nm=anl.CRGBABufferNormalMap(f,spacing,false)
	local norm=anl.CArray2Drgba(width,height)
	nm:get(norm)
	anl.saveRGBAArray(filename,norm)
end

function bakeBoxTileRGBA(filename, width, height, func)
	local a=anl.CArray2Drgba(width,height)
	bakeModelRGBA("cauldron.obj", a, func, 2)
	
	anl.saveRGBAArray(filename, a)
end

rnd=anl.KISS()
rnd:setSeedTime()

f=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 8, 3, true)
fac=anl.CImplicitAutoCorrect(f,-0.125,0.125)

f1=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 8, 3, true)
fac1=anl.CImplicitAutoCorrect(f1,-0.125,0.125)

f2=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 8, 3, true)
fac2=anl.CImplicitAutoCorrect(f2,-0.125,0.125)

fac3=anl.CImplicitAutoCorrect(f2,0,1)
fac4=anl.CImplicitAutoCorrect(f1,0,1)



cellgen=anl.CCellularGenerator()
cell=anl.CImplicitCellular(cellgen, -1, 1, 0, 0)
scale=anl.CImplicitMath(anl.MULTIPLY, cell, math.pi*0.5)
sine=anl.CImplicitMath(anl.SIN, scale, 0)

turb=anl.CImplicitTranslateDomain(sine, fac1, fac, fac2)

sd=anl.CImplicitScaleDomain(turb,6,6,6)

sel=anl.CImplicitSelect(0,1,sd,0.25,0.125)
sine2=anl.CImplicitMath(anl.BIAS, sd, 0.7)
gain=anl.CImplicitMath(anl.GAIN, sine2, 0.85)

rgba=anl.CRGBAImplicitGrayscale(fac4)


bakeBoxTileNormal("normal.png", 512,512, fac3, 0.25)
bakeBoxTileRGBA("color.png", 512,512, rgba)