-- Accidental Noise Library
-- Generate basic White noise illustration

t=anl.CTreeContainer()
t:basisFunction("F1", anl.WHITE, anl.QUINTIC, false)

t:implicitBufferImplicitAdapter("Adapter", "F1", anl.SEAMLESS_NONE, anl.SMappingRanges(0,4,0,4,0,4), true, 0)
t:implicitBufferScaleToRange("Scale", "Adapter", 0, 1)

i=anl.CArray2Dd()
i:resize(256,256)

t:getImplicitBuffer("Scale"):get(i)

anl.saveDoubleArray("img.png", i)

m=t:getImplicitModule("F1")

for i=0,2,0.1 do print(m:get(i,i,i)) end
