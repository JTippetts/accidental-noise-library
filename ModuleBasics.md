# Accidental Noise Library Basics #

ANL is a library for generating noise, visualizing color spaces, creating procedural textures, heightmaps, volumetrics, and so forth. It provides a framework for connecting small, black-box-like functions together, building complex functions from simple building blocks.

As currently stands, the library is composed of 3 main chunks: Noise (for generating continuous noise or patterns in the numeric space), RGBA (for visualizing generated noise in the RGBA space) and Imaging (for obtaining explicit 2D imagery from Noise and RGBA functions).

## Implicit (Noise) Modules ##

In the Noise space, modules are organized as classes derived from the common base class, [CImplicitModuleBase](CImplicitModuleBase.md). A class derived from this base provides the common interface:

```
class CImplicitModuleBase
{
public:
        CImplicitModuleBase();
        virtual ~CImplicitModuleBase();
        void setDerivSpacing(double spacing);
        virtual void setSeed(unsigned int seed);

        virtual double get(double x, double y)=0;
        virtual double get(double x, double y, double z)=0;
        virtual double get(double x, double y, double z, double w)=0;
        virtual double get(double x, double y, double z, double w, double u, double v)=0;

        double get_dx(double x, double y);
        double get_dy(double x, double y);

        double get_dx(double x, double y, double z);
        double get_dy(double x, double y, double z);
        double get_dz(double x, double y, double z);

        double get_dx(double x, double y, double z, double w);
        double get_dy(double x, double y, double z, double w);
        double get_dz(double x, double y, double z, double w);
        double get_dw(double x, double y, double z, double w);

        double get_dx(double x, double y, double z, double w, double u, double v);
        double get_dy(double x, double y, double z, double w, double u, double v);
        double get_dz(double x, double y, double z, double w, double u, double v);
        double get_dw(double x, double y, double z, double w, double u, double v);
        double get_du(double x, double y, double z, double w, double u, double v);
        double get_dv(double x, double y, double z, double w, double u, double v);
};
```

Each module produces its result in one of 4 coordinate systems: 2D, 3D, 4D and 6D. (Higher order variants, such as 4D and 6D, are useful when generating [seamless noise](SeamlessNoise.md), that tiles in multiple dimensions.)

Each module also provides methods to obtain the derivative of the function with respect to each of the (up to) 6 coordinate axes. This derivative is approximated by sampling multiple times using a specified **spacing** parameter, rather than by being calculated numerically (since numeric calculation of some of the more complex function chains could be... difficult.)

Implicit modules (Noise modules) are often parameterizable, accepting inputs from arbitrary sources that can be specified as either numeric constants (of type double) or other Implicit sources. As an example, the [CImplicitMath](CImplicitMath.md) module accepts 3 parameters: a mode (determining the type of math to perform, ie ADDITION, COS, POW, etc...) and two sources to act upon, the second source being ignored in the case of unary operations such as COS.

Here are some examples:

```
math1=anl.CImplicitMath(anl.MULTIPLY, 0.5, 0.3);
math2=anl.CImplicitMath(anl.COS, math1);
math3=anl.CImplicitMath(anl.POW, math1, math2);
```

The first example creates a math module that simply multiplies 0.5 by 0.3. All inputs to this function will return 0.15. The second example creates a math module that takes the cosine of the first module. (Also outputting a constant, incidentally, since **math1** is a constant). The third example raises the output of **math1** to the power of the output of **math2**-- again, a constant, since both preceding modules are constants. Where it gets fun, however, is in combining different non-constant functions to generate complex spaces.

## RGBA Modules ##

```
class CRGBAModuleBase
    {
        public:
        CRGBAModuleBase(){}
        virtual ~CRGBAModuleBase(){}

        void setSeed(unsigned int){};

        virtual SRGBA get(double x, double y)=0;
        virtual SRGBA get(double x, double y, double z)=0;
        virtual SRGBA get(double x, double y, double z, double w)=0;
        virtual SRGBA get(double x, double y, double z, double w, double u, double v)=0;
    };
```

RGBA modules operate similarly to Implicit modules, and in fact many of them integrate with Implicit modules for their normal operation. They typically act as **adapters**, hooking into functions in the Noise space and using the signals derived therefrom to generate an RGBA color space.

RGBA modules range from the simple [CRGBAImplicitAdapter](CRGBAImplicitAdapter.md), which merely transforms an input Noise signal into a grayscale color value, with values <=0 mapping to black, and values >=1 mapping to 1. Other modules include [CRGBACompositeChannels](CRGBACompositeChannels.md), which can hook into Noise modules for each of the Red, Green, Blue and Alpha (or Hue, Saturation, Value and Alpha) channels of an output RGBA color. Still others perform [select](CRGBASelect.md) or [blend](CRGBABlend.md) operations, [color operations](CRGBAColorOps.md) (such as Soft Light, Overlay, Dodge, Burn, etc...) and so forth.

