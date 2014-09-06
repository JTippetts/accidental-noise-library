#ifndef VM_H
#define VM_H

#include "instruction.h"
#include "coordinate.h"
#include "noise_gen.h"

//#include <vector>
#include "../templates/tarray1.h"

namespace anl
{
    struct SVMOutput
    {
        ANLFloatType outfloat_;
        RGBA outrgba_;

        SVMOutput()
        {
            outfloat_=0;
            outrgba_.r=0;
            outrgba_.g=0;
            outrgba_.b=0;
            outrgba_.a=0;
        }
    };

    typedef TArray1D<SInstruction> InstructionListType;
    typedef TArray1D<bool> EvaluatedType;
    typedef TArray1D<SVMOutput> CacheType;

    class CNoiseExecutor
    {
    public:
        CNoiseExecutor(InstructionListType *kernel);

        SVMOutput evaluate(CCoordinate &coord);
        SVMOutput evaluateAt(CCoordinate &coord, unsigned int index);
    private:
        void evaluateInstruction(InstructionListType &kernel, EvaluatedType &evaluated, CacheType &cache, unsigned int index, CCoordinate &coord);
        ANLFloatType evaluateParameter(InstructionListType &kernel, EvaluatedType &evaluated, CacheType &cache, unsigned int index, CCoordinate &coord);

        InstructionListType *kernel_;
        EvaluatedType evaluated_;
        CacheType cache_;

    };
};

#endif
