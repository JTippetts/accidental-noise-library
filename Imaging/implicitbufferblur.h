#ifndef IMPLICITBUFFERBLUR_H
#define IMPLICITBUFFERBLUR_H

#include "implicitbufferbase.h"
namespace anl
{
    class CImplicitBufferBlur : public CImplicitBufferBase
    {
    public:
      CImplicitBufferBlur();
      CImplicitBufferBlur(std::shared_ptr<CImplicitBufferBase> src, double blursize, bool seamless=false);
      ~CImplicitBufferBlur();

      void setSource(std::shared_ptr<CImplicitBufferBase> src);
      void setBlurSize(double blursize);
      void setSeamless(bool seamless);

      void get(CArray2Dd &out);
    private:
        std::shared_ptr<CImplicitBufferBase> m_source;
        double m_blursize;
        bool m_seamless;
    };
};

#endif
