#include "implicitcombiner.h"

namespace anl
{
    CImplicitCombiner::CImplicitCombiner(unsigned int type)
	{
		m_type=type;
		clearAllSources();
	}

	void CImplicitCombiner::setType(unsigned int type)
	{
		m_type=type;
	}

	void CImplicitCombiner::clearAllSources()
	{
		for(int c=0; c<MaxSources; ++c) m_sources[c]=0;
	}

	void CImplicitCombiner::setSource(int which, CImplicitModuleBase * b)
	{
		if(which<0 || which>=MaxSources) return;
		m_sources[which]=b;
	}

	ANLFloatType CImplicitCombiner::get(ANLFloatType x, ANLFloatType y)
	{
		switch(m_type)
		{
		case ADD: return Add_get(x,y); break;
		case MULT: return Mult_get(x,y); break;
		case MAX: return Max_get(x,y); break;
		case MIN: return Min_get(x,y); break;
		case AVG: return Avg_get(x,y); break;
		default: return 0.0; break;
		}
	}

	ANLFloatType CImplicitCombiner::get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
	{
	    switch(m_type)
		{
		case ADD: return Add_get(x,y,z); break;
		case MULT: return Mult_get(x,y,z); break;
		case MAX: return Max_get(x,y,z); break;
		case MIN: return Min_get(x,y,z); break;
		case AVG: return Avg_get(x,y,z); break;
		default: return 0.0; break;
		}
	}

	ANLFloatType CImplicitCombiner::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
	{
		switch(m_type)
		{
		case ADD: return Add_get(x,y,z,w); break;
		case MULT: return Mult_get(x,y,z,w); break;
		case MAX: return Max_get(x,y,z,w); break;
		case MIN: return Min_get(x,y,z,w); break;
		case AVG: return Avg_get(x,y,z,w); break;
		default: return 0.0; break;
		}
	}

	ANLFloatType CImplicitCombiner::get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
	{
		switch(m_type)
		{
		case ADD: return Add_get(x,y,z,w,u,v); break;
		case MULT: return Mult_get(x,y,z,w,u,v); break;
		case MAX: return Max_get(x,y,z,w,u,v); break;
		case MIN: return Min_get(x,y,z,w,u,v); break;
		case AVG: return Avg_get(x,y,z,w,u,v); break;
		default: return 0.0; break;
		}
	}


	ANLFloatType CImplicitCombiner::Add_get(ANLFloatType x, ANLFloatType y)
	{
		ANLFloatType value=0.0;
		for(int c=0; c<MaxSources; ++c)
		{
			if(m_sources[c]) value+=m_sources[c]->get(x,y);
		}
		return value;
	}
	ANLFloatType CImplicitCombiner::Add_get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
	{
	    ANLFloatType value=0;
	    for(int c=0; c<MaxSources; ++c)
	    {
	        if(m_sources[c]) value+=m_sources[c]->get(x,y,z);
	    }
	    return value;
	}
	ANLFloatType CImplicitCombiner::Add_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
	{
		ANLFloatType value=0.0;
		for(int c=0; c<MaxSources; ++c)
		{
			if(m_sources[c]) value+=m_sources[c]->get(x,y,z,w);
		}
		return value;
	}
	ANLFloatType CImplicitCombiner::Add_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
	{
		ANLFloatType value=0.0;
		for(int c=0; c<MaxSources; ++c)
		{
			if(m_sources[c]) value+=m_sources[c]->get(x,y,z,w,u,v);
		}
		return value;
	}

	ANLFloatType CImplicitCombiner::Mult_get(ANLFloatType x, ANLFloatType y)
	{
		ANLFloatType value=1.0;
		for(int c=0; c<MaxSources; ++c)
		{
			if(m_sources[c]) value*=m_sources[c]->get(x,y);
		}
		return value;
	}
	ANLFloatType CImplicitCombiner::Mult_get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
	{
		ANLFloatType value=1.0;
		for(int c=0; c<MaxSources; ++c)
		{
			if(m_sources[c]) value*=m_sources[c]->get(x,y,z);
		}
		return value;
	}
	ANLFloatType CImplicitCombiner::Mult_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
	{
		ANLFloatType value=1.0;
		for(int c=0; c<MaxSources; ++c)
		{
			if(m_sources[c]) value*=m_sources[c]->get(x,y,z,w);
		}
		return value;
	}
	ANLFloatType CImplicitCombiner::Mult_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
	{
		ANLFloatType value=1.0;
		for(int c=0; c<MaxSources; ++c)
		{
			if(m_sources[c]) value*=m_sources[c]->get(x,y,z,w,u,v);
		}
		return value;
	}

	ANLFloatType CImplicitCombiner::Min_get(ANLFloatType x, ANLFloatType y)
	{
		ANLFloatType mn;
		int c=0;
		while(c<MaxSources && !m_sources[c]) ++c;
		if(c==MaxSources) return 0.0;
		mn=m_sources[c]->get(x,y);

		for(int d=c; d<MaxSources; ++d)
		{
			if(m_sources[d])
			{
				ANLFloatType v=m_sources[d]->get(x,y);
				if(v<mn) mn=v;
			}
		}

		return mn;
	}

