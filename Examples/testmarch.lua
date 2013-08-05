-- Accidental Noise Library
-- Testing marching

rnd=anl.KISS()
rnd:setSeedTime()

fbm1=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 5, 2, true)
fbm2=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 5, 2, true)
fbm3=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 5, 2, true)

fbm1:setSeed(rnd:get())
fbm2:setSeed(rnd:get())
fbm3:setSeed(rnd:get())

power=0.225

ac1=anl.CImplicitAutoCorrect(fbm1,-power, power)
ac2=anl.CImplicitAutoCorrect(fbm2,-power, power)
ac3=anl.CImplicitAutoCorrect(fbm3,-power, power)

sphere=anl.CImplicitSphere(1.0, ac1, ac2, ac3)
ad=anl.CVolumeAdapter(sphere, anl.SEAMLESS_NONE, anl.SMappingRanges(-1.25,1.25,-1.25,1.25,-1.25,1.25))

a=anl.CArray3Dd()
a:resize(256,256,256)

ad:get(a)

anl.marchDensityFieldOBJ(a, 0.01, "test.obj")