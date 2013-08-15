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

        CTreeContainer &autoCorrect(std::string name, std::string src, double low=0, double high=1);
        CTreeContainer &basisFunction(std::string name, int type=GRADIENT, int interp=QUINTIC, bool rotate=true);
        CTreeContainer &blend(std::string name, double low, double high, double control);
        CTreeContainer &blend(std::string name, double low, double high, std::string control);
        CTreeContainer &blend(std::string name, double low, std::string high, double control);
        CTreeContainer &blend(std::string name, double low, std::string high, std::string control);
        CTreeContainer &blend(std::string name, std::string low, double high, double control);
        CTreeContainer &blend(std::string name, std::string low, double high, std::string control);
        CTreeContainer &blend(std::string name, std::string low, std::string high, double control);
        CTreeContainer &blend(std::string name, std::string low, std::string high, std::string control);

        CTreeContainer &brightContrast(std::string name, double s, double b, double t, double f);
        CTreeContainer &brightContrast(std::string name, double s, double b, double t, std::string f);
        CTreeContainer &brightContrast(std::string name, double s, double b, std::string t, double f);
        CTreeContainer &brightContrast(std::string name, double s, double b, std::string t, std::string f);
        CTreeContainer &brightContrast(std::string name, double s, std::string b, double t, double f);
        CTreeContainer &brightContrast(std::string name, double s, std::string b, double t, std::string f);
        CTreeContainer &brightContrast(std::string name, double s, std::string b, std::string t, double f);
        CTreeContainer &brightContrast(std::string name, double s, std::string b, std::string t, std::string f);
        CTreeContainer &brightContrast(std::string name, std::string s, double b, double t, double f);
        CTreeContainer &brightContrast(std::string name, std::string s, double b, double t, std::string f);
        CTreeContainer &brightContrast(std::string name, std::string s, double b, std::string t, double f);
        CTreeContainer &brightContrast(std::string name, std::string s, double b, std::string t, std::string f);
        CTreeContainer &brightContrast(std::string name, std::string s, std::string b, double t, double f);
        CTreeContainer &brightContrast(std::string name, std::string s, std::string b, double t, std::string f);
        CTreeContainer &brightContrast(std::string name, std::string s, std::string b, std::string t, double f);
        CTreeContainer &brightContrast(std::string name, std::string s, std::string b, std::string t, std::string f);

        CTreeContainer &cache(std::string name, double v);
        CTreeContainer &cache(std::string name, std::string v);

        CTreeContainer &cellular(std::string name, std::string g, double a=1, double b=0, double c=0, double d=0);
        CTreeContainer &cellularGenerator(std::string name);

        CTreeContainer &clamp(std::string name, double s, double l, double h);
        CTreeContainer &clamp(std::string name, double s, double l, std::string h);
        CTreeContainer &clamp(std::string name, double s, std::string l, double h);
        CTreeContainer &clamp(std::string name, double s, std::string l, std::string h);
        CTreeContainer &clamp(std::string name, std::string s, double l, double h);
        CTreeContainer &clamp(std::string name, std::string s, double l, std::string h);
        CTreeContainer &clamp(std::string name, std::string s, std::string l, double h);
        CTreeContainer &clamp(std::string name, std::string s, std::string l, std::string h);

        // TODO: Combiner. Might look at this to include fractal combiner types so that I can do custom fractals
        // The trick will be how to do variable entries
        // Maybe just do a single constructor, with default values for everything except the first two entries?

        CTreeContainer &constant(std::string name, double v);

        CTreeContainer &curve(std::string name, double s, int interptype);
        CTreeContainer &curve(std::string name, std::string s, int interptype);

        // TODO: ImplicitExtractRGBAChannel

        CTreeContainer &fractal(std::string name, unsigned int type=FBM, unsigned int basis=GRADIENT, unsigned int interp=QUINTIC, int octaves=8, double freq=1);

        CTreeContainer &functionGradient(std::string name, double s, int axis=X_AXIS, double spacing=0.0001);
        CTreeContainer &functionGradient(std::string name, std::string s, int axis=X_AXIS, double spacing=0.0001);

        CTreeContainer &gradient(std::string name, double x1, double x2, double y1, double y2, double z1, double z2, double w1=0, double w2=0, double u1=0, double u2=0, double v1=0, double v2=0);

        // TODO: Magnitude

        CTreeContainer &math(std::string name, int op, double s1, double s2=0.0);
        CTreeContainer &math(std::string name, int op, double s1, std::string s2);
        CTreeContainer &math(std::string name, int op, std::string s1, double s2=0.0);
        CTreeContainer &math(std::string name, int op, std::string s1, std::string s2);

        CTreeContainer &normalizeCoords(std::string name, double src, double length);
        CTreeContainer &normalizeCoords(std::string name, double src, std::string length);
        CTreeContainer &normalizeCoords(std::string name, std::string src, double length);
        CTreeContainer &normalizeCoords(std::string name, std::string src, std::string length);

        // TODO: ImplicitRGBADotProduct
        CTreeContainer &rotateDomain(std::string name, double src, double ax, double ay, double az, double angle);
        CTreeContainer &rotateDomain(std::string name, double src, double ax, double ay, double az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, double src, double ax, double ay, std::string az, double angle);
        CTreeContainer &rotateDomain(std::string name, double src, double ax, double ay, std::string az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, double src, double ax, std::string ay, double az, double angle);
        CTreeContainer &rotateDomain(std::string name, double src, double ax, std::string ay, double az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, double src, double ax, std::string ay, std::string az, double angle);
        CTreeContainer &rotateDomain(std::string name, double src, double ax, std::string ay, std::string az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, double src, std::string ax, double ay, double az, double angle);
        CTreeContainer &rotateDomain(std::string name, double src, std::string ax, double ay, double az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, double src, std::string ax, double ay, std::string az, double angle);
        CTreeContainer &rotateDomain(std::string name, double src, std::string ax, double ay, std::string az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, double src, std::string ax, std::string ay, double az, double angle);
        CTreeContainer &rotateDomain(std::string name, double src, std::string ax, std::string ay, double az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, double src, std::string ax, std::string ay, std::string az, double angle);
        CTreeContainer &rotateDomain(std::string name, double src, std::string ax, std::string ay, std::string az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, double ax, double ay, double az, double angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, double ax, double ay, double az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, double ax, double ay, std::string az, double angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, double ax, double ay, std::string az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, double ax, std::string ay, double az, double angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, double ax, std::string ay, double az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, double ax, std::string ay, std::string az, double angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, double ax, std::string ay, std::string az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, double ay, double az, double angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, double ay, double az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, double ay, std::string az, double angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, double ay, std::string az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, std::string ay, double az, double angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, std::string ay, double az, std::string angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, std::string ay, std::string az, double angle);
        CTreeContainer &rotateDomain(std::string name, std::string src, std::string ax, std::string ay, std::string az, std::string angle);

        CTreeContainer &sawtooth(std::string name, double src, double period);
        CTreeContainer &sawtooth(std::string name, double src, std::string period);
        CTreeContainer &sawtooth(std::string name, std::string src, double period);
        CTreeContainer &sawtooth(std::string name, std::string src, std::string period);

        CTreeContainer &scaleDomain(std::string name, double src, double sx, double sy, double sz);
        CTreeContainer &scaleDomain(std::string name, double src, double sx, double sy, std::string sz);
        CTreeContainer &scaleDomain(std::string name, double src, double sx, std::string sy, double sz);
        CTreeContainer &scaleDomain(std::string name, double src, double sx, std::string sy, std::string sz);
        CTreeContainer &scaleDomain(std::string name, double src, std::string sx, double sy, double sz);
        CTreeContainer &scaleDomain(std::string name, double src, std::string sx, double sy, std::string sz);
        CTreeContainer &scaleDomain(std::string name, double src, std::string sx, std::string sy, double sz);
        CTreeContainer &scaleDomain(std::string name, double src, std::string sx, std::string sy, std::string sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, double sx, double sy, double sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, double sx, double sy, std::string sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, double sx, std::string sy, double sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, double sx, std::string sy, std::string sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, std::string sx, double sy, double sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, std::string sx, double sy, std::string sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, std::string sx, std::string sy, double sz);
        CTreeContainer &scaleDomain(std::string name, std::string src, std::string sx, std::string sy, std::string sz);

        CTreeContainer &scaleOffset(std::string name, double src, double scale, double offset);
        CTreeContainer &scaleOffset(std::string name, double src, double scale, std::string offset);
        CTreeContainer &scaleOffset(std::string name, double src, std::string scale, double offset);
        CTreeContainer &scaleOffset(std::string name, double src, std::string scale, std::string offset);
        CTreeContainer &scaleOffset(std::string name, std::string src, double scale, double offset);
        CTreeContainer &scaleOffset(std::string name, std::string src, double scale, std::string offset);
        CTreeContainer &scaleOffset(std::string name, std::string src, std::string scale, double offset);
        CTreeContainer &scaleOffset(std::string name, std::string src, std::string scale, std::string offset);

        CTreeContainer &select(std::string name, double low, double high, double control, double threshold, double falloff);
        CTreeContainer &select(std::string name, double low, double high, double control, double threshold, std::string falloff);
        CTreeContainer &select(std::string name, double low, double high, double control, std::string threshold, double falloff);
        CTreeContainer &select(std::string name, double low, double high, double control, std::string threshold, std::string falloff);
        CTreeContainer &select(std::string name, double low, double high, std::string control, double threshold, double falloff);
        CTreeContainer &select(std::string name, double low, double high, std::string control, double threshold, std::string falloff);
        CTreeContainer &select(std::string name, double low, double high, std::string control, std::string threshold, double falloff);
        CTreeContainer &select(std::string name, double low, double high, std::string control, std::string threshold, std::string falloff);
        CTreeContainer &select(std::string name, double low, std::string high, double control, double threshold, double falloff);
        CTreeContainer &select(std::string name, double low, std::string high, double control, double threshold, std::string falloff);
        CTreeContainer &select(std::string name, double low, std::string high, double control, std::string threshold, double falloff);
        CTreeContainer &select(std::string name, double low, std::string high, double control, std::string threshold, std::string falloff);
        CTreeContainer &select(std::string name, double low, std::string high, std::string control, double threshold, double falloff);
        CTreeContainer &select(std::string name, double low, std::string high, std::string control, double threshold, std::string falloff);
        CTreeContainer &select(std::string name, double low, std::string high, std::string control, std::string threshold, double falloff);
        CTreeContainer &select(std::string name, double low, std::string high, std::string control, std::string threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, double high, double control, double threshold, double falloff);
        CTreeContainer &select(std::string name, std::string low, double high, double control, double threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, double high, double control, std::string threshold, double falloff);
        CTreeContainer &select(std::string name, std::string low, double high, double control, std::string threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, double high, std::string control, double threshold, double falloff);
        CTreeContainer &select(std::string name, std::string low, double high, std::string control, double threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, double high, std::string control, std::string threshold, double falloff);
        CTreeContainer &select(std::string name, std::string low, double high, std::string control, std::string threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, double control, double threshold, double falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, double control, double threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, double control, std::string threshold, double falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, double control, std::string threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, std::string control, double threshold, double falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, std::string control, double threshold, std::string falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, std::string control, std::string threshold, double falloff);
        CTreeContainer &select(std::string name, std::string low, std::string high, std::string control, std::string threshold, std::string falloff);

        CTreeContainer &sphere(std::string name, double radius, double cx, double cy, double cz);
        CTreeContainer &sphere(std::string name, double radius, double cx, double cy, std::string cz);
        CTreeContainer &sphere(std::string name, double radius, double cx, std::string cy, double cz);
        CTreeContainer &sphere(std::string name, double radius, double cx, std::string cy, std::string cz);
        CTreeContainer &sphere(std::string name, double radius, std::string cx, double cy, double cz);
        CTreeContainer &sphere(std::string name, double radius, std::string cx, double cy, std::string cz);
        CTreeContainer &sphere(std::string name, double radius, std::string cx, std::string cy, double cz);
        CTreeContainer &sphere(std::string name, double radius, std::string cx, std::string cy, std::string cz);
        CTreeContainer &sphere(std::string name, std::string radius, double cx, double cy, double cz);
        CTreeContainer &sphere(std::string name, std::string radius, double cx, double cy, std::string cz);
        CTreeContainer &sphere(std::string name, std::string radius, double cx, std::string cy, double cz);
        CTreeContainer &sphere(std::string name, std::string radius, double cx, std::string cy, std::string cz);
        CTreeContainer &sphere(std::string name, std::string radius, std::string cx, double cy, double cz);
        CTreeContainer &sphere(std::string name, std::string radius, std::string cx, double cy, std::string cz);
        CTreeContainer &sphere(std::string name, std::string radius, std::string cx, std::string cy, double cz);
        CTreeContainer &sphere(std::string name, std::string radius, std::string cx, std::string cy, std::string cz);

        CTreeContainer &tiers(std::string name, double src, int numtiers, bool smooth);
        CTreeContainer &tiers(std::string name, std::string src, int numtiers, bool smooth);

        CTreeContainer &translateDomain(std::string name, double src, double tx, double ty, double tz);
        CTreeContainer &translateDomain(std::string name, double src, double tx, double ty, std::string tz);
        CTreeContainer &translateDomain(std::string name, double src, double tx, std::string ty, double tz);
        CTreeContainer &translateDomain(std::string name, double src, double tx, std::string ty, std::string tz);
        CTreeContainer &translateDomain(std::string name, double src, std::string tx, double ty, double tz);
        CTreeContainer &translateDomain(std::string name, double src, std::string tx, double ty, std::string tz);
        CTreeContainer &translateDomain(std::string name, double src, std::string tx, std::string ty, double tz);
        CTreeContainer &translateDomain(std::string name, double src, std::string tx, std::string ty, std::string tz);
        CTreeContainer &translateDomain(std::string name, std::string src, double tx, double ty, double tz);
        CTreeContainer &translateDomain(std::string name, std::string src, double tx, double ty, std::string tz);
        CTreeContainer &translateDomain(std::string name, std::string src, double tx, std::string ty, double tz);
        CTreeContainer &translateDomain(std::string name, std::string src, double tx, std::string ty, std::string tz);
        CTreeContainer &translateDomain(std::string name, std::string src, std::string tx, double ty, double tz);
        CTreeContainer &translateDomain(std::string name, std::string src, std::string tx, double ty, std::string tz);
        CTreeContainer &translateDomain(std::string name, std::string src, std::string tx, std::string ty, double tz);
        CTreeContainer &translateDomain(std::string name, std::string src, std::string tx, std::string ty, std::string tz);

        CTreeContainer &triangle(std::string name, double src, double period, double offset);
        CTreeContainer &triangle(std::string name, double src, double period, std::string offset);
        CTreeContainer &triangle(std::string name, double src, std::string period, double offset);
        CTreeContainer &triangle(std::string name, double src, std::string period, std::string offset);
        CTreeContainer &triangle(std::string name, std::string src, double period, double offset);
        CTreeContainer &triangle(std::string name, std::string src, double period, std::string offset);
        CTreeContainer &triangle(std::string name, std::string src, std::string period, double offset);
        CTreeContainer &triangle(std::string name, std::string src, std::string period, std::string offset);

        CTreeContainer &rgbaBlend(std::string name, double control, SRGBA low, SRGBA high);
        CTreeContainer &rgbaBlend(std::string name, double control, SRGBA low, std::string high);
        CTreeContainer &rgbaBlend(std::string name, double control, std::string low, SRGBA high);
        CTreeContainer &rgbaBlend(std::string name, double control, std::string low, std::string high);
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

        CTreeContainer &rgbaCompositeChannels(std::string name, double r, double g, double b, double a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, double r, double g, double b, std::string a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, double r, double g, std::string b, double a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, double r, double g, std::string b, std::string a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, double r, std::string g, double b, double a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, double r, std::string g, double b, std::string a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, double r, std::string g, std::string b, double a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, double r, std::string g, std::string b, std::string a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, double g, double b, double a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, double g, double b, std::string a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, double g, std::string b, double a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, double g, std::string b, std::string a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, std::string g, double b, double a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, std::string g, double b, std::string a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, std::string g, std::string b, double a, int mode);
        CTreeContainer &rgbaCompositeChannels(std::string name, std::string r, std::string g, std::string b, std::string a, int mode);

        // TODO: RGBACurve

        CTreeContainer &rgbaHSVtoRGBA(std::string name, SRGBA c);
        CTreeContainer &rgbaHSVtoRGBA(std::string name, std::string c);

        CTreeContainer &rgbaRGBAtoHSV(std::string name, SRGBA c);
        CTreeContainer &rgbaRGBAtoHSV(std::string name, std::string c);

        CTreeContainer &rgbaImplicitGrayscale(std::string name, double s);
        CTreeContainer &rgbaImplicitGrayscale(std::string name, std::string s);

        CTreeContainer &rgbaNormalize(std::string name, SRGBA c);
        CTreeContainer &rgbaNormalize(std::string name, std::string c);

        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, double ax, double ay, double az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, double ax, double ay, double az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, double ax, double ay, std::string az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, double ax, double ay, std::string az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, double ax, std::string ay, double az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, double ax, std::string ay, double az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, double ax, std::string ay, std::string az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, double ax, std::string ay, std::string az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, double ay, double az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, double ay, double az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, double ay, std::string az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, double ay, std::string az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, double az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, double az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, std::string az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, SRGBA c, std::string ax, std::string ay, std::string az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, double ax, double ay, double az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, double ax, double ay, double az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, double ax, double ay, std::string az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, double ax, double ay, std::string az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, double ax, std::string ay, double az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, double ax, std::string ay, double az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, double ax, std::string ay, std::string az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, double ax, std::string ay, std::string az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, double ay, double az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, double ay, double az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, double ay, std::string az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, double ay, std::string az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, double az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, double az, std::string angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, std::string az, double angle);
        CTreeContainer &rgbaRotateColor(std::string name, std::string c, std::string ax, std::string ay, std::string az, std::string angle);

        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, double control, double threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, double control, double threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, double control, std::string threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, double control, std::string threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, double threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, double threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, std::string threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, SRGBA high, std::string control, std::string threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, double control, double threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, double control, double threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, double control, std::string threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, double control, std::string threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, double threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, double threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, std::string threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, SRGBA low, std::string high, std::string control, std::string threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, double control, double threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, double control, double threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, double control, std::string threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, double control, std::string threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, double threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, double threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, std::string threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, SRGBA high, std::string control, std::string threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, double control, double threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, double control, double threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, double control, std::string threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, double control, std::string threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, std::string control, double threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, std::string control, double threshold, std::string falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, std::string control, std::string threshold, double falloff);
        CTreeContainer &rgbaSelect(std::string name, std::string low, std::string high, std::string control, std::string threshold, std::string falloff);

		CTreeContainer &implicitBufferImplicitAdapter(std::string name, std::string source, int mapping, SMappingRanges ranges, bool use_z, double z);
		CTreeContainer &implicitBufferBlur(std::string name, std::string source, double blursize, bool seamless);
		CTreeContainer &implicitBufferScaleToRange(std::string name, std::string source, double low, double high);
		CTreeContainer &implicitBufferBumpMap(std::string name, std::string source, double lx, double ly, double lz, double spacing, bool seamless);
		CTreeContainer &implicitBufferUnaryMath(std::string name, std::string source, int op);
		CTreeContainer &implicitBufferSimpleErode(std::string name, std::string source, int numdrops, float power);
		CTreeContainer &implicitBufferSimpleRainfall(std::string name, std::string source, std::string depth, int iterations);
		CTreeContainer &implicitBufferSelect(std::string name, std::string low, std::string high, std::string control, double threshold, double falloff);

		CTreeContainer &rgbaBufferRGBAAdapter(std::string name, std::string source, int mapping, SMappingRanges ranges, bool use_z, double z);
		CTreeContainer &rgbaBufferImplicitBufferAdapter(std::string name, std::string source);
		CTreeContainer &rgbaBufferBlur(std::string name, std::string source, double blursize, bool seamless);
		CTreeContainer &rgbaBufferImplicitBufferMultiply(std::string name, std::string rgbasource, std::string implicitsource);
		CTreeContainer &rgbaBufferSelect(std::string name, std::string low, std::string high, std::string control, double threshold, double falloff);

        CImplicitModuleBase * getImplicitModule(std::string name);
        CRGBAModuleBase * getRGBAModule(std::string name);
        CImplicitBufferBase * getImplicitBuffer(std::string name);
		CRGBABufferBase * getRGBABuffer(std::string name);

        private:
        std::map<std::string, std::shared_ptr<CImplicitModuleBase> > m_modules;
        std::map<std::string, std::shared_ptr<CRGBAModuleBase> > m_rgbas;
        std::map<std::string, std::shared_ptr<CCellularGenerator> > m_cellgen;
		std::map<std::string, std::shared_ptr<CImplicitBufferBase> > m_implicitbuffers;
        std::map<std::string, std::shared_ptr<CRGBABufferBase> > m_rgbabuffers;

        CImplicitModuleBase * get(std::string name);
        double get(double g){return g;}
        CRGBAModuleBase * getRGBA(std::string name);
        SRGBA getRGBA(SRGBA c){return c;}
    };
};

#endif
