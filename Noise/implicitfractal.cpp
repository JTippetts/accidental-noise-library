#include "implicitfractal.h"
#include <cmath>
#include <iostream>

using namespace anl;
CImplicitFractal::CImplicitFractal(unsigned int type, unsigned int basistype, unsigned int interptype, int octaves, ANLFloatType freq, bool rotatedomain) : CImplicitModuleBase()
{
    m_rotatedomain=rotatedomain;
    setNumOctaves(octaves);
    setFrequency(freq);
    setLacunarity(2.0);
    setType(type);
    setAllSourceTypes(basistype, interptype);
    resetAllSources();

}

void CImplicitFractal::setNumOctaves(int n){if(n>=MaxSources) n=MaxSources-1; m_numoctaves=n;}
void CImplicitFractal::setFrequency(ANLFloatType f){m_frequency=f;}
void CImplicitFractal::setLacunarity(ANLFloatType l){m_lacunarity=l;}
void CImplicitFractal::setGain(ANLFloatType g){m_gain=g;}
void CImplicitFractal::setOffset(ANLFloatType o){m_offset=o;}
void CImplicitFractal::setH(ANLFloatType h){m_H=h;}

void CImplicitFractal::setType(unsigned int t)
	{
		m_type=t;
		switch(t)
		{
		case FBM:  m_H=1.0; m_gain=0.5;m_offset=0; fBm_calcWeights(); break;
		case RIDGEDMULTI: m_H=0.9; m_gain=0.5; m_offset=1; RidgedMulti_calcWeights(); break;
		case BILLOW: m_H=1; m_gain=0.5; m_offset=0; Billow_calcWeights(); break;
		case MULTI: m_H=1; m_offset=0; m_gain=0; Multi_calcWeights(); break;
		case HYBRIDMULTI: m_H=0.25; m_gain=1; m_offset=0.7; HybridMulti_calcWeights(); break;
		case DECARPENTIERSWISS: m_H=0.9; m_gain=0.6; m_offset=0.15; DeCarpentierSwiss_calcWeights(); break;
		default: m_H=1.0; m_gain=0;m_offset=0; fBm_calcWeights(); break;
		};
	}

	void CImplicitFractal::setAllSourceTypes(unsigned int basis_type, unsigned int interp)
    {
        for(int i=0; i<MaxSources;++i)
        {
            //m_basis[i].setType(basis_type);
            //m_basis[i].setInterp(interp);
            m_basis[i]=std::shared_ptr<CImplicitBasisFunction>(new CImplicitBasisFunction(basis_type, interp, m_rotatedomain));
            //if(!m_rotatedomain) m_basis[i]->setRotationAngle(1,0,0,0);
        }
    }

	void CImplicitFractal::setSourceType(int which, unsigned int type, unsigned int interp)
    {
        if(which>=MaxSources || which<0) return;
        if(!m_basis[which]) return;
        m_basis[which]->setType(type);
        m_basis[which]->setInterp(interp);
        //if(!m_rotatedomain) m_basis[which]->setRotationAngle(1,0,0,0);
    }

	void CImplicitFractal::overrideSource(int which, CImplicitModuleBase * b)
	{
		if(which<0 || which>=MaxSources) return;
		m_source[which]=b;
	}

	void CImplicitFractal::resetSource(int which)
	{
		if(which<0 || which>=MaxSources) return;
		if(!m_basis[which]) return;
		m_source[which]=m_basis[which].get();
	}

	void CImplicitFractal::resetAllSources()
	{
		for(int c=0; c<MaxSources; ++c)
        {
            m_source[c] = m_basis[c].get();
            //if(!m_rotatedomain) m_basis[c]->setRotationAngle(1,0,0,0);
        }
	}


	void CImplicitFractal::setSeed(unsigned int seed)
	{
		for(int c=0; c<MaxSources; ++c)
        {
            m_source[c]->setSeed(seed+c*300);
            //if(!m_rotatedomain) m_basis[c]->setRotationAngle(1,0,0,0);
           // else m_basis[c]->setNoRotation();
        }
	}

	CImplicitModuleBase * CImplicitFractal::getBasis(int which)
	{
		if(which<0 || which>=MaxSources) return 0;
		return m_basis[which].get();
	}

	ANLFloatType CImplicitFractal::get(ANLFloatType x, ANLFloatType y)
	{
	    ANLFloatType v;
		switch(m_type)
		{
		case FBM: v=fBm_get(x,y); break;
		case RIDGEDMULTI: v=RidgedMulti_get(x,y); break;
		case BILLOW: v=Billow_get(x,y); break;
		case MULTI: v=Multi_get(x,y); break;
		case HYBRIDMULTI: v=HybridMulti_get(x,y); break;
		case DECARPENTIERSWISS: v=DeCarpentierSwiss_get(x,y); break;
		default: v=fBm_get(x,y); break;
		}
		//return clamp(v,-1.0,1.0);
		return v;
	}

	ANLFloatType CImplicitFractal::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
	{
	    ANLFloatType val;
	    switch(m_type)
		{
		case FBM: val=fBm_get(x,y,z); break;
		case RIDGEDMULTI: val=RidgedMulti_get(x,y,z); break;
		case BILLOW: val=Billow_get(x,y,z); break;
		case MULTI: val=Multi_get(x,y,z); break;
		case HYBRIDMULTI: val=HybridMulti_get(x,y,z); break;
		case DECARPENTIERSWISS: val=DeCarpentierSwiss_get(x,y,z); break;
		default: val=fBm_get(x,y,z); break;
		}
		//return clamp(val,-1.0,1.0);
		return val;
	}

	ANLFloatType CImplicitFractal::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
	{
	    ANLFloatType val;
		switch(m_type)
		{
		case FBM: val=fBm_get(x,y,z,w); break;
		case RIDGEDMULTI: val=RidgedMulti_get(x,y,z,w); break;
		case BILLOW: val=Billow_get(x,y,z,w); break;
		case MULTI: val=Multi_get(x,y,z,w); break;
		case HYBRIDMULTI: val=HybridMulti_get(x,y,z,w); break;
		case DECARPENTIERSWISS: val=DeCarpentierSwiss_get(x,y,z,w); break;
		default: val=fBm_get(x,y,z,w); break;
		}
		return val;
	}

	ANLFloatType CImplicitFractal::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
	{
	    ANLFloatType val;
		switch(m_type)
		{
		case FBM: val=fBm_get(x,y,z,w,u,v); break;
		case RIDGEDMULTI: val=RidgedMulti_get(x,y,z,w,u,v); break;
		case BILLOW: val=Billow_get(x,y,z,w,u,v); break;
		case MULTI: val=Multi_get(x,y,z,w,u,v); break;
		case HYBRIDMULTI: val=HybridMulti_get(x,y,z,w,u,v); break;
		case DECARPENTIERSWISS: val=DeCarpentierSwiss_get(x,y,z,w,u,v); break;
		default: val=fBm_get(x,y,z,w,u,v); break;
		}

		return val;
	}

