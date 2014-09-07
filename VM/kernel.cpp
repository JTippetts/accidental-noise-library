#include "kernel.h"
#include "random_gen.h"
#include <cmath>

namespace anl
{

unsigned int CKernel::constant(ANLFloatType val)
{
    anl::SInstruction i;
    i.outfloat_=val;
    i.opcode_=anl::OP_Constant;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::valueBasis(unsigned int interpindex, unsigned int seed)
{
    anl::SInstruction i;

    i.opcode_=anl::OP_ValueBasis;
    i.sources_[0]=interpindex;
    i.seed_=seed;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::gradientBasis(unsigned int interp, unsigned int seed)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_GradientBasis;
    i.sources_[0]=interp;
    i.seed_=seed;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::simplexBasis(unsigned int seed)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_SimplexBasis;
    i.seed_=seed;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::cellularBasis(unsigned int f1, unsigned int f2, unsigned int f3, unsigned int f4, unsigned int d1, unsigned int d2, unsigned int d3, unsigned int d4, unsigned int dist, unsigned int seed)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_CellularBasis;
    i.seed_=seed;
    i.sources_[0]=dist;
    i.sources_[1]=f1;
    i.sources_[2]=f2;
    i.sources_[3]=f3;
    i.sources_[4]=f4;
    i.sources_[5]=d1;
    i.sources_[6]=d2;
    i.sources_[7]=d3;
    i.sources_[8]=d4;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::add(unsigned int s1, unsigned int s2)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Add;
    i.sources_[0]=s1;
    i.sources_[1]=s2;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::subtract(unsigned int s1, unsigned int s2)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Subtract;
    i.sources_[0]=s1;
    i.sources_[1]=s2;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::multiply(unsigned int s1, unsigned int s2)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Multiply;
    i.sources_[0]=s1;
    i.sources_[1]=s2;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::divide(unsigned int s1, unsigned int s2)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Divide;
    i.sources_[0]=s1;
    i.sources_[1]=s2;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::maximum(unsigned int s1index, unsigned int s2index)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Max;
    i.sources_[0]=s1index;
    i.sources_[1]=s2index;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::minimum(unsigned int s1index, unsigned int s2index)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Min;
    i.sources_[0]=s1index;
    i.sources_[1]=s2index;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::abs(unsigned int sindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Abs;
    i.sources_[0]=sindex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::pow(unsigned int s1, unsigned int s2)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Pow;
    i.sources_[0]=s1;
    i.sources_[1]=s2;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::cos(unsigned int sindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Cos;
    i.sources_[0]=sindex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::sin(unsigned int sindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Sin;
    i.sources_[0]=sindex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::tan(unsigned int sindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Tan;
    i.sources_[0]=sindex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::acos(unsigned int sindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ACos;
    i.sources_[0]=sindex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::asin(unsigned int sindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ASin;
    i.sources_[0]=sindex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::atan(unsigned int sindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ATan;
    i.sources_[0]=sindex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::scaleDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleDomain;
    i.sources_[0]=srcindex;
    i.sources_[1]=xindex;
    i.sources_[2]=yindex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::scaleDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex, unsigned int zindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleDomain;
    i.sources_[0]=srcindex;
    i.sources_[1]=xindex;
    i.sources_[2]=yindex;
    i.sources_[3]=zindex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::scaleDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex, unsigned int zindex, unsigned int windex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleDomain;
    i.sources_[0]=srcindex;
    i.sources_[1]=xindex;
    i.sources_[2]=yindex;
    i.sources_[3]=zindex;
    i.sources_[4]=windex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::scaleDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex, unsigned int zindex, unsigned int windex, unsigned int uindex, unsigned int vindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleDomain;
    i.sources_[0]=srcindex;
    i.sources_[1]=xindex;
    i.sources_[2]=yindex;
    i.sources_[3]=zindex;
    i.sources_[4]=windex;
    i.sources_[5]=uindex;
    i.sources_[6]=vindex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::scaleX(unsigned int src, unsigned int scale)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleX;
    i.sources_[0]=src;
    i.sources_[1]=scale;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::scaleY(unsigned int src, unsigned int scale)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleY;
    i.sources_[0]=src;
    i.sources_[1]=scale;
    kernel_.push_back(i);
    return lastIndex();
}
unsigned int CKernel::scaleZ(unsigned int src, unsigned int scale)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleZ;
    i.sources_[0]=src;
    i.sources_[1]=scale;
    kernel_.push_back(i);
    return lastIndex();
}
unsigned int CKernel::scaleW(unsigned int src, unsigned int scale)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleW;
    i.sources_[0]=src;
    i.sources_[1]=scale;
    kernel_.push_back(i);
    return lastIndex();
}
unsigned int CKernel::scaleU(unsigned int src, unsigned int scale)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleU;
    i.sources_[0]=src;
    i.sources_[1]=scale;
    kernel_.push_back(i);
    return lastIndex();
}
unsigned int CKernel::scaleV(unsigned int src, unsigned int scale)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_ScaleV;
    i.sources_[0]=src;
    i.sources_[1]=scale;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::translateDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateDomain;
    i.sources_[0]=srcindex;
    i.sources_[1]=xindex;
    i.sources_[2]=yindex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::translateDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex, unsigned int zindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateDomain;
    i.sources_[0]=srcindex;
    i.sources_[1]=xindex;
    i.sources_[2]=yindex;
    i.sources_[3]=zindex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::translateDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex, unsigned int zindex, unsigned int windex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateDomain;
    i.sources_[0]=srcindex;
    i.sources_[1]=xindex;
    i.sources_[2]=yindex;
    i.sources_[3]=zindex;
    i.sources_[4]=windex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::translateDomain(unsigned int srcindex, unsigned int xindex, unsigned int yindex, unsigned int zindex, unsigned int windex, unsigned int uindex, unsigned int vindex)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateDomain;
    i.sources_[0]=srcindex;
    i.sources_[1]=xindex;
    i.sources_[2]=yindex;
    i.sources_[3]=zindex;
    i.sources_[4]=windex;
    i.sources_[5]=uindex;
    i.sources_[6]=vindex;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::translateX(unsigned int src, unsigned int trans)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateX;
    i.sources_[0]=src;
    i.sources_[1]=trans;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::translateY(unsigned int src, unsigned int trans)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateY;
    i.sources_[0]=src;
    i.sources_[1]=trans;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::translateZ(unsigned int src, unsigned int trans)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateZ;
    i.sources_[0]=src;
    i.sources_[1]=trans;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::translateW(unsigned int src, unsigned int trans)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateW;
    i.sources_[0]=src;
    i.sources_[1]=trans;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::translateU(unsigned int src, unsigned int trans)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateU;
    i.sources_[0]=src;
    i.sources_[1]=trans;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::translateV(unsigned int src, unsigned int trans)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_TranslateV;
    i.sources_[0]=src;
    i.sources_[1]=trans;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::rotateDomain(unsigned int src, unsigned int angle, unsigned int ax, unsigned int ay, unsigned int az)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_RotateDomain;
    i.sources_[0]=src;
    i.sources_[1]=angle;
    i.sources_[2]=ax;
    i.sources_[3]=ay;
    i.sources_[4]=az;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::addSequence(unsigned int baseindex, unsigned int number, unsigned int stride)
{
    if(number<=1) return lastIndex();

    unsigned int s1=baseindex;
    unsigned int s2=baseindex+stride;

    unsigned int addstart=add(s1,s2);

    if(number==2)
    {
        return lastIndex();
    }

    s1=addstart;
    s2+=stride;
    for(unsigned int c=0; c<number-2; ++c)
    {
        add(s1,s2);
        ++s1;
        s2+=stride;
    }

    return lastIndex();
}

unsigned int CKernel::multiplySequence(unsigned int baseindex, unsigned int number, unsigned int stride)
{
    if(number<=1) return lastIndex();

    unsigned int s1=baseindex;
    unsigned int s2=baseindex+stride;

    unsigned int addstart=multiply(s1,s2);

    if(number==2)
    {
        return lastIndex();
    }

    s1=addstart;
    s2+=stride;
    for(unsigned int c=0; c<number-2; ++c)
    {
        multiply(s1,s2);
        ++s1;
        s2+=stride;
    }

    return lastIndex();
}

unsigned int CKernel::maxSequence(unsigned int baseindex, unsigned int number, unsigned int stride)
{
    if(number<=1) return lastIndex();

    unsigned int s1=baseindex;
    unsigned int s2=baseindex+stride;

    unsigned int addstart=maximum(s1,s2);

    if(number==2)
    {
        return lastIndex();
    }

    s1=addstart;
    s2+=stride;
    for(unsigned int c=0; c<number-2; ++c)
    {
        maximum(s1,s2);
        ++s1;
        s2+=stride;
    }

    return lastIndex();
}

unsigned int CKernel::minSequence(unsigned int baseindex, unsigned int number, unsigned int stride)
{
    if(number<=1) return lastIndex();

    unsigned int s1=baseindex;
    unsigned int s2=baseindex+stride;

    unsigned int addstart=minimum(s1,s2);

    if(number==2)
    {
        return lastIndex();
    }

    s1=addstart;
    s2+=stride;
    for(unsigned int c=0; c<number-2; ++c)
    {
        minimum(s1,s2);
        ++s1;
        s2+=stride;
    }

    return lastIndex();
}

unsigned int CKernel::blend(unsigned int low, unsigned int high, unsigned int control)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Blend;
    i.sources_[0]=low;
    i.sources_[1]=high;
    i.sources_[2]=control;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::select(unsigned int low, unsigned int high, unsigned int control, unsigned int threshold, unsigned int falloff)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Select;
    i.sources_[0]=low;
    i.sources_[1]=high;
    i.sources_[2]=control;
    i.sources_[3]=threshold;
    i.sources_[4]=falloff;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::simpleFractalLayer(unsigned int basistype, unsigned int interpindex, ANLFloatType layerscale, ANLFloatType layerfreq, unsigned int seed, bool rot,
                                                ANLFloatType angle, ANLFloatType ax, ANLFloatType ay, ANLFloatType az)
{
    unsigned int base=nextIndex();
    switch(basistype)
    {
    case anl::OP_ValueBasis:
        valueBasis(interpindex, seed);
        break;
    case anl::OP_GradientBasis:
        gradientBasis(interpindex, seed);
        break;
    case anl::OP_SimplexBasis:
        simplexBasis(seed);
        break;
    default:
        gradientBasis(interpindex, seed);
        break;
    }
    constant(layerscale);
    multiply(base,base+1);
    constant(layerfreq);
    scaleDomain(base+2, lastIndex(), lastIndex(), lastIndex(), lastIndex(), lastIndex(), lastIndex());
    if(rot)
    {
        constant(angle);
        constant(ax);
        constant(ay);
        constant(az);
        rotateDomain(lastIndex()-4, lastIndex()-3, lastIndex()-2, lastIndex()-1, lastIndex());
        //constant(ax);
    }
    return lastIndex();
}

unsigned int CKernel::simplefBm(unsigned int basistype, unsigned int interptype, unsigned int numoctaves, ANLFloatType frequency, unsigned int seed, bool rot)
{
    if(numoctaves<1) return 0;

    // push instruction denoting interpolation type constant
    unsigned int interpindex=constant(interptype);
    // Push layers.
    // Each layer consists of a basis, an amplitude scale, a multiply, and a domain scale.
    unsigned int basisstart=nextIndex();
    KISS rnd;
    rnd.setSeed(seed);
    for(unsigned int c=0; c<numoctaves; ++c)
    {
        // Basis function
        if(rot)
        {
            simpleFractalLayer(basistype, interpindex, 1.0/std::pow(2.0, (ANLFloatType)(c)), std::pow(2.0, (ANLFloatType)(c))*frequency, seed+10+c*1000,true,
                               rnd.get01()*3.14159265*2.0, rnd.get01()*2-1, rnd.get01()*2-1, rnd.get01()*2-1);
        }
        else
        {
            simpleFractalLayer(basistype, interpindex, 1.0/std::pow(2.0, (ANLFloatType)(c)), std::pow(2.0, (ANLFloatType)(c))*frequency, seed+10+c*1000, false);
        }
    }

    if (numoctaves==1)
    {
        return lastIndex();
    }

    // Sum the layers
    if(rot) addSequence(basisstart+9, numoctaves, 10);
    else addSequence(basisstart+4, numoctaves, 10);

    return lastIndex();
}

unsigned int CKernel::x()
{
    anl::SInstruction i;
    i.opcode_=anl::OP_X;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::y()
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Y;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::z()
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Z;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::w()
{
    anl::SInstruction i;
    i.opcode_=anl::OP_W;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::u()
{
    anl::SInstruction i;
    i.opcode_=anl::OP_U;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::v()
{
    anl::SInstruction i;
    i.opcode_=anl::OP_V;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::scaleOffset(unsigned int src, ANLFloatType scale, ANLFloatType offset)
{
    unsigned int c=constant(scale);
    unsigned int o=constant(offset);
    unsigned int m=multiply(src,c);
    add(m,o);
    return lastIndex();
}

unsigned int CKernel::radial()
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Radial;
    kernel_.push_back(i);
    return lastIndex();
}

unsigned int CKernel::clamp(unsigned int src, unsigned int low, unsigned int high)
{
    anl::SInstruction i;
    i.opcode_=anl::OP_Clamp;
    i.sources_[0]=src;
    i.sources_[1]=low;
    i.sources_[2]=high;
    kernel_.push_back(i);
    return lastIndex();
}
};
