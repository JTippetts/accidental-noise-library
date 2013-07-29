#ifndef IMPLICITBUFFERBLUR_H
#define IMPLICITBUFFERBLUR_H

#include "implicitbufferbase.h"
namespace anl
{
    class CImplicitBufferBlur : public CImplicitBufferBase
    {
    public:
      CImplicitBufferBlur();
      CImplicitBufferBlur(CImplicitBufferBase* src, double blursize, bool seamless=false);
      ~CImplicitBufferBlur();

      void setSource(CImplicitBufferBase *src);
      void setBlurSize(double blursize);
      void setSeamless(bool seamless);

      void get(CArray2Dd &out);
    private:
        CImplicitBufferBase *m_source;
        double m_blursize;
        bool m_seamless;
    };
};

#endif
