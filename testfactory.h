#ifndef TESTFACTORY_H
#define TESTFACTORY_H

#include "VM/instruction.h"
#include "VM/vm.h"
#include <string>
#include <map>

namespace anl
{

    class CKernel
    {
    public:

        unsigned int constant(ANLFloatType val);
        unsigned int valueBasis(unsigned int interpindex, unsigned int seed);
        unsigned int gradientBasis(unsigned int interpindex, unsigned int seed);
        unsigned int simplexBasis(unsigned int seed);
        unsigned int cellularBasis(unsigned int f1, unsigned int f2, unsigned int f3, unsigned int f4, unsigned int d1, unsigned int d2, unsigned int d3, unsigned int d4, unsigned int dist, unsigned int seed);
        unsigned int add(unsigned int s1index, unsigned int s2index);
        unsigned int subtract(unsigned int s1, unsigned int s2);
        unsigned int multiply(unsigned int s1index, unsigned int s2index);
        unsigned int divide(unsigned int s1, unsigned int s2);
        unsigned int maximum(unsigned int s1index, unsigned int s2index);
        unsigned int minimum(unsigned int s1index, unsigned int s2index);
        unsigned int abs(unsigned int sindex);
        unsigned int pow(unsigned int s1, unsigned int s2);

        unsigned int scaleDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex);
        unsigned int scaleDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex, unsigned int zindex);
        unsigned int scaleDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex, unsigned int zindex, unsigned int windex);
        unsigned int scaleDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex, unsigned int zindex, unsigned int windex, unsigned int uindex, unsigned int vindex);

        unsigned int scaleX(unsigned int src, unsigned int scale);
        unsigned int scaleY(unsigned int src, unsigned int scale);
        unsigned int scaleZ(unsigned int src, unsigned int scale);
        unsigned int scaleW(unsigned int src, unsigned int scale);
        unsigned int scaleU(unsigned int src, unsigned int scale);
        unsigned int scaleV(unsigned int src, unsigned int scale);

        unsigned int translateDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex);
        unsigned int translateDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex, unsigned int zindex);
        unsigned int translateDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex, unsigned int zindex, unsigned int windex);
        unsigned int translateDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex, unsigned int zindex, unsigned int windex, unsigned int uindex, unsigned int vindex);

        unsigned int translateX(unsigned int src, unsigned int trans);
        unsigned int translateY(unsigned int src, unsigned int trans);
        unsigned int translateZ(unsigned int src, unsigned int trans);
        unsigned int translateW(unsigned int src, unsigned int trans);
        unsigned int translateU(unsigned int src, unsigned int trans);
        unsigned int translateV(unsigned int src, unsigned int trans);

        unsigned int rotateDomain(unsigned int src, unsigned int angle, unsigned int ax, unsigned int ay, unsigned int az);

        unsigned int addSequence(unsigned int baseindex, unsigned int number, unsigned int stride);
        unsigned int multiplySequence(unsigned int baseindex, unsigned int number, unsigned int stride);
        unsigned int maxSequence(unsigned int baseindex, unsigned int number, unsigned int stride);
        unsigned int minSequence(unsigned int baseindex, unsigned int number, unsigned int stride);
        unsigned int blend(unsigned int low, unsigned int high, unsigned int control);
        unsigned int select(unsigned int low, unsigned int high, unsigned int control, unsigned int threshold, unsigned int falloff);
        unsigned int clamp(unsigned int src, unsigned int low, unsigned int high);

        unsigned int cos(unsigned int src);
        unsigned int sin(unsigned int src);
        unsigned int tan(unsigned int src);
        unsigned int acos(unsigned int src);
        unsigned int asin(unsigned int src);
        unsigned int atan(unsigned int src);

        unsigned int x();
        unsigned int y();
        unsigned int z();
        unsigned int w();
        unsigned int u();
        unsigned int v();
		
		unsigned int radial();

        unsigned int scaleOffset(unsigned int src, ANLFloatType scale, ANLFloatType offset);

        unsigned int simpleFractalLayer(unsigned int basistypeindex, unsigned int interptypeindex, ANLFloatType layerscale, ANLFloatType layerfreq, unsigned int seed, bool rot=true,
            ANLFloatType angle=0.5, ANLFloatType ax=0, ANLFloatType ay=0, ANLFloatType az=1);
        unsigned int simplefBm(unsigned int basistypeindex, unsigned int interptypeindex, unsigned int numoctaves, ANLFloatType frequency, unsigned int seed, bool rot=true);

        InstructionListType *getKernel(){return &kernel_;}
        unsigned int nextIndex(){return kernel_.size();}
        unsigned int lastIndex(){return kernel_.size()-1;}
    private:
        InstructionListType kernel_;
    };

};

#endif
