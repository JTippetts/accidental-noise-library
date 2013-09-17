-- Accidental Noise Library
-- Generate basic Value noise illustration

b1=anl.CImplicitBasisFunction(anl.SIMPLEX, anl.QUINTIC, false)
b2=anl.CImplicitBasisFunction(anl.SIMPLEX, anl.CUBIC, false)
b3=anl.CImplicitBasisFunction(anl.SIMPLEX, anl.LINEAR, false)
b4=anl.CImplicitBasisFunction(anl.SIMPLEX, anl.NONE, false)

grad=anl.CImplicitGradient(0,16,0,0)

sel1=anl.CImplicitSelect(b4,b3,grad, 0.25, 0)
sel2=anl.CImplicitSelect(sel1,b2,grad,0.5,0)
sel3=anl.CImplicitSelect(sel2,b1,grad,0.75,0)

ad=anl.CImplicitBufferImplicitAdapter(sel3, anl.SEAMLESS_NONE, anl.SMappingRanges(0,16,0,4,0,4), false, 0)
scale=anl.CImplicitBufferScaleToRange(ad, 0, 1)



i=anl.CArray2Dd()
i:resize(1024,256)

scale:get(i)

anl.saveDoubleArray("img.png", i)