	ANLFloatType CImplicitCombiner::Min_get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
	{
		ANLFloatType mn;
		int c=0;
		while(c<MaxSources && !m_sources[c]) ++c;
		if(c==MaxSources) return 0.0;
		mn=m_sources[c]->get(x,y,z);

		for(int d=c; d<MaxSources; ++d)
		{
			if(m_sources[d])
			{
				ANLFloatType v=m_sources[d]->get(x,y,z);
				if(v<mn) mn=v;
			}
		}

		return mn;
	}

	ANLFloatType CImplicitCombiner::Min_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
	{
		ANLFloatType mn;
		int c=0;
		while(c<MaxSources && !m_sources[c]) ++c;
		if(c==MaxSources) return 0.0;
		mn=m_sources[c]->get(x,y,z,w);

		for(int d=c; d<MaxSources; ++d)
		{
			if(m_sources[d])
			{
				ANLFloatType v=m_sources[d]->get(x,y,z,w);
				if(v<mn) mn=v;
			}
		}

		return mn;
	}

	ANLFloatType CImplicitCombiner::Min_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
	{
		ANLFloatType mn;
		int c=0;
		while(c<MaxSources && !m_sources[c]) ++c;
		if(c==MaxSources) return 0.0;
		mn=m_sources[c]->get(x,y,z,w,u,v);

		for(int d=c; d<MaxSources; ++d)
		{
			if(m_sources[d])
			{
				ANLFloatType val=m_sources[d]->get(x,y,z,w,u,v);
				if(val<mn) mn=val;
			}
		}

		return mn;
	}

	ANLFloatType CImplicitCombiner::Max_get(ANLFloatType x, ANLFloatType y)
	{
		ANLFloatType mn;
		int c=0;
		while(c<MaxSources && !m_sources[c]) ++c;
		if(c==MaxSources) return 0.0;
		mn=m_sources[c]->get(x,y);

		for(int d=c; d<MaxSources; ++d)
		{
			if(m_sources[d])
			{
				ANLFloatType v=m_sources[d]->get(x,y);
				if(v>mn) mn=v;
			}
		}

		return mn;
	}

	ANLFloatType CImplicitCombiner::Max_get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
	{
		ANLFloatType mn;
		int c=0;
		while(c<MaxSources && !m_sources[c]) ++c;
		if(c==MaxSources) return 0.0;
		mn=m_sources[c]->get(x,y,z);

		for(int d=c; d<MaxSources; ++d)
		{
			if(m_sources[d])
			{
				ANLFloatType v=m_sources[d]->get(x,y,z);
				if(v>mn) mn=v;
			}
		}

		return mn;
	}

	ANLFloatType CImplicitCombiner::Max_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
	{
		ANLFloatType mn;
		int c=0;
		while(c<MaxSources && !m_sources[c]) ++c;
		if(c==MaxSources) return 0.0;
		mn=m_sources[c]->get(x,y,z,w);

		for(int d=c; d<MaxSources; ++d)
		{
			if(m_sources[d])
			{
				ANLFloatType v=m_sources[d]->get(x,y,z,w);
				if(v>mn) mn=v;
			}
		}

		return mn;
	}

	ANLFloatType CImplicitCombiner::Max_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
	{
		ANLFloatType mn;
		int c=0;
		while(c<MaxSources && !m_sources[c]) ++c;
		if(c==MaxSources) return 0.0;
		mn=m_sources[c]->get(x,y,z,w,u,v);

		for(int d=c; d<MaxSources; ++d)
		{
			if(m_sources[d])
			{
				ANLFloatType val=m_sources[d]->get(x,y,z,w,u,v);
				if(val>mn) mn=val;
			}
		}

		return mn;
	}

	ANLFloatType CImplicitCombiner::Avg_get(ANLFloatType x, ANLFloatType y)
	{
		ANLFloatType count=0;
		ANLFloatType value=0;
		for(int c=0; c<MaxSources; ++c)
		{
			if(m_sources[c])
			{
				value+=m_sources[c]->get(x,y);
				count+=1.0;
			}
		}
		if(count==0.0) return 0.0;
		return value/count;
	}

	ANLFloatType CImplicitCombiner::Avg_get(ANLFloatType x, ANLFloatType y, ANLFloatType z)
	{
		ANLFloatType count=0;
		ANLFloatType value=0;
		for(int c=0; c<MaxSources; ++c)
		{
			if(m_sources[c])
			{
				value+=m_sources[c]->get(x,y,z);
				count+=1.0;
			}
		}
		if(count==0.0) return 0.0;
		return value/count;
	}

	ANLFloatType CImplicitCombiner::Avg_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w)
	{
		ANLFloatType count=0;
		ANLFloatType value=0;
		for(int c=0; c<MaxSources; ++c)
		{
			if(m_sources[c])
			{
				value+=m_sources[c]->get(x,y,z,w);
				count+=1.0;
			}
		}
		if(count==0.0) return 0.0;
		return value/count;
	}

	ANLFloatType CImplicitCombiner::Avg_get(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v)
	{
		ANLFloatType count=0;
		ANLFloatType value=0;
		for(int c=0; c<MaxSources; ++c)
		{
			if(m_sources[c])
			{
				value+=m_sources[c]->get(x,y,z,w,u,v);
				count+=1.0;
			}
		}
		if(count==0.0) return 0.0;
		return value/count;
	}
};
