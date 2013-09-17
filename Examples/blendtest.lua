-- Accidental Noise Library
-- Blend example

grad=anl.CImplicitGradient(0,0.5,0,0)
mult=anl.CImplicitMath(anl.MULTIPLY, grad, 1/32.0)
cosine=anl.CImplicitMath(anl.SIN, grad)
scaleoff=anl.CImplicitScaleOffset(cosine,0.5,0.5)

fractal=anl.CImplicitFractal(anl.RIDGEDMULTI, anl.GRADIENT, anl.QUINTIC, 8, 1, true)
ac=anl.CImplicitAutoCorrect(fractal, 0, 1)

celgen=anl.CCellularGenerator(anl.EUCLID)
cell=anl.CImplicitCellular(celgen, -1.0, 1.0, 0.0, 0.0)

blend=anl.CImplicitBlend(cell, ac, scaleoff)

sel1=anl.CImplicitSelect(cell, ac, mult, 0.25, 0)
sel2=anl.CImplicitSelect(sel1, scaleoff, mult, 0.5, 0)
sel3=anl.CImplicitSelect(sel2, blend, mult, 0.75, 0)

adapter=anl.CImplicitBufferImplicitAdapter(sel3, anl.SEAMLESS_NONE, anl.SMappingRanges(0,16,0,4), true, 0)

i=anl.CArray2Dd()
i:resize(1024,256)
adapter:get(i)
anl.saveDoubleArray("img.png", i)