void CImplicitFractal::fBm_calcWeights()
{
	//std::cout << "Weights: ";
	for(int i=0; i<(int)MaxSources; ++i)
    {
        m_exparray[i]= pow(m_lacunarity, -i*m_H);
    }

    // Calculate scale/bias pairs by guessing at minimum and maximum values and remapping to [-1,1]
    ANLFloatType minvalue=0.0, maxvalue=0.0;
    for(int i=0; i<MaxSources; ++i)
    {
        minvalue += -1.0 * m_exparray[i];
        maxvalue += 1.0 * m_exparray[i];

        ANLFloatType A=-1.0, B=1.0;
        ANLFloatType scale = (B-A) / (maxvalue-minvalue);
        ANLFloatType bias = A - minvalue*scale;
        m_correct[i][0]=scale;
        m_correct[i][1]=bias;

        //std::cout << minvalue << " " << maxvalue << " " << scale << " " << bias << std::endl;
    }
}

void CImplicitFractal::RidgedMulti_calcWeights()
{
	for(int i=0; i<(int)MaxSources; ++i)
    {
        m_exparray[i]= pow(m_lacunarity, -i*m_H);
    }

            // Calculate scale/bias pairs by guessing at minimum and maximum values and remapping to [-1,1]
    ANLFloatType minvalue=0.0, maxvalue=0.0;
    for(int i=0; i<MaxSources; ++i)
    {
        minvalue += (m_offset-1.0)*(m_offset-1.0)*m_exparray[i];
        maxvalue += (m_offset)*(m_offset) * m_exparray[i];

        ANLFloatType A=-1.0, B=1.0;
        ANLFloatType scale = (B-A) / (maxvalue-minvalue);
        ANLFloatType bias = A - minvalue*scale;
        m_correct[i][0]=scale;
        m_correct[i][1]=bias;
    }

}

