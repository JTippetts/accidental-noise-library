#include "treecontainer.h"
#include <iostream>

namespace anl
{
    CTreeContainer::~CTreeContainer()
    {

        m_modules.clear();
    }

    CImplicitModuleBase * CTreeContainer::get(std::string name)
    {
        auto i=m_modules.find(name);
        if(i==m_modules.end()) return 0;
        return i->second.get();
    }

    CRGBAModuleBase * CTreeContainer::getRGBA(std::string name)
    {
        auto i=m_rgbas.find(name);
        if(i==m_rgbas.end()) return 0;
        return i->second.get();
    }

    CImplicitModuleBase * CTreeContainer::getImplicitModule(std::string name)
    {
        return get(name);
    }

    CRGBAModuleBase * CTreeContainer::getRGBAModule(std::string name)
    {
        return getRGBA(name);
    }

	CImplicitBufferBase * CTreeContainer::getImplicitBuffer(std::string name)
    {
        auto i=m_implicitbuffers.find(name);
        if(i==m_implicitbuffers.end()) return 0;
        return i->second.get();
    }

    CRGBABufferBase * CTreeContainer::getRGBABuffer(std::string name)
    {
        auto i=m_rgbabuffers.find(name);
        if(i==m_rgbabuffers.end()) return 0;
        return i->second.get();
    }

