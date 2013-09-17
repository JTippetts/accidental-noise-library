-- Accidental Noise Library
-- Fractal test

rnd=anl.KISS()
rnd:setSeedTime()

img=anl.CArray2Dd()
img:resize(256,256)

for i=1,20,1 do
	f=anl.CImplicitFractal(rnd:getRange(anl.FBM, anl.DECARPENTIERSWISS), rnd:getRange(anl.VALUE, anl.SIMPLEX), rnd:getRange(anl.LINEAR,anl.QUINTIC), 8, 2, true)
	ad=anl.CImplicitBufferImplicitAdapter(f,anl.SEAMLESS_NONE, anl.SMappingRanges(2,4,2,4,2,4), true, 0)
	s=anl.CImplicitBufferScaleToRange(ad,0,1)
	f:setSeed(rnd:get())
	s:get(img)
	anl.saveDoubleArray("img"..i..".png", img)
end
