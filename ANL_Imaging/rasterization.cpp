#include "rasterization.h"
#include <iostream>

namespace anl
{
    void drawSpanImplicit(SSpan span, int y, CArray2Dd *img, CImplicitModuleBase *m)
    {
        float xdiff=span.x2_-span.x1_;
        if(xdiff<0) return;

        float factor=0;
        float factorStep=1.0f / xdiff;
        for(int x=span.x1_; x<=span.x2_; ++x)
        {
            CVec3f p=span.p1_ + (span.p2_ - span.p1_)*factor;
            img->set(x,y,m->get(p[0], p[1], p[2]));
            factor+=factorStep;
        }
    }

    void drawSpanRGBA(SSpan span, int y, CArray2Drgba *img, CRGBAModuleBase *m)
    {
        float xdiff=span.x2_-span.x1_;
        if(xdiff<0) return;

        float factor=0;
        float factorStep=1.0f / xdiff;
        for(int x=span.x1_; x<=span.x2_; ++x)
        {
            CVec3f p=span.p1_ + (span.p2_ - span.p1_)*factor;
            img->set(x,y,m->get(p[0], p[1], p[2]));
            factor+=factorStep;
        }
    }

    void drawSpansBetweenEdgesImplicit(SEdge e1, SEdge e2, CArray2Dd *img, CImplicitModuleBase *m)
    {
        float e1ydiff=(e1.y2_-e1.y1_);
        if(e1ydiff==0) return;

        float e2ydiff=(e2.y2_-e1.y1_);
        if(e2ydiff==0) return;

        float e1xdiff=(e1.x2_-e1.x1_);
        float e2xdiff=(e2.x2_-e2.x1_);

        float factor1=(e2.y1_-e1.y1_)/e1ydiff;
        float factorStep1=1.0/e1ydiff;
        float factor2=0;
        float factorStep2=1.0/e2ydiff;

        for(int y=e2.y1_; y<e2.y2_; ++y)
        {
            SSpan span(e1.x1_ + (int)(e1xdiff*factor1), e1.p1_+(e1.p2_-e1.p1_)*factor1, e2.x1_+(int)(e2xdiff*factor2), e2.p1_+(e2.p2_-e2.p1_)*factor2);
            drawSpanImplicit(span, y, img, m);
            factor1+=factorStep1;
            factor2+=factorStep2;
        }
    }

    void drawSpansBetweenEdgesRGBA(SEdge e1, SEdge e2, CArray2Drgba *img, CRGBAModuleBase *m)
    {
        float e1ydiff=(e1.y2_-e1.y1_);
        if(e1ydiff==0) return;

        float e2ydiff=(e2.y2_-e1.y1_);
        if(e2ydiff==0) return;

        float e1xdiff=(e1.x2_-e1.x1_);
        float e2xdiff=(e2.x2_-e2.x1_);

        float factor1=(e2.y1_-e1.y1_)/e1ydiff;
        float factorStep1=1.0/e1ydiff;
        float factor2=0;
        float factorStep2=1.0/e2ydiff;

        for(int y=e2.y1_; y<e2.y2_; ++y)
        {
            SSpan span(e1.x1_ + (int)(e1xdiff*factor1), e1.p1_+(e1.p2_-e1.p1_)*factor1, e2.x1_+(int)(e2xdiff*factor2), e2.p1_+(e2.p2_-e2.p1_)*factor2);
            drawSpanRGBA(span, y, img, m);
            factor1+=factorStep1;
            factor2+=factorStep2;
        }
    }

    void rasterizeImplicitTriangle(int u1, int v1, CVec3f p1, int u2, int v2, CVec3f p2, int u3, int v3, CVec3f p3, CArray2Dd *a, CImplicitModuleBase *f)
    {
        SEdge edges[3]=
        {
            SEdge(u1,v1,p1, u2,v2,p2),
            SEdge(u2,v2,p2, u3,v3,p3),
            SEdge(u3,v3,p3, u1,v1,p1)
        };

        float maxLength=0;
        int longEdge=0;

        for(int i=0; i<3; ++i)
        {
            float length=edges[i].y2_ - edges[i].y1_;
            if(length>maxLength)
            {
                maxLength=length;
                longEdge=i;
            }
        }

        int shortEdge1=(longEdge+1)%3;
        int shortEdge2=(longEdge+2)%3;

        drawSpansBetweenEdgesImplicit(edges[longEdge], edges[shortEdge1], a,f);
        drawSpansBetweenEdgesImplicit(edges[longEdge], edges[shortEdge2], a,f);;
    }

    void rasterizeRGBATriangle(int u1, int v1, CVec3f p1, int u2, int v2, CVec3f p2, int u3, int v3, CVec3f p3, CArray2Drgba *a, CRGBAModuleBase *f)
    {
        SEdge edges[3]=
        {
            SEdge(u1,v1,p1, u2,v2,p2),
            SEdge(u2,v2,p2, u3,v3,p3),
            SEdge(u3,v3,p3, u1,v1,p1)
        };

        float maxLength=0;
        int longEdge=0;

        for(int i=0; i<3; ++i)
        {
            float length=edges[i].y2_ - edges[i].y1_;
            if(length>maxLength)
            {
                maxLength=length;
                longEdge=i;
            }
        }

        int shortEdge1=(longEdge+1)%3;
        int shortEdge2=(longEdge+2)%3;

        drawSpansBetweenEdgesRGBA(edges[longEdge], edges[shortEdge1], a,f);
        drawSpansBetweenEdgesRGBA(edges[longEdge], edges[shortEdge2], a,f);;
    }
};
