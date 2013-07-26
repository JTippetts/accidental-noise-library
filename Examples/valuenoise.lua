-- Accidental Noise Library
-- Generate basic Value noise illustration

t=anl.CTreeContainer()
t:basisFunction("F1", anl.VALUE, anl.QUINTIC, false)

t:implicitBufferImplicitAdapter("Adapter", "F1", anl.SEAMLESS_NONE, anl.SMappingRanges(0,4,0,4,0,4), true, 0)
t:implicitBufferScaleToRange("Scale", "Adapter", 0, 1)

i=anl.CArray2Dd()
i:resize(256,256)

t:getImplicitBufferUnsafe("Scale"):get(i)

anl.saveDoubleArray("img.tga", i)