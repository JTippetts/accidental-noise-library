#ifndef TREECONTAINER_H
#define TREECONTAINER_H
#include "../Noise/anl_noise.h"
#include "../RGBA/anl_rgba.h"
#include "../Imaging/anl_imaging.h"
#include <map>
#include <string>

namespace anl
{
    class CTreeContainer
    {
        public:
        CTreeContainer(){}
        ~CTreeContainer();

        CTreeContainer &autoCorrect(std::string name, std::string src, ANLFloatType low=0, ANLFloatType high=1);
        CTreeContainer &basisFunction(std::string name, int type=GRADIENT, int interp=QUINTIC, bool rotate=true);
        CTreeContainer &blend(std::string name, ANLFloatType low, ANLFloatType high, ANLFloatType control);
        CTreeContainer &blend(std::string name, ANLFloatType low, ANLFloatType high, std::string control);
        CTreeContainer &blend(std::string name, ANLFloatType low, std::string high, ANLFloatType control);
        CTreeContainer &blend(std::string name, ANLFloatType low, std::string high, std::string control);
        CTreeContainer &blend(std::string name, std::string low, ANLFloatType high, ANLFloatType control);
        CTreeContainer &blend(std::string name, std::string low, ANLFloatType high, std::string control);
        CTreeContainer &blend(std::string name, std::string low, std::string high, ANLFloatType control);
        CTreeContainer &blend(std::string name, std::string low, std::string high, std::string control);

        CTreeContainer &brightContrast(std::string name, ANLFloatType s, ANLFloatType b, ANLFloatType t, ANLFloatType f);
        CTreeContainer &brightContrast(std::string name, ANLFloatType s, ANLFloatType b, ANLFloatType t, std::string f);
        CTreeContainer &brightContrast(std::string name, ANLFloatType s, ANLFloatType b, std::string t, ANLFloatType f);
        CTreeContainer &brightContrast(std::string name, ANLFloatType s, ANLFloatType b, std::string t, std::string f);
        CTreeContainer &brightContrast(std::string name, ANLFloatType s, std::string b, ANLFloatType t, ANLFloatType f);
        CTreeContainer &brightContrast(std::string name, ANLFloatType s, std::string b, ANLFloatType t, std::string f);
        CTreeContainer &brightContrast(std::string name, ANLFloatType s, std::string b, std::string t, ANLFloatType f);
        CTreeContainer &brightContrast(std::string name, ANLFloatType s, std::string b, std::string t, std::string f);
        CTreeContainer &brightContrast(std::string name, std::string s, ANLFloatType b, ANLFloatType t, ANLFloatType f);
        CTreeContainer &brightContrast(std::string name, std::string s, ANLFloatType b, ANLFloatType t, std::string f);
        CTreeContainer &brightContrast(std::string name, std::string s, ANLFloatType b, std::string t, ANLFloatType f);
        CTreeContainer &brightContrast(std::string name, std::string s, ANLFloatType b, std::string t, std::string f);
        CTreeContainer &brightContrast(std::string name, std::string s, std::string b, ANLFloatType t, ANLFloatType f);
        CTreeContainer &brightContrast(std::string name, std::string s, std::string b, ANLFloatType t, std::string f);
        CTreeContainer &brightContrast(std::string name, std::string s, std::string b, std::string t, ANLFloatType f);
        CTreeContainer &brightContrast(std::string name, std::string s, std::string b, std::string t, std::string f);

        CTreeContainer &cache(std::string name, ANLFloatType v);
        CTreeContainer &cache(std::string name, std::string v);

        CTreeContainer &cellular(std::string name, std::string g, ANLFloatType a=1, ANLFloatType b=0, ANLFloatType c=0, ANLFloatType d=0);
        CTreeContainer &cellularGenerator(std::string name, unsigned int distfunc=0);
		CTreeContainer &voronoi(std::string name, std::string g);

        CTreeContainer &clamp(std::string name, ANLFloatType s, ANLFloatType l, ANLFloatType h);
        CTreeContainer &clamp(std::string name, ANLFloatType s, ANLFloatType l, std::string h);
        CTreeContainer &clamp(std::string name, ANLFloatType s, std::string l, ANLFloatType h);
        CTreeContainer &clamp(std::string name, ANLFloatType s, std::string l, std::string h);
        CTreeContainer &clamp(std::string name, std::string s, ANLFloatType l, ANLFloatType h);
        CTreeContainer &clamp(std::string name, std::string s, ANLFloatType l, std::string h);
        CTreeContainer &clamp(std::string name, std::string s, std::string l, ANLFloatType h);
        CTreeContainer &clamp(std::string name, std::string s, std::string l, std::string h);

