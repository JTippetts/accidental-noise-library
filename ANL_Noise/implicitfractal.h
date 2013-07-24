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
        CImplicitFractal(unsigned int type, unsigned int basistype, unsigned int interptype, int octaves, double freq, bool rotatedomain);

        void setNumOctaves(int n);
        void setFrequency(double f);
        void setLacunarity(double l);
        void setGain(double g);
        void setOffset(double o);
        void setH(double h);

        void setType(unsigned int t);
        void setAllSourceTypes(unsigned int basis_type, unsigned int interp);
        void setSourceType(int which, unsigned int type, unsigned int interp);
        void overrideSource(int which, std::shared_ptr<CImplicitModuleBase>  b);
        void resetSource(int which);
        void resetAllSources();
        void setSeed(unsigned int seed);
        std::shared_ptr<CImplicitModuleBase> getBasis(int which);
        double get(double x, double y);
        double get(double x, double y, double z);
        double get(double x, double y, double z, double w);
        double get(double x, double y, double z, double w, double u, double v);

        protected:
        std::shared_ptr<CImplicitBasisFunction> m_basis[MaxSources];
        std::shared_ptr<CImplicitModuleBase>  m_source[MaxSources];
        double m_exparray[MaxSources];
        double m_correct[MaxSources][2];

        double m_offset, m_gain, m_H;
        double m_frequency, m_lacunarity;
        unsigned int m_numoctaves;
        unsigned int m_type;
        bool m_rotatedomain;

        void fBm_calcWeights();
        void RidgedMulti_calcWeights();
        void Billow_calcWeights();
        void Multi_calcWeights();
        void HybridMulti_calcWeights();
		void DeCarpentierSwiss_calcWeights();

        double fBm_get(double x, double y);
        double fBm_get(double x, double y, double z);
        double fBm_get(double x, double y, double z, double w);
        double fBm_get(double x, double y, double z, double w, double u, double v);

        double RidgedMulti_get(double x, double y);
        double RidgedMulti_get(double x, double y, double z);
        double RidgedMulti_get(double x, double y, double z, double w);
        double RidgedMulti_get(double x, double y, double z, double w, double u, double v);

        double Billow_get(double x, double y);
        double Billow_get(double x, double y, double z);
        double Billow_get(double x, double y, double z, double w);
        double Billow_get(double x, double y, double z, double w, double u, double v);

        double Multi_get(double x, double y);
        double Multi_get(double x, double y, double z);
        double Multi_get(double x, double y, double z, double w);
        double Multi_get(double x, double y, double z, double w, double u, double v);

        double HybridMulti_get(double x, double y);
        double HybridMulti_get(double x, double y, double z);
        double HybridMulti_get(double x, double y, double z, double w);
        double HybridMulti_get(double x, double y, double z, double w, double u, double v);

		double DeCarpentierSwiss_get(double x, double y);
        double DeCarpentierSwiss_get(double x, double y, double z);
        double DeCarpentierSwiss_get(double x, double y, double z, double w);
        double DeCarpentierSwiss_get(double x, double y, double z, double w, double u, double v);


    };

};
#endif
