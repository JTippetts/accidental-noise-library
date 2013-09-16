#include "anlmesh.h"
#include <fstream>

namespace anl
{
	CMesh::CMesh()
	{
	}
	
	CMesh::~CMesh()
	{
	}
		
	unsigned int CMesh::getVertexCount()
	{
		return vertices_.size();
	}
	
	unsigned int CMesh::getIndexCount()
	{
		return indices_.size();
	}
	
	SVertex CMesh::getVertex(unsigned int which)
	{
		if(which>=vertices_.size()) return SVertex();
		
		return vertices_[which];
	}
	
	unsigned int CMesh::getIndex(unsigned int which)
	{
		if(which>=indices_.size()) return 0;
		return indices_[which];
	}
	
	void CMesh::setVertex(unsigned int which, SVertex &vertex)
	{
		if(which>=vertices_.size()) return;
		
		vertices_[which]=vertex;
	}
	
	void CMesh::setIndex(unsigned int which, unsigned int index)
	{
		if(which>=indices_.size()) return;
		
		indices_[which]=index;
	}
		
	void CMesh::pushVertex(SVertex vertex)
	{
		vertices_.push_back(vertex);
	}
	
	void CMesh::pushIndex(unsigned int index)
	{
		indices_.push_back(index);
	}
		
	void CMesh::saveOBJ(std::string &name, bool savetex, bool savenormal)
	{
		std::fstream outfile(name,std::ios::out);
		
		for(unsigned int c=0; c<vertices_.size(); ++c)
		{
			SVertex vert=getVertex(c);
			outfile << "v " << vert.v[0] << " " << vert.v[1] << " " << vert.v[2] << std::endl;
		}
		
		if(savenormal)
		{
			for(unsigned int c=0; c<vertices_.size(); ++c)
			{
				SVertex vert=getVertex(c);
				outfile << "vn " << vert.n[0] << " " << vert.n[1] << " " << vert.n[2] << std::endl;
			}
		}
		
		if(savetex)
		{
			for(unsigned int c=0; c<vertices_.size(); ++c)
			{
				SVertex vert=getVertex(c);
				outfile << "vt " << vert.tc[0] << " " << vert.tc[1] << std::endl;
			}
		}
		
		for(unsigned int c=0; c<indices_.size(); c+=3)
		{
			outfile << "f " << getIndex(c)+1;
			if(savetex || savenormal)
			{
				if(savetex)
				{
					outfile << "/" << getIndex(c)+1;
				}
				else
				{
					outfile << "/";
				}
				if(savenormal)
				{
					outfile << "/" << getIndex(c)+1;
				}
			}
			
			outfile << " " << getIndex(c+1)+1;
			if(savetex || savenormal)
			{
				if(savetex)
				{
					outfile << "/" << getIndex(c+1)+1;
				}
				else
				{
					outfile << "/";
				}
				if(savenormal)
				{
					outfile << "/" << getIndex(c+1)+1;
				}
			}
			
			outfile << " " << getIndex(c+2)+1;
			if(savetex || savenormal)
			{
				if(savetex)
				{
					outfile << "/" << getIndex(c+2)+1;
				}
				else
				{
					outfile << "/";
				}
				if(savenormal)
				{
					outfile << "/" << getIndex(c+2)+1;
				}
			}
			
			outfile << std::endl;
		}
		
		outfile.close();
	}
};