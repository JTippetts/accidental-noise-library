-- Accidental Noise Library
-- Cellular noise test

celgen=anl.CCellularGenerator(anl.LEASTAXIS)

cell=anl.CImplicitCellular(celgen, -1.0, 1.0, 0.0, 0.0)
vor=anl.CImplicitVoronoi(celgen)

ad=anl.CImplicitBufferImplicitAdapter(cell, anl.SEAMLESS_NONE, anl.SMappingRanges(0,4,0,4,0,4), false, 0)
scale=anl.CImplicitBufferScaleToRange(ad, 0, 1)



i=anl.CArray2Dd()
i:resize(256,256)

scale:get(i)

anl.saveDoubleArray("img.tga", i)