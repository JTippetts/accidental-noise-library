#include "noise_gen.h"
#include "noise_lut.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace anl;

ANLFloatType anl::noInterp(ANLFloatType t)
{
    return 0;
}

ANLFloatType anl::linearInterp(ANLFloatType t)
{
    return t;
}

ANLFloatType anl::hermiteInterp(ANLFloatType t)
{
    return (t*t*(3-2*t));
}

ANLFloatType anl::quinticInterp(ANLFloatType t)
{
    return t*t*t*(t*(t*6-15)+10);

}

inline int fast_floor(ANLFloatType t)
{
    return (t>0 ? (int)t : (int)t - 1);
}

inline ANLFloatType array_dot2(ANLFloatType *arr, ANLFloatType a, ANLFloatType b)
{
    return a*arr[0] + b*arr[1];
}

inline ANLFloatType array_dot3(ANLFloatType *arr, ANLFloatType a, ANLFloatType b, ANLFloatType c)
{
    return a*arr[0]+b*arr[1]+c*arr[2];
}

inline ANLFloatType array_dot4(ANLFloatType *arr, ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
{
	return x*arr[0]+y*arr[1]+z*arr[2]+w*arr[3];
}

inline ANLFloatType array_dot6(ANLFloatType *arr, ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
	return x*arr[0]+y*arr[1]+z*arr[2]+w*arr[3]+u*arr[4]+v*arr[5];
}

// Distance

ANLFloatType anl::distEuclid2(ANLFloatType x1, ANLFloatType y1, ANLFloatType x2, ANLFloatType y2)
{
    ANLFloatType dx=x2-x1;
    ANLFloatType dy=y2-y1;
    return sqrt(dx*dx+dy*dy);
}

ANLFloatType anl::distEuclid3(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2)
{
    ANLFloatType dx=x2-x1;
    ANLFloatType dy=y2-y1;
    ANLFloatType dz=z2-z1;
    return sqrt(dx*dx+dy*dy+dz*dz);
}

ANLFloatType anl::distEuclid4(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2)
{
    ANLFloatType dx=x2-x1;
    ANLFloatType dy=y2-y1;
    ANLFloatType dz=z2-z1;
    ANLFloatType dw=w2-w1;
    return sqrt(dx*dx+dy*dy+dz*dz+dw*dw);
}

ANLFloatType anl::distEuclid6(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType u1, ANLFloatType v1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2, ANLFloatType u2, ANLFloatType v2)
{
    ANLFloatType dx=x2-x1;
    ANLFloatType dy=y2-y1;
    ANLFloatType dz=z2-z1;
    ANLFloatType dw=w2-w1;
    ANLFloatType du=u2-u1;
    ANLFloatType dv=v2-v1;
    return sqrt(dx*dx+dy*dy+dz*dz+dw*dw+du*du+dv*dv);
}


ANLFloatType anl::distManhattan2(ANLFloatType x1, ANLFloatType y1, ANLFloatType x2, ANLFloatType y2)
{
    ANLFloatType dx=fabs(x2-x1);
    ANLFloatType dy=fabs(y2-y1);
    //return std::max(dx,dy);
    return dx+dy;
}

ANLFloatType anl::distManhattan3(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2)
{
    ANLFloatType dx=fabs(x2-x1);
    ANLFloatType dy=fabs(y2-y1);
    ANLFloatType dz=fabs(z2-z1);
    //return std::max(dz,std::max(dx,dy));
    return dx+dy+dz;
}

ANLFloatType anl::distManhattan4(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2)
{
    ANLFloatType dx=fabs(x2-x1);
    ANLFloatType dy=fabs(y2-y1);
    ANLFloatType dz=fabs(z2-z1);
    ANLFloatType dw=fabs(w2-w1);
    //return std::max(dw,std::max(dz,std::max(dx,dy)));
    return dx+dy+dz+dw;
}

ANLFloatType anl::distManhattan6(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType u1, ANLFloatType v1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2, ANLFloatType u2, ANLFloatType v2)
{
    ANLFloatType dx=fabs(x2-x1);
    ANLFloatType dy=fabs(y2-y1);
    ANLFloatType dz=fabs(z2-z1);
    ANLFloatType dw=fabs(w2-w1);
    ANLFloatType du=fabs(u2-u1);
    ANLFloatType dv=fabs(v2-v1);
    //return std::max(du,std::max(dv,std::max(dw,std::max(dz,std::max(dx,dy)))));
    return dx+dy+dz+dw+du+dv;
}

ANLFloatType anl::distGreatestAxis2(ANLFloatType x1, ANLFloatType y1, ANLFloatType x2, ANLFloatType y2)
{
    ANLFloatType dx=fabs(x2-x1);
    ANLFloatType dy=fabs(y2-y1);
    return std::max(dx,dy);
}

ANLFloatType anl::distGreatestAxis3(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2)
{
    ANLFloatType dx=fabs(x2-x1);
    ANLFloatType dy=fabs(y2-y1);
    ANLFloatType dz=fabs(z2-z1);
    return std::max(dz,std::max(dx,dy));
}

ANLFloatType anl::distGreatestAxis4(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2)
{
    ANLFloatType dx=fabs(x2-x1);
    ANLFloatType dy=fabs(y2-y1);
    ANLFloatType dz=fabs(z2-z1);
    ANLFloatType dw=fabs(w2-w1);
    return std::max(dw,std::max(dz,std::max(dx,dy)));
}

ANLFloatType anl::distGreatestAxis6(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType u1, ANLFloatType v1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2, ANLFloatType u2, ANLFloatType v2)
{
    ANLFloatType dx=fabs(x2-x1);
    ANLFloatType dy=fabs(y2-y1);
    ANLFloatType dz=fabs(z2-z1);
    ANLFloatType dw=fabs(w2-w1);
    ANLFloatType du=fabs(u2-u1);
    ANLFloatType dv=fabs(v2-v1);
    return std::max(du,std::max(dv,std::max(dw,std::max(dz,std::max(dx,dy)))));
}

ANLFloatType anl::distLeastAxis2(ANLFloatType x1, ANLFloatType y1, ANLFloatType x2, ANLFloatType y2)
{
    ANLFloatType dx=fabs(x2-x1);
    ANLFloatType dy=fabs(y2-y1);
    return std::min(dx,dy);
}

ANLFloatType anl::distLeastAxis3(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2)
{
    ANLFloatType dx=fabs(x2-x1);
    ANLFloatType dy=fabs(y2-y1);
    ANLFloatType dz=fabs(z2-z1);
    return std::min(dz,std::min(dx,dy));
}

ANLFloatType anl::distLeastAxis4(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2)
{
    ANLFloatType dx=fabs(x2-x1);
    ANLFloatType dy=fabs(y2-y1);
    ANLFloatType dz=fabs(z2-z1);
    ANLFloatType dw=fabs(w2-w1);
    return std::min(dw,std::min(dz,std::min(dx,dy)));
}

ANLFloatType anl::distLeastAxis6(ANLFloatType x1, ANLFloatType y1, ANLFloatType z1, ANLFloatType w1, ANLFloatType u1, ANLFloatType v1, ANLFloatType x2, ANLFloatType y2, ANLFloatType z2, ANLFloatType w2, ANLFloatType u2, ANLFloatType v2)
{
    ANLFloatType dx=fabs(x2-x1);
    ANLFloatType dy=fabs(y2-y1);
    ANLFloatType dz=fabs(z2-z1);
    ANLFloatType dw=fabs(w2-w1);
    ANLFloatType du=fabs(u2-u1);
    ANLFloatType dv=fabs(v2-v1);
    return std::min(du,std::min(dv,std::min(dw,std::min(dz,std::min(dx,dy)))));
}

// Hashing

// The "new" FNV-1A hashing
#define FNV_32_PRIME ((unsigned int)0x01000193)
#define FNV_32_INIT ((unsigned int )2166136261)
#define FNV_MASK_8 (((unsigned int)1<<8)-1)

unsigned int fnv_32_a_buf(void *buf, unsigned int len)
{
    unsigned int hval=(unsigned int)FNV_32_INIT;
    unsigned int *bp = (unsigned int *)buf;
    unsigned int *be = bp+len;
    while (bp<be)
    {
        hval ^=*bp++;
        hval*=FNV_32_PRIME;
    }
    return hval;
}

unsigned int fnv_32_a_combine(unsigned int hash, unsigned int val)
{
	hash^=val;
	hash*=FNV_32_PRIME;
	return hash;
}


unsigned char xor_fold_hash(unsigned int hash)
{
    // Implement XOR-folding to reduce from 32 to 8-bit hash
    return (unsigned char)((hash>>8) ^ (hash & FNV_MASK_8));
}


// FNV-based coordinate hashes
unsigned int hash_coords_2(int x, int y, unsigned int seed)
{
    //unsigned int d[3]={(unsigned int)x,(unsigned int)y,seed};
    //return xor_fold_hash(fnv_32_a_buf(d, 3));
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash,(unsigned int)x);
	hash=fnv_32_a_combine(hash,(unsigned int)y);
	hash=fnv_32_a_combine(hash,seed);
	return xor_fold_hash(hash);
}
unsigned int hash_coords_3(int x, int y, int z, unsigned int seed)
{
    //unsigned int d[4]={(unsigned int)x,(unsigned int)y,(unsigned int)z,seed};
    //return xor_fold_hash(fnv_32_a_buf(d, 4));
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash,(unsigned int)x);
	hash=fnv_32_a_combine(hash,(unsigned int)y);
	hash=fnv_32_a_combine(hash,(unsigned int)z);
	hash=fnv_32_a_combine(hash,seed);
	return xor_fold_hash(hash);
}

