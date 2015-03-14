# Domain Rotation #

Domain rotation is a trick that is used in ANL, specifically in the [CImplicitBasisFunction](CImplicitBasisFunction.md), [CImplicitFractal](CImplicitFractal.md) and [CImplicitRotateDomain](CImplicitRotateDomain.md) functions, although in the CImplicitRotateDomain module it is used in a more explicit manner as an actual tool for the user, while in CImplicitBasisFunction and CImplicitFractal it is used in a more behind-the-scenes manner, controlled by the user through a boolean flag.

The idea behind domain rotation is to apply a coordinate transform to the input coordinates of a function before the function is evaluate. The purpose is for the elimination of grid-based artifacts. Noise and fractal functions, especially those based on Perlin noise or other noise variants, fall prey to grid-based artifacts that can occur due to the noise function being generated on an N-dimensional lattice. Certain combinations or certain fractal types can compound these problems. To demonstrate the issue, here is a progression of images of a ridged multifractal being built up by successive layers of noise:

![http://i.imgur.com/8VIEXW8.png](http://i.imgur.com/8VIEXW8.png)

It becomes obvious as more layers are added that there is a grid-based bias occurring in the fractal layers. Each successive layer only makes the apparent grid-based-ness only more pronunced.

By introducing a randomized rotation to each successive layer of the fractal, the artifacts disappear:

![http://i.imgur.com/2qBdzpg.png](http://i.imgur.com/2qBdzpg.png)

The randomized rotations between layers help to ensure that successive layers don't line up their own grid bias. The bias is still there (the noise is still generated on a grid, after all) but since the amplifying effect is eliminated, the grid-based-ness is no longer apparent.

```
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
```