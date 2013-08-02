#include "marchvolume.h"

#include <cmath>
#include <vector>
#include <deque>
#include <fstream>
#include <iostream>

namespace anl
{

CVec3f VertexInterp(float isolevel, CVec3f &p1, CVec3f &p2, float valp1, float valp2)
{
    float mu;
    CVec3f p;

    if(fabs(isolevel-valp1) < 0.00001) return(p1);
    if(fabs(isolevel-valp2) < 0.00001) return(p2);
    if(fabs(valp1-valp2) < 0.00001) return p1;
    mu = (isolevel - valp1) / (valp2-valp1);
    return p1 + (p2-p1)*mu;


}


/*
   Polygonise a tetrahedron given its vertices within a cube
   This is an alternative algorithm to polygonisegrid.
   It results in a smoother surface but more triangular facets.

                      + 0
                     /|\
                    / | \
                   /  |  \
                  /   |   \
                 /    |    \
                /     |     \
               +-------------+ 1
              3 \     |     /
                 \    |    /
                  \   |   /
                   \  |  /
                    \ | /
                     \|/
                      + 2

   It's main purpose is still to polygonise a gridded dataset and
   would normally be called 6 times, one for each tetrahedron making
   up the grid cell.
   Given the grid labelling as in PolygniseGrid one would call
      PolygoniseTri(grid,iso,triangles,0,2,3,7);
      PolygoniseTri(grid,iso,triangles,0,2,6,7);
      PolygoniseTri(grid,iso,triangles,0,4,6,7);
      PolygoniseTri(grid,iso,triangles,0,6,1,2);
      PolygoniseTri(grid,iso,triangles,0,6,1,4);
      PolygoniseTri(grid,iso,triangles,5,6,1,4);
*/

void marchTetraGrid(CVec3f cube[8], float vals[8], float iso, int v0, int v1, int v2, int v3, std::vector<CVec3f> &verts, std::vector<int> &faces)
{
    int ntri = 0;
   int triindex;
   /*
      Determine which of the 16 cases we have given which vertices
      are above or below the isosurface
   */
   triindex = 0;
   if (vals[v0] < iso) triindex |= 1;
   if (vals[v1] < iso) triindex |= 2;
   if (vals[v2] < iso) triindex |= 4;
   if (vals[v3] < iso) triindex |= 8;

   CVec3f tri[6];

   /* Form the vertices of the triangles for each case */
   switch (triindex) {
   case 0x00:
   case 0x0F:
      break;
   case 0x0E:
   case 0x01:
      tri[0] = VertexInterp(iso,cube[v0],cube[v1],vals[v0],vals[v1]);
      tri[1] = VertexInterp(iso,cube[v0],cube[v2],vals[v0],vals[v2]);
      tri[2] = VertexInterp(iso,cube[v0],cube[v3],vals[v0],vals[v3]);
      ntri++;
      break;
   case 0x0D:
   case 0x02:
      tri[0] = VertexInterp(iso,cube[v1],cube[v0],vals[v1],vals[v0]);
      tri[1] = VertexInterp(iso,cube[v1],cube[v3],vals[v1],vals[v3]);
      tri[2] = VertexInterp(iso,cube[v1],cube[v2],vals[v1],vals[v2]);
      ntri++;
      break;
   case 0x0C:
   case 0x03:
      tri[0] = VertexInterp(iso,cube[v0],cube[v3],vals[v0],vals[v3]);
      tri[1] = VertexInterp(iso,cube[v0],cube[v2],vals[v0],vals[v2]);
      tri[2] = VertexInterp(iso,cube[v1],cube[v3],vals[v1],vals[v3]);
      ntri++;
      tri[3] = tri[2];
      tri[4] = VertexInterp(iso,cube[v1],cube[v2],vals[v1],vals[v2]);
      tri[5] = tri[1];
      ntri++;
      break;
   case 0x0B:
   case 0x04:
      tri[0] = VertexInterp(iso,cube[v2],cube[v0],vals[v2],vals[v0]);
      tri[1] = VertexInterp(iso,cube[v2],cube[v1],vals[v2],vals[v1]);
      tri[2] = VertexInterp(iso,cube[v2],cube[v3],vals[v2],vals[v3]);
      ntri++;
      break;
   case 0x0A:
   case 0x05:
      tri[0] = VertexInterp(iso,cube[v0],cube[v1],vals[v0],vals[v1]);
      tri[1] = VertexInterp(iso,cube[v2],cube[v3],vals[v2],vals[v3]);
      tri[2] = VertexInterp(iso,cube[v0],cube[v3],vals[v0],vals[v3]);
      ntri++;
      tri[3] = tri[0];
      tri[4] = VertexInterp(iso,cube[v1],cube[v2],vals[v1],vals[v2]);
      tri[5] = tri[1];
      ntri++;
      break;
   case 0x09:
   case 0x06:
      tri[0] = VertexInterp(iso,cube[v0],cube[v1],vals[v0],vals[v1]);
      tri[1] = VertexInterp(iso,cube[v1],cube[v3],vals[v1],vals[v3]);
      tri[2] = VertexInterp(iso,cube[v2],cube[v3],vals[v2],vals[v3]);
      ntri++;
      tri[3] = tri[0];
      tri[4] = VertexInterp(iso,cube[v0],cube[v2],vals[v0],vals[v2]);
      tri[5] = tri[2];
      ntri++;
      break;
   case 0x07:
   case 0x08:
      tri[0] = VertexInterp(iso,cube[v3],cube[v0],vals[v3],vals[v0]);
      tri[1] = VertexInterp(iso,cube[v3],cube[v2],vals[v3],vals[v2]);
      tri[2] = VertexInterp(iso,cube[v3],cube[v1],vals[v3],vals[v1]);
      ntri++;
      break;
   }

   int face=faces.size();
   for(int c=0; c<ntri*3; ++c)
   {
       verts.push_back(tri[c]);
       faces.push_back(face+c);
   }
}

void marchCubeGrid(CVec3f cube[8], float vals[8], float iso, std::vector<CVec3f> &verts, std::vector<int> &faces)
{
    marchTetraGrid(cube,vals,iso,0,2,3,7,verts,faces);
    marchTetraGrid(cube,vals,iso,0,2,6,7,verts,faces);
    marchTetraGrid(cube,vals,iso,0,4,6,7,verts,faces);
    marchTetraGrid(cube,vals,iso,0,6,1,2,verts,faces);
    marchTetraGrid(cube,vals,iso,0,6,1,4,verts,faces);
    marchTetraGrid(cube,vals,iso,5,6,1,4,verts,faces);
}

unsigned char marchCalcCode(CArray3Dd &field, unsigned int x, unsigned int y, unsigned int z, float iso)
{
    unsigned char code=0;
    if(field.get(x,y,z)<iso) code+=1;
    if(field.get(x+1,y,z)<iso) code+=2;
    if(field.get(x+1,y,z+1)<iso) code+=4;
    if(field.get(x,y,z+1)<iso) code+=8;
    if(field.get(x,y+1,z)<iso) code+=16;
    if(field.get(x+1,y+1,z)<iso) code+=32;
    if(field.get(x+1,y+1,z+1)<iso) code+=64;
    if(field.get(x,y+1,z+1)<iso) code+=128;

    return code;
}

unsigned char marchCubeCompute(CArray3Dd &field, unsigned int x, unsigned int y, unsigned int z, float iso,
    std::vector<CVec3f> &verts, std::vector<int> &faces)
{
    // Compute neighbor code, populate grid and vals, and call marchCubeGrid. Return code.
    unsigned int sx=field.width(), sy=field.height(), sz=field.depth();
    if(x>=sx-1 || y>=sy-1 || z>=sz-1) return 0;
    // Calculate the grid coordinates of the cube
    CVec3f cube[8]=
    {
        CVec3f(x,y,z),
        CVec3f(x+1,y,z),
        CVec3f(x+1,y,z+1),
        CVec3f(x,y,z+1),
        CVec3f(x,y+1,z),
        CVec3f(x+1,y+1,z),
        CVec3f(x+1,y+1,z+1),
        CVec3f(x,y+1,z+1)
    };

    float vals[8];
    unsigned int c;
    unsigned char code=0;

    for(c=0; c<8; ++c)
    {
        vals[c]=field.get((unsigned int)cube[c][0], (unsigned int)cube[c][1], (unsigned int)cube[c][2]);
        //std::cout << vals[c] << std::endl;
    }

    if(vals[0]<iso) code+=1;
    if(vals[1]<iso) code+=2;
    if(vals[2]<iso) code+=4;
    if(vals[3]<iso) code+=8;
    if(vals[4]<iso) code+=16;
    if(vals[5]<iso) code+=32;
    if(vals[6]<iso) code+=64;
    if(vals[7]<iso) code+=128;

    marchCubeGrid(cube,vals,iso,verts,faces);
    return code;
}


// Function to generate the neighbors of a voxel based on the code
void marchGenerateNeighbors(CArray3Dd &field, unsigned int x, unsigned int y, unsigned int z, float iso, CArray3Dd &visited,
    std::deque<CVec3ui> &open)
{
    // Iterate neighbors, call marchCalcCode to calculate if the neighbor is a surface node,
    // push and visit it if so.
    unsigned int sx=visited.width(), sy=visited.height(), sz=visited.depth();
    for(int nx=x-1; nx<=x+1; ++nx)
    {
        for(int ny=y-1; ny<=y+1; ++ny)
        {
            for(int nz=z-1; nz<=z+1; ++nz)
            {
                if(nx>=0 && nx<(int)sx-1 && ny>=0 && ny<(int)sy-1 && nz>=0 && nz<(int)sz-1)
                {
                    if(visited.get((unsigned int)nx,(unsigned int)ny,(unsigned int)nz)==0)
                    {
                        unsigned char code=marchCalcCode(field,(unsigned int)nx,(unsigned int)ny,(unsigned int)nz,iso);
                        if(code!=0 && code!=255)
                        {
                            visited.set((unsigned int)nx,(unsigned int)ny,(unsigned int)nz,1);
                            open.push_back(CVec3ui((unsigned int)nx, (unsigned int)ny, (unsigned int)nz));
                        }
                    }
                }
            }
        }
    }
}



// Function to find a surface voxel cell index
CVec3ui marchFindSurfaceCell(CArray3Dd &field, float iso)
{
    unsigned int sx=field.width(), sy=field.height(), sz=field.depth();

    for(unsigned int x=0; x<sx-1; ++x)
    {
        for(unsigned int y=0; y<sy-1; ++y)
        {
            for(unsigned int z=0; z<sz-1; ++z)
            {
                unsigned char code=0;
                if(field.get(x,y,z)<iso) code+=1;
                if(field.get(x+1,y,z)<iso) code+=2;
                if(field.get(x+1,y,z+1)<iso) code+=4;
                if(field.get(x,y,z+1)<iso) code+=8;
                if(field.get(x,y+1,z)<iso) code+=16;
                if(field.get(x+1,y+1,z)<iso) code+=32;
                if(field.get(x+1,y+1,z+1)<iso) code+=64;
                if(field.get(x,y+1,z+1)<iso) code+=128;

                if(code!=0 && code!=255) return CVec3ui(x,y,z);
            }
        }
    }

    // Couldn't find one
    return CVec3ui(sx,sy,sz);
}


// Function to march a voxel volume following the surface
void marchDensityFieldSurface(CArray3Dd &field, float iso, std::vector<CVec3f> &verts, std::vector<int> &faces)
{
    unsigned int sx=field.width(), sy=field.height(), sz=field.depth();

    std::deque<CVec3ui> open;
    //CVoxelField visited(sx,sy,sz);
	CArray3Dd visited;
	visited.resize(sx,sy,sz);

    CVec3ui startcell=marchFindSurfaceCell(field,iso);
    if(startcell[0]==sx)
    {
        // No surface
        std::cout << "Error: Couldn't find surface." <<std::endl;
        return;
    }

    std::cout << "Start cell: " << startcell[0] << "," << startcell[1] << "," << startcell[2] << std::endl;

    // Set visited and push to open
    visited.set(startcell[0], startcell[1], startcell[2],1);
    open.push_back(startcell);

    while(!open.empty())
    {
        // pop a cell
        CVec3ui cell=open.front();
        open.pop_front();

        //std::cout << "Current cell: " << cell[0] << "," << cell[1] << "," << cell[2] << std::endl;

        // Evaluate cell
        unsigned char code=marchCubeCompute(field,cell[0],cell[1],cell[2],iso,verts,faces);

        // Generate neighbors
        marchGenerateNeighbors(field,cell[0], cell[1], cell[2], iso, visited, open);
    }

    // Done
}

// Function to march a field without surface following
void marchDensityField(CArray3Dd &field, float iso, std::vector<CVec3f> &verts, std::vector<int> &faces)
{
    unsigned int sx=field.width(), sy=field.height(), sz=field.depth();

    for(unsigned int x=0; x<sx-1; ++x)
    {
        for(unsigned int y=0; y<sy-1; ++y)
        {
            for(unsigned int z=0; z<sz-1; ++z)
            {
                marchCubeCompute(field,x,y,z,iso,verts,faces);
            }
        }
    }
}

void replaceIndex(std::vector<int> &faces, int what, int replace)
{
    for(int c=0; c<faces.size(); ++c)
    {
        if(faces[c]==what) faces[c]=replace;
    }
}

bool compareVerts(CVec3f &v1, CVec3f &v2, float epsilon)
{
    if((abs(v1.x()-v2.x())>epsilon)) return false;
    if((abs(v1.y()-v2.y())>epsilon)) return false;
    if((abs(v1.z()-v2.z())>epsilon)) return false;
    return true;
}

void removeDoubles(std::vector<CVec3f> &verts, std::vector<int> &faces)
{
    // Iterate verts, find any verts that are within Epsilon of each other, and consolidate them
    std::vector<CVec3f> newverts;
    float epsilon=0.001f;
    int count=0;
    for(int v1=0; v1<verts.size(); ++v1)
    {
        for(int v2=v1+1; v2<verts.size(); ++v2)
        {
            if(compareVerts(verts[v1], verts[v2], epsilon))
            {
                newverts.push_back(verts[v1]);
                replaceIndex(faces, v1, count);
                replaceIndex(faces, v2, count);
                ++count;
            }
            else
            {
                newverts.push_back(verts[v1]);
                replaceIndex(faces, v1, count);
                ++count;
            }
        }
    }

    verts=newverts;
}


void marchDensityFieldSurfaceOBJ(CArray3Dd &field, float iso, std::string name)
{
    std::vector<CVec3f> verts;
    std::vector<int> faces;

    marchDensityFieldSurface(field,iso,verts,faces);

    std::fstream outfile(name,std::ios::out);
    for(int c=0; c<verts.size(); ++c)
    {
        outfile << "v " << verts[c][0] << " " << verts[c][1] << " " << verts[c][2] << std::endl;
    }

    for(int c=0; c<faces.size(); c+=3)
    {
        outfile << "f " << faces[c]+1 << " " << faces[c]+2 << " " << faces[c]+3 << std::endl;
    }

    outfile.close();
}

void marchDensityFieldOBJ(CArray3Dd &field, float iso, std::string name)
{
    std::vector<CVec3f> verts;
    std::vector<int> faces;

    marchDensityField(field,iso,verts,faces);
    removeDoubles(verts, faces);

    std::fstream outfile(name,std::ios::out);
    for(int c=0; c<verts.size(); ++c)
    {
        outfile << "v " << verts[c][0] << " " << verts[c][1] << " " << verts[c][2] << std::endl;
    }

    for(int c=0; c<faces.size(); c+=3)
    {
        outfile << "f " << faces[c]+1 << " " << faces[c]+2 << " " << faces[c]+3 << std::endl;
    }

    outfile.close();
}




int marchTetra(CArray3Dd &field,unsigned int x, unsigned int y, unsigned int z, double iso,
   CVec3f tri[6],int v0,int v1,int v2,int v3)
{
   int ntri = 0;
   int triindex;

   unsigned int sx=field.width(), sy=field.height(), sz=field.depth();
    if(x>=sx-1 || y>=sy-1 || z>=sz-1) return 0;
    // Calculate the grid coordinates of the cube
    CVec3f cube[8]=
    {
        CVec3f(x,y,z),
        CVec3f(x+1,y,z),
        CVec3f(x+1,y,z+1),
        CVec3f(x,y,z+1),
        CVec3f(x,y+1,z),
        CVec3f(x+1,y+1,z),
        CVec3f(x+1,y+1,z+1),
        CVec3f(x,y+1,z+1)
    };

    float vals[8];
    unsigned int c;
    for(c=0; c<8; ++c)
    {
        vals[c]=field.get((unsigned int)cube[c][0], (unsigned int)cube[c][1], (unsigned int)cube[c][2]);
    }

   /*
      Determine which of the 16 cases we have given which vertices
      are above or below the isosurface
   */
   triindex = 0;
   if (vals[v0] < iso) triindex |= 1;
   if (vals[v1] < iso) triindex |= 2;
   if (vals[v2] < iso) triindex |= 4;
   if (vals[v3] < iso) triindex |= 8;

   /* Form the vertices of the triangles for each case */
   switch (triindex) {
   case 0x00:
   case 0x0F:
      break;
   case 0x0E:
   case 0x01:
      tri[0] = VertexInterp(iso,cube[v0],cube[v1],vals[v0],vals[v1]);
      tri[1] = VertexInterp(iso,cube[v0],cube[v2],vals[v0],vals[v2]);
      tri[2] = VertexInterp(iso,cube[v0],cube[v3],vals[v0],vals[v3]);
      ntri++;
      break;
   case 0x0D:
   case 0x02:
      tri[0] = VertexInterp(iso,cube[v1],cube[v0],vals[v1],vals[v0]);
      tri[1] = VertexInterp(iso,cube[v1],cube[v3],vals[v1],vals[v3]);
      tri[2] = VertexInterp(iso,cube[v1],cube[v2],vals[v1],vals[v2]);
      ntri++;
      break;
   case 0x0C:
   case 0x03:
      tri[0] = VertexInterp(iso,cube[v0],cube[v3],vals[v0],vals[v3]);
      tri[1] = VertexInterp(iso,cube[v0],cube[v2],vals[v0],vals[v2]);
      tri[2] = VertexInterp(iso,cube[v1],cube[v3],vals[v1],vals[v3]);
      ntri++;
      tri[3] = tri[2];
      tri[4] = VertexInterp(iso,cube[v1],cube[v2],vals[v1],vals[v2]);
      tri[5] = tri[1];
      ntri++;
      break;
   case 0x0B:
   case 0x04:
      tri[0] = VertexInterp(iso,cube[v2],cube[v0],vals[v2],vals[v0]);
      tri[1] = VertexInterp(iso,cube[v2],cube[v1],vals[v2],vals[v1]);
      tri[2] = VertexInterp(iso,cube[v2],cube[v3],vals[v2],vals[v3]);
      ntri++;
      break;
   case 0x0A:
   case 0x05:
      tri[0] = VertexInterp(iso,cube[v0],cube[v1],vals[v0],vals[v1]);
      tri[1] = VertexInterp(iso,cube[v2],cube[v3],vals[v2],vals[v3]);
      tri[2] = VertexInterp(iso,cube[v0],cube[v3],vals[v0],vals[v3]);
      ntri++;
      tri[3] = tri[0];
      tri[4] = VertexInterp(iso,cube[v1],cube[v2],vals[v1],vals[v2]);
      tri[5] = tri[1];
      ntri++;
      break;
   case 0x09:
   case 0x06:
      tri[0] = VertexInterp(iso,cube[v0],cube[v1],vals[v0],vals[v1]);
      tri[1] = VertexInterp(iso,cube[v1],cube[v3],vals[v1],vals[v3]);
      tri[2] = VertexInterp(iso,cube[v2],cube[v3],vals[v2],vals[v3]);
      ntri++;
      tri[3] = tri[0];
      tri[4] = VertexInterp(iso,cube[v0],cube[v2],vals[v0],vals[v2]);
      tri[5] = tri[2];
      ntri++;
      break;
   case 0x07:
   case 0x08:
      tri[0] = VertexInterp(iso,cube[v3],cube[v0],vals[v3],vals[v0]);
      tri[1] = VertexInterp(iso,cube[v3],cube[v2],vals[v3],vals[v2]);
      tri[2] = VertexInterp(iso,cube[v3],cube[v1],vals[v3],vals[v1]);
      ntri++;
      break;
   }

   return(ntri);
}

};