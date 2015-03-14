# CImplicitAutoCorrect #

The CImplicitAutoCorrect module is useful for automatically re-mapping the output of a specified module into a desired range. This is an approximate remapping only; mistakes can be made. The module operates by analyzing the source module during construction (or when **setSource()** or **setRange()** are called) to determine the approximate minimum and maximum, then performing a calculation to remap from (min,max) to (low,high) specified at construction or by **setRange()**. This module is useful especially for functions like [CImplicitBasisFunction](CImplicitBasisFunction.md) and [CImplicitFractal](CImplicitFractal.md), as well as for certain complex module chains, due to the fact that the output of some fractal functions can be difficult to predict and tame.

Note that this module does include some overhead upon construction or when the range or source are set, in that it will perform the analysis to account for the change. Not also that changing things "upstream" of the module will not trigger a change, so if you alter an upstream source then you may need to manually call **calculate()** to re-analyze and calculate new scaling and offset factors.

This module will clamp the output to the desired range. If this is not desired behavior, then you can use [CImplicitScaleOffset](CImplicitScaleOffset.md), specifying your own scale and offset pairs to perform the re-mapping.

The scale/offset pair is calculated by:

```
scale=(high-low) / (max-min);
offset=low-min*scale;
```

By analyzing your own functions and providing specific scale/offset pairs, you can use [CImplicitScaleOffset](CImplicitScaleOffset.md) and skip the run-time analysis of the source module.