unsigned int hash_coords_4(int x, int y, int z, int w, unsigned int seed)
{
    //unsigned int d[5]={(unsigned int)x,(unsigned int)y,(unsigned int)z,(unsigned int)w,seed};
    //return xor_fold_hash(fnv_32_a_buf(d, 5));
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash,(unsigned int)x);
	hash=fnv_32_a_combine(hash,(unsigned int)y);
	hash=fnv_32_a_combine(hash,(unsigned int)z);
	hash=fnv_32_a_combine(hash,(unsigned int)w);
	hash=fnv_32_a_combine(hash,seed);
	return xor_fold_hash(hash);
}

unsigned int hash_coords_6(int x, int y, int z, int w, int u, int v, unsigned int seed)
{
    //unsigned int d[7]={(unsigned int)x,(unsigned int)y,(unsigned int)z,(unsigned int)w,(unsigned int)u,(unsigned int)v,seed};
    //return xor_fold_hash(fnv_32_a_buf(d, 7));
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash,(unsigned int)x);
	hash=fnv_32_a_combine(hash,(unsigned int)y);
	hash=fnv_32_a_combine(hash,(unsigned int)z);
	hash=fnv_32_a_combine(hash,(unsigned int)w);
	hash=fnv_32_a_combine(hash,(unsigned int)u);
	hash=fnv_32_a_combine(hash,(unsigned int)v);
	hash=fnv_32_a_combine(hash,seed);
	return xor_fold_hash(hash);
}

