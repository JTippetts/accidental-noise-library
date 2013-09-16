// Accidental Noise Library
// Mesh structure

#ifndef ANL_MESH_H
#define ANL_MESH_H

#include "../Imaging/vectortypes.h"
#include <vector>
#include <string>

namespace anl
{
	struct SVertex
	{
		CVec3f v;
		CVec3f n;
		CVec2f tc;
			
		SVertex() : v(0,0,0), n(0,0,0), tc(0,0){}
		SVertex(const SVertex &rhs): v(rhs.v), n(rhs.n), tc(rhs.tc){}
		//SVertex(SVertex rhs) : v(rhs.v), n(rhs.n), tc(rhs.tc){}
		SVertex(CVec3f V, CVec3f N, CVec2f TC) : v(V), n(N), tc(TC){}
		SVertex(float x, float y, float z, float nx, float ny, float nz, float u, float v) : v(x,y,z), n(nx,ny,nz), tc(u,v){}
	};
	class CMesh
	{
	public:
		
		CMesh();
		~CMesh();
		
		unsigned int getVertexCount();
		unsigned int getIndexCount();
		SVertex getVertex(unsigned int which);
		unsigned int getIndex(unsigned int which);
		void setVertex(unsigned int which, SVertex &vertex);
		void setIndex(unsigned int which, unsigned int index);
		
		void pushVertex(SVertex vertex);
		void pushIndex(unsigned int index);
		
		void saveOBJ(std::string &name, bool savetex, bool savenormal);
	
	private:
		std::vector<SVertex> vertices_;
		std::vector<unsigned int> indices_;
	};
};

#endif
