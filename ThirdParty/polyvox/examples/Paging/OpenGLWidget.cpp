#include "OpenGLWidget.h"

#include <QMouseEvent>

using namespace PolyVox;
using namespace std;

OpenGLWidget::OpenGLWidget(QWidget *parent)
	:QGLWidget(parent)
	,m_uBeginIndex(0)
	,m_uEndIndex(0)
	,noOfIndices(0)
	,m_xRotation(0)
	,m_yRotation(0)
{
}

void OpenGLWidget::setSurfaceMeshToRender(const PolyVox::SurfaceMesh<PositionMaterialNormal>& surfaceMesh)
{
	if((surfaceMesh.getNoOfIndices() == 0) || (surfaceMesh.getNoOfVertices() == 0))
	{
		//We don't have a valid mesh
		return;
	}

	//Convienient access to the vertices and indices
	const vector<uint32_t>& vecIndices = surfaceMesh.getIndices();
	const vector<PositionMaterialNormal>& vecVertices = surfaceMesh.getVertices();

	//Build an OpenGL index buffer
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	const GLvoid* pIndices = static_cast<const GLvoid*>(&(vecIndices[0]));		
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, vecIndices.size() * sizeof(uint32_t), pIndices, GL_STATIC_DRAW);

	//Build an OpenGL vertex buffer
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	const GLvoid* pVertices = static_cast<const GLvoid*>(&(vecVertices[0]));	
	glBufferData(GL_ARRAY_BUFFER, vecVertices.size() * sizeof(PositionMaterialNormal), pVertices, GL_STATIC_DRAW);

	m_uBeginIndex = 0;
	m_uEndIndex = vecIndices.size();
	noOfIndices = surfaceMesh.getNoOfIndices();
}

void OpenGLWidget::initializeGL()
{
	//We need GLEW to access recent OpenGL functionality
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		std::cout << "GLEW Error: " << glewGetErrorString(err) << std::endl;
	}

	//Set up the clear colour
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		
	glClearDepth(1.0f);		

	//Enable the depth buffer
	glEnable(GL_DEPTH_TEST);					
	glDepthFunc(GL_LEQUAL);						

	//Anable smooth lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);

	//We'll be rendering with index/vertex arrays
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
}

void OpenGLWidget::resizeGL(int w, int h)
{
	//Setup the viewport
	glViewport(0, 0, w, h);

	//Set up the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float frustumSize = 128.0f * 1.7f; //Half the volume diagonal
	float aspect = static_cast<float>(width()) / static_cast<float>(height());
	glOrtho(frustumSize*aspect, -frustumSize*aspect, frustumSize, -frustumSize, 10.0, 10000);
}

void OpenGLWidget::paintGL()
{
	if(noOfIndices == 0)
	{
		//Nothing to render
		return;
	}

	//Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Set up the viewing transformation
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-5000.0f); //Centre volume and move back
	glRotatef(m_xRotation, 1.0f, 0.0f, 0.0f);
	glRotatef(m_yRotation, 0.0f, 1.0f, 0.0f);
	glTranslatef(-128.0f,-128.0f,-128.0f); //Centre volume and move back

	//Bind the index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

	//Bind the vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexPointer(3, GL_FLOAT, sizeof(PositionMaterialNormal), 0);
	glNormalPointer(GL_FLOAT, sizeof(PositionMaterialNormal), (GLvoid*)12);

	glDrawRangeElements(GL_TRIANGLES, m_uBeginIndex, m_uEndIndex-1, m_uEndIndex - m_uBeginIndex, GL_UNSIGNED_INT, 0);
}

void OpenGLWidget::mousePressEvent(QMouseEvent* event)
{
	m_CurrentMousePos = event->pos();
	m_LastFrameMousePos = m_CurrentMousePos;

	update();
}

void OpenGLWidget::mouseMoveEvent(QMouseEvent* event)
{
	m_CurrentMousePos = event->pos();
	QPoint diff = m_CurrentMousePos - m_LastFrameMousePos;
	m_xRotation += diff.x();
	m_yRotation += diff.y();
	m_LastFrameMousePos = m_CurrentMousePos;

	update();
}
