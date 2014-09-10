#include <iostream>

#include "../VM/vm.h"
#include "../VM/instruction.h"
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
	anl::CInstructionIndex fbm=factory.simplefBm(anl::OP_GradientBasis, 3, 8, 2, 12345, true);

    anl::CInstructionIndex gradx=factory.x();
    anl::CInstructionIndex grady=factory.y();
    anl::CInstructionIndex xab=factory.abs(gradx);
    anl::CInstructionIndex yab=factory.abs(grady);

    anl::CInstructionIndex grad=factory.minimum(xab,yab);
    anl::CInstructionIndex rad=factory.radial();

    anl::CInstructionIndex radius=factory.constant(1);
    anl::CInstructionIndex armthick=factory.constant(0.25);
    anl::CInstructionIndex one=factory.constant(1);
    anl::CInstructionIndex zero=factory.constant(0);
    anl::CInstructionIndex sub=factory.subtract(radius,rad);
    anl::CInstructionIndex div=factory.divide(sub,radius);
    anl::CInstructionIndex clamp=factory.clamp(div,zero,one);

    anl::CInstructionIndex armsub=factory.subtract(armthick,grad);
    anl::CInstructionIndex armdiv=factory.divide(armsub,armthick);
    anl::CInstructionIndex armclamp=factory.clamp(armdiv,zero,one);
    anl::CInstructionIndex mult=factory.multiply(armclamp,clamp);

    anl::CInstructionIndex maxangle=factory.constant(3.14159265*0.5);
    anl::CInstructionIndex rotangle=factory.multiply(rad,maxangle);


    anl::CInstructionIndex interp=factory.constant(3);
    anl::CInstructionIndex white=factory.gradientBasis(interp, 12345);
    anl::CInstructionIndex whitefactor=factory.constant(2.55);
    anl::CInstructionIndex whitescale=factory.scaleDomain(white,whitefactor,whitefactor,whitefactor);
    anl::CInstructionIndex starthresh=factory.constant(0);
    anl::CInstructionIndex starfall=factory.constant(0.125);
    anl::CInstructionIndex starfield=factory.select(zero,whitescale,whitescale,starthresh,starfall);
    anl::CInstructionIndex starmul=factory.multiply(starfield,mult);

    anl::CInstructionIndex rotator=factory.rotateDomain(starmul,rotangle,zero,zero,one);
	
	anl::CInstructionIndex stepsize=factory.constant(0.02);
	anl::CInstructionIndex negstepsize=factory.constant(-0.02);
	anl::CInstructionIndex step1=factory.translateX(mult,stepsize);
	anl::CInstructionIndex step2=factory.translateX(mult,negstepsize);
	anl::CInstructionIndex stepsub=factory.subtract(step2,step1);
	anl::CInstructionIndex stepdiv=factory.divide(stepsub,stepsize);
	
	
	
    anl::CNoiseExecutor vm(factory.getKernel());


    // Map the kernel function to an image and save PNG
    anl::map2D(anl::SEAMLESS_XY, img, vm, anl::SMappingRanges(), fbm, 0);

    img.scaleToRange(0,1);
    anl::saveDoubleArray("out.png", &img);

    // Print kernel
    //outputKernel(factory.getKernel());

    return 0;
}