As with the Noise modules, RGBA modules are callable in 2, 3, 4 and 6 dimensions. The output of a call to **get()** will be an RGBA color.

## Imaging ##

ANL provides a small library to assist in various imaging-related tasks such as mapping Noise and RGBA modules to 2D image buffers for export to .TGA, performing buffer-based operations such as erosion and blur, and so forth.

### Buffer Modules ###

Buffer modules come in 2 flavors: Implicit (for mapping Noise functions to grayscale images) and RGBA. They operate similarly to how the function modules work, allowing chaining of operations. Grayscale buffers derive from [CImplicitBufferBase](CImplicitBufferBase.md) and RGBA buffers derive from [CRGBABufferBase](CRGBABufferBase.md). Note that these modules don't incorporate buffers themselves; instead, they provide an adapter interface by which an external buffer may be populated.

Both Buffer module types provide, as part of their library of modules, direct Adapter modules that interface directly with either an Implicit or RGBA module. They are [CImplicitBufferImplicitAdapter](CImplicitBufferImplicitAdapter.md) and [CRGBABufferRGBAAdapter](CRGBABufferRGBAAdapter.md). These modules provide an interface to specify how the mapping from Implicit/RGBA function space to 2D buffer space is to be accomplished.

When mapping an N-dimensional function to a 2D buffer space, there are a number of ways it can be done. The easiest is to take a simple cross-section of noise or color, mapped from a rectangular section of a plane cutting through the N-dimensional space. The exact size of the area to map can be specified using the [SMappingRanges](SMappingRanges.md) structure. Additionally, noise or color can be mapped in a [seamless](SeamlessNoise.md) fashion, with seamlessness specifiable for any of the X<sub>IMG</sub> , Y<sub>IMG</sub> or Z<sub>IMG</sub> (or, time) axes of the output buffer. That is, you can choose to map a region of a function so that the output in the buffer is seamless in the X axis of the image, or the Y axis, or both. Additionally, you can map a  buffer of the function at some Z value, and specify that Z should be seamless as well. A sequence of mapped buffer images that are seamless in Z will, if shown sequentially, appear to "animate" seamlessly in a loop with no discontinuities.

When a Buffer Adapter is used, the dimensionality of the base functions that is used behind the scenes is determined partially by the **seamless** mapping mode and partially by a boolean that determines whether or not to use a Z value, and a specifiable Z value if this is true. This functionality is useful, for example, in taking a simple planar cross-section of a 3D noise function then animating Z down or up to make the buffer image gradually morph over time.

## Basic Example ##

To show how the 3 parts of the overall chain work together, here is an example. This example is written in Lua for the Framework.exe which is built alongside the library.

```
celgen=anl.CCellularGenerator(anl.EUCLID)
cell=anl.CImplicitCellular(celgen, -1.0, 1.0, 0.0, 0.0)

fbm=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 8, 1, true)
ac=anl.CImplicitAutoCorrect(fbm,-0.5,0.5)

turb=anl.CImplicitTranslateDomain(cell,ac,0.0,0.0)

colorscale=anl.CRGBACurve(turb,anl.LINEAR)
colorscale:pushPoint(-0.1, 0,0.125,0.25,1)
colorscale:pushPoint(0, 0,0.125,0.25,1)
colorscale:pushPoint(0.35, 0.75,1,0.25,1)
colorscale:pushPoint(1, 1.0,0.75,0.25,1)


rgbaad=anl.CRGBABufferRGBAAdapter(colorscale, anl.SEAMLESS_NONE, anl.SMappingRanges(0,4,0,4,0,4), true, 0)

impad=anl.CImplicitBufferImplicitAdapter(turb, anl.SEAMLESS_NONE, anl.SMappingRanges(0,4,0,4,0,4), true, 0)
erode=anl.CImplicitBufferSimpleErode(impad, 0, 0.35)
blur=anl.CImplicitBufferBlur(erode, 3/256)
bump=anl.CImplicitBufferBumpMap(blur, -1.5, 3.5, 1.5, 0.1, false)

mult=anl.CRGBABufferImplicitBufferMultiply(rgbaad, bump)

i=anl.CArray2Drgba()
i:resize(256,256)
mult:get(i)
anl.saveRGBAArray("img.tga", i)
```

Execute this script using the framework (which will be placed in the Bin folder of the build directory):

```
Framework.exe ../../accidental-source-library/Examples/basicexample.lua
```

And the result after execution will be a .TGA image in the Bin folder called **img.tga**. Open it up in an image editor and you should see this:

![http://i.imgur.com/ER5Mbal.png](http://i.imgur.com/ER5Mbal.png)

Here is a break down of what is occurring here.

```
celgen=anl.CCellularGenerator(anl.EUCLID)
cell=anl.CImplicitCellular(celgen, -1.0, 1.0, 0.0, 0.0)
```

This part sets up a [CCellularGenerator](CCellularGenerator.md) and hooks its output to a [CImplicitCellular](CImplicitCellular.md) module, with the coefficients (F1=-1, F2=1).

```
fbm=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 8, 1, true)
ac=anl.CImplicitAutoCorrect(fbm,-0.5,0.5)
```

Next, a basic fBm fractal, using Perlin's original gradient noise, is created using quintic (smoothest) interpolation with 8 octaves and a frequency of 1. The output of this function is passed to a [CImplicitAutoCorrect](CImplicitAutoCorrect.md) module to correct its output into the range (-0.5,0.5). (Fractals are notorious for having wacky output ranges.)

```
turb=anl.CImplicitTranslateDomain(cell,ac,0.0,0.0)
```

A [CImplicitTranslateDomain](CImplicitTranslateDomain.md) function is set up with the cellular noise as the source and the auto-corrected fractal as the X-axis translation factor. Domain translation is a fun beast. Essentially, it takes the output of one noise module and uses it to perturb, or modify, the input coordinate to another module. In this case, the fractal is evaluated and the result is used to modify the X component of the input coordinate to the cellular function. This has the result of introducing noise, or turbulence, into the cellular function.

```
colorscale=anl.CRGBACurve(turb,anl.LINEAR)
colorscale:pushPoint(-0.1, 0,0.125,0.25,1)
colorscale:pushPoint(0, 0,0.125,0.25,1)
colorscale:pushPoint(0.35, 0.75,1,0.25,1)
colorscale:pushPoint(1, 1.0,0.75,0.25,1)
```

The output of the perturbed function is now passed on to an RGBA function. The Implicit function is used as an index into a color scale that maps from 0 to 1. Colors can be specified at any point along the scale. In this case, a few throwaway colors are used. (This isn't a really well-thought-out example, here.)

```
rgbaad=anl.CRGBABufferRGBAAdapter(colorscale, anl.SEAMLESS_NONE, anl.SMappingRanges(0,4,0,4,0,4), true, 0)
```

At this point, we hook-up an RGBA buffer adapter to the colorscale function. This adapter is set to use no seamless mapping, and to map from the range 0<=X<=4 and 0<=Y<=4. Since it is a non-seamless mapping, the Z mapping range has no effect. The mapping is set to use Z, however, forcing the underlying generator to use a 3D function.

```
impad=anl.CImplicitBufferImplicitAdapter(turb, anl.SEAMLESS_NONE, anl.SMappingRanges(0,4,0,4,0,4), true, 0)
erode=anl.CImplicitBufferSimpleErode(impad, 0, 0.35)
blur=anl.CImplicitBufferBlur(erode, 3/256)
bump=anl.CImplicitBufferBumpMap(blur, -1.5, 3.5, 1.5, 0.1, false)
```

Here, the output of the perturbed Implicit module is again taken and passed to an [CImplicitBufferImplicitAdapter](CImplicitBufferImplicitAdapter.md), with the same settings as the color adapter above. This will take the same domain of output noise and allow it to be mapped to a 2D grayscale buffer. The output of this adapter is then passed to a [CImplicitBufferSimpleErode](CImplicitBufferSimpleErode.md). This module performs a rough approximation of a hydraulic erosion pass on the buffer. Then the signal is passed on to a [CImplicitBufferBlur](CImplicitBufferBlur.md) module, which will run a pass of Gaussian blur across the buffer. Finally, the result of the blur pass is passed on to a [CImplicitBufferBumpMap](CImplicitBufferBumpMap.md) module, which will use a specified light vector and sample spacing in order to calculate a basic lit version of the grayscale buffer.

```
mult=anl.CRGBABufferImplicitBufferMultiply(rgbaad, bump)
```

The output of the RGBA Buffer adapter is multiplied by the output of the bump map buffer using a [CRGBABufferImplicitBufferMultiply](CRGBABufferImplicitBufferMultiply.md) module. Each color component is multiplied by the lit value in the bump-map to produce a shaded color in the final buffer.

```
i=anl.CArray2Drgba()
i:resize(256,256)
mult:get(i)
anl.saveRGBAArray("img.tga", i)
```

Finally, an actual buffer is created, sized to 256x256 and passed to the **get()** method of the multiplication module. This call will fill the buffer with the final result of the module chain, which is saved to file and the script exits.

This example, while simple and stupid, exhibits the main behavior of the Accidental Noise Library. Modules are chained together, the output from one fed as an input to another, building a tree-like structure that can be used at the end to generate a complex result.