    CTreeContainer &CTreeContainer::autoCorrect(std::string name, std::string src, ANLFloatType low, ANLFloatType high)
    {
        if(get(name)) return *this;
        CImplicitModuleBase * s=get(src);
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitAutoCorrect(s,low,high));
        return *this;
    }

    CTreeContainer &CTreeContainer::basisFunction(std::string name, int type, int interp, bool rotate)
    {
        if(get(name)) return *this;
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBasisFunction(type,interp,rotate));
        return *this;
    }

    CTreeContainer &CTreeContainer::blend(std::string name, ANLFloatType low, ANLFloatType high, ANLFloatType control)
    {
        if(get(name)) return *this;
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBlend(low,high,control));
        return *this;
    }

    CTreeContainer &CTreeContainer::blend(std::string name, ANLFloatType low, ANLFloatType high, std::string control)
    {
        if(get(name)) return *this;
        CImplicitModuleBase * c=get(control);
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBlend(low,high,c));
        return *this;
    }

    CTreeContainer &CTreeContainer::blend(std::string name, ANLFloatType low, std::string high, ANLFloatType control)
    {
        if(get(name)) return *this;
        CImplicitModuleBase * h=get(high);
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBlend(low,h,control));
        return *this;
    }

    CTreeContainer &CTreeContainer::blend(std::string name, ANLFloatType low, std::string high, std::string control)
    {
        if(get(name)) return *this;
        CImplicitModuleBase * h=get(high);
        CImplicitModuleBase * c=get(control);
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBlend(low,h,c));
        return *this;
    }

    CTreeContainer &CTreeContainer::blend(std::string name, std::string low, ANLFloatType high, ANLFloatType control)
    {
        if(get(name)) return *this;
        CImplicitModuleBase * l=get(low);
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBlend(l,high,control));
        return *this;
    }

    CTreeContainer &CTreeContainer::blend(std::string name, std::string low, ANLFloatType high, std::string control)
    {
        if(get(name)) return *this;
        CImplicitModuleBase * l=get(low);
        CImplicitModuleBase * c=get(control);
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBlend(l,high,c));
        return *this;
    }

    CTreeContainer &CTreeContainer::blend(std::string name, std::string low, std::string high, ANLFloatType control)
    {
        if(get(name)) return *this;
        CImplicitModuleBase * l=get(low);
        CImplicitModuleBase * h=get(high);
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBlend(l,h,control));
        return *this;
    }

    CTreeContainer &CTreeContainer::blend(std::string name, std::string low, std::string high, std::string control)
    {
        if(get(name)) return *this;
        CImplicitModuleBase * l=get(low);
        CImplicitModuleBase * h=get(high);
        CImplicitModuleBase * c=get(control);
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBlend(l,h,c));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, ANLFloatType s, ANLFloatType b, ANLFloatType t, ANLFloatType f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, ANLFloatType s, ANLFloatType b, ANLFloatType t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, ANLFloatType s, ANLFloatType b, std::string t, ANLFloatType f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, ANLFloatType s, ANLFloatType b, std::string t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, ANLFloatType s, std::string b, ANLFloatType t, ANLFloatType f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, ANLFloatType s, std::string b, ANLFloatType t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, ANLFloatType s, std::string b, std::string t, ANLFloatType f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, ANLFloatType s, std::string b, std::string t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, ANLFloatType b, ANLFloatType t, ANLFloatType f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, ANLFloatType b, ANLFloatType t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, ANLFloatType b, std::string t, ANLFloatType f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, ANLFloatType b, std::string t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, std::string b, ANLFloatType t, ANLFloatType f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, std::string b, ANLFloatType t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, std::string b, std::string t, ANLFloatType f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, std::string b, std::string t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::cache(std::string name, ANLFloatType v)
    {
        if(get(name)) return *this;
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitCache(v));
        return *this;
    }

    CTreeContainer &CTreeContainer::cache(std::string name, std::string v)
    {
        if(get(name)) return *this;
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitCache(get(v)));
        return *this;
    }

    CTreeContainer &CTreeContainer::cellular(std::string name, std::string g, ANLFloatType a, ANLFloatType b, ANLFloatType c, ANLFloatType d)
    {
        if(get(name)) return *this;
        auto geni=m_cellgen.find(g);
        if(geni==m_cellgen.end()) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitCellular(geni->second.get(),a,b,c,d));
        return *this;
    }

    CTreeContainer &CTreeContainer::cellularGenerator(std::string name)
    {
        auto geni=m_cellgen.find(name);
        if(geni!=m_cellgen.end()) return *this;

        m_cellgen[name]=std::shared_ptr<CCellularGenerator>(new CCellularGenerator());
        return *this;
    }

    CTreeContainer &CTreeContainer::clamp(std::string name, ANLFloatType s, ANLFloatType l, ANLFloatType h)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitClamp(get(s), get(l), get(h)));
        return *this;
    }

    CTreeContainer &CTreeContainer::clamp(std::string name, ANLFloatType s, ANLFloatType l, std::string h)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitClamp(get(s), get(l), get(h)));
        return *this;
    }

    CTreeContainer &CTreeContainer::clamp(std::string name, ANLFloatType s, std::string l, ANLFloatType h)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitClamp(get(s), get(l), get(h)));
        return *this;
    }

    CTreeContainer &CTreeContainer::clamp(std::string name, ANLFloatType s, std::string l, std::string h)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitClamp(get(s), get(l), get(h)));
        return *this;
    }

    CTreeContainer &CTreeContainer::clamp(std::string name, std::string s, ANLFloatType l, ANLFloatType h)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitClamp(get(s), get(l), get(h)));
        return *this;
    }

    CTreeContainer &CTreeContainer::clamp(std::string name, std::string s, ANLFloatType l, std::string h)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitClamp(get(s), get(l), get(h)));
        return *this;
    }

    CTreeContainer &CTreeContainer::clamp(std::string name, std::string s, std::string l, ANLFloatType h)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitClamp(get(s), get(l), get(h)));
        return *this;
    }

    CTreeContainer &CTreeContainer::clamp(std::string name, std::string s, std::string l, std::string h)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitClamp(get(s), get(l), get(h)));
        return *this;
    }

    CTreeContainer &CTreeContainer::constant(std::string name, ANLFloatType v)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitConstant(v));
        return *this;
    }

    CTreeContainer &CTreeContainer::curve(std::string name, ANLFloatType s, int interptype)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitCurve(get(s),interptype));
        return *this;
    }

    CTreeContainer &CTreeContainer::curve(std::string name, std::string s, int interptype)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitCurve(get(s),interptype));
        return *this;
    }

    CTreeContainer &CTreeContainer::fractal(std::string name, unsigned int type, unsigned int basis, unsigned int interp, int octaves, ANLFloatType freq)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitFractal(type,basis,interp,octaves,freq,true));
        return *this;
    }

    CTreeContainer &CTreeContainer::functionGradient(std::string name, ANLFloatType s, int axis, ANLFloatType spacing)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitFunctionGradient(get(s),axis,spacing));
        return *this;
    }

    CTreeContainer &CTreeContainer::functionGradient(std::string name, std::string s, int axis, ANLFloatType spacing)

    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitFunctionGradient(get(s),axis,spacing));
        return *this;
    }

    CTreeContainer &CTreeContainer::gradient(std::string name, ANLFloatType x1, ANLFloatType x2, ANLFloatType y1, ANLFloatType y2, ANLFloatType z1, ANLFloatType z2, ANLFloatType w1, ANLFloatType w2, ANLFloatType u1, ANLFloatType u2, ANLFloatType v1, ANLFloatType v2)
    {
        if(get(name)) return *this;
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitGradient(x1,x2,y1,y2,z1,z2,w1,w2,u1,u2,v1,v2));
        return *this;
    }

    CTreeContainer &CTreeContainer::math(std::string name, int op, ANLFloatType s1, ANLFloatType s2)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitMath(op,get(s1), get(s2)));
        return *this;
    }

    CTreeContainer &CTreeContainer::math(std::string name, int op, ANLFloatType s1, std::string s2)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitMath(op,get(s1), get(s2)));
        return *this;
    }

    CTreeContainer &CTreeContainer::math(std::string name, int op, std::string s1, ANLFloatType s2)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitMath(op,get(s1), get(s2)));
        return *this;
    }

    CTreeContainer &CTreeContainer::math(std::string name, int op, std::string s1, std::string s2)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitMath(op,get(s1), get(s2)));
        return *this;
    }

    CTreeContainer &CTreeContainer::normalizeCoords(std::string name, ANLFloatType src, ANLFloatType length)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitNormalizeCoords(get(src), get(length)));
        return *this;
    }

    CTreeContainer &CTreeContainer::normalizeCoords(std::string name, ANLFloatType src, std::string length)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitNormalizeCoords(get(src), get(length)));
        return *this;
    }

    CTreeContainer &CTreeContainer::normalizeCoords(std::string name, std::string src, ANLFloatType length)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitNormalizeCoords(get(src), get(length)));
        return *this;
    }

    CTreeContainer &CTreeContainer::normalizeCoords(std::string name, std::string src, std::string length)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitNormalizeCoords(get(src), get(length)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, ANLFloatType ay, std::string az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, ANLFloatType ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, std::string ay, ANLFloatType az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, std::string ay, ANLFloatType az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, std::string ay, std::string az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, std::string ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, std::string ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, std::string ax, ANLFloatType ay, ANLFloatType az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, std::string ax, ANLFloatType ay, std::string az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, std::string ax, ANLFloatType ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, std::string ax, std::string ay, ANLFloatType az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, std::string ax, std::string ay, ANLFloatType az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, std::string ax, std::string ay, std::string az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, ANLFloatType src, std::string ax, std::string ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, ANLFloatType ax, ANLFloatType ay, std::string az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, ANLFloatType ax, ANLFloatType ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, ANLFloatType ax, std::string ay, ANLFloatType az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, ANLFloatType ax, std::string ay, ANLFloatType az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, ANLFloatType ax, std::string ay, std::string az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, ANLFloatType ax, std::string ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, ANLFloatType ay, ANLFloatType az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, ANLFloatType ay, std::string az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, ANLFloatType ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, std::string ay, ANLFloatType az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, std::string ay, ANLFloatType az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, std::string ay, std::string az, ANLFloatType angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, std::string ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sawtooth(std::string name, ANLFloatType src, ANLFloatType period)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSawtooth(get(src),get(period)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sawtooth(std::string name, ANLFloatType src, std::string period)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSawtooth(get(src),get(period)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sawtooth(std::string name, std::string src, ANLFloatType period)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSawtooth(get(src),get(period)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sawtooth(std::string name, std::string src, std::string period)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSawtooth(get(src),get(period)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, ANLFloatType src, ANLFloatType sx, ANLFloatType sy, ANLFloatType sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, ANLFloatType src, ANLFloatType sx, ANLFloatType sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, ANLFloatType src, ANLFloatType sx, std::string sy, ANLFloatType sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, ANLFloatType src, ANLFloatType sx, std::string sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, ANLFloatType src, std::string sx, ANLFloatType sy, ANLFloatType sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, ANLFloatType src, std::string sx, ANLFloatType sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, ANLFloatType src, std::string sx, std::string sy, ANLFloatType sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, ANLFloatType src, std::string sx, std::string sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, ANLFloatType sx, ANLFloatType sy, ANLFloatType sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, ANLFloatType sx, ANLFloatType sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, ANLFloatType sx, std::string sy, ANLFloatType sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, ANLFloatType sx, std::string sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, std::string sx, ANLFloatType sy, ANLFloatType sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, std::string sx, ANLFloatType sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, std::string sx, std::string sy, ANLFloatType sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, std::string sx, std::string sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, ANLFloatType src, ANLFloatType scale, ANLFloatType offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleOffset(get(src),get(scale),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, ANLFloatType src, ANLFloatType scale, std::string offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleOffset(get(src),get(scale),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, ANLFloatType src, std::string scale, ANLFloatType offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleOffset(get(src),get(scale),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, ANLFloatType src, std::string scale, std::string offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleOffset(get(src),get(scale),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, std::string src, ANLFloatType scale, ANLFloatType offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleOffset(get(src),get(scale),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, std::string src, ANLFloatType scale, std::string offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleOffset(get(src),get(scale),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, std::string src, std::string scale, ANLFloatType offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleOffset(get(src),get(scale),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, std::string src, std::string scale, std::string offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleOffset(get(src),get(scale),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff)
    {
	std::cout << "1" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, std::string falloff)
    {
	std::cout << "2" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, ANLFloatType high, ANLFloatType control, std::string threshold, ANLFloatType falloff)
    {
	std::cout << "3" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, ANLFloatType high, ANLFloatType control, std::string threshold, std::string falloff)
    {
	std::cout << "4" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, ANLFloatType high, std::string control, ANLFloatType threshold, ANLFloatType falloff)
    {
	std::cout << "5" << std::endl;
		std::cout << "Test" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, ANLFloatType high, std::string control, ANLFloatType threshold, std::string falloff)
    {
	std::cout << "6" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, ANLFloatType high, std::string control, std::string threshold, ANLFloatType falloff)
    {
	std::cout << "7" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, ANLFloatType high, std::string control, std::string threshold, std::string falloff)
    {
	std::cout << "8" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, std::string high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff)
    {
	std::cout << "9" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, std::string high, ANLFloatType control, ANLFloatType threshold, std::string falloff)
    {
	std::cout << "10" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, std::string high, ANLFloatType control, std::string threshold, ANLFloatType falloff)
    {
	std::cout << "11" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, std::string high, ANLFloatType control, std::string threshold, std::string falloff)
    {
	std::cout << "12" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, std::string high, std::string control, ANLFloatType threshold, ANLFloatType falloff)
    {
	std::cout << "13" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, std::string high, std::string control, ANLFloatType threshold, std::string falloff)
    {
	std::cout << "14" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, std::string high, std::string control, std::string threshold, ANLFloatType falloff)
    {
	std::cout << "15" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, ANLFloatType low, std::string high, std::string control, std::string threshold, std::string falloff)
    {
	std::cout << "16" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff)
    {
	std::cout << "17" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, std::string falloff)
    {
	std::cout << "18" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, ANLFloatType high, ANLFloatType control, std::string threshold, ANLFloatType falloff)
    {
	std::cout << "19" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, ANLFloatType high, ANLFloatType control, std::string threshold, std::string falloff)
    {
	std::cout << "20" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, ANLFloatType high, std::string control, ANLFloatType threshold, ANLFloatType falloff)
    {
	std::cout << "21" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, ANLFloatType high, std::string control, ANLFloatType threshold, std::string falloff)
    {
	std::cout << "22" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, ANLFloatType high, std::string control, std::string threshold, ANLFloatType falloff)
    {
	std::cout << "23" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, ANLFloatType high, std::string control, std::string threshold, std::string falloff)
    {
	std::cout << "24" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff)
    {
	std::cout << "25" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, ANLFloatType control, ANLFloatType threshold, std::string falloff)
    {
	std::cout << "26" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, ANLFloatType control, std::string threshold, ANLFloatType falloff)
    {
	std::cout << "27" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, ANLFloatType control, std::string threshold, std::string falloff)
    {
	std::cout << "28" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, std::string control, ANLFloatType threshold, ANLFloatType falloff)
    {
	std::cout << "29" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, std::string control, ANLFloatType threshold, std::string falloff)
    {
	std::cout << "30" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, std::string control, std::string threshold, ANLFloatType falloff)
    {
	std::cout << "31" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, std::string control, std::string threshold, std::string falloff)
    {
	std::cout << "32" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, ANLFloatType radius, ANLFloatType cx, ANLFloatType cy, ANLFloatType cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, ANLFloatType radius, ANLFloatType cx, ANLFloatType cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, ANLFloatType radius, ANLFloatType cx, std::string cy, ANLFloatType cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, ANLFloatType radius, ANLFloatType cx, std::string cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, ANLFloatType radius, std::string cx, ANLFloatType cy, ANLFloatType cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, ANLFloatType radius, std::string cx, ANLFloatType cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, ANLFloatType radius, std::string cx, std::string cy, ANLFloatType cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, ANLFloatType radius, std::string cx, std::string cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, ANLFloatType cx, ANLFloatType cy, ANLFloatType cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, ANLFloatType cx, ANLFloatType cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, ANLFloatType cx, std::string cy, ANLFloatType cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, ANLFloatType cx, std::string cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, std::string cx, ANLFloatType cy, ANLFloatType cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, std::string cx, ANLFloatType cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, std::string cx, std::string cy, ANLFloatType cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, std::string cx, std::string cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::tiers(std::string name, ANLFloatType src, int numtiers, bool smooth)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTiers(get(src),numtiers,smooth));
        return *this;
    }

    CTreeContainer &CTreeContainer::tiers(std::string name, std::string src, int numtiers, bool smooth)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTiers(get(src),numtiers,smooth));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, ANLFloatType src, ANLFloatType tx, ANLFloatType ty, ANLFloatType tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, ANLFloatType src, ANLFloatType tx, ANLFloatType ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, ANLFloatType src, ANLFloatType tx, std::string ty, ANLFloatType tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, ANLFloatType src, ANLFloatType tx, std::string ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, ANLFloatType src, std::string tx, ANLFloatType ty, ANLFloatType tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, ANLFloatType src, std::string tx, ANLFloatType ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, ANLFloatType src, std::string tx, std::string ty, ANLFloatType tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, ANLFloatType src, std::string tx, std::string ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, ANLFloatType tx, ANLFloatType ty, ANLFloatType tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, ANLFloatType tx, ANLFloatType ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, ANLFloatType tx, std::string ty, ANLFloatType tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, ANLFloatType tx, std::string ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, std::string tx, ANLFloatType ty, ANLFloatType tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, std::string tx, ANLFloatType ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, std::string tx, std::string ty, ANLFloatType tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, std::string tx, std::string ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::triangle(std::string name, ANLFloatType src, ANLFloatType period, ANLFloatType offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTriangle(get(src),get(period),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::triangle(std::string name, ANLFloatType src, ANLFloatType period, std::string offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTriangle(get(src),get(period),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::triangle(std::string name, ANLFloatType src, std::string period, ANLFloatType offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTriangle(get(src),get(period),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::triangle(std::string name, ANLFloatType src, std::string period, std::string offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTriangle(get(src),get(period),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::triangle(std::string name, std::string src, ANLFloatType period, ANLFloatType offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTriangle(get(src),get(period),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::triangle(std::string name, std::string src, ANLFloatType period, std::string offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTriangle(get(src),get(period),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::triangle(std::string name, std::string src, std::string period, ANLFloatType offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTriangle(get(src),get(period),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::triangle(std::string name, std::string src, std::string period, std::string offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTriangle(get(src),get(period),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlend(std::string name, ANLFloatType control, SRGBA low, SRGBA high)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlend(get(control), getRGBA(low), getRGBA(high)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlend(std::string name, ANLFloatType control, SRGBA low, std::string high)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlend(get(control), getRGBA(low), getRGBA(high)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlend(std::string name, ANLFloatType control, std::string low, SRGBA high)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlend(get(control), getRGBA(low), getRGBA(high)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlend(std::string name, ANLFloatType control, std::string low, std::string high)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlend(get(control), getRGBA(low), getRGBA(high)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlend(std::string name, std::string control, SRGBA low, SRGBA high)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlend(get(control), getRGBA(low), getRGBA(high)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlend(std::string name, std::string control, SRGBA low, std::string high)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlend(get(control), getRGBA(low), getRGBA(high)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlend(std::string name, std::string control, std::string low, SRGBA high)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlend(get(control), getRGBA(low), getRGBA(high)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlend(std::string name, std::string control, std::string low, std::string high)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlend(get(control), getRGBA(low), getRGBA(high)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlendOps(std::string name, SRGBA s1, SRGBA s2, int op1, int op2)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlendOps(getRGBA(s1), getRGBA(s2), op1, op2));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlendOps(std::string name, SRGBA s1, std::string s2, int op1, int op2)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlendOps(getRGBA(s1), getRGBA(s2), op1, op2));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlendOps(std::string name, std::string s1, SRGBA s2, int op1, int op2)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlendOps(getRGBA(s1), getRGBA(s2), op1, op2));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlendOps(std::string name, std::string s1, std::string s2, int op1, int op2)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlendOps(getRGBA(s1), getRGBA(s2), op1, op2));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaColorOps(std::string name, SRGBA s1, SRGBA s2, int op)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBAColorOps(getRGBA(s1), getRGBA(s2), op));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaColorOps(std::string name, SRGBA s1, std::string s2, int op)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBAColorOps(getRGBA(s1), getRGBA(s2), op));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaColorOps(std::string name, std::string s1, SRGBA s2, int op)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBAColorOps(getRGBA(s1), getRGBA(s2), op));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaColorOps(std::string name, std::string s1, std::string s2, int op)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBAColorOps(getRGBA(s1), getRGBA(s2), op));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, ANLFloatType r, ANLFloatType g, ANLFloatType b, ANLFloatType a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, ANLFloatType r, ANLFloatType g, ANLFloatType b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, ANLFloatType r, ANLFloatType g, std::string b, ANLFloatType a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, ANLFloatType r, ANLFloatType g, std::string b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, ANLFloatType r, std::string g, ANLFloatType b, ANLFloatType a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, ANLFloatType r, std::string g, ANLFloatType b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, ANLFloatType r, std::string g, std::string b, ANLFloatType a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, ANLFloatType r, std::string g, std::string b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, ANLFloatType g, ANLFloatType b, ANLFloatType a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, ANLFloatType g, ANLFloatType b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, ANLFloatType g, std::string b, ANLFloatType a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, ANLFloatType g, std::string b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, std::string g, ANLFloatType b, ANLFloatType a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, std::string g, ANLFloatType b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, std::string g, std::string b, ANLFloatType a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, std::string g, std::string b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaHSVtoRGBA(std::string name, SRGBA c)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBAHSVToRGBA(getRGBA(c)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaHSVtoRGBA(std::string name, std::string c)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBAHSVToRGBA(getRGBA(c)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRGBAtoHSV(std::string name, SRGBA c)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARGBAToHSV(getRGBA(c)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRGBAtoHSV(std::string name, std::string c)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARGBAToHSV(getRGBA(c)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaImplicitGrayscale(std::string name, ANLFloatType s)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBAImplicitGrayscale(get(s)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaImplicitGrayscale(std::string name, std::string s)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBAImplicitGrayscale(get(s)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaNormalize(std::string name, SRGBA c)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBANormalize(getRGBA(c)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaNormalize(std::string name, std::string c)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBANormalize(getRGBA(c)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, ANLFloatType ay, std::string az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, ANLFloatType ay, std::string az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, std::string ay, ANLFloatType az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, std::string ay, ANLFloatType az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, std::string ay, std::string az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, std::string ay, std::string az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, ANLFloatType ay, ANLFloatType az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, ANLFloatType ay, std::string az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, ANLFloatType ay, std::string az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, ANLFloatType az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, ANLFloatType az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, std::string az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, std::string az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, ANLFloatType ay, std::string az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, ANLFloatType ay, std::string az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, std::string ay, ANLFloatType az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, std::string ay, ANLFloatType az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, std::string ay, std::string az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, std::string ay, std::string az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, ANLFloatType ay, ANLFloatType az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, ANLFloatType ay, std::string az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, ANLFloatType ay, std::string az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, ANLFloatType az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, ANLFloatType az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, std::string az, ANLFloatType angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, std::string az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, ANLFloatType control, ANLFloatType threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, ANLFloatType control, std::string threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, ANLFloatType control, std::string threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, ANLFloatType threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, ANLFloatType threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, std::string threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, std::string threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, ANLFloatType control, ANLFloatType threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, ANLFloatType control, std::string threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, ANLFloatType control, std::string threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, ANLFloatType threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, ANLFloatType threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, std::string threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, std::string threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, ANLFloatType control, ANLFloatType threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, ANLFloatType control, std::string threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, ANLFloatType control, std::string threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, ANLFloatType threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, ANLFloatType threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, std::string threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, std::string threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, ANLFloatType control, ANLFloatType threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, ANLFloatType control, std::string threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, ANLFloatType control, std::string threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, std::string control, ANLFloatType threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }
    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, std::string control, ANLFloatType threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, std::string control, std::string threshold, ANLFloatType falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, std::string control, std::string threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

	CTreeContainer &CTreeContainer::implicitBufferImplicitAdapter(std::string name, std::string source, int mapping, SMappingRanges ranges, bool use_z, ANLFloatType z)
    {
        if(getImplicitBuffer(name)) return *this;
        auto src=get(source);
        if(!src) return *this;

        m_implicitbuffers[name]=std::shared_ptr<CImplicitBufferBase>( new CImplicitBufferImplicitAdapter(src,mapping,ranges,use_z,z));


        return *this;
    }

    CTreeContainer &CTreeContainer::implicitBufferBlur(std::string name, std::string source, ANLFloatType blursize, bool seamless)
    {
        if(getImplicitBuffer(name) ||get(name) || getRGBA(name)) return *this;
        auto src=getImplicitBuffer(source);
        if(!src) return *this;

        m_implicitbuffers[name]=std::shared_ptr<CImplicitBufferBase>(new CImplicitBufferBlur(src,blursize,seamless));


        return *this;
    }

    CTreeContainer &CTreeContainer::implicitBufferScaleToRange(std::string name, std::string source, ANLFloatType low, ANLFloatType high)
    {
        if(getImplicitBuffer(name) ||get(name) || getRGBA(name)) return *this;
        auto src=getImplicitBuffer(source);
        if(!src) return *this;

        m_implicitbuffers[name]=std::shared_ptr<CImplicitBufferBase>(new CImplicitBufferScaleToRange(src,low,high));


        return *this;
    }

    CTreeContainer &CTreeContainer::implicitBufferBumpMap(std::string name, std::string source, ANLFloatType lx, ANLFloatType ly, ANLFloatType lz, ANLFloatType spacing, bool seamless)
    {
        if(getImplicitBuffer(name) ||get(name) || getRGBA(name)) return *this;
        auto src=getImplicitBuffer(source);
        if(!src) return *this;

        m_implicitbuffers[name]=std::shared_ptr<CImplicitBufferBase>(new CImplicitBufferBumpMap(src,lx,ly,lz,spacing,seamless));



        return *this;
    }

    CTreeContainer &CTreeContainer::implicitBufferUnaryMath(std::string name, std::string source, int op)
    {
         if(getImplicitBuffer(name) ||get(name) || getRGBA(name)) return *this;
        auto src=getImplicitBuffer(source);
        if(!src) return *this;

        m_implicitbuffers[name]=std::shared_ptr<CImplicitBufferBase>(new CImplicitBufferUnaryMath(src,op));


        return *this;
    }

    CTreeContainer &CTreeContainer::implicitBufferSimpleErode(std::string name, std::string source, int numdrops, float power, unsigned int iterations)
    {
        if(getImplicitBuffer(name) ||get(name) || getRGBA(name)) return *this;
        auto src=getImplicitBuffer(source);
        if(!src) return *this;

        m_implicitbuffers[name]=std::shared_ptr<CImplicitBufferBase>(new CImplicitBufferSimpleErode(src,numdrops,power,iterations));



        return *this;
    }

    CTreeContainer &CTreeContainer::implicitBufferSimpleRainfall(std::string name, std::string source)
    {
        if(getImplicitBuffer(name) ||get(name) || getRGBA(name)) return *this;
        auto src=getImplicitBuffer(source);
        if(!src) return *this;


        m_implicitbuffers[name]=std::shared_ptr<CImplicitBufferBase>(new CImplicitBufferSimpleRainfall(src));



        return *this;
    }

	CTreeContainer &CTreeContainer::implicitBufferSelect(std::string name, std::string low, std::string high, std::string control, ANLFloatType threshold, ANLFloatType falloff)
	{
		if(getImplicitBuffer(name) || get(name) || getRGBA(name) || getRGBABuffer(name)) return *this;
		auto l=getImplicitBuffer(low);
		auto h=getImplicitBuffer(high);
		auto c=getImplicitBuffer(control);
		if(!l || !h || !c) return *this;

		m_implicitbuffers[name]=std::shared_ptr<CImplicitBufferBase>(new CImplicitBufferSelect(l,h,c,threshold,falloff));
		return *this;
	}



    CTreeContainer &CTreeContainer::rgbaBufferRGBAAdapter(std::string name, std::string source, int mapping, SMappingRanges ranges, bool use_z, ANLFloatType z)
    {
        if(getRGBABuffer(name) || getImplicitBuffer(name) || get(name) || getRGBA(name)) return *this;
        auto src=getRGBA(source);
        if(!src) return *this;

        m_rgbabuffers[name]=std::shared_ptr<CRGBABufferBase>(new CRGBABufferRGBAAdapter(src,mapping,ranges,use_z,z));


        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBufferImplicitBufferAdapter(std::string name, std::string source)
    {
        if(getRGBABuffer(name) || getImplicitBuffer(name) || get(name) || getRGBA(name)) return *this;
        auto src=getImplicitBuffer(source);
        if(!src) return *this;

        m_rgbabuffers[name]=std::shared_ptr<CRGBABufferBase>(new CRGBABufferImplicitBufferAdapter(src));


        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBufferBlur(std::string name, std::string source, ANLFloatType blursize, bool seamless)
    {
        if(getRGBABuffer(name) || getImplicitBuffer(name) || get(name) || getRGBA(name)) return *this;
        auto src=getRGBABuffer(source);
        if(!src) return *this;

        m_rgbabuffers[name]=std::shared_ptr<CRGBABufferBase>(new CRGBABufferBlur(src,blursize,seamless));

        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBufferImplicitBufferMultiply(std::string name, std::string rgbasource, std::string implicitsource)
    {
        if(getRGBABuffer(name) || getImplicitBuffer(name) || get(name) || getRGBA(name)) return *this;
        auto rgbasrc=getRGBABuffer(rgbasource);
        if(!rgbasrc) return *this;

        auto impsrc=getImplicitBuffer(implicitsource);
        if(!impsrc) return *this;

        m_rgbabuffers[name]=std::shared_ptr<CRGBABufferBase>(new CRGBABufferImplicitBufferMultiply(rgbasrc,impsrc));

        return *this;
    }

	CTreeContainer &CTreeContainer::rgbaBufferSelect(std::string name, std::string low, std::string high, std::string control, ANLFloatType threshold, ANLFloatType falloff)
	{
		if(getImplicitBuffer(name) || get(name) || getRGBA(name) || getRGBABuffer(name)) return *this;
		auto l=getRGBABuffer(low);
		auto h=getRGBABuffer(high);
		auto c=getImplicitBuffer(control);
		if(!l || !h || !c) return *this;

		m_rgbabuffers[name]=std::shared_ptr<CRGBABufferBase>(new CRGBABufferSelect(l,h,c,threshold,falloff));
		return *this;
	}





};

