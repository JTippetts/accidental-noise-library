# CImplicitBlend #

The CImplicitBlend module is used for blending the output of 2 modules based on the output of a third module. The blending is performed as a basic linear interpolation between the two sources, using the control source as the interpolant.

Here is an example:
![http://i.imgur.com/UJcvKr8.png](http://i.imgur.com/UJcvKr8.png)

The first section shows a bit of [cellular noise](CImplicitCellular.md), the second section shows a bit of [ridged mult-fractal noise](CImplicitFractal.md), the third section shows a [gradient module](CImplicitGradient.md) coupled with a [sine modifier](CImplicitMath.md), and the final section shows the result of blending the first and second sources using the third as the control source.

Blending (and its counter part, [CImplicitSelect](CImplicitSelect.md)) are useful tools in creating [composite functions](FunctionComposition.md), or complex functions created from simple building blocks.