# CImplicitBasisFunction #

CImplicitBasisFunction is a noise generator unit that generates a single layer of noise using a specifiable set of parameters. These parameters are:

  * Type (int), one of
    * VALUE - Noise generated from [random values at grid lattice points](ValueNoise.md)
    * GRADIENT - Noise generated using [Perlin's original noise function](PerlinNoise.md), which specifies gradient functions per lattice point.
    * GRADVAL - A combination (sum) of VALUE and GRADIENT types.
    * SIMPLEX - An implementation of [Perlin's "improved" noise](PerlinSimplexNoise.md).
    * WHITE -- Chaotic, [fully random noise](WhiteNoise.md) source.
  * Interpolation (int), the method for interpolating noise values across grid cells; one of
    * NONE - No interpolation (returns one value across entire grid cell)
    * LINEAR - Linear interpolation (see below)
    * CUBIC - Cubic interpolation (see below)
    * QUINTIC - Quintic interpolation (see below)
  * Rotate Domain (bool), specifies whether a randomized rotation should be applied to input coordinates before sampling. (see below)

**VALUE** noise generates noise by interpolating values specified for each grid point on the lattice. These values are calculated by using a hash of the input coordinates (integral part) in conjunction with a random seed. Value noise utilizes the selected interpolation strategy to smooth (or not smooth, in the case of NONE) the generated function. Here is value noise in the four interpolation variants, NONE, LINEAR, CUBIC, QUINTIC (left to right):
![http://i.imgur.com/SysPto2.png](http://i.imgur.com/SysPto2.png)

**GRADIENT** noise generates noise using Perlin's original method. A gradient function at each vertex on the lattice is evaluated using the fractional part of the input coordinates, and all vertices of the cell are interpolated to obtain the final signal, using the selected interpolation function. Here are the four interpolated variants of gradient noise:
![http://i.imgur.com/0BAfBJZ.png](http://i.imgur.com/0BAfBJZ.png)

**GRADVAL** noise is a simple weight sum (50/50) of VALUE and GRADIENT noise. It uses the specified interpolation for both layers before summing them together.
![http://i.imgur.com/jGONNRf.png](http://i.imgur.com/jGONNRf.png)

**SIMPLEX** calculates the signal using Perlin's improved method; gradient functions are specified at the vertices of a lattice of simplices in N-dimensional space (as opposed to the regular grid used in GRADIENT noise). See [Simplex Noise Demystified](http://webstaff.itn.liu.se/~stegu/simplexnoise/simplexnoise.pdf) for more information. Simplex noise ignores the specified interpolation function, due to the fact that beneath the covers is performs a weighted sum of values rather than a lattice interpolation. So the only variant of simplex noise is a quintic equivalent:
![http://i.imgur.com/d87dgr1.png](http://i.imgur.com/d87dgr1.png)