-- Accidental Noise Library
-- CImplicitCurve test

g=anl.CImplicitGradient(0,1,0,0)
c=anl.CImplicitCurve(g, anl.QUINTIC)

c:pushPoint(0,0.25)
c:pushPoint(0.5, 1)
c:pushPoint(1,0)

ad=anl.CImplicitBufferImplicitAdapter(c, anl.SEAMLESS_NONE, anl.SMappingRanges(-0.5,1.5, 0,1, 0,1), true, 0)

i=anl.CArray2Dd()
i:resize(256,256)

ad:get(i)
anl.saveDoubleArray("img.png", i)
