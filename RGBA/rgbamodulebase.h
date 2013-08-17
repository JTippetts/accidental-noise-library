#ifndef RGBA_MODULE_BASE_H
#define RGBA_MODULE_BASE_H
//#include "rgba.h"

#include <memory>
#include "../Imaging/vectortypes.h"

namespace anl
{
    class CRGBAModuleBase
    {
        public:
        CRGBAModuleBase(){}
        virtual ~CRGBAModuleBase(){}

        void setSeed(unsigned int){};

        virtual SRGBA get(ANLFloatType x, ANLFloatType y)=0;
        virtual SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z)=0;
        virtual SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)=0;
        virtual SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)=0;
    };

    class CRGBAParameter
    {
        public:
        CRGBAParameter() : m_source(0), m_constant(0,0,0,0){}
        CRGBAParameter(SRGBA c) : m_source(0), m_constant(c){}
        CRGBAParameter(CRGBAModuleBase * c) : m_source(c), m_constant(0,0,0,0){}

        void set(SRGBA c)
        {
            m_source=0;
            m_constant=c;
        }
        void set(CRGBAModuleBase * m)
        {
            m_source=m;
        }

        SRGBA get(ANLFloatType x, ANLFloatType y)
        {
            if(m_source) return m_source->get(x,y);
            else return m_constant;
        }

        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
        {
            if(m_source) return m_source->get(x,y,z);
            else return m_constant;
        }

        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
        {
            if(m_source) return m_source->get(x,y,z,w);
            else return m_constant;
        }

        SRGBA get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
        {
            if(m_source) return m_source->get(x,y,z,w,u,v);
            else return m_constant;
        }


        protected:
        CRGBAModuleBase * m_source;
        SRGBA m_constant;

    };

};

#endif
