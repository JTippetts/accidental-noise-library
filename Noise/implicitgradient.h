#ifndef IMPLICIT_GRADIENT_H
#define IMPLICIT_GRADIENT_H
#include "implicitmodulebase.h"

namespace anl
{
    class CImplicitGradient : public CImplicitModuleBase
    {
        public:
        CImplicitGradient();
        CImplicitGradient(ANLFloatType x1, ANLFloatType x2, ANLFloatType y1, ANLFloatType y2, ANLFloatType z1=0, ANLFloatType z2=0,
        ANLFloatType w1=0, ANLFloatType w2=0, ANLFloatType u1=0, ANLFloatType u2=0, ANLFloatType v1=0, ANLFloatType v2=0);
        ~CImplicitGradient();

        void setGradient(ANLFloatType x1, ANLFloatType x2, ANLFloatType y1, ANLFloatType y2, ANLFloatType z1=0, ANLFloatType z2=0,
        ANLFloatType w1=0, ANLFloatType w2=0, ANLFloatType u1=0, ANLFloatType u2=0, ANLFloatType v1=0, ANLFloatType v2=0);


        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);


        protected:
        ANLFloatType m_gx1, m_gy1, m_gz1, m_gw1, m_gu1, m_gv1;
        ANLFloatType m_gx2, m_gy2, m_gz2, m_gw2, m_gu2, m_gv2;
        ANLFloatType m_x, m_y, m_z, m_w, m_u, m_v;
        ANLFloatType m_vlen;
    };
};
#endif