        // TODO: Combiner. Might look at this to include fractal combiner types so that I can do custom fractals
        // The trick will be how to do variable entries
        // Maybe just do a single constructor, with default values for everything except the first two entries?

        CTreeContainer &constant(std::string name, ANLFloatType v);

        CTreeContainer &curve(std::string name, ANLFloatType s, int interptype);
        CTreeContainer &curve(std::string name, std::string s, int interptype);

        // TODO: ImplicitExtractRGBAChannel

        CTreeContainer &fractal(std::string name, unsigned int type=FBM, unsigned int basis=GRADIENT, unsigned int interp=QUINTIC, int octaves=8, ANLFloatType freq=1, bool rotate=true);

        CTreeContainer &functionGradient(std::string name, ANLFloatType s, int axis=X_AXIS, ANLFloatType spacing=0.0001);
        CTreeContainer &functionGradient(std::string name, std::string s, int axis=X_AXIS, ANLFloatType spacing=0.0001);

        CTreeContainer &gradient(std::string name, ANLFloatType x1, ANLFloatType x2, ANLFloatType y1, ANLFloatType y2, ANLFloatType z1, ANLFloatType z2, ANLFloatType w1=0, ANLFloatType w2=0, ANLFloatType u1=0, ANLFloatType u2=0, ANLFloatType v1=0, ANLFloatType v2=0);

        // TODO: Magnitude

        CTreeContainer &math(std::string name, int op, ANLFloatType s1, ANLFloatType s2=0.0);
        CTreeContainer &math(std::string name, int op, ANLFloatType s1, std::string s2);
        CTreeContainer &math(std::string name, int op, std::string s1, ANLFloatType s2=0.0);
        CTreeContainer &math(std::string name, int op, std::string s1, std::string s2);

        CTreeContainer &normalizeCoords(std::string name, ANLFloatType src, ANLFloatType length);
        CTreeContainer &normalizeCoords(std::string name, ANLFloatType src, std::string length);
        CTreeContainer &normalizeCoords(std::string name, std::string src, ANLFloatType length);
        CTreeContainer &normalizeCoords(std::string name, std::string src, std::string length);

        // TODO: ImplicitRGBADotProduct
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, ANLFloatType ay, std::string az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, ANLFloatType ay, std::string az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, std::string ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, std::string ay, ANLFloatType az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, std::string ay, std::string az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, ANLFloatType ax, std::string ay, std::string az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, std::string ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, std::string ax, ANLFloatType ay, ANLFloatType az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, std::string ax, ANLFloatType ay, std::string az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, std::string ax, ANLFloatType ay, std::string az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, std::string ax, std::string ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, std::string ax, std::string ay, ANLFloatType az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, std::string ax, std::string ay, std::string az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, ANLFloatType src, std::string ax, std::string ay, std::string az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, ANLFloatType ax, ANLFloatType ay, std::string az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, ANLFloatType ax, ANLFloatType ay, std::string az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, ANLFloatType ax, std::string ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, ANLFloatType ax, std::string ay, ANLFloatType az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, ANLFloatType ax, std::string ay, std::string az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, ANLFloatType ax, std::string ay, std::string az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, ANLFloatType ay, ANLFloatType az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, ANLFloatType ay, std::string az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, ANLFloatType ay, std::string az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, std::string ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, std::string ay, ANLFloatType az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, std::string ay, std::string az, ANLFloatType angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, std::string ay, std::string az, std::string angle);

        CTreeContainer &sawtooth(std::string name, ANLFloatType src, ANLFloatType period);
        CTreeContainer &sawtooth(std::string name, ANLFloatType src, std::string period);
        CTreeContainer &sawtooth(std::string name, std::string src, ANLFloatType period);
        CTreeContainer &sawtooth(std::string name, std::string src, std::string period);

