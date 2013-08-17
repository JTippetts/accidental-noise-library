#ifndef CELLULAR_GEN_H
#define CELLULAR_GEN_H
#include "implicitmodulebase.h"
#include "noise_gen.h"

/********************************************************
CCellularGen
    Implement a class to generate and cache cellular noise. Multiple front-end classes can
call this, and as long as the input coords remain the same, the cached value will be returned.
Generates F1..F4 and V1..V4.
*********************************************************/

namespace anl
{
    enum EDistanceFunction
    {
        EUCLID,
        MANHATTAN,
        GREATESTAXIS,
        LEASTAXIS
    };

struct SCellularCache
{
    ANLFloatType f[4];
    ANLFloatType d[4];
    ANLFloatType x,y,z,w,u,v;
    bool valid;

    SCellularCache()
    {
        valid=false;
    }
};


class CCellularGenerator
{
    public:
    CCellularGenerator();
    CCellularGenerator(int distfunc);
    ~CCellularGenerator();

    SCellularCache &get(ANLFloatType x, ANLFloatType y);
    SCellularCache &get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
    SCellularCache &get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
    SCellularCache &get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

    void setSeed(unsigned int seed);
    void setDistanceFunction(int func);


    protected:
    unsigned int m_seed;
    SCellularCache m_cache2, m_cache3, m_cache4, m_cache6;
    dist_func2 m_dist2;
    dist_func3 m_dist3;
    dist_func4 m_dist4;
    dist_func6 m_dist6;


};

};

#endif
