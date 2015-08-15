#ifndef VM_H
#define VM_H

#include "instruction.h"
#include "coordinate.h"
#include "noise_gen.h"

//#include <vector>
#include "../templates/tarray1.h"
#include "../vectortypes.h"

struct TileCoord
{
	unsigned int x,y;
};

struct CoordPair
{
	double x,y;
};

namespace anl
{
    struct SVMOutput
    {
        double outfloat_;
        SRGBA outrgba_;

        SVMOutput() : outfloat_(0), outrgba_(0,0,0,0)
        {

        }
		
		SVMOutput(double v) : outfloat_(v), outrgba_(v,v,v,1)
		{
		}
		
		SVMOutput(double v, SRGBA rgba)
		{
			outfloat_=v;
			outrgba_=rgba;
		}
		
		SVMOutput(const SVMOutput &rhs) : outfloat_(rhs.outfloat_), outrgba_(rhs.outrgba_)
		{
		}

		void set(double v)
		{
			outfloat_=v;
			outrgba_.r=outrgba_.g=outrgba_.b=v;
			outrgba_.a=1;
		}

		void set(SRGBA v)
		{
			outrgba_=v;
		}
		
		SVMOutput operator-(const SVMOutput &rhs) const
		{
			return SVMOutput(outfloat_-rhs.outfloat_, outrgba_-rhs.outrgba_);
		}
		
		SVMOutput operator+(const SVMOutput &rhs) const
		{
			return SVMOutput(outfloat_+rhs.outfloat_, outrgba_+rhs.outrgba_);
		}
		
		SVMOutput operator*(const SVMOutput &rhs) const
		{
			return SVMOutput(outfloat_*rhs.outfloat_, outrgba_*rhs.outrgba_);
		}
		
		SVMOutput operator/(const SVMOutput &rhs) const
		{
			return SVMOutput(outfloat_/rhs.outfloat_, outrgba_/rhs.outrgba_);
		}
		
		SVMOutput operator*(double rhs) const
		{
			return SVMOutput(outfloat_*rhs, outrgba_*rhs);
		}
		
		
		void set(const SVMOutput &rhs)
		{
			outfloat_=rhs.outfloat_;
			outrgba_=rhs.outrgba_;
		}
    };

    typedef TArray1D<SInstruction> InstructionListType;
    typedef TArray1D<bool> EvaluatedType;
	typedef TArray1D<CCoordinate> CoordCacheType;
    typedef TArray1D<SVMOutput> CacheType;

    class CNoiseExecutor
    {
    public:
        CNoiseExecutor(CKernel *kernel);

        SVMOutput evaluate(CCoordinate &coord);
        SVMOutput evaluateAt(CCoordinate &coord, CInstructionIndex index);
    private:
        void evaluateInstruction(InstructionListType &kernel, EvaluatedType &evaluated, CoordCacheType &coordcache, CacheType &cache, unsigned int index, CCoordinate &coord);
        double evaluateParameter(InstructionListType &kernel, EvaluatedType &evaluated, CoordCacheType &coordcache, CacheType &cache, unsigned int index, CCoordinate &coord);
		SVMOutput evaluateBoth(InstructionListType &kernel, EvaluatedType &evaluated, CoordCacheType &coordcache, CacheType &cache, unsigned int index, CCoordinate &coord);
		SRGBA evaluateRGBA(InstructionListType &kernel, EvaluatedType &evaluated, CoordCacheType &coordcache, CacheType &cache, unsigned int index, CCoordinate &coord);
		TileCoord calcHexPointTile(float px, float py);
		CoordPair calcHexTileCenter(int tx, int ty);

        InstructionListType *kernel_;
        EvaluatedType evaluated_;
		CoordCacheType coordcache_;
        CacheType cache_;

    };
};

#endif