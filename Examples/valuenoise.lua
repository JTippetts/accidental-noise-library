-- Accidental Noise Library
-- Generate basic Value noise illustration

t=anl.CTreeContainer()
t:basisFunction("F1", anl.VALUE, anl.QUINTIC, false)
t:basisFunction("F2", anl.VALUE, anl.CUBIC, false)
t:basisFunction("F3", anl.VALUE, anl.LINEAR, false)
t:basisFunction("F4", anl.VALUE, anl.NONE, false)

t:gradient("Grad", 0,16,0,0,0,0)

t:select("Sel1", tonumber(0.0), tonumber(1.0), tostring("Grad"), tonumber(0.5), tonumber(0.0))
t:select("Sel2", "F3", "Sel1", "Grad", 0.5, 0)
t:select("Sel3", "F4", "Sel2", "Grad", 0.75, 0)

t:implicitBufferImplicitAdapter("Adapter", "Sel1", anl.SEAMLESS_NONE, anl.SMappingRanges(0,16,0,4,0,4), true, 0)
t:implicitBufferScaleToRange("Scale", "Adapter", 0, 1)

i=anl.CArray2Dd()
i:resize(1024,256)

--t:getImplicitBufferUnsafe("Adapter"):get(i)

anl.saveDoubleArray("img.tga", i)

m=t:getModuleUnsafe("Sel1")

for i=-16,16,0.5 do
	print(m:get(i,0,0))
end