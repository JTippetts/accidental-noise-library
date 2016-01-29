# Accidental Noise Library

## Overview

The ANL is a C++ library (C++11 supported) for the generation of complex noise functions. Functions include noise generators such as Ken Perlin's [improved gradient noise](https://mrl.nyu.edu/~perlin/noise/) and [simplex noise](http://webstaff.itn.liu.se/~stegu/simplexnoise/simplexnoise.pdf) variants, a value noise generator, and [Worley's cellular noise](https://en.wikipedia.org/wiki/Worley_noise). The library allows combining various generator functions using operations (arithmetic and otherwise) in order to generate a complex output.

The library is based mostly on 2 classes:  [CKernel](https://github.com/JTippetts/accidental-noise-library/blob/master/VM/kernel.h) and [CNoiseExecutor](https://github.com/JTippetts/accidental-noise-library/blob/master/VM/vm.h#L99). CKernel encapsulate a compound noise function, and CNoiseExecutor is used to evaluate the function or a specified sub-element of the function. It's easiest to see by example:

    anl::CKernel kernel;
    anl::CNoiseExecutor vm(kernel);

    auto b=kernel.gradientBasis(kernel.constant(3), kernel.seed(1546));

    auto i=vm.evaluateScalar(0.1,0.1,b);
    std::cout << i << std::endl;
	
	--> 0.113505
	
In this short snippet, a kernel is created and assigned to a newly created noise executor. Then the method `CKernel::gradientBasis()` is called. This method creates a function generator based on Perlin's improved gradient noise. The gradientBasis() method accepts 2 input parameters: a constant denoting which [interpolation type][interpolation] to use, and a constant to use as a random seed. All function creation methods of CKernel return an instance of the CInstructionIndex class, which can be used to access a given function. (The class simply encapsulates an unsigned int index into a std::vector, but is there to prevent users trying to pass constants directly, as opposed to creating a constant as part of the process.) Using the returned index from gradientBasis(), the `CNoiseExecutor::evaluateScalar()` method is called, with 2 coordinates (x and y) and the index of the created gradient function. The value is output to console.

Behind th
---

