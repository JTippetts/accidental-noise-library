# CImplicitFractal #

The CImplicitFractal module implements various types of fractal noise, or noise built up from successive layers of basis function output. The module allows the user to specify at creation:

  * Fractal type, one of FBM, RIDGEDMULTI, BILLOW, HYBRIDMULTI or [DECARPENTIERSWISS](http://www.decarpentier.nl/scape-procedural-extensions)
  * [Basis type](CImplicitBasisFunction.md), one of VALUE, GRADIENT, GRADVAL or SIMPLEX
  * [Interpolation type](CImplicitBasisFunction.md), one of NONE, LINEAR, CUBIC or QUINTIC
  * Number of octaves, or layers; up to a maximum of 20, specified in **implicitmodulebase.h** as MaxSources.
  * Frequency
  * [Rotate domain](DomainRotation.md) (boolean); should each layer use a domain rotation?

The fractal holds an internal array of source modules which are iterated, evaluated and combined according to the specified fractal type. Any of the source layer modules may be overridden with another external function by calling **overrideSource()** method.

The number of parameters, in addition to the ability to override sources, provide the ability to generate a large number of fractal patterns. Following are some representative samples of generated fractals, to demonstrate the wide variety possible.

![http://i.imgur.com/xV0ombQ.png](http://i.imgur.com/xV0ombQ.png)

All of these were created by running a simple randomization script:

```
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
	anl.saveDoubleArray("img"..i..".tga", img)
end
```

Randomizing fractal type, basis type and interpolation type from among the various alternatives. Even more variety is possible by overriding layers within the fractal.