void CImplicitFractal::DeCarpentierSwiss_calcWeights()
{
	for(int i=0; i<(int)MaxSources; ++i)
    {
        m_exparray[i]= pow(m_lacunarity, -i*m_H);
    }

            // Calculate scale/bias pairs by guessing at minimum and maximum values and remapping to [-1,1]
    ANLFloatType minvalue=0.0, maxvalue=0.0;
    for(int i=0; i<MaxSources; ++i)
    {
        minvalue += (m_offset-1.0)*(m_offset-1.0)*m_exparray[i];
        maxvalue += (m_offset)*(m_offset) * m_exparray[i];

        ANLFloatType A=-1.0, B=1.0;
        ANLFloatType scale = (B-A) / (maxvalue-minvalue);
        ANLFloatType bias = A - minvalue*scale;
        m_correct[i][0]=scale;
        m_correct[i][1]=bias;
    }

}

void CImplicitFractal::Billow_calcWeights()
{
	for(int i=0; i<(int)MaxSources; ++i)
    {
        m_exparray[i]= pow(m_lacunarity, -i*m_H);
    }

    // Calculate scale/bias pairs by guessing at minimum and maximum values and remapping to [-1,1]
    ANLFloatType minvalue=0.0, maxvalue=0.0;
    for(int i=0; i<MaxSources; ++i)
    {
        minvalue += -1.0 * m_exparray[i];
        maxvalue += 1.0 * m_exparray[i];

        ANLFloatType A=-1.0, B=1.0;
        ANLFloatType scale = (B-A) / (maxvalue-minvalue);
        ANLFloatType bias = A - minvalue*scale;
        m_correct[i][0]=scale;
        m_correct[i][1]=bias;
    }

}

void CImplicitFractal::Multi_calcWeights()
{
	for(int i=0; i<(int)MaxSources; ++i)
    {
        m_exparray[i]= pow(m_lacunarity, -i*m_H);
    }

    // Calculate scale/bias pairs by guessing at minimum and maximum values and remapping to [-1,1]
    ANLFloatType minvalue=1.0, maxvalue=1.0;
    for(int i=0; i<MaxSources; ++i)
    {
        minvalue *= -1.0*m_exparray[i]+1.0;
        maxvalue *= 1.0*m_exparray[i]+1.0;

        ANLFloatType A=-1.0, B=1.0;
        ANLFloatType scale = (B-A) / (maxvalue-minvalue);
        ANLFloatType bias = A - minvalue*scale;
        m_correct[i][0]=scale;
        m_correct[i][1]=bias;
    }

}

void CImplicitFractal::HybridMulti_calcWeights()
{
	for(int i=0; i<(int)MaxSources; ++i)
    {
        m_exparray[i]= pow(m_lacunarity, -i*m_H);
    }

    // Calculate scale/bias pairs by guessing at minimum and maximum values and remapping to [-1,1]
    ANLFloatType minvalue=1.0, maxvalue=1.0;
    ANLFloatType weightmin, weightmax;
    ANLFloatType A=-1.0, B=1.0, scale, bias;

    minvalue = m_offset - 1.0;
    maxvalue = m_offset + 1.0;
    weightmin = m_gain*minvalue;
    weightmax = m_gain*maxvalue;

    scale = (B-A) / (maxvalue-minvalue);
    bias = A - minvalue*scale;
    m_correct[0][0]=scale;
    m_correct[0][1]=bias;


    for(int i=1; i<MaxSources; ++i)
    {
        if(weightmin>1.0) weightmin=1.0;
        if(weightmax>1.0) weightmax=1.0;

        ANLFloatType signal=(m_offset-1.0)*m_exparray[i];
        minvalue += signal*weightmin;
        weightmin *=m_gain*signal;

        signal=(m_offset+1.0)*m_exparray[i];
        maxvalue += signal*weightmax;
        weightmax *=m_gain*signal;


        scale = (B-A) / (maxvalue-minvalue);
        bias = A - minvalue*scale;
        m_correct[i][0]=scale;
        m_correct[i][1]=bias;
    }

}


