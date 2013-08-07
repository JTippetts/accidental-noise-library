-- Accidental Noise Library
-- Volumetric Terrain


grad=anl.CImplicitGradient(0,0,1,0,0,0)

fbm1=anl.CImplicitFractal(anl.DECARPENTIERSWISS, anl.GRADIENT, anl.QUINTIC, 5, 4, true)
ac1=anl.CImplicitAutoCorrect(fbm1, -0.0625, 0.0625)
scaledom=anl.CImplicitScaleDomain(ac1,1,0,1)

fbm2=anl.CImplicitFractal(anl.RIDGEDMULTI, anl.GRADIENT, anl.QUINTIC, 3, 2, true)
ac2=anl.CImplicitAutoCorrect(fbm2, -0.25, 0.25)

swirl=anl.CImplicitTranslateDomain(scaledom, ac2, 0, 0)

turb=anl.CImplicitTranslateDomain(grad,0.0,swirl,0.0)

ad=anl.CVolumeAdapter(turb, anl.SEAMLESS_NONE, anl.SMappingRanges(0,2,0,1,0,2))

a=anl.CArray3Dd()
a:resize(256,128,256)

ad:get(a)

anl.marchDensityFieldSmoothOBJ(a, 0.5, "test.obj")