unsigned int compute_hash_ANLFloatType_2(ANLFloatType x, ANLFloatType y, unsigned int seed)
{
    //ANLFloatType d[3]={x,y,(ANLFloatType)seed};
	//unsigned int s=sizeof(d) / sizeof(unsigned int);
    //return xor_fold_hash(fnv_32_a_buf(d, s));
	
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash, (unsigned int)(x*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, (unsigned int)(y*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, seed);
	return xor_fold_hash(hash);
}


unsigned int compute_hash_ANLFloatType_3(ANLFloatType x, ANLFloatType y, ANLFloatType z, unsigned int seed)
{
    //ANLFloatType d[4]={x,y,z,(ANLFloatType)seed};
	//unsigned int s=sizeof(d) / sizeof(unsigned int);
    //return xor_fold_hash(fnv_32_a_buf(d, s));
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash, (unsigned int)(x*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, (unsigned int)(y*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, (unsigned int)(z*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, seed);
	return xor_fold_hash(hash);
	
}

unsigned int compute_hash_ANLFloatType_4(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed)
{
    //ANLFloatType d[5]={x,y,z,w,(ANLFloatType)seed};
	//unsigned int s=sizeof(d) / sizeof(unsigned int);
    //return xor_fold_hash(fnv_32_a_buf(d, s));
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash, (unsigned int)(x*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, (unsigned int)(y*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, (unsigned int)(z*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, (unsigned int)(w*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, seed);
	return xor_fold_hash(hash);
}

unsigned int compute_hash_ANLFloatType_6(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, unsigned int seed)
{
    //ANLFloatType d[7]={x,y,z,w,u,v,(ANLFloatType)seed};
	//unsigned int s=sizeof(d) / sizeof(unsigned int);
    //return xor_fold_hash(fnv_32_a_buf(d, s));
	unsigned int hash=FNV_32_INIT;
	hash=fnv_32_a_combine(hash, (unsigned int)(x*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, (unsigned int)(y*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, (unsigned int)(z*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, (unsigned int)(w*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, (unsigned int)(u*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, (unsigned int)(v*(ANLFloatType)1000000));
	hash=fnv_32_a_combine(hash, seed);
	return xor_fold_hash(hash);
}



// Worker noise functions
typedef ANLFloatType (*worker_noise_2)(ANLFloatType, ANLFloatType, int, int, unsigned int);
typedef ANLFloatType (*worker_noise_3)(ANLFloatType, ANLFloatType, ANLFloatType, int, int, int, unsigned int);
typedef ANLFloatType (*worker_noise_4)(ANLFloatType,ANLFloatType,ANLFloatType,ANLFloatType,int,int,int,int,unsigned int);
typedef ANLFloatType (*worker_noise_6)(ANLFloatType,ANLFloatType,ANLFloatType,ANLFloatType,ANLFloatType,ANLFloatType,int,int,int,int,int,int,unsigned int);


ANLFloatType value_noise_2( ANLFloatType x, ANLFloatType y, int ix, int iy, unsigned int seed)
{
    unsigned int n = (hash_coords_2(ix,iy,seed));
    ANLFloatType noise = (ANLFloatType)n / 255.0;
    return noise*2.0 - 1.0;
}
ANLFloatType value_noise_3(ANLFloatType x, ANLFloatType y, ANLFloatType z, int ix, int iy, int iz, unsigned int seed)
{
    unsigned int n = (hash_coords_3(ix,iy,iz,seed));
    ANLFloatType noise=(ANLFloatType)n/(255.0);
    return noise*2.0-1.0;
}
ANLFloatType value_noise_4(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, int ix, int iy,int iz,int iw, unsigned int seed)
{
    unsigned int n = (hash_coords_4(ix,iy,iz,iw,seed));
    ANLFloatType noise = (ANLFloatType)n / 255.0;
    return noise*2.0 - 1.0;
}
ANLFloatType value_noise_6(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, int ix, int iy,int iz,int iw, int iu, int iv, unsigned int seed)
{
    unsigned int n = (hash_coords_6(ix,iy,iz,iw,iu,iv,seed));
    ANLFloatType noise = (ANLFloatType)n / 255.0;
    return noise*2.0 - 1.0;
}

ANLFloatType grad_noise_2(ANLFloatType x, ANLFloatType y, int ix, int iy, unsigned int seed)
{
    unsigned int hash=hash_coords_2(ix,iy,seed);
    ANLFloatType *vec=&gradient2D_lut[hash][0];

    ANLFloatType dx=x-(ANLFloatType)ix;
    ANLFloatType dy=y-(ANLFloatType)iy;

    return (dx*vec[0] + dy*vec[1]);
}

ANLFloatType grad_noise_3(ANLFloatType x, ANLFloatType y, ANLFloatType z, int ix, int iy, int iz, unsigned int seed)
{
    unsigned int hash=hash_coords_3(ix,iy,iz,seed);
    ANLFloatType *vec=&gradient3D_lut[hash][0];

    ANLFloatType dx=x-(ANLFloatType)ix;
    ANLFloatType dy=y-(ANLFloatType)iy;
    ANLFloatType dz=z-(ANLFloatType)iz;
    return (dx*vec[0]+dy*vec[1]+dz*vec[2]);
}

ANLFloatType grad_noise_4(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, int ix, int iy, int iz, int iw, unsigned int seed)
{
    unsigned int hash=hash_coords_4(ix,iy,iz,iw,seed);
    ANLFloatType *vec=&gradient4D_lut[hash][0];

    ANLFloatType dx=x-(ANLFloatType)ix;
    ANLFloatType dy=y-(ANLFloatType)iy;
    ANLFloatType dz=z-(ANLFloatType)iz;
    ANLFloatType dw=w-(ANLFloatType)iw;

    return (dx*vec[0] + dy*vec[1] + dz*vec[2] + dw*vec[3]);

}

ANLFloatType grad_noise_6(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, int ix, int iy, int iz, int iw, int iu, int iv, unsigned int seed)
{
    unsigned int hash=hash_coords_6(ix,iy,iz,iw,iu,iv,seed);
    ANLFloatType *vec=&gradient6D_lut[hash][0];

    ANLFloatType dx=x-(ANLFloatType)ix;
    ANLFloatType dy=y-(ANLFloatType)iy;
    ANLFloatType dz=z-(ANLFloatType)iz;
    ANLFloatType dw=w-(ANLFloatType)iw;
    ANLFloatType du=u-(ANLFloatType)iu;
    ANLFloatType dv=v-(ANLFloatType)iv;

    return (dx*vec[0] + dy*vec[1] + dz*vec[2] + dw*vec[3] + du*vec[4] + dv*vec[5]);

}



// Edge/Face/Cube/Hypercube interpolation
ANLFloatType lerp(ANLFloatType s, ANLFloatType v1, ANLFloatType v2)
{
	return v1+s*(v2-v1);
}

ANLFloatType interp_X_2(ANLFloatType x, ANLFloatType y, ANLFloatType xs, int x0, int x1, int iy, unsigned int seed, worker_noise_2 noisefunc)
{
	ANLFloatType v1=noisefunc(x,y,x0,iy,seed);
	ANLFloatType v2=noisefunc(x,y,x1,iy,seed);
	return lerp(xs,v1,v2);
}

ANLFloatType interp_XY_2(ANLFloatType x, ANLFloatType y, ANLFloatType xs, ANLFloatType ys, int x0, int x1, int y0, int y1, unsigned int seed, worker_noise_2 noisefunc)
{
	ANLFloatType v1=interp_X_2(x,y,xs,x0,x1,y0,seed,noisefunc);
	ANLFloatType v2=interp_X_2(x,y,xs,x0,x1,y1,seed,noisefunc);
	return lerp(ys,v1,v2);
}

ANLFloatType interp_X_3(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType xs, int x0, int x1, int iy, int iz, unsigned int seed, worker_noise_3 noisefunc)
{
    ANLFloatType v1=noisefunc(x,y,z,x0,iy,iz,seed);
    ANLFloatType v2=noisefunc(x,y,z,x1,iy,iz,seed);
    return lerp(xs,v1,v2);
}

ANLFloatType interp_XY_3(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType xs, ANLFloatType ys, int x0, int x1, int y0, int y1, int iz, unsigned int seed, worker_noise_3 noisefunc)
{
    ANLFloatType v1=interp_X_3(x,y,z,xs,x0,x1,y0,iz,seed,noisefunc);
    ANLFloatType v2=interp_X_3(x,y,z,xs,x0,x1,y1,iz,seed,noisefunc);
    return lerp(ys,v1,v2);
}

ANLFloatType interp_XYZ_3(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType xs, ANLFloatType ys, ANLFloatType zs, int x0, int x1, int y0, int y1, int z0, int z1, unsigned int seed, worker_noise_3 noisefunc)
{
    ANLFloatType v1=interp_XY_3(x,y,z,xs,ys,x0,x1,y0,y1,z0,seed,noisefunc);
    ANLFloatType v2=interp_XY_3(x,y,z,xs,ys,x0,x1,y0,y1,z1,seed,noisefunc);
    return lerp(zs,v1,v2);
}

ANLFloatType interp_X_4(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType xs, int x0, int x1, int iy, int iz, int iw, unsigned int seed, worker_noise_4 noisefunc)
{
	ANLFloatType v1=noisefunc(x,y,z,w,x0,iy,iz,iw,seed);
	ANLFloatType v2=noisefunc(x,y,z,w,x1,iy,iz,iw,seed);
	return lerp(xs,v1,v2);
}

ANLFloatType interp_XY_4(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType xs, ANLFloatType ys, int x0, int x1, int y0, int y1, int iz, int iw, unsigned int seed, worker_noise_4 noisefunc)
{
	ANLFloatType v1=interp_X_4(x,y,z,w,xs,x0,x1,y0,iz,iw,seed,noisefunc);
	ANLFloatType v2=interp_X_4(x,y,z,w,xs,x0,x1,y1,iz,iw,seed,noisefunc);
	return lerp(ys,v1,v2);
}

ANLFloatType interp_XYZ_4(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType xs, ANLFloatType ys, ANLFloatType zs, int x0, int x1, int y0, int y1, int z0, int z1, int iw, unsigned int seed, worker_noise_4 noisefunc)
{
	ANLFloatType v1=interp_XY_4(x,y,z,w,xs,ys,x0,x1,y0,y1,z0,iw,seed,noisefunc);
	ANLFloatType v2=interp_XY_4(x,y,z,w,xs,ys,x0,x1,y0,y1,z1,iw,seed,noisefunc);
	return lerp(zs,v1,v2);
}

ANLFloatType interp_XYZW_4(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType xs, ANLFloatType ys, ANLFloatType zs, ANLFloatType ws, int x0, int x1, int y0, int y1, int z0, int z1, int w0, int w1, unsigned int seed, worker_noise_4 noisefunc)
{
	ANLFloatType v1=interp_XYZ_4(x,y,z,w,xs,ys,zs,x0,x1,y0,y1,z0,z1,w0,seed,noisefunc);
	ANLFloatType v2=interp_XYZ_4(x,y,z,w,xs,ys,zs,x0,x1,y0,y1,z0,z1,w1,seed,noisefunc);
	return lerp(ws,v1,v2);
}


ANLFloatType interp_X_6(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, ANLFloatType xs, int x0, int x1, int iy, int iz, int iw, int iu, int iv, unsigned int seed, worker_noise_6 noisefunc)
{
    ANLFloatType v1=noisefunc(x,y,z,w,u,v,x0,iy,iz,iw,iu,iv,seed);
    ANLFloatType v2=noisefunc(x,y,z,w,u,v,x1,iy,iz,iw,iu,iv,seed);
    return lerp(xs,v1,v2);
}

ANLFloatType interp_XY_6(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, ANLFloatType xs, ANLFloatType ys, int x0, int x1, int y0, int y1, int iz, int iw, int iu, int iv, unsigned int seed, worker_noise_6 noisefunc)
{
    ANLFloatType v1=interp_X_6(x,y,z,w,u,v,xs, x0,x1,y0,iz,iw,iu,iv,seed,noisefunc);
    ANLFloatType v2=interp_X_6(x,y,z,w,u,v,xs,x0,x1,y1,iz,iw,iu,iv,seed,noisefunc);
    return lerp(ys,v1,v2);
}

ANLFloatType interp_XYZ_6(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, ANLFloatType xs, ANLFloatType ys, ANLFloatType zs, int x0, int x1, int y0, int y1, int z0, int z1, int iw, int iu, int iv, unsigned int seed, worker_noise_6 noisefunc)
{
    ANLFloatType v1=interp_XY_6(x,y,z,w,u,v,xs,ys,x0,x1,y0,y1,z0,iw,iu,iv,seed,noisefunc);
    ANLFloatType v2=interp_XY_6(x,y,z,w,u,v,xs,ys,x0,x1,y0,y1,z1,iw,iu,iv,seed,noisefunc);
    return lerp(zs,v1,v2);
}

ANLFloatType interp_XYZW_6(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, ANLFloatType xs, ANLFloatType ys, ANLFloatType zs, ANLFloatType ws, int x0, int x1, int y0, int y1, int z0, int z1, int w0, int w1, int iu, int iv, unsigned int seed,worker_noise_6 noisefunc)
{
    ANLFloatType v1=interp_XYZ_6(x,y,z,w,u,v,xs,ys,zs,x0,x1,y0,y1,z0,z1,w0,iu,iv,seed,noisefunc);
    ANLFloatType v2=interp_XYZ_6(x,y,z,w,u,v,xs,ys,zs,x0,x1,y0,y1,z0,z1,w1,iu,iv,seed,noisefunc);
    return lerp(ws,v1,v2);
}

ANLFloatType interp_XYZWU_6(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, ANLFloatType xs, ANLFloatType ys, ANLFloatType zs, ANLFloatType ws, ANLFloatType us, int x0, int x1, int y0, int y1, int z0, int z1, int w0, int w1, int u0, int u1, int iv, unsigned int seed, worker_noise_6 noisefunc)
{
    ANLFloatType v1=interp_XYZW_6(x,y,z,w,u,v,xs,ys,zs,ws,x0,x1,y0,y1,z0,z1,w0,w1,u0,iv,seed,noisefunc);
    ANLFloatType v2=interp_XYZW_6(x,y,z,w,u,v,xs,ys,zs,ws,x0,x1,y0,y1,z0,z1,w0,w1,u1,iv,seed,noisefunc);
    return lerp(us,v1,v2);
}

ANLFloatType interp_XYZWUV_6(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, ANLFloatType xs, ANLFloatType ys, ANLFloatType zs, ANLFloatType ws, ANLFloatType us, ANLFloatType vs, int x0, int x1, int y0, int y1, int z0, int z1, int w0, int w1, int u0, int u1, int v0, int v1, unsigned int seed, worker_noise_6 noisefunc)
{
    ANLFloatType val1=interp_XYZWU_6(x,y,z,w,u,v,xs,ys,zs,ws,us,x0,x1,y0,y1,z0,z1,w0,w1,u0,u1,v0,seed,noisefunc);
    ANLFloatType val2=interp_XYZWU_6(x,y,z,w,u,v,xs,ys,zs,ws,us,x0,x1,y0,y1,z0,z1,w0,w1,u0,u1,v1,seed,noisefunc);
    return lerp(vs,val1,val2);
}



// The usable noise functions

ANLFloatType anl::value_noise2D(ANLFloatType x, ANLFloatType y, unsigned int seed, interp_func interp)
{
	int x0=fast_floor(x);
    int y0=fast_floor(y);

    int x1=x0+1;
    int y1=y0+1;

    ANLFloatType xs=interp((x-(ANLFloatType)x0));
    ANLFloatType ys=interp((y-(ANLFloatType)y0));

	return interp_XY_2(x,y,xs,ys,x0,x1,y0,y1,seed,value_noise_2);
}

ANLFloatType anl::value_noise3D(ANLFloatType x, ANLFloatType y, ANLFloatType z, unsigned int seed, interp_func interp)
{
    int x0=fast_floor(x);
    int y0=fast_floor(y);
    int z0=fast_floor(z);
    int x1=x0+1;
    int y1=y0+1;
    int z1=z0+1;

    ANLFloatType xs=interp((x-(ANLFloatType)x0));
    ANLFloatType ys=interp((y-(ANLFloatType)y0));
    ANLFloatType zs=interp((z-(ANLFloatType)z0));

    return interp_XYZ_3(x,y,z,xs,ys,zs,x0,x1,y0,y1,z0,z1,seed,value_noise_3);
}

ANLFloatType anl::value_noise4D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed, interp_func interp)
{
	int x0=fast_floor(x);
    int y0=fast_floor(y);
    int z0=fast_floor(z);
    int w0=fast_floor(w);

    int x1=x0+1;
    int y1=y0+1;
    int z1=z0+1;
    int w1=w0+1;

    ANLFloatType xs=interp((x-(ANLFloatType)x0));
    ANLFloatType ys=interp((y-(ANLFloatType)y0));
	ANLFloatType zs=interp((z-(ANLFloatType)z0));
	ANLFloatType ws=interp((w-(ANLFloatType)w0));

	return interp_XYZW_4(x,y,z,w,xs,ys,zs,ws,x0,x1,y0,y1,z0,z1,w0,w1,seed,value_noise_4);
}

ANLFloatType anl::value_noise6D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, unsigned int seed, interp_func interp)
{
	int x0=fast_floor(x);
    int y0=fast_floor(y);
    int z0=fast_floor(z);
    int w0=fast_floor(w);
    int u0=fast_floor(u);
    int v0=fast_floor(v);

    int x1=x0+1;
    int y1=y0+1;
    int z1=z0+1;
    int w1=w0+1;
    int u1=u0+1;
    int v1=v0+1;

    ANLFloatType xs=interp((x-(ANLFloatType)x0));
    ANLFloatType ys=interp((y-(ANLFloatType)y0));
    ANLFloatType zs=interp((z-(ANLFloatType)z0));
    ANLFloatType ws=interp((w-(ANLFloatType)w0));
    ANLFloatType us=interp((u-(ANLFloatType)u0));
    ANLFloatType vs=interp((v-(ANLFloatType)v0));

	return interp_XYZWUV_6(x,y,z,w,u,v,xs,ys,zs,ws,us,vs,x0,x1,y0,y1,z0,z1,w0,w1,u0,u1,v0,v1,seed,value_noise_6);
}

ANLFloatType anl::gradient_noise2D(ANLFloatType x, ANLFloatType y, unsigned int seed, interp_func interp)
{
	int x0=fast_floor(x);
    int y0=fast_floor(y);

    int x1=x0+1;
    int y1=y0+1;

    ANLFloatType xs=interp((x-(ANLFloatType)x0));
    ANLFloatType ys=interp((y-(ANLFloatType)y0));

	return interp_XY_2(x,y,xs,ys,x0,x1,y0,y1,seed,grad_noise_2);
}

ANLFloatType anl::gradient_noise3D(ANLFloatType x, ANLFloatType y, ANLFloatType z, unsigned int seed, interp_func interp)
{
    int x0=fast_floor(x);
    int y0=fast_floor(y);
    int z0=fast_floor(z);

    int x1=x0+1;
    int y1=y0+1;
    int z1=z0+1;

    ANLFloatType xs=interp((x-(ANLFloatType)x0));
    ANLFloatType ys=interp((y-(ANLFloatType)y0));
	ANLFloatType zs=interp((z-(ANLFloatType)z0));

	return interp_XYZ_3(x,y,z,xs,ys,zs,x0,x1,y0,y1,z0,z1,seed,grad_noise_3);
}

ANLFloatType anl::gradient_noise4D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed, interp_func interp)
{
	int x0=fast_floor(x);
    int y0=fast_floor(y);
    int z0=fast_floor(z);
    int w0=fast_floor(w);

    int x1=x0+1;
    int y1=y0+1;
    int z1=z0+1;
    int w1=w0+1;

    ANLFloatType xs=interp((x-(ANLFloatType)x0));
    ANLFloatType ys=interp((y-(ANLFloatType)y0));
	ANLFloatType zs=interp((z-(ANLFloatType)z0));
	ANLFloatType ws=interp((w-(ANLFloatType)w0));

	return interp_XYZW_4(x,y,z,w,xs,ys,zs,ws,x0,x1,y0,y1,z0,z1,w0,w1,seed,grad_noise_4);
}
ANLFloatType anl::gradient_noise6D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, unsigned int seed, interp_func interp)
{
	int x0=fast_floor(x);
    int y0=fast_floor(y);
    int z0=fast_floor(z);
    int w0=fast_floor(w);
    int u0=fast_floor(u);
    int v0=fast_floor(v);

    int x1=x0+1;
    int y1=y0+1;
    int z1=z0+1;
    int w1=w0+1;
    int u1=u0+1;
    int v1=v0+1;

    ANLFloatType xs=interp((x-(ANLFloatType)x0));
    ANLFloatType ys=interp((y-(ANLFloatType)y0));
    ANLFloatType zs=interp((z-(ANLFloatType)z0));
    ANLFloatType ws=interp((w-(ANLFloatType)w0));
    ANLFloatType us=interp((u-(ANLFloatType)u0));
    ANLFloatType vs=interp((v-(ANLFloatType)v0));

	return interp_XYZWUV_6(x,y,z,w,u,v,xs,ys,zs,ws,us,vs,x0,x1,y0,y1,z0,z1,w0,w1,u0,u1,v0,v1,seed,grad_noise_6);
}

ANLFloatType anl::gradval_noise2D(ANLFloatType x, ANLFloatType y, unsigned int seed, interp_func interp)
{
	return value_noise2D(x,y,seed,interp)+gradient_noise2D(x,y,seed,interp);
}

ANLFloatType anl::gradval_noise3D(ANLFloatType x, ANLFloatType y, ANLFloatType z, unsigned int seed, interp_func interp)
{
    return value_noise3D(x,y,z,seed,interp)+gradient_noise3D(x,y,z,seed,interp);
}

ANLFloatType anl::gradval_noise4D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed, interp_func interp)
{
	return value_noise4D(x,y,z,w,seed,interp)+gradient_noise4D(x,y,z,w,seed,interp);
}

ANLFloatType anl::gradval_noise6D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, unsigned int seed, interp_func interp)
{
	return value_noise6D(x,y,z,w,u,v,seed,interp)+gradient_noise6D(x,y,z,w,u,v,seed,interp);
}

ANLFloatType anl::white_noise2D(ANLFloatType x, ANLFloatType y, unsigned int seed, interp_func interp)
{
	unsigned char hash=compute_hash_ANLFloatType_2(x,y,seed);
	return whitenoise_lut[hash];
}

ANLFloatType anl::white_noise3D(ANLFloatType x, ANLFloatType y, ANLFloatType z, unsigned int seed, interp_func interp)
{
    unsigned char hash=compute_hash_ANLFloatType_3(x,y,z,seed);
	//std::cout << (unsigned int)hash << std::endl;
    return whitenoise_lut[hash];
}

ANLFloatType anl::white_noise4D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed, interp_func interp)
{
	unsigned char hash=compute_hash_ANLFloatType_4(x,y,z,w,seed);
	return whitenoise_lut[hash];
}

ANLFloatType anl::white_noise6D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, unsigned int seed, interp_func interp)
{
	unsigned char hash=compute_hash_ANLFloatType_6(x,y,z,w,u,v,seed);
	return whitenoise_lut[hash];
}

void add_dist(ANLFloatType *f, ANLFloatType *disp, ANLFloatType testdist, ANLFloatType testdisp)
{
    int index;
    // Compare the given distance to the ones already in f
    if(testdist < f[3])
    {
       index=3;
       while(index>0 && testdist<f[index-1]) index--;
       for(int i=3; i-->index;)
       {
           f[i+1]=f[i];
           disp[i+1]=disp[i];
       }
       f[index]=testdist;
       disp[index]=testdisp;
    }
}


// Cellular functions. Compute distance (for cellular modules) and displacement (for voronoi modules)



void anl::cellular_function2D(ANLFloatType x, ANLFloatType y, unsigned int seed, ANLFloatType *f, ANLFloatType *disp, dist_func2 distance)
{
    int xint = fast_floor(x);
    int yint = fast_floor(y);

    for(int c=0; c<4; ++c){ f[c]=99999.0; disp[c]=0.0;}

    {
        for(int ycur=yint-3; ycur<=yint+3; ++ycur)
        {
            for(int xcur=xint-3; xcur<=xint+3; ++xcur)
            {
                ANLFloatType xpos = (ANLFloatType)xcur + value_noise_2(x,y,xcur,ycur,seed);
                ANLFloatType ypos = (ANLFloatType)ycur + value_noise_2(x,y,xcur,ycur,seed+1);
                //ANLFloatType xdist=xpos-x;
                //ANLFloatType ydist=ypos-y;
                //ANLFloatType dist=(xdist*xdist + ydist*ydist);
                ANLFloatType dist=distance(xpos,ypos,x,y);
                int xval=fast_floor(xpos);
                int yval=fast_floor(ypos);
                ANLFloatType dsp=value_noise_2(x,y,xval,yval,seed+3);
                add_dist(f,disp, dist, dsp);
            }
        }
    }
}

void anl::cellular_function3D(ANLFloatType x, ANLFloatType y, ANLFloatType z, unsigned int seed, ANLFloatType *f, ANLFloatType *disp, dist_func3 distance)
{
    int xint = fast_floor(x);
    int yint = fast_floor(y);
    int zint = fast_floor(z);

    for(int c=0; c<4; ++c){ f[c]=99999.0; disp[c]=0.0;}

    for (int zcur=zint-2; zcur<=zint+2; ++zcur)
    {
        for(int ycur=yint-2; ycur<=yint+2; ++ycur)
        {
            for(int xcur=xint-2; xcur<=xint+2; ++xcur)
            {
                ANLFloatType xpos = (ANLFloatType)xcur + value_noise_3(x,y,z,xcur,ycur,zcur,seed);
                ANLFloatType ypos = (ANLFloatType)ycur + value_noise_3(x,y,z,xcur,ycur,zcur,seed+1);
                ANLFloatType zpos = (ANLFloatType)zcur + value_noise_3(x,y,z,xcur,ycur,zcur,seed+2);
                //ANLFloatType xdist=xpos-x;
                //ANLFloatType ydist=ypos-y;
                //ANLFloatType zdist=zpos-z;
                //ANLFloatType dist=(xdist*xdist + ydist*ydist + zdist*zdist);
                ANLFloatType dist=distance(xpos,ypos,zpos,x,y,z);
                int xval=fast_floor(xpos);
                int yval=fast_floor(ypos);
                int zval=fast_floor(zpos);
                ANLFloatType dsp=value_noise_3(x,y,z,xval,yval,zval,seed+3);
                add_dist(f,disp, dist, dsp);
            }
        }
    }
}

void anl::cellular_function4D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed, ANLFloatType *f, ANLFloatType *disp, dist_func4 distance)
{
    int xint = fast_floor(x);
    int yint = fast_floor(y);
    int zint = fast_floor(z);
    int wint = fast_floor(w);

    for(int c=0; c<4; ++c){ f[c]=99999.0; disp[c]=0.0;}

    for (int wcur=wint-2; wcur<=wint+2; ++wcur)
    {
    for (int zcur=zint-2; zcur<=zint+2; ++zcur)
    {
        for(int ycur=yint-2; ycur<=yint+2; ++ycur)
        {
            for(int xcur=xint-2; xcur<=xint+2; ++xcur)
            {
                ANLFloatType xpos = (ANLFloatType)xcur + value_noise_4(x,y,z,w,xcur,ycur,zcur,wcur,seed);
                ANLFloatType ypos = (ANLFloatType)ycur + value_noise_4(x,y,z,w,xcur,ycur,zcur,wcur,seed+1);
                ANLFloatType zpos = (ANLFloatType)zcur + value_noise_4(x,y,z,w,xcur,ycur,zcur,wcur,seed+2);
                ANLFloatType wpos = (ANLFloatType)wcur + value_noise_4(x,y,z,w,xcur,ycur,zcur,wcur,seed+3);
                //ANLFloatType xdist=xpos-x;
                //ANLFloatType ydist=ypos-y;
                //ANLFloatType zdist=zpos-z;
                //ANLFloatType wdist=wpos-w;
                //ANLFloatType dist=(xdist*xdist + ydist*ydist + zdist*zdist + wdist*wdist);
                ANLFloatType dist=distance(xpos,ypos,zpos,wpos,x,y,z,w);
                int xval=fast_floor(xpos);
                int yval=fast_floor(ypos);
                int zval=fast_floor(zpos);
                int wval=fast_floor(wpos);
                ANLFloatType dsp=value_noise_4(x,y,z,w,xval,yval,zval,wval,seed+3);
                add_dist(f,disp, dist, dsp);
            }
        }
    }
    }
}

void anl::cellular_function6D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, unsigned int seed, ANLFloatType *f, ANLFloatType *disp, dist_func6 distance)
{
    int xint = fast_floor(x);
    int yint = fast_floor(y);
    int zint = fast_floor(z);
    int wint = fast_floor(w);
    int uint = fast_floor(u);
    int vint = fast_floor(v);

    for(int c=0; c<4; ++c){ f[c]=99999.0; disp[c]=0.0;}

    for (int vcur=vint-1; vcur<=vint+1; ++vcur)
    {
        for(int ucur=uint-1; ucur<=uint+1; ++ucur)
        {

            for (int wcur=wint-2; wcur<=wint+2; ++wcur)
            {
                for (int zcur=zint-2; zcur<=zint+2; ++zcur)
                {
                    for(int ycur=yint-2; ycur<=yint+2; ++ycur)
                    {
                        for(int xcur=xint-2; xcur<=xint+2; ++xcur)
                        {
                            ANLFloatType xpos = (ANLFloatType)xcur + value_noise_6(x,y,z,w,u,v,xcur,ycur,zcur,wcur,ucur,vcur,seed);
                            ANLFloatType ypos = (ANLFloatType)ycur + value_noise_6(x,y,z,w,u,v,xcur,ycur,zcur,wcur,ucur,vcur,seed+1);
                            ANLFloatType zpos = (ANLFloatType)zcur + value_noise_6(x,y,z,w,u,v,xcur,ycur,zcur,wcur,ucur,vcur,seed+2);
                            ANLFloatType wpos = (ANLFloatType)wcur + value_noise_6(x,y,z,w,u,v,xcur,ycur,zcur,wcur,ucur,vcur,seed+3);
                            ANLFloatType upos = (ANLFloatType)ucur + value_noise_6(x,y,z,w,u,v,xcur,ycur,zcur,wcur,ucur,vcur,seed+4);
                            ANLFloatType vpos = (ANLFloatType)vcur + value_noise_6(x,y,z,w,u,v,xcur,ycur,zcur,wcur,ucur,vcur,seed+5);
                            //ANLFloatType xdist=xpos-x;
                            //ANLFloatType ydist=ypos-y;
                            //ANLFloatType zdist=zpos-z;
                            //ANLFloatType wdist=wpos-w;
                            //ANLFloatType udist=upos-u;
                            //ANLFloatType vdist=vpos-v;
                            //ANLFloatType dist=(xdist*xdist + ydist*ydist + zdist*zdist + wdist*wdist + udist*udist + vdist*vdist);
                            ANLFloatType dist=distance(xpos,ypos,zpos,wpos,upos,vpos,x,y,z,w,u,v);
                            int xval=fast_floor(xpos);
                            int yval=fast_floor(ypos);
                            int zval=fast_floor(zpos);
                            int wval=fast_floor(wpos);
                            int uval=fast_floor(upos);
                            int vval=fast_floor(vpos);
                            ANLFloatType dsp=value_noise_6(x,y,z,w,u,v,xval,yval,zval,wval,uval,vval,seed+6);
                            add_dist(f,disp, dist, dsp);
                        }
                    }
                }
            }
        }
    }
}


const ANLFloatType F2=0.36602540378443864676372317075294;
const ANLFloatType G2=0.21132486540518711774542560974902;
const ANLFloatType F3=1.0/3.0;
const ANLFloatType G3=1.0/6.0;


ANLFloatType anl::simplex_noise2D(ANLFloatType x, ANLFloatType y, unsigned int seed, interp_func interp)
{
    ANLFloatType s = (x+y)*F2;
    int i=fast_floor(x+s);
    int j=fast_floor(y+s);

    ANLFloatType t = (i+j)*G2;
    ANLFloatType X0=i-t;
    ANLFloatType Y0=j-t;
    ANLFloatType x0=x-X0;
    ANLFloatType y0=y-Y0;

    int i1,j1;
    if(x0>y0)
    {
        i1=1; j1=0;
    }
    else
    {
        i1=0; j1=1;
    }

    ANLFloatType x1=x0-(ANLFloatType)i1+G2;
    ANLFloatType y1=y0-(ANLFloatType)j1+G2;
    ANLFloatType x2=x0-1.0+2.0*G2;
    ANLFloatType y2=y0-1.0+2.0*G2;

    // Hash the triangle coordinates to index the gradient table
    unsigned int h0=hash_coords_2(i,j,seed);
    unsigned int h1=hash_coords_2(i+i1,j+j1,seed);
    unsigned int h2=hash_coords_2(i+1,j+1,seed);

    // Now, index the tables
    ANLFloatType *g0 = &gradient2D_lut[h0][0];
    ANLFloatType *g1 = &gradient2D_lut[h1][0];
    ANLFloatType *g2 = &gradient2D_lut[h2][0];

    ANLFloatType n0,n1,n2;
    // Calculate the contributions from the 3 corners
    ANLFloatType t0=0.5-x0*x0-y0*y0;
    if(t0<0) n0=0;
    else
    {
        t0 *= t0;
        n0 = t0 * t0 * array_dot2(g0,x0,y0);
    }

    ANLFloatType t1=0.5-x1*x1-y1*y1;
    if(t1<0) n1=0;
    else
    {
        t1*=t1;
        n1=t1*t1*array_dot2(g1,x1,y1);
    }

    ANLFloatType t2=0.5-x2*x2-y2*y2;
    if(t2<0) n2=0;
    else
    {
        t2*=t2;
        n2=t2*t2*array_dot2(g2,x2,y2);
    }

    // Add contributions together
    return (70.0 * (n0+n1+n2)) *1.42188695 + 0.001054489;
}


ANLFloatType anl::simplex_noise3D(ANLFloatType x, ANLFloatType y, ANLFloatType z, unsigned int seed, interp_func interp)
{
    //static ANLFloatType F3 = 1.0/3.0;
    //static ANLFloatType G3 = 1.0/6.0;
    ANLFloatType n0,n1,n2,n3;

    ANLFloatType s=(x+y+z)*F3;
    int i=fast_floor(x+s);
    int j=fast_floor(y+s);
    int k=fast_floor(z+s);

    ANLFloatType t=(i+j+k)*G3;
    ANLFloatType X0=i-t;
    ANLFloatType Y0=j-t;
    ANLFloatType Z0=k-t;

    ANLFloatType x0=x-X0;
    ANLFloatType y0=y-Y0;
    ANLFloatType z0=z-Z0;

    int i1, j1, k1;
    int i2, j2, k2;

    if(x0>=y0)
    {
        if(y0>=z0)
        {
            i1=1; j1=0; k1=0; i2=1; j2=1; k2=0;
        }
        else if(x0>=z0)
        {
            i1=1; j1=0; k1=0; i2=1; j2=0; k2=1;
        }
        else
        {
            i1=0; j1=0; k1=1; i2=1; j2=0; k2=1;
        }
    }
    else
    {
        if(y0<z0)
        {
            i1=0; j1=0; k1=1; i2=0; j2=1; k2=1;
        }
        else if(x0<z0)
        {
            i1=0; j1=1; k1=0; i2=0; j2=1; k2=1;
        }
        else
        {
            i1=0; j1=1; k1=0; i2=1; j2=1; k2=0;
        }
    }

    ANLFloatType x1=x0-i1+G3;
    ANLFloatType y1=y0-j1+G3;
    ANLFloatType z1=z0-k1+G3;
    ANLFloatType x2=x0-i2+2.0*G3;
    ANLFloatType y2=y0-j2+2.0*G3;
    ANLFloatType z2=z0-k2+2.0*G3;
    ANLFloatType x3=x0-1.0+3.0*G3;
    ANLFloatType y3=y0-1.0+3.0*G3;
    ANLFloatType z3=z0-1.0+3.0*G3;

    unsigned int h0,h1,h2,h3;

    h0=hash_coords_3(i,j,k,seed);
    h1=hash_coords_3(i+i1,j+j1,k+k1,seed);
    h2=hash_coords_3(i+i2,j+j2,k+k2,seed);
    h3=hash_coords_3(i+1,j+1,k+1,seed);

    ANLFloatType *g0=&gradient3D_lut[h0][0];
    ANLFloatType *g1=&gradient3D_lut[h1][0];
    ANLFloatType *g2=&gradient3D_lut[h2][0];
    ANLFloatType *g3=&gradient3D_lut[h3][0];

    ANLFloatType t0=0.6-x0*x0-y0*y0-z0*z0;
    if(t0<0.0) n0=0.0;
    else
    {
        t0 *= t0;
        n0 = t0*t0*array_dot3(g0,x0,y0,z0);
    }

    ANLFloatType t1=0.6-x1*x1-y1*y1-z1*z1;
    if(t1<0.0) n1=0.0;
    else
    {
        t1*=t1;
        n1=t1*t1*array_dot3(g1,x1,y1,z1);
    }

    ANLFloatType t2=0.6-x2*x2-y2*y2-z2*z2;
    if(t2<0) n2=0.0;
    else
    {
        t2 *= t2;
        n2 = t2*t2*array_dot3(g2,x2,y2,z2);
    }

    ANLFloatType t3=0.6-x3*x3-y3*y3-z3*z3;
    if(t3<0) n3=0.0;
    else
    {
        t3*=t3;
        n3=t3*t3*array_dot3(g3,x3,y3,z3);
    }

    return (32.0*(n0+n1+n2+n3))*1.25086885 + 0.0003194984;
}

ANLFloatType anl::simplex_noise4D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed, interp_func interp)
{
    static int simplex[64][4] = {
    {0,1,2,3},{0,1,3,2},{0,0,0,0},{0,2,3,1},{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,2,3,0},
    {0,2,1,3},{0,0,0,0},{0,3,1,2},{0,3,2,1},{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,3,2,0},
    {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
    {1,2,0,3},{0,0,0,0},{1,3,0,2},{0,0,0,0},{0,0,0,0},{0,0,0,0},{2,3,0,1},{2,3,1,0},
    {1,0,2,3},{1,0,3,2},{0,0,0,0},{0,0,0,0},{0,0,0,0},{2,0,3,1},{0,0,0,0},{2,1,3,0},
    {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
    {2,0,1,3},{0,0,0,0},{0,0,0,0},{0,0,0,0},{3,0,1,2},{3,0,2,1},{0,0,0,0},{3,1,2,0},
    {2,1,0,3},{0,0,0,0},{0,0,0,0},{0,0,0,0},{3,1,0,2},{0,0,0,0},{3,2,0,1},{3,2,1,0}};

    ANLFloatType F4 = (sqrt(5.0)-1.0)/4.0;
    ANLFloatType G4 = (5.0-sqrt(5.0))/20.0;
    ANLFloatType n0, n1, n2, n3, n4; // Noise contributions from the five corners
    // Skew the (x,y,z,w) space to determine which cell of 24 simplices we're in
    ANLFloatType s = (x + y + z + w) * F4; // Factor for 4D skewing
    int i = fast_floor(x + s);
    int j = fast_floor(y + s);
    int k = fast_floor(z + s);
    int l = fast_floor(w + s);
    ANLFloatType t = (i + j + k + l) * G4; // Factor for 4D unskewing
    ANLFloatType X0 = i - t; // Unskew the cell origin back to (x,y,z,w) space
    ANLFloatType Y0 = j - t;
    ANLFloatType Z0 = k - t;
    ANLFloatType W0 = l - t;
    ANLFloatType x0 = x - X0; // The x,y,z,w distances from the cell origin
    ANLFloatType y0 = y - Y0;
    ANLFloatType z0 = z - Z0;
    ANLFloatType w0 = w - W0;
// For the 4D case, the simplex is a 4D shape I won't even try to describe.
// To find out which of the 24 possible simplices we're in, we need to
// determine the magnitude ordering of x0, y0, z0 and w0.
// The method below is a good way of finding the ordering of x,y,z,w and
// then find the correct traversal order for the simplex we’re in.
// First, six pair-wise comparisons are performed between each possible pair
// of the four coordinates, and the results are used to add up binary bits
// for an integer index.
    int c1 = (x0 > y0) ? 32 : 0;
    int c2 = (x0 > z0) ? 16 : 0;
    int c3 = (y0 > z0) ? 8 : 0;
    int c4 = (x0 > w0) ? 4 : 0;
    int c5 = (y0 > w0) ? 2 : 0;
    int c6 = (z0 > w0) ? 1 : 0;
    int c = c1 + c2 + c3 + c4 + c5 + c6;
    int i1, j1, k1, l1; // The integer offsets for the second simplex corner
    int i2, j2, k2, l2; // The integer offsets for the third simplex corner
    int i3, j3, k3, l3; // The integer offsets for the fourth simplex corner
// simplex[c] is a 4-vector with the numbers 0, 1, 2 and 3 in some order.
// Many values of c will never occur, since e.g. x>y>z>w makes x<z, y<w and x<w
// impossible. Only the 24 indices which have non-zero entries make any sense.
// We use a thresholding to set the coordinates in turn from the largest magnitude.
// The number 3 in the "simplex" array is at the position of the largest coordinate.
    i1 = simplex[c][0]>=3 ? 1 : 0;
    j1 = simplex[c][1]>=3 ? 1 : 0;
    k1 = simplex[c][2]>=3 ? 1 : 0;
    l1 = simplex[c][3]>=3 ? 1 : 0;
// The number 2 in the "simplex" array is at the second largest coordinate.
    i2 = simplex[c][0]>=2 ? 1 : 0;
    j2 = simplex[c][1]>=2 ? 1 : 0;
    k2 = simplex[c][2]>=2 ? 1 : 0;
    l2 = simplex[c][3]>=2 ? 1 : 0;
// The number 1 in the "simplex" array is at the second smallest coordinate.
    i3 = simplex[c][0]>=1 ? 1 : 0;
    j3 = simplex[c][1]>=1 ? 1 : 0;
    k3 = simplex[c][2]>=1 ? 1 : 0;
    l3 = simplex[c][3]>=1 ? 1 : 0;
// The fifth corner has all coordinate offsets = 1, so no need to look that up.
    ANLFloatType x1 = x0 - i1 + G4; // Offsets for second corner in (x,y,z,w) coords
    ANLFloatType y1 = y0 - j1 + G4;
    ANLFloatType z1 = z0 - k1 + G4;
    ANLFloatType w1 = w0 - l1 + G4;
    ANLFloatType x2 = x0 - i2 + 2.0*G4; // Offsets for third corner in (x,y,z,w) coords
    ANLFloatType y2 = y0 - j2 + 2.0*G4;
    ANLFloatType z2 = z0 - k2 + 2.0*G4;
    ANLFloatType w2 = w0 - l2 + 2.0*G4;
    ANLFloatType x3 = x0 - i3 + 3.0*G4; // Offsets for fourth corner in (x,y,z,w) coords
    ANLFloatType y3 = y0 - j3 + 3.0*G4;
    ANLFloatType z3 = z0 - k3 + 3.0*G4;
    ANLFloatType w3 = w0 - l3 + 3.0*G4;
    ANLFloatType x4 = x0 - 1.0 + 4.0*G4; // Offsets for last corner in (x,y,z,w) coords
    ANLFloatType y4 = y0 - 1.0 + 4.0*G4;
    ANLFloatType z4 = z0 - 1.0 + 4.0*G4;
    ANLFloatType w4 = w0 - 1.0 + 4.0*G4;
// Work out the hashed gradient indices of the five simplex corners
    unsigned int h0,h1,h2,h3,h4;
    h0=hash_coords_4(i,j,k,l,seed);
    h1=hash_coords_4(i+i1,j+j1,k+k1,l+l1,seed);
    h2=hash_coords_4(i+i2,j+j2,k+k2,l+l2,seed);
    h3=hash_coords_4(i+i3,j+j3,k+k3,l+l3,seed);
    h4=hash_coords_4(i+1,j+1,k+1,l+1,seed);

    ANLFloatType *g0=&gradient4D_lut[h0][0];
    ANLFloatType *g1=&gradient4D_lut[h1][0];
    ANLFloatType *g2=&gradient4D_lut[h2][0];
    ANLFloatType *g3=&gradient4D_lut[h3][0];
    ANLFloatType *g4=&gradient4D_lut[h4][0];


// Calculate the contribution from the five corners
    ANLFloatType t0 = 0.6 - x0*x0 - y0*y0 - z0*z0 - w0*w0;
    if(t0<0) n0 = 0.0;
    else {
        t0 *= t0;
        n0 = t0 * t0 * array_dot4(g0, x0, y0, z0, w0);
    }
    ANLFloatType t1 = 0.6 - x1*x1 - y1*y1 - z1*z1 - w1*w1;
    if(t1<0) n1 = 0.0;
    else {
        t1 *= t1;
        n1 = t1 * t1 * array_dot4(g1, x1, y1, z1, w1);
    }
    ANLFloatType t2 = 0.6 - x2*x2 - y2*y2 - z2*z2 - w2*w2;
    if(t2<0) n2 = 0.0;
    else {
        t2 *= t2;
        n2 = t2 * t2 * array_dot4(g2, x2, y2, z2, w2);
    }
    ANLFloatType t3 = 0.6 - x3*x3 - y3*y3 - z3*z3 - w3*w3;
    if(t3<0) n3 = 0.0;
    else {
        t3 *= t3;
        n3 = t3 * t3 * array_dot4(g3, x3, y3, z3, w3);
    }
    ANLFloatType t4 = 0.6 - x4*x4 - y4*y4 - z4*z4 - w4*w4;
    if(t4<0) n4 = 0.0;
    else {
        t4 *= t4;
        n4 = t4 * t4 * array_dot4(g4, x4, y4, z4, w4);
    }
// Sum up and scale the result to cover the range [-1,1]
    return 27.0 * (n0 + n1 + n2 + n3 + n4);
}



struct SVectorOrdering4
{
    SVectorOrdering4(ANLFloatType v, int X, int Y, int Z, int W)
    {
        coord=v;
        x=X;y=Y;z=Z;w=W;
    };
    ANLFloatType coord;
    int x,y,z,w;
};

bool svec4Compare(SVectorOrdering4 v1, SVectorOrdering4 v2)
{
    if(v1.coord > v2.coord) return true;
    return false;
}

struct SVectorOrdering
{
    SVectorOrdering(){val=0; axis=0;}
    SVectorOrdering(ANLFloatType v, int a)
    {
        val=v;
        axis=a;
    };
    ANLFloatType val;
    int axis;
};

bool vectorOrderingCompare(SVectorOrdering v1, SVectorOrdering v2)
{
    if(v1.val > v2.val) return true;
    return false;
}

void sortBy_4(ANLFloatType *l1, int *l2)
{
    SVectorOrdering a[4];
    for(int c=0; c<4; ++c) {a[c].val=l1[c]; a[c].axis=l2[c];}

    std::sort(&a[0],&a[4],vectorOrderingCompare);
    for(int c=0; c<4; ++c) l2[c]=a[c].axis;
}
void sortBy_6(ANLFloatType *l1, int *l2)
{
    SVectorOrdering a[6];
    for(int c=0; c<6; ++c) {a[c].val=l1[c]; a[c].axis=l2[c];}
    std::sort(&a[0],&a[6],vectorOrderingCompare);
    for(int c=0; c<6; ++c) l2[c]=a[c].axis;
}

ANLFloatType anl::new_simplex_noise4D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, unsigned int seed, interp_func interp)
{
    // f = ((self.d + 1) ** .5 - 1) / self.d
    ANLFloatType F4=(sqrt(5.0)-1.0)/4.0;

    // g=self.f/(1+self.d*self.f)
    ANLFloatType G4 = F4/(1.0+4.0*F4);

    static ANLFloatType sideLength=2.0 / (4.0 * F4 + 1.0);
    static ANLFloatType a=sqrt((sideLength*sideLength)-((sideLength/2.0)*(sideLength/2.0)));
    static ANLFloatType cornerToFace=sqrt((a*a+(a/2.0)*(a/2.0)));
    static ANLFloatType cornerToFaceSquared=cornerToFace*cornerToFace;

    static ANLFloatType valueScaler=pow(3.0, -0.5);
    // Rough estimated/expirmentally determined function
    // for scaling output to be -1 to 1
    valueScaler*=pow(3.0, -3.5)*100.0 + 13.0;

    ANLFloatType loc[4]={x,y,z,w};
    ANLFloatType s=0;
    for (int c=0; c<4; ++c) s+=loc[c];
    s*=F4;

    int skewLoc[4]={fast_floor(x+s),fast_floor(y+s),fast_floor(z+s),fast_floor(w+s)};
    int intLoc[4]={fast_floor(x+s),fast_floor(y+s),fast_floor(z+s),fast_floor(w+s)};
    ANLFloatType unskew=0.0;
    for(int c=0; c<4; ++c) unskew+=skewLoc[c];
    unskew*=G4;
    ANLFloatType cellDist[4]={loc[0]-(ANLFloatType)skewLoc[0]+unskew, loc[1]-(ANLFloatType)skewLoc[1]+unskew,
        loc[2]-(ANLFloatType)skewLoc[2]+unskew, loc[3]-(ANLFloatType)skewLoc[3]+unskew};
    int distOrder[4]={0,1,2,3};
    sortBy_4(cellDist,distOrder);

    int newDistOrder[5]={-1,distOrder[0],distOrder[1],distOrder[2],distOrder[3]};

    ANLFloatType n=0.0;
    ANLFloatType skewOffset=0.0;

    for(int c=0; c<5; ++c)
    {
        int i=newDistOrder[c];
        if(i!=-1) intLoc[i]+=1;

        ANLFloatType u[4];
        for(int d=0; d<4; ++d)
        {
            u[d]=cellDist[d]-(intLoc[d]-skewLoc[d])+skewOffset;
        }

        ANLFloatType t=cornerToFaceSquared;

        for(int d=0; d<4; ++d)
        {
            t-=u[d]*u[d];
        }

        if(t>0.0)
        {
            unsigned int h=hash_coords_4(intLoc[0],intLoc[1],intLoc[2],intLoc[3],seed);
            ANLFloatType *vec=&gradient4D_lut[h][0];
            ANLFloatType gr=0.0;
            for(int d=0; d<4; ++d)
            {
                gr+=vec[d]*u[d];
            }

            n+=gr*t*t*t*t;
        }
        skewOffset+=G4;
    }
    n*=valueScaler;
    return n;
}



ANLFloatType anl::simplex_noise6D(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v, unsigned int seed, interp_func interp)
{
    // Skew
    //self.f = ((self.d + 1) ** .5 - 1) / self.d

    static ANLFloatType F4 = (sqrt(7.0)-1.0)/6.0; //(sqrt(5.0)-1.0)/4.0;

    // Unskew
    // self.g=self.f/(1+self.d*self.f)
    static ANLFloatType G4 = F4/(1.0+6.0*F4);

    static ANLFloatType sideLength=sqrt(6.0)/ (6.0 * F4 +1.0);
    static ANLFloatType a=sqrt((sideLength*sideLength)-((sideLength/2.0)*(sideLength/2.0)));
    static ANLFloatType cornerFace=sqrt(a*a + (a/2.0)*(a/2.0));

    static ANLFloatType cornerFaceSqrd=cornerFace*cornerFace;

    //self.valueScaler=(self.d-1)**-.5
    ANLFloatType valueScaler=pow(5.0, -0.5);
    valueScaler*=pow(5.0, -3.5)*100+13;

    ANLFloatType loc[6]={x,y,z,w,u,v};
    ANLFloatType s=0;
    for (int c=0; c<6; ++c) s+=loc[c];
    s*=F4;

    int skewLoc[6]={fast_floor(x+s),fast_floor(y+s),fast_floor(z+s),fast_floor(w+s),fast_floor(u+s),fast_floor(v+s)};
    int intLoc[6]={fast_floor(x+s),fast_floor(y+s),fast_floor(z+s),fast_floor(w+s),fast_floor(u+s),fast_floor(v+s)};
    ANLFloatType unskew=0.0;
    for(int c=0; c<6; ++c) unskew+=skewLoc[c];
    unskew*=G4;
    ANLFloatType cellDist[6]={loc[0]-(ANLFloatType)skewLoc[0]+unskew, loc[1]-(ANLFloatType)skewLoc[1]+unskew,
        loc[2]-(ANLFloatType)skewLoc[2]+unskew, loc[3]-(ANLFloatType)skewLoc[3]+unskew,
        loc[4]-(ANLFloatType)skewLoc[4]+unskew, loc[5]-(ANLFloatType)skewLoc[5]+unskew};
    int distOrder[6]={0,1,2,3,4,5};
    sortBy_6(cellDist,distOrder);

    int newDistOrder[7]={-1,distOrder[0],distOrder[1],distOrder[2],distOrder[3],distOrder[4],distOrder[5]};

    ANLFloatType n=0.0;
    ANLFloatType skewOffset=0.0;

    for(int c=0; c<7; ++c)
    {
        int i=newDistOrder[c];
        if(i!=-1) intLoc[i]+=1;

        ANLFloatType u[6];
        for(int d=0; d<6; ++d)
        {
            u[d]=cellDist[d]-(intLoc[d]-skewLoc[d])+skewOffset;
        }

        ANLFloatType t=cornerFaceSqrd;

        for(int d=0; d<6; ++d)
        {
            t-=u[d]*u[d];
        }

        if(t>0.0)
        {
            unsigned int h=hash_coords_6(intLoc[0],intLoc[1],intLoc[2],intLoc[3],intLoc[4],intLoc[5],seed);
            ANLFloatType *vec=&gradient6D_lut[h][0];
            ANLFloatType gr=0.0;
            for(int d=0; d<6; ++d)
            {
                gr+=vec[d]*u[d];
            }

            n+=gr*t*t*t*t;
        }
        skewOffset+=G4;
    }
    n*=valueScaler;
    return n;
}