ANLFloatType CImplicitFractal::fBm_get(ANLFloatType x, ANLFloatType y)
{
	ANLFloatType sum=0;
	ANLFloatType amp=1.0;

	x*=m_frequency;
	y*=m_frequency;

	for(unsigned int i=0; i<m_numoctaves; ++i)
	{
		ANLFloatType n=m_source[i]->get(x,y);
		sum+=n*amp;
		amp*=m_gain;

		x*=m_lacunarity;
		y*=m_lacunarity;
	}
	return sum;
}

ANLFloatType CImplicitFractal::fBm_get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
{
    ANLFloatType sum=0;
	ANLFloatType amp=1.0;

	x*=m_frequency;
	y*=m_frequency;
	z*=m_frequency;

	for(unsigned int i=0; i<m_numoctaves; ++i)
	{
		ANLFloatType n=m_source[i]->get(x,y,z);
		sum+=n*amp;
		amp*=m_gain;

		x*=m_lacunarity;
		y*=m_lacunarity;
		z*=m_lacunarity;
	}
	return sum;
}

ANLFloatType CImplicitFractal::fBm_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
{
	ANLFloatType sum=0;
	ANLFloatType amp=1.0;

	x*=m_frequency;
	y*=m_frequency;
	z*=m_frequency;
	w*=m_frequency;

	for(unsigned int i=0; i<m_numoctaves; ++i)
	{
		ANLFloatType n=m_source[i]->get(x,y,z,w);
		sum+=n*amp;
		amp*=m_gain;

		x*=m_lacunarity;
		y*=m_lacunarity;
		z*=m_lacunarity;
		w*=m_lacunarity;
	}
	return sum;
}

ANLFloatType CImplicitFractal::fBm_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
	ANLFloatType sum=0;
	ANLFloatType amp=1.0;

	x*=m_frequency;
	y*=m_frequency;
	z*=m_frequency;
	w*=m_frequency;
	u*=m_frequency;
	v*=m_frequency;

	for(unsigned int i=0; i<m_numoctaves; ++i)
	{
		ANLFloatType n=m_source[i]->get(x,y,z,w);
		sum+=n*amp;
		amp*=m_gain;

		x*=m_lacunarity;
		y*=m_lacunarity;
		z*=m_lacunarity;
		w*=m_lacunarity;
		u*=m_lacunarity;
		v*=m_lacunarity;
	}
	return sum;
}

ANLFloatType CImplicitFractal::Multi_get(ANLFloatType x, ANLFloatType y)
{
    ANLFloatType value=1.0;
    x*=m_frequency;
    y*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        value *= m_source[i]->get(x,y)*m_exparray[i]+1.0;
        x*=m_lacunarity;
        y*=m_lacunarity;

    }

    return value*m_correct[m_numoctaves-1][0] + m_correct[m_numoctaves-1][1];
}

ANLFloatType CImplicitFractal::Multi_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
{
    ANLFloatType value=1.0;
    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;
    w*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        value *= m_source[i]->get(x,y,z,w)*m_exparray[i]+1.0;
        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
        w*=m_lacunarity;
    }

    return value*m_correct[m_numoctaves-1][0] + m_correct[m_numoctaves-1][1];
}

ANLFloatType CImplicitFractal::Multi_get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
{
    ANLFloatType value=1.0;
    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        value *= m_source[i]->get(x,y,z)*m_exparray[i]+1.0;
        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
    }

    return value*m_correct[m_numoctaves-1][0] + m_correct[m_numoctaves-1][1];
}


ANLFloatType CImplicitFractal::Multi_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
	    ANLFloatType value=1.0;
    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;
    w*=m_frequency;
	u*=m_frequency;
	v*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        value *= m_source[i]->get(x,y,z,w,u,v)*m_exparray[i]+1.0;
        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
        w*=m_lacunarity;
		u*=m_lacunarity;
		v*=m_lacunarity;
    }

    return value*m_correct[m_numoctaves-1][0] + m_correct[m_numoctaves-1][1];
}