        CTreeContainer &scaleDomain(std::string name, ANLFloatType src, ANLFloatType sx, ANLFloatType sy, ANLFloatType sz);
        CTreeContainer &scaleDomain(std::string name, ANLFloatType src, ANLFloatType sx, ANLFloatType sy, std::string sz);
        CTreeContainer &scaleDomain(std::string name, ANLFloatType src, ANLFloatType sx, std::string sy, ANLFloatType sz);
        CTreeContainer &scaleDomain(std::string name, ANLFloatType src, ANLFloatType sx, std::string sy, std::string sz);
        CTreeContainer &scaleDomain(std::string name, ANLFloatType src, std::string sx, ANLFloatType sy, ANLFloatType sz);
        CTreeContainer &scaleDomain(std::string name, ANLFloatType src, std::string sx, ANLFloatType sy, std::string sz);
        CTreeContainer &scaleDomain(std::string name, ANLFloatType src, std::string sx, std::string sy, ANLFloatType sz);
        CTreeContainer &scaleDomain(std::string name, ANLFloatType src, std::string sx, std::string sy, std::string sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, ANLFloatType sx, ANLFloatType sy, ANLFloatType sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, ANLFloatType sx, ANLFloatType sy, std::string sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, ANLFloatType sx, std::string sy, ANLFloatType sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, ANLFloatType sx, std::string sy, std::string sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, std::string sx, ANLFloatType sy, ANLFloatType sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, std::string sx, ANLFloatType sy, std::string sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, std::string sx, std::string sy, ANLFloatType sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, std::string sx, std::string sy, std::string sz);

        CTreeContainer &scaleOffset(std::string name, ANLFloatType src, ANLFloatType scale, ANLFloatType offset);
        CTreeContainer &scaleOffset(std::string name, ANLFloatType src, ANLFloatType scale, std::string offset);
        CTreeContainer &scaleOffset(std::string name, ANLFloatType src, std::string scale, ANLFloatType offset);
        CTreeContainer &scaleOffset(std::string name, ANLFloatType src, std::string scale, std::string offset);
        CTreeContainer &scaleOffset(std::string name, std::string src, ANLFloatType scale, ANLFloatType offset);
        CTreeContainer &scaleOffset(std::string name, std::string src, ANLFloatType scale, std::string offset);
        CTreeContainer &scaleOffset(std::string name, std::string src, std::string scale, ANLFloatType offset);
        CTreeContainer &scaleOffset(std::string name, std::string src, std::string scale, std::string offset);
		
		CTreeContainer &seamlessMapping(std::string name, std::string src, int mapping, ANLFloatType periodx=1, ANLFloatType periody=1, ANLFloatType periodz=1);

        CTreeContainer &select(std::string name, ANLFloatType low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, ANLFloatType high, ANLFloatType control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, ANLFloatType high, ANLFloatType control, std::string threshold, std::string falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, ANLFloatType high, std::string control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, ANLFloatType high, std::string control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, ANLFloatType high, std::string control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, ANLFloatType high, std::string control, std::string threshold, std::string falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, std::string high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, std::string high, ANLFloatType control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, std::string high, ANLFloatType control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, std::string high, ANLFloatType control, std::string threshold, std::string falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, std::string high, std::string control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, std::string high, std::string control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, std::string high, std::string control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, ANLFloatType low, std::string high, std::string control, std::string threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, std::string low, ANLFloatType high, ANLFloatType control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, ANLFloatType high, ANLFloatType control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, std::string low, ANLFloatType high, ANLFloatType control, std::string threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, ANLFloatType high, std::string control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, std::string low, ANLFloatType high, std::string control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, ANLFloatType high, std::string control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, std::string low, ANLFloatType high, std::string control, std::string threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, ANLFloatType control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, ANLFloatType control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, ANLFloatType control, std::string threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, std::string control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, std::string control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, std::string control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, std::string control, std::string threshold, std::string falloff);

