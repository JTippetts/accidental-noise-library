-- Accidental Noise Library

rnd=anl.KISS()
--rnd:setSeedTime()
rnd:setSeed(1234)

range=anl.SMappingRanges(0,32,0,32,0,32)

cellgen=anl.CCellularGenerator()
cell=anl.CImplicitCellular(cellgen, -1,1,0,0)
cellgen:setSeed(rnd:get())

fbm1=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 8, 2, true)
fbm2=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 8, 2, true)
fbm1:setSeed(rnd:get())
fbm2:setSeed(rnd:get())

fbmac1=anl.CImplicitAutoCorrect(fbm1,-0.5, 0.5)
fbmac2=anl.CImplicitAutoCorrect(fbm2,-0.5, 0.5)

turb=anl.CImplicitTranslateDomain(cell, fbmac1, fbmac2, 0.0)

mtncolor=anl.CRGBACurve(turb,anl.LINEAR)
mtncolor:pushPoint(0, 86/255,105/255,119/255,1)
mtncolor:pushPoint(0.75, 1,1,1,1)
mtncolor:pushPoint(1,1,1,1,1)

mtnelev=anl.CImplicitScaleOffset(turb,0.75,0.5)


fbm3=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 6,0.25,true)
fbmac3=anl.CImplicitAutoCorrect(fbm3,0,1)
fbm3:setSeed(rnd:get())

fbm4=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 4, 1, true)
fbmac4=anl.CImplicitAutoCorrect(fbm4, 0.25,0.45)
fbm4:setSeed(rnd:get())

mtnselect=anl.CImplicitSelect(fbmac4, mtnelev, fbmac3, 0.7, 0.125)

groundcolor=anl.CRGBACurve(fbmac3,anl.LINEAR)
groundcolor:pushPoint(0,130/255,106/255,89/255,1)
groundcolor:pushPoint(0.25,130/255,106/255,89/255,1)
groundcolor:pushPoint(1,26/255,131/255,12/255,1)

mtncolorselect=anl.CRGBASelect(groundcolor, mtncolor, fbmac3, 0.7, 0.125)

sandcolor=anl.CRGBACurve(fbmac3, anl.LINEAR)
sandcolor:pushPoint(0,222/255,187/255,132/255,1)
sandcolor:pushPoint(1,234/255,212/255,108/255,1)

sandfbm=anl.CImplicitFractal(anl.RIDGEDMULTI, anl.GRADIENT, anl.QUINTIC, 4, 0.25, true)
sandfbmac=anl.CImplicitAutoCorrect(sandfbm, 0.25,0.35)
sandscaledomain=anl.CImplicitScaleDomain(sandfbmac, 1, 4,1)
sandfbm:setSeed(rnd:get())

waterselectfbm=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 6, 0.125, true)
waterselectfbmac=anl.CImplicitAutoCorrect(waterselectfbm, 0, 1)

sandselect=anl.CImplicitSelect(sandscaledomain, mtnselect, waterselectfbmac, 0.45, 0.25)
sandcolorselect=anl.CRGBASelect(sandcolor, mtncolorselect, waterselectfbmac, 0.45, 0.25)


waterfrac=anl.CImplicitFractal(anl.BILLOW, anl.GRADIENT, anl.QUINTIC, 6, 0.125, true)
waterfracac=anl.CImplicitAutoCorrect(waterfrac,0.125,0.25)
waterscaledomain=anl.CImplicitScaleDomain(waterfracac,1,6,1)
waterfrac:setSeed(rnd:get())

watercolor=anl.CRGBACurve(fbmac3, anl.LINEAR)
watercolor:pushPoint(0,17/255,121/255,193/255,1)
watercolor:pushPoint(1,101/255,188/255,249/255,1)

waterselect=anl.CImplicitSelect(waterscaledomain, sandselect, waterselectfbmac, 0.25, 0.0625)
watercolorselect=anl.CRGBASelect(watercolor, sandcolorselect, waterselectfbmac, 0.25, 0.0625)

elevationbuf=anl.CImplicitBufferImplicitAdapter(waterselect,anl.SEAMLESS_NONE,range,true,0)
elevationscale=anl.CImplicitBufferScaleToRange(elevationbuf,0,1)
elevationbump=anl.CImplicitBufferBumpMap(elevationscale,-1.5,3.5,-1.5,0.05,false)

colorbuf=anl.CRGBABufferRGBAAdapter(watercolorselect, anl.SEAMLESS_NONE, range, true, 0)
colormult=anl.CRGBABufferImplicitBufferMultiply(colorbuf, elevationbump)


i=anl.CArray2Drgba()
i:resize(1024,1024)

colormult:get(i)

anl.saveRGBAArray("img.tga", i)