ANLFloatType CImplicitFractal::Billow_get(ANLFloatType x, ANLFloatType y)
{
    ANLFloatType sum=0.0;
    ANLFloatType amp=1.0;

    x*=m_frequency;
    y*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        ANLFloatType n=m_source[i]->get(x,y);
        sum+=(2.0 * fabs(n)-1.0)*amp;
        amp*=m_gain;

        x*=m_lacunarity;
        y*=m_lacunarity;
    }
    return sum;
}

ANLFloatType CImplicitFractal::Billow_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
{
	ANLFloatType sum=0.0;
    ANLFloatType amp=1.0;

    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;
    w*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        ANLFloatType n=m_source[i]->get(x,y,z,w);
        sum+=(2.0 * fabs(n)-1.0)*amp;
        amp*=m_gain;

        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
        w*=m_lacunarity;
    }
    return sum;
}

ANLFloatType CImplicitFractal::Billow_get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
{
    ANLFloatType sum=0.0;
    ANLFloatType amp=1.0;

    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        ANLFloatType n=m_source[i]->get(x,y,z);
        sum+=(2.0 * fabs(n)-1.0)*amp;
        amp*=m_gain;

        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
    }
    return sum;
}

ANLFloatType CImplicitFractal::Billow_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
	ANLFloatType sum=0.0;
    ANLFloatType amp=1.0;

    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;
    w*=m_frequency;
    u*=m_frequency;
    v*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        ANLFloatType n=m_source[i]->get(x,y,z,w,u,v);
        sum+=(2.0 * fabs(n)-1.0)*amp;
        amp*=m_gain;

        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
        w*=m_lacunarity;
        u*=m_lacunarity;
        v*=m_lacunarity;
    }
    return sum;
}

ANLFloatType CImplicitFractal::RidgedMulti_get(ANLFloatType x, ANLFloatType y)
{
    ANLFloatType sum=0;
    ANLFloatType amp=1.0;

    x*=m_frequency;
    y*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        ANLFloatType n=m_source[i]->get(x,y);
        n=1.0-fabs(n);
        sum+=amp*n;
        amp*=m_gain;

        x*=m_lacunarity;
        y*=m_lacunarity;
    }
    return sum;
	/*ANLFloatType result=0.0, signal;
    x*=m_frequency;
    y*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        signal=m_source[i]->get(x,y);
        signal=m_offset-fabs(signal);
        signal *= signal;
        result +=signal*m_exparray[i];

        x*=m_lacunarity;
        y*=m_lacunarity;

    }

    return result*m_correct[m_numoctaves-1][0] + m_correct[m_numoctaves-1][1];*/
}

ANLFloatType CImplicitFractal::RidgedMulti_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
{
	ANLFloatType result=0.0, signal;
    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;
    w*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        signal=m_source[i]->get(x,y,z,w);
        signal=m_offset-fabs(signal);
        signal *= signal;
        result +=signal*m_exparray[i];

        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
        w*=m_lacunarity;
    }

    return result*m_correct[m_numoctaves-1][0] + m_correct[m_numoctaves-1][1];
}

ANLFloatType CImplicitFractal::RidgedMulti_get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
{
    ANLFloatType sum=0;
    ANLFloatType amp=1.0;

    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        ANLFloatType n=m_source[i]->get(x,y,z);
        n=1.0-fabs(n);
        sum+=amp*n;
        amp*=m_gain;

        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
    }
    return sum;
}

ANLFloatType CImplicitFractal::RidgedMulti_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
	ANLFloatType result=0.0, signal;
    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;
    w*=m_frequency;
	u*=m_frequency;
	v*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        signal=m_source[i]->get(x,y,z,w,u,v);
        signal=m_offset-fabs(signal);
        signal *= signal;
        result +=signal*m_exparray[i];

        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
        w*=m_lacunarity;
		u*=m_lacunarity;
		v*=m_lacunarity;
    }

    return result*m_correct[m_numoctaves-1][0] + m_correct[m_numoctaves-1][1];
}

