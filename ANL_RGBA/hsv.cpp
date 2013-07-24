#include "hsv.h"
#include <cmath>

namespace anl
{
float min3(float v1, float v2, float v3)
{
	float cm=v1;
	if(v2<cm) cm=v2;
	if(v3<cm) cm=v3;
	return cm;
}

float max3(float v1, float v2, float v3)
{
	float cm=v1;
	if(v2>cm) cm=v2;
	if(v3>cm) cm=v3;
	return cm;
}

void RGBAtoHSV(SRGBA &col, SRGBA &hsv)
{
	float mn,mx,dlt;
	float h,s,v;
	mn=min3(col[0],col[1],col[2]);
	mx=max3(col[0],col[1],col[2]);
	dlt=mx-mn;
	v=mx;

	if(mx!=0)
	{
		//s=dlt/mx;
		s=1.0f-(mn/mx);
	}
	else
	{
		hsv=SRGBA(0,0,0,col[3]);
		return;
	}

	if(col[0]==mx)
	{
		//h=(col[1]-col[2])/dlt;
		h=(float)((int)(60.0f * ((col[1]-col[2]) / dlt))%360);
	}
	else if(col[1]==mx)
	{
		//h=2.0f+(col[2]-col[0])/dlt;
		h=60.0f*((col[2]-col[0]) / dlt) +120.0f;
	}
	else
	{
		//h=4.0f+(col[0]-col[1])/dlt;
		h=60.0f*((col[0]-col[1])/dlt)+240.0f;
	}

	//h=h*60;
	//if(h<0) h=h+360.0f;
	hsv[0]=h/360.0f;
	hsv[1]=s;
	hsv[2]=v;
	hsv[3]=col[3];

/*	float maxc=max3(c[0], c[1], c[2]);
	float minc=min3(c[0], c[1], c[2]);
	int h;
	float s,v;
	if(minc==maxc) h=0;
    else if(maxc==c[0]) h=(int)(60.0f * ((c[1]-c[2]) / (maxc-minc))) % 360;
    else if(maxc==c[1]) h=(int)(60.0f * ((c[2]-c[0]) / (maxc-minc))) +120;
    else h=(int)(60.0f * ((c[0]-c[1]) / (maxc-minc))) +240;
    v=maxc;
    if(maxc==0.0f) s=0.0f;
    else s=1.0f-(minc/maxc);
    hsv=CRGBAf((float)(h)/360.0f, s, v, c[3]);*/
}

void HSVtoRGBA(SRGBA &hsv, SRGBA &col)
{
    /*
    hsv[0]=hsv[0]*360.0f;
    int hi = ((int)(floorf(hsv[0] / 60.0f)) % 6);
    float f=(hsv[0]/60.0f) - floorf(hsv[0]/60.0f);
    float p=hsv[2]*(1.0f-hsv[1]);
    float q=hsv[2]*(1.0-(f*hsv[1]));
    float t=hsv[2]*(1.0-((1.0-f)*hsv[1]));
    float v=hsv[2];

    switch(hi)
    {
        case 0: col=CRGBAf(v,t,p,hsv[3]); break;
        case 1: col=CRGBAf(q,v,p,hsv[3]); break;
        case 2: col=CRGBAf(p,v,t,hsv[3]); break;
        case 3: col=CRGBAf(p,q,v,hsv[3]); break;
        case 4: col=CRGBAf(t,p,v,hsv[3]); break;
        case 5: col=CRGBAf(v,p,q,hsv[3]); break;
        default: break;
    }
*/

	float i,f,p,q,t,r,g,b;
	float h=hsv[0], s=hsv[1], v=hsv[2];

	if(s==0)
	{
		col=SRGBA(v,v,v,hsv[3]);
		return;
	}

	h=(h*360.0f)/60.0f;
	i=floorf(h);
	f=h-i;
	p=v*(1.0f-s);
	q=v*(1.0f-s*f);
	t=v*(1.0f-s*(1.0f-f));

	if(i==0)
	{
		r=v; g=t; b=p;
	}
	else if(i==1)
	{
		r=q; g=v; b=p;
	}
	else if(i==2)
	{
		r=p; g=v; b=t;
	}
	else if(i==3)
	{
		r=p; g=q; b=v;
	}
	else if(i==4)
	{
		r=t; g=p; b=v;
	}
	else
	{
		r=v; g=p; b=q;
	}

	col=SRGBA(r,g,b,hsv[3]);
}
};
