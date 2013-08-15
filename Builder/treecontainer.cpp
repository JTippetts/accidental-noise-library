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

    CTreeContainer &CTreeContainer::autoCorrect(std::string name, std::string src, double low, double high)
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

    CTreeContainer &CTreeContainer::blend(std::string name, double low, double high, double control)
    {
        if(get(name)) return *this;
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBlend(low,high,control));
        return *this;
    }

    CTreeContainer &CTreeContainer::blend(std::string name, double low, double high, std::string control)
    {
        if(get(name)) return *this;
        CImplicitModuleBase * c=get(control);
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBlend(low,high,c));
        return *this;
    }

    CTreeContainer &CTreeContainer::blend(std::string name, double low, std::string high, double control)
    {
        if(get(name)) return *this;
        CImplicitModuleBase * h=get(high);
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBlend(low,h,control));
        return *this;
    }

    CTreeContainer &CTreeContainer::blend(std::string name, double low, std::string high, std::string control)
    {
        if(get(name)) return *this;
        CImplicitModuleBase * h=get(high);
        CImplicitModuleBase * c=get(control);
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBlend(low,h,c));
        return *this;
    }

    CTreeContainer &CTreeContainer::blend(std::string name, std::string low, double high, double control)
    {
        if(get(name)) return *this;
        CImplicitModuleBase * l=get(low);
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBlend(l,high,control));
        return *this;
    }

    CTreeContainer &CTreeContainer::blend(std::string name, std::string low, double high, std::string control)
    {
        if(get(name)) return *this;
        CImplicitModuleBase * l=get(low);
        CImplicitModuleBase * c=get(control);
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBlend(l,high,c));
        return *this;
    }

    CTreeContainer &CTreeContainer::blend(std::string name, std::string low, std::string high, double control)
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

    CTreeContainer &CTreeContainer::brightContrast(std::string name, double s, double b, double t, double f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, double s, double b, double t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, double s, double b, std::string t, double f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, double s, double b, std::string t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, double s, std::string b, double t, double f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, double s, std::string b, double t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, double s, std::string b, std::string t, double f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, double s, std::string b, std::string t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, double b, double t, double f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, double b, double t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, double b, std::string t, double f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, double b, std::string t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, std::string b, double t, double f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, std::string b, double t, std::string f)
    {
        if(get(name)) return *this;

        auto src=get(s);
        auto bright=get(b);
        auto thresh=get(t);
        auto factor=get(f);

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitBrightContrast(src,bright,thresh,factor));
        return *this;
    }

    CTreeContainer &CTreeContainer::brightContrast(std::string name, std::string s, std::string b, std::string t, double f)
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

    CTreeContainer &CTreeContainer::cache(std::string name, double v)
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

    CTreeContainer &CTreeContainer::cellular(std::string name, std::string g, double a, double b, double c, double d)
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

    CTreeContainer &CTreeContainer::clamp(std::string name, double s, double l, double h)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitClamp(get(s), get(l), get(h)));
        return *this;
    }

    CTreeContainer &CTreeContainer::clamp(std::string name, double s, double l, std::string h)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitClamp(get(s), get(l), get(h)));
        return *this;
    }

    CTreeContainer &CTreeContainer::clamp(std::string name, double s, std::string l, double h)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitClamp(get(s), get(l), get(h)));
        return *this;
    }

    CTreeContainer &CTreeContainer::clamp(std::string name, double s, std::string l, std::string h)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitClamp(get(s), get(l), get(h)));
        return *this;
    }

    CTreeContainer &CTreeContainer::clamp(std::string name, std::string s, double l, double h)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitClamp(get(s), get(l), get(h)));
        return *this;
    }

    CTreeContainer &CTreeContainer::clamp(std::string name, std::string s, double l, std::string h)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitClamp(get(s), get(l), get(h)));
        return *this;
    }

    CTreeContainer &CTreeContainer::clamp(std::string name, std::string s, std::string l, double h)
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

    CTreeContainer &CTreeContainer::constant(std::string name, double v)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitConstant(v));
        return *this;
    }

    CTreeContainer &CTreeContainer::curve(std::string name, double s, int interptype)
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

    CTreeContainer &CTreeContainer::fractal(std::string name, unsigned int type, unsigned int basis, unsigned int interp, int octaves, double freq)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitFractal(type,basis,interp,octaves,freq,true));
        return *this;
    }

    CTreeContainer &CTreeContainer::functionGradient(std::string name, double s, int axis, double spacing)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitFunctionGradient(get(s),axis,spacing));
        return *this;
    }

    CTreeContainer &CTreeContainer::functionGradient(std::string name, std::string s, int axis, double spacing)

    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitFunctionGradient(get(s),axis,spacing));
        return *this;
    }

    CTreeContainer &CTreeContainer::gradient(std::string name, double x1, double x2, double y1, double y2, double z1, double z2, double w1, double w2, double u1, double u2, double v1, double v2)
    {
        if(get(name)) return *this;
        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitGradient(x1,x2,y1,y2,z1,z2,w1,w2,u1,u2,v1,v2));
        return *this;
    }

    CTreeContainer &CTreeContainer::math(std::string name, int op, double s1, double s2)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitMath(op,get(s1), get(s2)));
        return *this;
    }

    CTreeContainer &CTreeContainer::math(std::string name, int op, double s1, std::string s2)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitMath(op,get(s1), get(s2)));
        return *this;
    }

    CTreeContainer &CTreeContainer::math(std::string name, int op, std::string s1, double s2)
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

    CTreeContainer &CTreeContainer::normalizeCoords(std::string name, double src, double length)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitNormalizeCoords(get(src), get(length)));
        return *this;
    }

    CTreeContainer &CTreeContainer::normalizeCoords(std::string name, double src, std::string length)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitNormalizeCoords(get(src), get(length)));
        return *this;
    }

    CTreeContainer &CTreeContainer::normalizeCoords(std::string name, std::string src, double length)
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

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, double ax, double ay, double az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, double ax, double ay, double az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, double ax, double ay, std::string az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, double ax, double ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, double ax, std::string ay, double az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, double ax, std::string ay, double az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, double ax, std::string ay, std::string az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, double ax, std::string ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, std::string ax, double ay, double az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, std::string ax, double ay, double az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, std::string ax, double ay, std::string az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, std::string ax, double ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, std::string ax, std::string ay, double az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, std::string ax, std::string ay, double az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, std::string ax, std::string ay, std::string az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, double src, std::string ax, std::string ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, double ax, double ay, double az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, double ax, double ay, double az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, double ax, double ay, std::string az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, double ax, double ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, double ax, std::string ay, double az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, double ax, std::string ay, double az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, double ax, std::string ay, std::string az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, double ax, std::string ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, double ay, double az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, double ay, double az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, double ay, std::string az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, double ay, std::string az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, std::string ay, double az, double angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, std::string ay, double az, std::string angle)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitRotateDomain(get(src),get(ax),get(ay),get(az),get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rotateDomain(std::string name, std::string src, std::string ax, std::string ay, std::string az, double angle)
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

    CTreeContainer &CTreeContainer::sawtooth(std::string name, double src, double period)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSawtooth(get(src),get(period)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sawtooth(std::string name, double src, std::string period)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSawtooth(get(src),get(period)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sawtooth(std::string name, std::string src, double period)
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

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, double src, double sx, double sy, double sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, double src, double sx, double sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, double src, double sx, std::string sy, double sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, double src, double sx, std::string sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, double src, std::string sx, double sy, double sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, double src, std::string sx, double sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, double src, std::string sx, std::string sy, double sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, double src, std::string sx, std::string sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, double sx, double sy, double sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, double sx, double sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, double sx, std::string sy, double sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, double sx, std::string sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, std::string sx, double sy, double sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, std::string sx, double sy, std::string sz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleDomain(get(src),get(sx),get(sy),get(sz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleDomain(std::string name, std::string src, std::string sx, std::string sy, double sz)
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

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, double src, double scale, double offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleOffset(get(src),get(scale),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, double src, double scale, std::string offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleOffset(get(src),get(scale),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, double src, std::string scale, double offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleOffset(get(src),get(scale),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, double src, std::string scale, std::string offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleOffset(get(src),get(scale),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, std::string src, double scale, double offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleOffset(get(src),get(scale),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, std::string src, double scale, std::string offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitScaleOffset(get(src),get(scale),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::scaleOffset(std::string name, std::string src, std::string scale, double offset)
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

    CTreeContainer &CTreeContainer::select(std::string name, double low, double high, double control, double threshold, double falloff)
    {
	std::cout << "1" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, double high, double control, double threshold, std::string falloff)
    {
	std::cout << "2" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, double high, double control, std::string threshold, double falloff)
    {
	std::cout << "3" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, double high, double control, std::string threshold, std::string falloff)
    {
	std::cout << "4" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, double high, std::string control, double threshold, double falloff)
    {
	std::cout << "5" << std::endl;
		std::cout << "Test" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, double high, std::string control, double threshold, std::string falloff)
    {
	std::cout << "6" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, double high, std::string control, std::string threshold, double falloff)
    {
	std::cout << "7" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, double high, std::string control, std::string threshold, std::string falloff)
    {
	std::cout << "8" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, std::string high, double control, double threshold, double falloff)
    {
	std::cout << "9" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, std::string high, double control, double threshold, std::string falloff)
    {
	std::cout << "10" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, std::string high, double control, std::string threshold, double falloff)
    {
	std::cout << "11" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, std::string high, double control, std::string threshold, std::string falloff)
    {
	std::cout << "12" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, std::string high, std::string control, double threshold, double falloff)
    {
	std::cout << "13" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, std::string high, std::string control, double threshold, std::string falloff)
    {
	std::cout << "14" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, std::string high, std::string control, std::string threshold, double falloff)
    {
	std::cout << "15" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, double low, std::string high, std::string control, std::string threshold, std::string falloff)
    {
	std::cout << "16" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, double high, double control, double threshold, double falloff)
    {
	std::cout << "17" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, double high, double control, double threshold, std::string falloff)
    {
	std::cout << "18" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, double high, double control, std::string threshold, double falloff)
    {
	std::cout << "19" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, double high, double control, std::string threshold, std::string falloff)
    {
	std::cout << "20" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, double high, std::string control, double threshold, double falloff)
    {
	std::cout << "21" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, double high, std::string control, double threshold, std::string falloff)
    {
	std::cout << "22" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, double high, std::string control, std::string threshold, double falloff)
    {
	std::cout << "23" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, double high, std::string control, std::string threshold, std::string falloff)
    {
	std::cout << "24" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, double control, double threshold, double falloff)
    {
	std::cout << "25" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, double control, double threshold, std::string falloff)
    {
	std::cout << "26" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, double control, std::string threshold, double falloff)
    {
	std::cout << "27" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, double control, std::string threshold, std::string falloff)
    {
	std::cout << "28" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, std::string control, double threshold, double falloff)
    {
	std::cout << "29" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, std::string control, double threshold, std::string falloff)
    {
	std::cout << "30" << std::endl;
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSelect(get(low),get(high),get(control),get(threshold),get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::select(std::string name, std::string low, std::string high, std::string control, std::string threshold, double falloff)
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

    CTreeContainer &CTreeContainer::sphere(std::string name, double radius, double cx, double cy, double cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, double radius, double cx, double cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, double radius, double cx, std::string cy, double cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, double radius, double cx, std::string cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, double radius, std::string cx, double cy, double cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, double radius, std::string cx, double cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, double radius, std::string cx, std::string cy, double cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, double radius, std::string cx, std::string cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, double cx, double cy, double cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, double cx, double cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, double cx, std::string cy, double cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, double cx, std::string cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, std::string cx, double cy, double cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, std::string cx, double cy, std::string cz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitSphere(get(radius),get(cx),get(cy),get(cz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::sphere(std::string name, std::string radius, std::string cx, std::string cy, double cz)
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

    CTreeContainer &CTreeContainer::tiers(std::string name, double src, int numtiers, bool smooth)
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

    CTreeContainer &CTreeContainer::translateDomain(std::string name, double src, double tx, double ty, double tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, double src, double tx, double ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, double src, double tx, std::string ty, double tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, double src, double tx, std::string ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, double src, std::string tx, double ty, double tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, double src, std::string tx, double ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, double src, std::string tx, std::string ty, double tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, double src, std::string tx, std::string ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, double tx, double ty, double tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, double tx, double ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, double tx, std::string ty, double tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, double tx, std::string ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, std::string tx, double ty, double tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, std::string tx, double ty, std::string tz)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTranslateDomain(get(src),get(tx),get(ty),get(tz)));
        return *this;
    }

    CTreeContainer &CTreeContainer::translateDomain(std::string name, std::string src, std::string tx, std::string ty, double tz)
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

    CTreeContainer &CTreeContainer::triangle(std::string name, double src, double period, double offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTriangle(get(src),get(period),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::triangle(std::string name, double src, double period, std::string offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTriangle(get(src),get(period),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::triangle(std::string name, double src, std::string period, double offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTriangle(get(src),get(period),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::triangle(std::string name, double src, std::string period, std::string offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTriangle(get(src),get(period),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::triangle(std::string name, std::string src, double period, double offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTriangle(get(src),get(period),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::triangle(std::string name, std::string src, double period, std::string offset)
    {
        if(get(name)) return *this;

        m_modules[name]=std::shared_ptr<CImplicitModuleBase>(new CImplicitTriangle(get(src),get(period),get(offset)));
        return *this;
    }

    CTreeContainer &CTreeContainer::triangle(std::string name, std::string src, std::string period, double offset)
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

    CTreeContainer &CTreeContainer::rgbaBlend(std::string name, double control, SRGBA low, SRGBA high)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlend(get(control), getRGBA(low), getRGBA(high)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlend(std::string name, double control, SRGBA low, std::string high)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlend(get(control), getRGBA(low), getRGBA(high)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlend(std::string name, double control, std::string low, SRGBA high)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBABlend(get(control), getRGBA(low), getRGBA(high)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaBlend(std::string name, double control, std::string low, std::string high)
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

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, double r, double g, double b, double a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, double r, double g, double b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, double r, double g, std::string b, double a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, double r, double g, std::string b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, double r, std::string g, double b, double a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, double r, std::string g, double b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, double r, std::string g, std::string b, double a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, double r, std::string g, std::string b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, double g, double b, double a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, double g, double b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, double g, std::string b, double a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, double g, std::string b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, std::string g, double b, double a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, std::string g, double b, std::string a, int mode)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBACompositeChannels(get(r),get(g),get(b),get(a),mode));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaCompositeChannels(std::string name, std::string r, std::string g, std::string b, double a, int mode)
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

    CTreeContainer &CTreeContainer::rgbaImplicitGrayscale(std::string name, double s)
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

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, double ax, double ay, double az, double angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, double ax, double ay, double az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, double ax, double ay, std::string az, double angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, double ax, double ay, std::string az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, double ax, std::string ay, double az, double angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, double ax, std::string ay, double az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, double ax, std::string ay, std::string az, double angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, double ax, std::string ay, std::string az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, double ay, double az, double angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, double ay, double az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, double ay, std::string az, double angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, double ay, std::string az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, double az, double angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, double az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, std::string az, double angle)
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

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, double ax, double ay, double az, double angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, double ax, double ay, double az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, double ax, double ay, std::string az, double angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, double ax, double ay, std::string az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, double ax, std::string ay, double az, double angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, double ax, std::string ay, double az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, double ax, std::string ay, std::string az, double angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, double ax, std::string ay, std::string az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, double ay, double az, double angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, double ay, double az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, double ay, std::string az, double angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, double ay, std::string az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, double az, double angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, double az, std::string angle)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBARotateColor(getRGBA(c), get(ax), get(ay), get(az), get(angle)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, std::string az, double angle)
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

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, double control, double threshold, double falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, double control, double threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, double control, std::string threshold, double falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, double control, std::string threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, double threshold, double falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, double threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, std::string threshold, double falloff)
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

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, double control, double threshold, double falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, double control, double threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, double control, std::string threshold, double falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, double control, std::string threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, double threshold, double falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, double threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, std::string threshold, double falloff)
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

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, double control, double threshold, double falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, double control, double threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, double control, std::string threshold, double falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, double control, std::string threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, double threshold, double falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, double threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, std::string threshold, double falloff)
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

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, double control, double threshold, double falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, double control, double threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, double control, std::string threshold, double falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, double control, std::string threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, std::string control, double threshold, double falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }
    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, std::string control, double threshold, std::string falloff)
    {
        if(getRGBA(name)) return *this;

        m_rgbas[name]=std::shared_ptr<CRGBAModuleBase>(new CRGBASelect(getRGBA(low), getRGBA(high), get(control), get(threshold), get(falloff)));
        return *this;
    }

    CTreeContainer &CTreeContainer::rgbaSelect(std::string name, std::string low, std::string high, std::string control, std::string threshold, double falloff)
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

	CTreeContainer &CTreeContainer::implicitBufferImplicitAdapter(std::string name, std::string source, int mapping, SMappingRanges ranges, bool use_z, double z)
    {
        if(getImplicitBuffer(name)) return *this;
        auto src=get(source);
        if(!src) return *this;

        m_implicitbuffers[name]=std::shared_ptr<CImplicitBufferBase>( new CImplicitBufferImplicitAdapter(src,mapping,ranges,use_z,z));


        return *this;
    }

    CTreeContainer &CTreeContainer::implicitBufferBlur(std::string name, std::string source, double blursize, bool seamless)
    {
        if(getImplicitBuffer(name) ||get(name) || getRGBA(name)) return *this;
        auto src=getImplicitBuffer(source);
        if(!src) return *this;

        m_implicitbuffers[name]=std::shared_ptr<CImplicitBufferBase>(new CImplicitBufferBlur(src,blursize,seamless));


        return *this;
    }

    CTreeContainer &CTreeContainer::implicitBufferScaleToRange(std::string name, std::string source, double low, double high)
    {
        if(getImplicitBuffer(name) ||get(name) || getRGBA(name)) return *this;
        auto src=getImplicitBuffer(source);
        if(!src) return *this;

        m_implicitbuffers[name]=std::shared_ptr<CImplicitBufferBase>(new CImplicitBufferScaleToRange(src,low,high));


        return *this;
    }

    CTreeContainer &CTreeContainer::implicitBufferBumpMap(std::string name, std::string source, double lx, double ly, double lz, double spacing, bool seamless)
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

    CTreeContainer &CTreeContainer::implicitBufferSimpleErode(std::string name, std::string source, int numdrops, float power)
    {
        if(getImplicitBuffer(name) ||get(name) || getRGBA(name)) return *this;
        auto src=getImplicitBuffer(source);
        if(!src) return *this;

        m_implicitbuffers[name]=std::shared_ptr<CImplicitBufferBase>(new CImplicitBufferSimpleErode(src,numdrops,power));



        return *this;
    }

    CTreeContainer &CTreeContainer::implicitBufferSimpleRainfall(std::string name, std::string source, std::string depth, int iterations)
    {
        if(getImplicitBuffer(name) ||get(name) || getRGBA(name)) return *this;
        auto src=getImplicitBuffer(source);
        if(!src) return *this;
        auto dep=getImplicitBuffer(depth);
        if(!dep) return *this;

        m_implicitbuffers[name]=std::shared_ptr<CImplicitBufferBase>(new CImplicitBufferSimpleRainfall(src,dep,iterations));



        return *this;
    }
	
	CTreeContainer &CTreeContainer::implicitBufferSelect(std::string name, std::string low, std::string high, std::string control, double threshold, double falloff)
	{
		if(getImplicitBuffer(name) || get(name) || getRGBA(name) || getRGBABuffer(name)) return *this;
		auto l=getImplicitBuffer(low);
		auto h=getImplicitBuffer(high);
		auto c=getImplicitBuffer(control);
		if(!l || !h || !c) return *this;
		
		m_implicitbuffers[name]=std::shared_ptr<CImplicitBufferBase>(new CImplicitBufferSelect(l,h,c,threshold,falloff));
		return *this;
	}



    CTreeContainer &CTreeContainer::rgbaBufferRGBAAdapter(std::string name, std::string source, int mapping, SMappingRanges ranges, bool use_z, double z)
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

    CTreeContainer &CTreeContainer::rgbaBufferBlur(std::string name, std::string source, double blursize, bool seamless)
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
	
	CTreeContainer &CTreeContainer::rgbaBufferSelect(std::string name, std::string low, std::string high, std::string control, double threshold, double falloff)
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