ANLFloatType CImplicitFractal::HybridMulti_get(ANLFloatType x, ANLFloatType y)
{
	ANLFloatType value, signal, weight;
    x*=m_frequency;
    y*=m_frequency;


    value = m_source[0]->get(x,y) + m_offset;
    weight = m_gain * value;
    x*=m_lacunarity;
    y*=m_lacunarity;

    for(unsigned int i=1; i<m_numoctaves; ++i)
    {
        if(weight>1.0) weight=1.0;
        signal = (m_source[i]->get(x,y)+m_offset)*m_exparray[i];
        value += weight*signal;
        weight *=m_gain * signal;
        x*=m_lacunarity;
        y*=m_lacunarity;

    }

    return value*m_correct[m_numoctaves-1][0] + m_correct[m_numoctaves-1][1];
}

ANLFloatType CImplicitFractal::HybridMulti_get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
{
    ANLFloatType value, signal, weight;
    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;

    value = m_source[0]->get(x,y,z) + m_offset;
    weight = m_gain * value;
    x*=m_lacunarity;
    y*=m_lacunarity;
    z*=m_lacunarity;

    for(unsigned int i=1; i<m_numoctaves; ++i)
    {
        if(weight>1.0) weight=1.0;
        signal = (m_source[i]->get(x,y,z)+m_offset)*m_exparray[i];
        value += weight*signal;
        weight *=m_gain * signal;
        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
    }

    return value*m_correct[m_numoctaves-1][0] + m_correct[m_numoctaves-1][1];
}

ANLFloatType CImplicitFractal::HybridMulti_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
{
	ANLFloatType value, signal, weight;
    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;
    w*=m_frequency;

    value = m_source[0]->get(x,y,z,w) + m_offset;
    weight = m_gain * value;
    x*=m_lacunarity;
    y*=m_lacunarity;
    z*=m_lacunarity;
    w*=m_lacunarity;

    for(unsigned int i=1; i<m_numoctaves; ++i)
    {
        if(weight>1.0) weight=1.0;
        signal = (m_source[i]->get(x,y,z,w)+m_offset)*m_exparray[i];
        value += weight*signal;
        weight *=m_gain * signal;
        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
        w*=m_lacunarity;
    }

    return value*m_correct[m_numoctaves-1][0] + m_correct[m_numoctaves-1][1];
}

ANLFloatType CImplicitFractal::HybridMulti_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
	ANLFloatType value, signal, weight;
    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;
    w*=m_frequency;
	u*=m_frequency;
	v*=m_frequency;

    value = m_source[0]->get(x,y,z,w,u,v) + m_offset;
    weight = m_gain * value;
    x*=m_lacunarity;
    y*=m_lacunarity;
    z*=m_lacunarity;
    w*=m_lacunarity;
	u*=m_lacunarity;
	v*=m_lacunarity;

    for(unsigned int i=1; i<m_numoctaves; ++i)
    {
        if(weight>1.0) weight=1.0;
        signal = (m_source[i]->get(x,y,z,w,u,v)+m_offset)*m_exparray[i];
        value += weight*signal;
        weight *=m_gain * signal;
        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
        w*=m_lacunarity;
		u*=m_lacunarity;
		v*=m_lacunarity;
    }

    return value*m_correct[m_numoctaves-1][0] + m_correct[m_numoctaves-1][1];
}

ANLFloatType CImplicitFractal::DeCarpentierSwiss_get(ANLFloatType x, ANLFloatType y)
{
    ANLFloatType sum=0;
    ANLFloatType amp=1.0;

    ANLFloatType dx_sum=0;
    ANLFloatType dy_sum=0;

    x*=m_frequency;
    y*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        ANLFloatType n=m_source[i]->get(x+m_offset*dx_sum,y+m_offset*dy_sum);
        ANLFloatType dx=m_source[i]->get_dx(x+m_offset*dx_sum,y+m_offset*dy_sum);
        ANLFloatType dy=m_source[i]->get_dy(x+m_offset*dx_sum,y+m_offset*dy_sum);
        sum+=amp * (1.0-fabs(n));
        dx_sum+=amp*dx*-n;
        dy_sum+=amp*dy*-n;
        amp*=m_gain*clamp(sum,(ANLFloatType)0.0,(ANLFloatType)1.0);
        x*=m_lacunarity;
        y*=m_lacunarity;
    }
    return sum;
}

