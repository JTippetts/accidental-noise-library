-- Accidental Noise Library
-- Islands Example

islandroughness=0.75

-- Ocean floor
oceanbase=anl.CImplicitFractal(anl.RIDGEDMULTI, anl.GRADIENT, anl.QUINTIC, 2, 2, true)
oceanbaseac=anl.CImplicitAutoCorrect(oceanbase,0,0.1375)

oceanturb=anl.CImplicitFractal(anl.RIDGEDMULTI, anl.GRADIENT, anl.QUINTIC, 8, 1, true)
oceanturbac=anl.CImplicitAutoCorrect(oceanturb,-0.5,0.5)

oceanfloor=anl.CImplicitTranslateDomain(oceanbaseac,oceanturbac,0.0,0.0)


-- Island shape
islandturbx=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 8, 2, true)
islandturbxac=anl.CImplicitAutoCorrect(islandturbx, -islandroughness, islandroughness)

islandturby=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 8, 2, true)
islandturbyac=anl.CImplicitAutoCorrect(islandturby, -islandroughness, islandroughness)

islandshapesphere=anl.CImplicitSphere(1,islandturbxac,islandturbyac,0.0)
islandshape=anl.CImplicitMath(anl.EASEQUINTIC, islandshapesphere)



-- Island elevation
islandelevationbase=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 6, 2, true)
islandelevationbaseac=anl.CImplicitAutoCorrect(islandelevationbase, 0, 1)

islandelevationturb=anl.CImplicitTranslateDomain(islandelevationbaseac, oceanturbac,0,0)

islandelevation=anl.CImplicitMath(anl.MULTIPLY, islandelevationturb, islandshape)


-- Island select
--islandselect=anl.CImplicitSelect(oceanfloor, islandelevationbaseac, islandshape, 0.125,0.0625)
islandselect=anl.CImplicitMath(anl.SUM, islandelevation, oceanfloor)




adapter=anl.CImplicitBufferImplicitAdapter(islandselect, anl.SEAMLESS_NONE, anl.SMappingRanges(-1-islandroughness,1+islandroughness, -1-islandroughness,1+islandroughness, -1,1), true, 0)
scale=anl.CImplicitBufferScaleToRange(adapter,0,1)
blur=anl.CImplicitBufferBlur(scale, 5/256)
bump=anl.CImplicitBufferBumpMap(scale,-1.5,3.5,-1.5,0.05,false)


rnd=anl.KISS()
rnd:setSeedTime()

oceanbase:setSeed(rnd:get())
oceanturb:setSeed(rnd:get())
islandturbx:setSeed(rnd:get())
islandturby:setSeed(rnd:get())
islandelevationbase:setSeed(rnd:get())

i=anl.CArray2Dd()
i:resize(1024,1024)
bump:get(i)
anl.saveDoubleArray("img.png", i)
