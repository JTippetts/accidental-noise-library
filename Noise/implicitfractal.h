#ifndef IMPLICIT_FRACTAL_H
#define IMPLICIT_FRACTAL_H
#include "implicitmodulebase.h"
#include "implicitbasisfunction.h"
#include "utility.h"

namespace anl
{

    enum EFractalTypes
    {
        FBM,
        RIDGEDMULTI,
        BILLOW,
        MULTI,
        HYBRIDMULTI,
		DECARPENTIERSWISS
};



    class CImplicitFractal : public CImplicitModuleBase
    {
        public:
        CImplicitFractal(unsigned int type, unsigned int basistype, unsigned int interptype, int octaves, ANLFloatType freq, bool rotatedomain);

        void setNumOctaves(int n);
        void setFrequency(ANLFloatType f);
        void setLacunarity(ANLFloatType l);
        void setGain(ANLFloatType g);
        void setOffset(ANLFloatType o);
        void setH(ANLFloatType h);

        void setType(unsigned int t);
        void setAllSourceTypes(unsigned int basis_type, unsigned int interp);
        void setSourceType(int which, unsigned int type, unsigned int interp);
        void overrideSource(int which, CImplicitModuleBase *  b);
        void resetSource(int which);
        void resetAllSources();
        void setSeed(unsigned int seed);
        CImplicitModuleBase * getBasis(int which);
        ANLFloatType get(ANLFloatType x, ANLFloatType y);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        protected:
        std::shared_ptr<CImplicitBasisFunction> m_basis[MaxSources];
        CImplicitModuleBase *  m_source[MaxSources];
        ANLFloatType m_exparray[MaxSources];
        ANLFloatType m_correct[MaxSources][2];

        ANLFloatType m_offset, m_gain, m_H;
        ANLFloatType m_frequency, m_lacunarity;
        unsigned int m_numoctaves;
        unsigned int m_type;
        bool m_rotatedomain;

        void fBm_calcWeights();
        void RidgedMulti_calcWeights();
        void Billow_calcWeights();
        void Multi_calcWeights();
        void HybridMulti_calcWeights();
		void DeCarpentierSwiss_calcWeights();

        ANLFloatType fBm_get(ANLFloatType x, ANLFloatType y);
        ANLFloatType fBm_get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType fBm_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType fBm_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        ANLFloatType RidgedMulti_get(ANLFloatType x, ANLFloatType y);
        ANLFloatType RidgedMulti_get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType RidgedMulti_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType RidgedMulti_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        ANLFloatType Billow_get(ANLFloatType x, ANLFloatType y);
        ANLFloatType Billow_get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType Billow_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType Billow_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        ANLFloatType Multi_get(ANLFloatType x, ANLFloatType y);
        ANLFloatType Multi_get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType Multi_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType Multi_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        ANLFloatType HybridMulti_get(ANLFloatType x, ANLFloatType y);
        ANLFloatType HybridMulti_get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType HybridMulti_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType HybridMulti_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

		ANLFloatType DeCarpentierSwiss_get(ANLFloatType x, ANLFloatType y);
        ANLFloatType DeCarpentierSwiss_get(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        ANLFloatType DeCarpentierSwiss_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        ANLFloatType DeCarpentierSwiss_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);


    };

};
#endif
