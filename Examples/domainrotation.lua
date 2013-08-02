-- Accidental Noise Library
-- Domain Rotation Demonstration

f=anl.CImplicitFractal(anl.RIDGEDMULTI, anl.GRADIENT, anl.QUINTIC, 1, 2, false)

ad=anl.CImplicitBufferImplicitAdapter(f,anl.SEAMLESS_NONE, anl.SMappingRanges(2,4,2,4,2,4), true, 0)
s=anl.CImplicitBufferScaleToRange(ad,0,1)

img=anl.CArray2Dd()
img:resize(256,256)

for i=1,4,1 do
	f:setNumOctaves(i)
	s:get(img)
	anl.saveDoubleArray("img"..i..".tga", img)
end

f=anl.CImplicitFractal(anl.RIDGEDMULTI, anl.GRADIENT, anl.QUINTIC, 1, 2, true)

ad=anl.CImplicitBufferImplicitAdapter(f,anl.SEAMLESS_NONE, anl.SMappingRanges(2,4,2,4,2,4), true, 0)
s=anl.CImplicitBufferScaleToRange(ad,0,1)


for i=1,4,1 do
	f:setNumOctaves(i)
	s:get(img)
	anl.saveDoubleArray("img"..(i+4)..".tga", img)
end