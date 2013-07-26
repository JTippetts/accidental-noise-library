#ifndef IMPLICITBUFFERUNARYMATH_H
#define IMPLICITBUFFERUNARYMATH_H
#include "implicitbufferbase.h"

namespace anl
{
    class CImplicitBufferUnaryMath : public CImplicitBufferBase
    {
    public:
        CImplicitBufferUnaryMath();
        CImplicitBufferUnaryMath(std::shared_ptr<CImplicitBufferBase> source, int op);
        ~CImplicitBufferUnaryMath();

        void setSource(std::shared_ptr<CImplicitBufferBase> source);
        void setOp(int op);

        void get(CArray2Dd &out);

    private:
        std::shared_ptr<CImplicitBufferBase> m_source;
        int m_op;
    };
};

#endif