        CTreeContainer &sphere(std::string name, ANLFloatType radius, ANLFloatType cx, ANLFloatType cy, ANLFloatType cz);
        CTreeContainer &sphere(std::string name, ANLFloatType radius, ANLFloatType cx, ANLFloatType cy, std::string cz);
        CTreeContainer &sphere(std::string name, ANLFloatType radius, ANLFloatType cx, std::string cy, ANLFloatType cz);
        CTreeContainer &sphere(std::string name, ANLFloatType radius, ANLFloatType cx, std::string cy, std::string cz);
        CTreeContainer &sphere(std::string name, ANLFloatType radius, std::string cx, ANLFloatType cy, ANLFloatType cz);
        CTreeContainer &sphere(std::string name, ANLFloatType radius, std::string cx, ANLFloatType cy, std::string cz);
        CTreeContainer &sphere(std::string name, ANLFloatType radius, std::string cx, std::string cy, ANLFloatType cz);
        CTreeContainer &sphere(std::string name, ANLFloatType radius, std::string cx, std::string cy, std::string cz);
        CTreeContainer &sphere(std::string name, std::string radius, ANLFloatType cx, ANLFloatType cy, ANLFloatType cz);
        CTreeContainer &sphere(std::string name, std::string radius, ANLFloatType cx, ANLFloatType cy, std::string cz);
        CTreeContainer &sphere(std::string name, std::string radius, ANLFloatType cx, std::string cy, ANLFloatType cz);
        CTreeContainer &sphere(std::string name, std::string radius, ANLFloatType cx, std::string cy, std::string cz);
        CTreeContainer &sphere(std::string name, std::string radius, std::string cx, ANLFloatType cy, ANLFloatType cz);
        CTreeContainer &sphere(std::string name, std::string radius, std::string cx, ANLFloatType cy, std::string cz);
        CTreeContainer &sphere(std::string name, std::string radius, std::string cx, std::string cy, ANLFloatType cz);
        CTreeContainer &sphere(std::string name, std::string radius, std::string cx, std::string cy, std::string cz);

        CTreeContainer &tiers(std::string name, ANLFloatType src, int numtiers, bool smooth);
        CTreeContainer &tiers(std::string name, std::string src, int numtiers, bool smooth);

        CTreeContainer &translateDomain(std::string name, ANLFloatType src, ANLFloatType tx, ANLFloatType ty, ANLFloatType tz);
        CTreeContainer &translateDomain(std::string name, ANLFloatType src, ANLFloatType tx, ANLFloatType ty, std::string tz);
        CTreeContainer &translateDomain(std::string name, ANLFloatType src, ANLFloatType tx, std::string ty, ANLFloatType tz);
        CTreeContainer &translateDomain(std::string name, ANLFloatType src, ANLFloatType tx, std::string ty, std::string tz);
        CTreeContainer &translateDomain(std::string name, ANLFloatType src, std::string tx, ANLFloatType ty, ANLFloatType tz);
        CTreeContainer &translateDomain(std::string name, ANLFloatType src, std::string tx, ANLFloatType ty, std::string tz);
        CTreeContainer &translateDomain(std::string name, ANLFloatType src, std::string tx, std::string ty, ANLFloatType tz);
        CTreeContainer &translateDomain(std::string name, ANLFloatType src, std::string tx, std::string ty, std::string tz);
        CTreeContainer &translateDomain(std::string name, std::string src, ANLFloatType tx, ANLFloatType ty, ANLFloatType tz);
        CTreeContainer &translateDomain(std::string name, std::string src, ANLFloatType tx, ANLFloatType ty, std::string tz);
        CTreeContainer &translateDomain(std::string name, std::string src, ANLFloatType tx, std::string ty, ANLFloatType tz);
        CTreeContainer &translateDomain(std::string name, std::string src, ANLFloatType tx, std::string ty, std::string tz);
        CTreeContainer &translateDomain(std::string name, std::string src, std::string tx, ANLFloatType ty, ANLFloatType tz);
        CTreeContainer &translateDomain(std::string name, std::string src, std::string tx, ANLFloatType ty, std::string tz);
        CTreeContainer &translateDomain(std::string name, std::string src, std::string tx, std::string ty, ANLFloatType tz);
        CTreeContainer &translateDomain(std::string name, std::string src, std::string tx, std::string ty, std::string tz);

        CTreeContainer &triangle(std::string name, ANLFloatType src, ANLFloatType period, ANLFloatType offset);
        CTreeContainer &triangle(std::string name, ANLFloatType src, ANLFloatType period, std::string offset);
        CTreeContainer &triangle(std::string name, ANLFloatType src, std::string period, ANLFloatType offset);
        CTreeContainer &triangle(std::string name, ANLFloatType src, std::string period, std::string offset);
        CTreeContainer &triangle(std::string name, std::string src, ANLFloatType period, ANLFloatType offset);
        CTreeContainer &triangle(std::string name, std::string src, ANLFloatType period, std::string offset);
        CTreeContainer &triangle(std::string name, std::string src, std::string period, ANLFloatType offset);
        CTreeContainer &triangle(std::string name, std::string src, std::string period, std::string offset);