ANLFloatType CImplicitFractal::DeCarpentierSwiss_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
{
	ANLFloatType sum=0;
    ANLFloatType amp=1.0;

    ANLFloatType dx_sum=0;
    ANLFloatType dy_sum=0;
    ANLFloatType dz_sum=0;
    ANLFloatType dw_sum=0;

    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;
    w*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        ANLFloatType n=m_source[i]->get(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum, w+m_offset*dw_sum);
        ANLFloatType dx=m_source[i]->get_dx(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum, w+m_offset*dw_sum);
        ANLFloatType dy=m_source[i]->get_dy(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum, w+m_offset*dw_sum);
        ANLFloatType dz=m_source[i]->get_dz(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum, w+m_offset*dw_sum);
        ANLFloatType dw=m_source[i]->get_dw(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum, w+m_offset*dw_sum);
        sum+=amp * (1.0-fabs(n));
        dx_sum+=amp*dx*-n;
        dy_sum+=amp*dy*-n;
        dz_sum+=amp*dz*-n;
        dw_sum+=amp*dw*-n;
        amp*=m_gain*clamp(sum,(ANLFloatType)0.0,(ANLFloatType)1.0);
        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
        w*=m_lacunarity;
    }
    return sum;
}

ANLFloatType CImplicitFractal::DeCarpentierSwiss_get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
{
    ANLFloatType sum=0;
    ANLFloatType amp=1.0;

    ANLFloatType dx_sum=0;
    ANLFloatType dy_sum=0;
    ANLFloatType dz_sum=0;

    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        ANLFloatType n=m_source[i]->get(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum);
        ANLFloatType dx=m_source[i]->get_dx(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum);
        ANLFloatType dy=m_source[i]->get_dy(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum);
        ANLFloatType dz=m_source[i]->get_dz(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum);
        sum+=amp * (1.0-fabs(n));
        dx_sum+=amp*dx*-n;
        dy_sum+=amp*dy*-n;
        dz_sum+=amp*dz*-n;
        amp*=m_gain*clamp(sum,(ANLFloatType)0.0,(ANLFloatType)1.0);
        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
    }
    return sum;
}

ANLFloatType CImplicitFractal::DeCarpentierSwiss_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
{
	ANLFloatType sum=0;
    ANLFloatType amp=1.0;

    ANLFloatType dx_sum=0;
    ANLFloatType dy_sum=0;
    ANLFloatType dz_sum=0;
    ANLFloatType dw_sum=0;
    ANLFloatType du_sum=0;
    ANLFloatType dv_sum=0;

    x*=m_frequency;
    y*=m_frequency;
    z*=m_frequency;
    w*=m_frequency;
    u*=m_frequency;
    v*=m_frequency;

    for(unsigned int i=0; i<m_numoctaves; ++i)
    {
        ANLFloatType n=m_source[i]->get(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum);
        ANLFloatType dx=m_source[i]->get_dx(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dx_sum, w+m_offset*dw_sum, u+m_offset*du_sum, v+m_offset*dv_sum);
        ANLFloatType dy=m_source[i]->get_dy(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum, w+m_offset*dw_sum, u+m_offset*du_sum, v+m_offset*dv_sum);
        ANLFloatType dz=m_source[i]->get_dz(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum, w+m_offset*dw_sum, u+m_offset*du_sum, v+m_offset*dv_sum);
        ANLFloatType dw=m_source[i]->get_dw(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum, w+m_offset*dw_sum, u+m_offset*du_sum, v+m_offset*dv_sum);
        ANLFloatType du=m_source[i]->get_du(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum, w+m_offset*dw_sum, u+m_offset*du_sum, v+m_offset*dv_sum);
        ANLFloatType dv=m_source[i]->get_dv(x+m_offset*dx_sum,y+m_offset*dy_sum,z+m_offset*dz_sum, w+m_offset*dw_sum, u+m_offset*du_sum, v+m_offset*dv_sum);
        sum+=amp * (1.0-fabs(n));
        dx_sum+=amp*dx*-n;
        dy_sum+=amp*dy*-n;
        dz_sum+=amp*dz*-n;
        dw_sum+=amp*dw*-n;
        du_sum+=amp*du*-n;
        dv_sum+=amp*dv*-n;
        amp*=m_gain*clamp(sum,(ANLFloatType)0.0,(ANLFloatType)1.0);
        x*=m_lacunarity;
        y*=m_lacunarity;
        z*=m_lacunarity;
        w*=m_lacunarity;
        u*=m_lacunarity;
        v*=m_lacunarity;
    }
    return sum;
}
