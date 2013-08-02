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

#ifndef __PolyVox_OpenGLWidget_H__
#define __PolyVox_OpenGLWidget_H__

#include "glew/glew.h"

#include <QGLWidget>
#include <QTimer>

#include "PolyVoxCore/LargeVolume.h"
#include "PolyVoxCore/SurfaceMesh.h"
#include "PolyVoxCore/Impl/Utility.h"

#include "OpenGLImmediateModeSupport.h"
#include "OpenGLVertexBufferObjectSupport.h"
#include "Shapes.h"

const int32_t g_uVolumeSideLength = 128;

class OpenGLWidget : public QGLWidget
 {

 public:
     OpenGLWidget(QWidget *parent);

	 void setVolume(PolyVox::LargeVolume<PolyVox::MaterialDensityPair44>* volData);

	 void mouseMoveEvent(QMouseEvent* event);
	 void mousePressEvent(QMouseEvent* event);

 protected:
     void initializeGL();
     void resizeGL(int w, int h);
     void paintGL();

 private:
	 void setupProjectionMatrix(void);
	QPoint m_LastFrameMousePos;
	QPoint m_CurrentMousePos;

	int m_xRotation;
	int m_yRotation;

	QTimer *timer;

	 bool m_bUseOpenGLVertexBufferObjects;

	 //Creates a volume 128x128x128
	PolyVox::LargeVolume<PolyVox::MaterialDensityPair44>* m_volData;

	//Rather than storing one big mesh, the volume is broken into regions and a mesh is stored for each region
	std::map<PolyVox::Vector3DUint8, OpenGLSurfaceMesh> m_mapOpenGLSurfaceMeshes;
	std::map<PolyVox::Vector3DUint8, polyvox_shared_ptr<PolyVox::SurfaceMesh<PolyVox::PositionMaterialNormal> > > m_mapSurfaceMeshes;

	unsigned int m_uRegionSideLength;
	unsigned int m_uVolumeWidthInRegions;
	unsigned int m_uVolumeHeightInRegions;
	unsigned int m_uVolumeDepthInRegions;
 };

#endif //__PolyVox_OpenGLWidget_H__
