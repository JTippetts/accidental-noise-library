-- Accidental Noise Library
-- Basic Example

celgen=anl.CCellularGenerator(anl.EUCLID)

cell=anl.CImplicitCellular(celgen, -1.0, 1.0, 0.0, 0.0)

fbm=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 8, 1, true)
ac=anl.CImplicitAutoCorrect(fbm,-0.5,0.5)

turb=anl.CImplicitTranslateDomain(cell,ac,0.0,0.0)

colorscale=anl.CRGBACurve(turb,anl.LINEAR)
colorscale:pushPoint(-0.1, 0,0.125,0.25,1)
colorscale:pushPoint(0, 0,0.125,0.25,1)
colorscale:pushPoint(0.35, 0.75,1,0.25,1)
colorscale:pushPoint(1, 1.0,0.75,0.25,1)


rgbaad=anl.CRGBABufferRGBAAdapter(colorscale, anl.SEAMLESS_NONE, anl.SMappingRanges(0,4,0,4,0,4), true, 0)

impad=anl.CImplicitBufferImplicitAdapter(turb, anl.SEAMLESS_NONE, anl.SMappingRanges(0,4,0,4,0,4), true, 0)
erode=anl.CImplicitBufferSimpleErode(impad, 0, 0.35)
blur=anl.CImplicitBufferBlur(erode, 3/256)
bump=anl.CImplicitBufferBumpMap(blur, -1.5, 3.5, 1.5, 0.1, false)

mult=anl.CRGBABufferImplicitBufferMultiply(rgbaad, bump)



i=anl.CArray2Drgba()
i:resize(256,256)

mult:get(i)

anl.saveRGBAArray("img.tga", i)