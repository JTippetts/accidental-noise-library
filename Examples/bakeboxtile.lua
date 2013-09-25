require 'baking'

function bakeBoxTileNormal(filename, width, height, func, spacing)
	local a=anl.CArray2Dd(width, height)
	bakeModelImplicit("boxtile.obj", a, func, 2)
	a:scaleToRange(0,1)
	
	local f=anl.CImplicitBufferFile(a)
	local nm=anl.CRGBABufferNormalMap(f,spacing,false)
	local norm=anl.CArray2Drgba(width,height)
	nm:get(norm)
	anl.saveRGBAArray(filename,norm)
end

function bakeBoxTileRGBA(filename, width, height, func)
	local a=anl.CArray2Drgba(width,height)
	bakeModelRGBA("boxtile.obj", a, func, 2)
	
	anl.saveRGBAArray(filename, a)
end

fbm=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 8,3,true)
fbmac=anl.CImplicitAutoCorrect(fbm,0,1)

rgb=anl.CRGBAImplicitGrayscale(fbmac)


bakeBoxTileNormal("normal.png", 256,256, fbm, 0.5)
bakeBoxTileRGBA("color.png", 256,256, rgb)