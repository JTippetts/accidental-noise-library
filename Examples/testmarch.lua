-- Accidental Noise Library
-- Testing marching

sphere=anl.CImplicitSphere(1.0, 0,0,0)
ad=anl.CVolumeAdapter(sphere, anl.SEAMLESS_NONE, anl.SMappingRanges(-1,1,-1,1,-1,1))

a=anl.CArray3Dd()
a:resize(128,128,128)

ad:get(a)

anl.marchDensityFieldOBJ(a, 0.01, "test.obj")