#ifndef IMPLICITBUFFERBASE_H
#define IMPLICITBUFFERBASE_H

#include "mapping.h"
#include <memory>

namespace anl
{
    class CImplicitBufferBase
    {
    public:
        CImplicitBufferBase(){};
        virtual ~CImplicitBufferBase(){};

        virtual void get(CArray2Dd &out)=0;
    };
};

#endif
