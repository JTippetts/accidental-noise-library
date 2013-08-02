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

#include "OpenGLImmediateModeSupport.h"
#include "OpenGLSupport.h"

#include "PolyVoxCore/SurfaceMesh.h"

using namespace PolyVox;
using namespace std;

void renderRegionImmediateMode(PolyVox::SurfaceMesh<PositionMaterialNormal>& mesh, unsigned int uLodLevel)
{
	const vector<PositionMaterialNormal>& vecVertices = mesh.getVertices();
	const vector<uint32_t>& vecIndices = mesh.getIndices();

	int beginIndex = mesh.m_vecLodRecords[uLodLevel].beginIndex;
	int endIndex = mesh.m_vecLodRecords[uLodLevel].endIndex;

	glBegin(GL_TRIANGLES);
	//for(vector<PolyVox::uint32_t>::const_iterator iterIndex = vecIndices.begin(); iterIndex != vecIndices.end(); ++iterIndex)
	for(int index = beginIndex; index < endIndex; ++index)
	{
		const PositionMaterialNormal& vertex = vecVertices[vecIndices[index]];
		const Vector3DFloat& v3dVertexPos = vertex.getPosition();
		//const Vector3DFloat v3dRegionOffset(uRegionX * g_uRegionSideLength, uRegionY * g_uRegionSideLength, uRegionZ * g_uRegionSideLength);
		const Vector3DFloat v3dFinalVertexPos = v3dVertexPos + static_cast<Vector3DFloat>(mesh.m_Region.getLowerCorner());




		uint8_t material = static_cast<uint8_t>(vertex.getMaterial() + 0.5);

		OpenGLColour colour = convertMaterialIDToColour(material);

		glColor3f(colour.red, colour.green, colour.blue);
		glNormal3f(vertex.getNormal().getX(), vertex.getNormal().getY(), vertex.getNormal().getZ());
		glVertex3f(v3dFinalVertexPos.getX(), v3dFinalVertexPos.getY(), v3dFinalVertexPos.getZ());


	}
	glEnd();
}