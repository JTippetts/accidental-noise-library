-- Accidental Noise Library
-- Multicolor http://www.gamedev.net/topic/643968-procedural-terrainworld/

rnd=anl.KISS()
--rnd:setSeedTime()

start=os.clock()

img=anl.CArray2Drgba()
img:resize(512,512)

y=anl.CTreeContainer()

-- channel 1
y:gradient("Grad1", 0,1,0,0,0,0)
y:math("Math1", anl.MULTIPLY, "Grad1", 36.0)
y:math("Math2", anl.COS, "Math1", 0.0)
y:fractal("Fractal1", anl.FBM, anl.GRADIENT, anl.QUINTIC, 8, 3)
y:getImplicitModule("Fractal1"):setSeed(rnd:get())
y:autoCorrect("AutoCorrect1", "Fractal1", -0.25, 0.25)
y:translateDomain("Translate1", "Math2", "AutoCorrect1", 0.0, 0.0)
y:scaleOffset("ScaleOffset1", "Translate1", 0.5, 0.5)

-- channel 2
y:gradient("Grad2", 0,1,0,0,0,0)
y:math("Math3", anl.MULTIPLY, "Grad2", 36.0)
y:math("Math4", anl.COS, "Math3", 0.0)
y:fractal("Fractal2", anl.FBM, anl.GRADIENT, anl.QUINTIC, 8, 3)
y:getImplicitModule("Fractal2"):setSeed(rnd:get())
y:autoCorrect("AutoCorrect2", "Fractal2", -0.25, 0.25)
y:translateDomain("Translate2", "Math4", "AutoCorrect2", 0.0, 0.0)
y:scaleOffset("ScaleOffset2", "Translate2", 0.5, 0.5)

-- channel 3
y:gradient("Grad3", 0,1,0,0,0,0)
y:math("Math5", anl.MULTIPLY, "Grad3", 36.0)
y:math("Math6", anl.COS, "Math5", 0.0)
y:fractal("Fractal3", anl.FBM, anl.GRADIENT, anl.QUINTIC, 8, 3)
y:getImplicitModule("Fractal3"):setSeed(rnd:get())
y:autoCorrect("AutoCorrect3", "Fractal3", -0.25, 0.25)
y:translateDomain("Translate3", "Math6", "AutoCorrect3", 0.0, 0.0)
y:scaleOffset("ScaleOffset3", "Translate3", 0.5, 0.5)

y:rgbaCompositeChannels("RGBA", "ScaleOffset1", "ScaleOffset2", "ScaleOffset3", 1.0, anl.RGB)
y:rgbaBufferRGBAAdapter("O1", "RGBA", anl.SEAMLESS_NONE, anl.SMappingRanges(0,4,0,4,0,4), true, 0)
rgba=y:getRGBABuffer("O1")
rgba:get(img)

anl.saveRGBAArray("multicolor.tga", img)

-- dump some values from the diagonal
aa=y:getRGBAModule("RGBA")
for i=0,2,0.1 do 
        color = aa:get(i,i)
        print(color.x, color.y, color.z, color.w) 
end

-- simple timing
now=os.clock()
print("elapsed: " .. (now - start) .. " seconds")