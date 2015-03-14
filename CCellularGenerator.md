# CCellularGenerator #

CCellularGenerator is a generator module that generates cellular noise based on the cellular generator by [Steven Worley](http://en.wikipedia.org/wiki/Worley_noise). CCellularGenerator does not inherit from CImplicitModuleBase, and so it can't be used in module chains directly; instead, it is intended to be used in conjunction with a [CImplicitCellular](CImplicitCellular.md) module or a [CImplicitVoronoi](CImplicitVoronoi.md) module, which acts as an interface to the function.

The only avenue for customization (outside of random seed) for a cellular generator is a specifiable distance function. Cellular noise is calculated by computing the distance from the input point to the 4 nearest seed points. The specified distance function is used to actually calculate the distance, and can be one of:

  * EUCLID - The Euclidean distance, or real straight-line distance.
  * MANHATTAN - Manhattan, or L1 Norm, distance calculated by summing the axis components of the delta between the points
  * GREATESTAXIS - The length of the longest axis component delta
  * LEASTAXIS - The length of the shortest axis component delta

The generator provides to a caller the 4 distance values as well as an ID value for each seed point. It is the responsibility of the adapter ([CImplicitCellular](CImplicitCellular.md) or [CImplicitVoronoi](CImplicitVoronoi.md)) to turn these values into something useful.