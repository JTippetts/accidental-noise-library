#include "arrayoperations.h"
#include <math.h>

namespace anl
{
    void normalizeVec3(ANLFloatType v[3])
    {
        ANLFloatType len=sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
        v[0]/=len;
        v[1]/=len;
        v[2]/=len;
    }

    void calcBumpMap(CArray2Dd *map, CArray2Dd *bump, float light[3], ANLFloatType spacing, bool wrap)
    {
        if(!map || !bump) return;
        int mw=map->width(), mh=map->height();
        if(mw!=bump->width() || mh!=bump->height()) bump->resize(mw,mh);

        for(int x=0; x<mw; ++x)
        {
            for(int y=0; y<mh; ++y)
            {
                ANLFloatType n[3]={0.0, 1.0, 0.0};

                if(!wrap)
                {
                    if(x==0 || y==0 || x==mw-1 || y==mh-1)
                    {
                        n[0]=0.0;
                        n[2]=0.0;
                    }
                    else
                    {
                        n[0]=(map->get(x-1,y)-map->get(x+1,y)) / spacing;
                        n[2]=(map->get(x,y-1)-map->get(x,y+1)) / spacing;
                    }
                    normalizeVec3(n);
                }
                else
                {
                    int x1,x2,y1,y2;
                    if(x==0) x1=mw-1;
                    else x1=x-1;

                    if(y==0) y1=mh-1;
                    else y1=y-1;

                    if(x==mw-1) x2=0;
                    else x2=x+1;

                    if(y==mh-1) y2=0;
                    else y2=y+1;

                    n[0]=(map->get(x1,y)-map->get(x2,y)) / spacing;
                    n[2]=(map->get(x,y1)-map->get(x,y2)) / spacing;
                    normalizeVec3(n);
                }
                ANLFloatType b = light[0]*n[0] + light[1]*n[1] + light[2]*n[2];
                if(b<0.0) b=0.0;
                if(b>1.0) b=1.0;
                bump->set(x,y,b);
            }
        }
    }

    void calcNormalMap(CArray2Dd *map, CArray2Drgba *bump, ANLFloatType spacing, bool normalize, bool wrap)
    {
        if(!map || !bump) return;
        int mw=map->width(), mh=map->height();
        if(mw!=bump->width() || mh!=bump->height()) bump->resize(mw,mh);

        for(int x=0; x<mw; ++x)
        {
            for(int y=0; y<mh; ++y)
            {
                ANLFloatType n[3]={0.0, 1.0, 0.0};

                if(!wrap)
                {
                    if(x==0 || y==0 || x==mw-1 || y==mh-1)
                    {
                        n[0]=0.0;
                        n[2]=0.0;
                    }
                    else
                    {
                        n[0]=(map->get(x-1,y)-map->get(x+1,y)) / spacing;
                        n[2]=(map->get(x,y-1)-map->get(x,y+1)) / spacing;
                    }
                    normalizeVec3(n);
                }
                else
                {
                    int x1,x2,y1,y2;
                    if(x==0) x1=mw-1;
                    else x1=x-1;

                    if(y==0) y1=mh-1;
                    else y1=y-1;

                    if(x==mw-1) x2=0;
                    else x2=x+1;

                    if(y==mh-1) y2=0;
                    else y2=y+1;

                    n[0]=(map->get(x1,y)-map->get(x2,y)) / spacing;
                    n[2]=(map->get(x,y1)-map->get(x,y2)) / spacing;
                    normalizeVec3(n);
                }
                if(normalize)
                {
                    n[0]=n[0]*0.5 + 0.5;
                    n[1]=n[1]*0.5 + 0.5;
                    n[2]=n[2]*0.5 + 0.5;
                }
                bump->set(x,y,SRGBA((float)n[0], (float)n[2], (float)n[1], 1.0));
            }
        }
    }

    void multRGBAByDouble(CArray2Drgba *rgba, CArray2Dd *map)
    {
        if(!rgba || !map) return;

        int mw=rgba->width(), mh=rgba->height();
        if(mw!=map->width() || mh!=map->height()) return;

        for(int x=0; x<mw; ++x)
        {
            for(int y=0; y<mh; ++y)
            {
                ANLFloatType v=map->get(x,y);
                SRGBA c=rgba->get(x,y);
                rgba->set(x,y,SRGBA(c[0]*v, c[1]*v, c[2]*v, c[3]));
            }
        }
    }
};
