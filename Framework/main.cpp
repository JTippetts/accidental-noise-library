#include <iostream>

#include "../VM/vm.h"
#include "../VM/kernel.h"
#include "../Imaging/imaging.h"

//using namespace std;

void outputInstruction(anl::SInstruction &i)
{
    switch(i.opcode_)
    {
        case anl::OP_NOP: std::cout << "NOP" << std::endl; break;
        case anl::OP_Constant: std::cout << "Constant: " << i.outfloat_ << std::endl; break;
        case anl::OP_ValueBasis: std::cout << "Value basis, interpolation constant at " << i.sources_[0] << std::endl; break;
        case anl::OP_GradientBasis: std::cout << "Gradient basis, interpolation constant at " << i.sources_[0] << std::endl; break;
        case anl::OP_Add: std::cout << "Add, source " << i.sources_[0] << " and " << i.sources_[1] << std::endl; break;
        case anl::OP_Multiply: std::cout << "Multiply, source " << i.sources_[0] << " and " << i.sources_[1] << std::endl; break;
        case anl::OP_ScaleDomain: std::cout << "ScaleDomain, source is " << i.sources_[0] << ", scale x by " << i.sources_[1] << " and scale y by " << i.sources_[2] << std::endl; break;
        default: std::cout << "Unrecognized opcode." << std::endl; break;
    };
}

void outputKernel(std::vector<anl::SInstruction> *kernel)
{
    for(int c=kernel->size()-1; c>=0; --c)
    {
        std::cout << c << ":" << std::endl;
        outputInstruction((*kernel)[c]);
        std::cout << std::endl;
    }
}

int main()
{
    anl::CKernel factory;
    anl::TArray2D<ANLFloatType> img(512,512);

    unsigned int gradx=factory.x();
    unsigned int grady=factory.y();
    unsigned int xab=factory.abs(gradx);
    unsigned int yab=factory.abs(grady);

    unsigned int grad=factory.minimum(xab,yab);
    unsigned int rad=factory.radial();

    unsigned int radius=factory.constant(2);
    unsigned int armthick=factory.constant(0.5);
    unsigned int one=factory.constant(1);
    unsigned int zero=factory.constant(0);
    unsigned int sub=factory.subtract(radius,rad);
    unsigned int div=factory.divide(sub,radius);
    unsigned int clamp=factory.clamp(div,zero,one);

    unsigned int armsub=factory.subtract(armthick,grad);
    unsigned int armdiv=factory.divide(armsub,armthick);
    unsigned int armclamp=factory.clamp(armdiv,zero,one);
    unsigned int mult=factory.multiply(armclamp,clamp);

    unsigned int maxangle=factory.constant(3.14159265*0.5);
    unsigned int rotangle=factory.multiply(rad,maxangle);


    unsigned int interp=factory.constant(3);
    unsigned int white=factory.valueBasis(interp, 12345);
    unsigned int whitefactor=factory.constant(255);
    unsigned int whitescale=factory.scaleDomain(white,whitefactor,whitefactor,whitefactor);
    unsigned int starthresh=factory.constant(0);
    unsigned int starfall=factory.constant(0.125);
    unsigned int starfield=factory.select(zero,whitescale,whitescale,starthresh,starfall);
    unsigned int starmul=factory.multiply(starfield,mult);

    unsigned int rotator=factory.rotateDomain(starmul,rotangle,zero,zero,one);
	
	unsigned int stepsize=factory.constant(0.02);
	unsigned int negstepsize=factory.constant(-0.02);
	unsigned int step1=factory.translateX(mult,stepsize);
	unsigned int step2=factory.translateX(mult,negstepsize);
	unsigned int stepsub=factory.subtract(step2,step1);
	unsigned int stepdiv=factory.divide(stepsub,stepsize);
	
    anl::CNoiseExecutor vm(factory.getKernel());


    // Map the kernel function to an image and save PNG
    for(int x=0; x<img.width(); ++x)
    {
        for(int y=0; y<img.height(); ++y)
        {
            // Evaluate the kernel using a 2D VM
            ANLFloatType i,j;
            i=((ANLFloatType)x / (ANLFloatType)img.width())*2-1;
            j=((ANLFloatType)y / (ANLFloatType)img.height())*2-1;
            anl::CCoordinate coord(i*2,j*2,0);
            //anl::SVMOutput out=vm.evaluate(factory.getKernel(), coord);
            anl::SVMOutput out=vm.evaluateAt(coord,rotator);
            //std::cout << "Coord dim: " << coord.dimension_ << std::endl;

            // Shift range from [-1,1] to [0,1] and clamp
            ANLFloatType v=out.outfloat_;//*0.5+0.5;
            //v=std::max(0.0, std::min(1.0, v));
            img.set(x,y,v);
        }
    }

    img.scaleToRange(0,1);
    anl::saveDoubleArray("out.png", &img);

    // Print kernel
    //outputKernel(factory.getKernel());

    return 0;
}
