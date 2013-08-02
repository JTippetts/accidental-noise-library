/*******************************************************************************
Copyright (c) 2005-2009 David Williams

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution. 	
*******************************************************************************/

#include "OpenGLSupport.h"
#include "OpenGLVertexBufferObjectSupport.h"

#include "PolyVoxCore/SurfaceMesh.h"

using namespace PolyVox;
using namespace std;

OpenGLSurfaceMesh BuildOpenGLSurfaceMesh(const SurfaceMesh<PositionMaterialNormal>& mesh)
{
	//Represents our filled in OpenGL vertex and index buffer objects.
	OpenGLSurfaceMesh result;

	//The source
	result.sourceMesh = &mesh;

	//Convienient access to the vertices and indices
	const vector<PositionMaterialNormal>& vecVertices = mesh.getVertices();
	const vector<uint32_t>& vecIndices = mesh.getIndices();

	//If we have any indices...
	if(!vecIndices.empty())
	{
		//Create an OpenGL index buffer
		glGenBuffers(1, &result.indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, result.indexBuffer);

		//Get a pointer to the first index
		GLvoid* pIndices = (GLvoid*)(&(vecIndices[0]));		

		//Fill the OpenGL index buffer with our data. 
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, vecIndices.size() * sizeof(uint32_t), pIndices, GL_STATIC_DRAW);
	}

	result.noOfIndices = vecIndices.size();

	glGenBuffers(1, &result.vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, result.vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vecVertices.size() * sizeof(GLfloat) * 9, 0, GL_STATIC_DRAW);
	GLfloat* ptr = (GLfloat*)glMapBuffer(GL_ARRAY_BUFFER, GL_READ_WRITE);

	for(vector<PositionMaterialNormal>::const_iterator iterVertex = vecVertices.begin(); iterVertex != vecVertices.end(); ++iterVertex)
	{
		const PositionMaterialNormal& vertex = *iterVertex;
		const Vector3DFloat& v3dVertexPos = vertex.getPosition();
		//const Vector3DFloat v3dRegionOffset(uRegionX * g_uRegionSideLength, uRegionY * g_uRegionSideLength, uRegionZ * g_uRegionSideLength);
		const Vector3DFloat v3dFinalVertexPos = v3dVertexPos + static_cast<Vector3DFloat>(mesh.m_Region.getLowerCorner());

		*ptr = v3dFinalVertexPos.getX();
		ptr++;
		*ptr = v3dFinalVertexPos.getY();
		ptr++;
		*ptr = v3dFinalVertexPos.getZ();
		ptr++;

		*ptr = vertex.getNormal().getX();
		ptr++;
		*ptr = vertex.getNormal().getY();
		ptr++;
		*ptr = vertex.getNormal().getZ();
		ptr++;

		uint8_t material = static_cast<uint8_t>(vertex.getMaterial() + 0.5);

		OpenGLColour colour = convertMaterialIDToColour(material);

		*ptr = colour.red;
		ptr++;
		*ptr = colour.green;
		ptr++;
		*ptr = colour.blue;
		ptr++;
	}

	glUnmapBuffer(GL_ARRAY_BUFFER);

	return result;
}

void renderRegionVertexBufferObject(const OpenGLSurfaceMesh& openGLSurfaceMesh, unsigned int uLodLevel)
{
	int beginIndex = openGLSurfaceMesh.sourceMesh->m_vecLodRecords[uLodLevel].beginIndex;
	int endIndex = openGLSurfaceMesh.sourceMesh->m_vecLodRecords[uLodLevel].endIndex;
	glBindBuffer(GL_ARRAY_BUFFER, openGLSurfaceMesh.vertexBuffer);
	glVertexPointer(3, GL_FLOAT, 36, 0);
	glNormalPointer(GL_FLOAT, 36, (GLvoid*)12);
	glColorPointer(3, GL_FLOAT, 36, (GLvoid*)24);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, openGLSurfaceMesh.indexBuffer);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	//glDrawElements(GL_TRIANGLES, openGLSurfaceMesh.noOfIndices, GL_UNSIGNED_INT, 0);
	glDrawRangeElements(GL_TRIANGLES, beginIndex, endIndex-1, endIndex - beginIndex,/* openGLSurfaceMesh.noOfIndices,*/ GL_UNSIGNED_INT, 0);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}