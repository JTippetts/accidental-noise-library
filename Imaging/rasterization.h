#ifndef RASTERIZATION_H
#define RASTERIZATION_H

#include "../Noise/anl_noise.h"
#include "../RGBA/anl_rgba.h"
#include "../Imaging/anl_imaging.h"

namespace anl
{
    enum ERasterTriangleModes
    {
        RTM_Replace,
        RTM_Add,
        RTM_SubtractSrc,
        RTM_SubtractDest,
        RTM_Average,
        RTM_AverageNonZero,
        RTM_Min,
        RTM_Max,
        RTM_Multiply,
        RTM_Blend
    };

    struct SEdge
    {
        SEdge(int x1, int y1, CVec3f p1, int x2, int y2, CVec3f p2)
        {
            if(y1 < y2)
            {
                p1_=p1;
                x1_=x1;
                y1_=y1;
                x2_=x2;
                y2_=y2;
                p2_=p2;
            }
            else
            {
                p1_=p2;
                x1_=x2;
                y1_=y2;
                x2_=x1;
                y2_=y1;
                p2_=p1;
            }
        }

        int x1_, y1_, x2_, y2_;
        CVec3f p1_, p2_;
    };

    struct SSpan
    {
        SSpan(int x1, CVec3f p1, int x2, CVec3f p2)
        {
            if(x1<x2)
            {
                p1_=p1;
                x1_=x1;
                p2_=p2;
                x2_=x2;
            }
            else
            {
                p1_=p2;
                x1_=x2;
                p2_=p1;
                x2_=x1;
            }
        }

        int x1_, x2_;
        CVec3f p1_, p2_;
    };

    void rasterizeImplicitTriangle(int u1, int v1, CVec3f p1, int u2, int v2, CVec3f p2, int u3, int v3, CVec3f p3, CArray2Dd *a, CImplicitModuleBase *f);
    void rasterizeRGBATriangle(int u1, int v1, CVec3f p1, int u2, int v2, CVec3f p2, int u3, int v3, CVec3f p3, CArray2Drgba *a, CRGBAModuleBase *f);

};

#endif
