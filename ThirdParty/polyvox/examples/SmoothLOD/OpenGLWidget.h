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

#ifndef __BasicExample_OpenGLWidget_H__
#define __BasicExample_OpenGLWidget_H__

#include "PolyVoxCore/SurfaceMesh.h"

#include "glew/glew.h"

#include <QGLWidget>

class OpenGLWidget : public QGLWidget
{
public:
	//Constructor
	OpenGLWidget(QWidget *parent);

	//Mouse handling
	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);

	//Convert a SrfaceMesh to OpenGL index/vertex buffers
	void setSurfaceMeshToRender(const PolyVox::SurfaceMesh<PolyVox::PositionMaterialNormal>& surfaceMesh);
	void setSurfaceMeshToRenderLowLOD(const PolyVox::SurfaceMesh<PolyVox::PositionMaterialNormal>& surfaceMesh);

protected:
	//Qt OpenGL functions
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();

private:
	//Index/vertex buffer data
	GLuint m_uBeginIndex;
	GLuint m_uEndIndex;
	//GLuint noOfIndices;
	GLuint indexBuffer;
	GLuint vertexBuffer;

	GLuint m_uBeginIndexLow;
	GLuint m_uEndIndexLow;
	//GLuint noOfIndicesLow;
	GLuint indexBufferLow;
	GLuint vertexBufferLow;

	//Mouse data
	QPoint m_LastFrameMousePos;
	QPoint m_CurrentMousePos;
	int m_xRotation;
	int m_yRotation;
};

#endif //__BasicExample_OpenGLWidget_H__