        CTreeContainer &rgbaBlend(std::string name, ANLFloatType control, SRGBA low, SRGBA high);
        CTreeContainer &rgbaBlend(std::string name, ANLFloatType control, SRGBA low, std::string high);
        CTreeContainer &rgbaBlend(std::string name, ANLFloatType control, std::string low, SRGBA high);
        CTreeContainer &rgbaBlend(std::string name, ANLFloatType control, std::string low, std::string high);
        CTreeContainer &rgbaBlend(std::string name, std::string control, SRGBA low, SRGBA high);
        CTreeContainer &rgbaBlend(std::string name, std::string control, SRGBA low, std::string high);
        CTreeContainer &rgbaBlend(std::string name, std::string control, std::string low, SRGBA high);
        CTreeContainer &rgbaBlend(std::string name, std::string control, std::string low, std::string high);

        CTreeContainer &rgbaBlendOps(std::string name, SRGBA s1, SRGBA s2, int op1, int op2);
        CTreeContainer &rgbaBlendOps(std::string name, SRGBA s1, std::string s2, int op1, int op2);
        CTreeContainer &rgbaBlendOps(std::string name, std::string s1, SRGBA s2, int op1, int op2);
        CTreeContainer &rgbaBlendOps(std::string name, std::string s1, std::string s2, int op1, int op2);

        CTreeContainer &rgbaColorOps(std::string name, SRGBA s1, SRGBA s2, int op);
        CTreeContainer &rgbaColorOps(std::string name, SRGBA s1, std::string s2, int op);
        CTreeContainer &rgbaColorOps(std::string name, std::string s1, SRGBA s2, int op);
        CTreeContainer &rgbaColorOps(std::string name, std::string s1, std::string s2, int op);

        CTreeContainer &rgbaCompositeChannels(std::string name, ANLFloatType r, ANLFloatType g, ANLFloatType b, ANLFloatType a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, ANLFloatType r, ANLFloatType g, ANLFloatType b, std::string a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, ANLFloatType r, ANLFloatType g, std::string b, ANLFloatType a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, ANLFloatType r, ANLFloatType g, std::string b, std::string a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, ANLFloatType r, std::string g, ANLFloatType b, ANLFloatType a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, ANLFloatType r, std::string g, ANLFloatType b, std::string a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, ANLFloatType r, std::string g, std::string b, ANLFloatType a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, ANLFloatType r, std::string g, std::string b, std::string a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, ANLFloatType g, ANLFloatType b, ANLFloatType a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, ANLFloatType g, ANLFloatType b, std::string a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, ANLFloatType g, std::string b, ANLFloatType a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, ANLFloatType g, std::string b, std::string a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, std::string g, ANLFloatType b, ANLFloatType a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, std::string g, ANLFloatType b, std::string a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, std::string g, std::string b, ANLFloatType a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, std::string g, std::string b, std::string a, int mode);

        // TODO: RGBACurve

        CTreeContainer &rgbaHSVtoRGBA(std::string name, SRGBA c);
        CTreeContainer &rgbaHSVtoRGBA(std::string name, std::string c);

        CTreeContainer &rgbaRGBAtoHSV(std::string name, SRGBA c);
        CTreeContainer &rgbaRGBAtoHSV(std::string name, std::string c);

        CTreeContainer &rgbaImplicitGrayscale(std::string name, ANLFloatType s);
        CTreeContainer &rgbaImplicitGrayscale(std::string name, std::string s);

