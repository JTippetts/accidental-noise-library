#ifndef IMPLICITBUFFERUNARYMATH_H
#define IMPLICITBUFFERUNARYMATH_H
#include "implicitbufferbase.h"

namespace anl
{
    class CImplicitBufferUnaryMath : public CImplicitBufferBase
    {
    public:
        CImplicitBufferUnaryMath();
        CImplicitBufferUnaryMath(CImplicitBufferBase * source, int op);
        ~CImplicitBufferUnaryMath();

        void setSource(CImplicitBufferBase * source);
        void setOp(int op);

        void get(CArray2Dd &out);

    private:
        CImplicitBufferBase * m_source;
        int m_op;
    };
};

#endif