        CTreeContainer &rgbaNormalize(std::string name, SRGBA c);
        CTreeContainer &rgbaNormalize(std::string name, std::string c);

        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, ANLFloatType ay, std::string az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, ANLFloatType ay, std::string az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, std::string ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, std::string ay, ANLFloatType az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, std::string ay, std::string az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, ANLFloatType ax, std::string ay, std::string az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, ANLFloatType ay, ANLFloatType az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, ANLFloatType ay, std::string az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, ANLFloatType ay, std::string az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, ANLFloatType az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, std::string az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, std::string az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, ANLFloatType ay, ANLFloatType az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, ANLFloatType ay, std::string az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, ANLFloatType ay, std::string az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, std::string ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, std::string ay, ANLFloatType az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, std::string ay, std::string az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, ANLFloatType ax, std::string ay, std::string az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, ANLFloatType ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, ANLFloatType ay, ANLFloatType az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, ANLFloatType ay, std::string az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, ANLFloatType ay, std::string az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, ANLFloatType az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, ANLFloatType az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, std::string az, ANLFloatType angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, std::string az, std::string angle);

        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, ANLFloatType control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, ANLFloatType control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, ANLFloatType control, std::string threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, std::string threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, ANLFloatType control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, ANLFloatType control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, ANLFloatType control, std::string threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, std::string threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, ANLFloatType control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, ANLFloatType control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, ANLFloatType control, std::string threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, std::string threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, ANLFloatType control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, ANLFloatType control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, ANLFloatType control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, ANLFloatType control, std::string threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, std::string control, ANLFloatType threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, std::string control, ANLFloatType threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, std::string control, std::string threshold, ANLFloatType falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, std::string control, std::string threshold, std::string falloff);

		CTreeContainer &implicitBufferImplicitAdapter(std::string name, std::string source, int mapping, SMappingRanges ranges, bool use_z, ANLFloatType z);
		CTreeContainer &implicitBufferBlur(std::string name, std::string source, ANLFloatType blursize, bool seamless);
		CTreeContainer &implicitBufferScaleToRange(std::string name, std::string source, ANLFloatType low, ANLFloatType high);
		CTreeContainer &implicitBufferBumpMap(std::string name, std::string source, ANLFloatType lx, ANLFloatType ly, ANLFloatType lz, ANLFloatType spacing, bool seamless);
		CTreeContainer &implicitBufferUnaryMath(std::string name, std::string source, int op);
		CTreeContainer &implicitBufferSimpleErode(std::string name, std::string source, int numdrops, float power, unsigned int iterations);
		CTreeContainer &implicitBufferSimpleRainfall(std::string name, std::string source);
		CTreeContainer &implicitBufferSelect(std::string name, std::string low, std::string high, std::string control, ANLFloatType threshold, ANLFloatType falloff);
		CTreeContainer &implicitBufferConstant(std::string name, ANLFloatType constant);

		CTreeContainer &rgbaBufferRGBAAdapter(std::string name, std::string source, int mapping, SMappingRanges ranges, bool use_z, ANLFloatType z);
		CTreeContainer &rgbaBufferImplicitBufferAdapter(std::string name, std::string source);
		CTreeContainer &rgbaBufferBlur(std::string name, std::string source, ANLFloatType blursize, bool seamless);
		CTreeContainer &rgbaBufferImplicitBufferMultiply(std::string name, std::string rgbasource, std::string implicitsource);
		CTreeContainer &rgbaBufferSelect(std::string name, std::string low, std::string high, std::string control, ANLFloatType threshold, ANLFloatType falloff);
		CTreeContainer &rgbaBufferNormalMap(std::string name, std::string source, float spacing, bool seamless);

        CImplicitModuleBase * getImplicitModule(std::string name);
        CRGBAModuleBase * getRGBAModule(std::string name);
        CImplicitBufferBase * getImplicitBuffer(std::string name);
		CRGBABufferBase * getRGBABuffer(std::string name);
		
		void setSeedAll(unsigned int seed);

        private:
        std::map<std::string, std::shared_ptr<CImplicitModuleBase> > m_modules;
        std::map<std::string, std::shared_ptr<CRGBAModuleBase> > m_rgbas;
        std::map<std::string, std::shared_ptr<CCellularGenerator> > m_cellgen;
		std::map<std::string, std::shared_ptr<CImplicitBufferBase> > m_implicitbuffers;
        std::map<std::string, std::shared_ptr<CRGBABufferBase> > m_rgbabuffers;

        CImplicitModuleBase * get(std::string name);
        ANLFloatType get(ANLFloatType g){return g;}
        CRGBAModuleBase * getRGBA(std::string name);
        SRGBA getRGBA(SRGBA c){return c;}
    };
};

#endif
