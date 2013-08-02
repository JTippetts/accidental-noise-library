#include "OpenGLWidget.h"

#include <QMouseEvent>

using namespace PolyVox;
using namespace std;

OpenGLWidget::OpenGLWidget(QWidget *parent)
	:QGLWidget(parent)
	,m_xRotation(0)
	,m_yRotation(0)
{
}

void OpenGLWidget::setSurfaceMeshToRender(const PolyVox::SurfaceMesh<PositionMaterialNormal>& surfaceMesh)
{
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
}

void OpenGLWidget::setSurfaceMeshToRenderLowLOD(const PolyVox::SurfaceMesh<PositionMaterialNormal>& surfaceMesh)
{
	//Convienient access to the vertices and indices
	const vector<uint32_t>& vecIndices = surfaceMesh.getIndices();
	const vector<PositionMaterialNormal>& vecVertices = surfaceMesh.getVertices();

	//Build an OpenGL index buffer
	glGenBuffers(1, &indexBufferLow);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferLow);
	const GLvoid* pIndices = static_cast<const GLvoid*>(&(vecIndices[0]));		
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, vecIndices.size() * sizeof(uint32_t), pIndices, GL_STATIC_DRAW);

	//Build an OpenGL vertex buffer
	glGenBuffers(1, &vertexBufferLow);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferLow);
	const GLvoid* pVertices = static_cast<const GLvoid*>(&(vecVertices[0]));	
	glBufferData(GL_ARRAY_BUFFER, vecVertices.size() * sizeof(PositionMaterialNormal), pVertices, GL_STATIC_DRAW);

	m_uBeginIndexLow = 0;
	m_uEndIndexLow = vecIndices.size();
}

void OpenGLWidget::initializeGL()
{
	//We need GLEW to access recent OpenGL functionality
	std::cout << "Initialising GLEW...";
	GLenum result = glewInit();
	if (result == GLEW_OK)
	{
	  std::cout << "success" << std::endl;
	}
	else
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		std::cout << "failed" << std::endl;
		std::cout << "Initialising GLEW failed with the following error: " << glewGetErrorString(result) << std::endl;
		exit(EXIT_FAILURE);
	}
	
	//Print out some information about the OpenGL implementation.
	std::cout << "OpenGL Implementation Details:" << std::endl;
	if(glGetString(GL_VENDOR))
	  std::cout << "\tGL_VENDOR: " << glGetString(GL_VENDOR) << std::endl;
	if(glGetString(GL_RENDERER))
	  std::cout << "\tGL_RENDERER: " << glGetString(GL_RENDERER) << std::endl;
	if(glGetString(GL_VERSION))
	  std::cout << "\tGL_VERSION: " << glGetString(GL_VERSION) << std::endl;
	if(glGetString(GL_SHADING_LANGUAGE_VERSION))
	  std::cout << "\tGL_SHADING_LANGUAGE_VERSION: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	
	//Check our version of OpenGL is recent enough.
	//We need at least 1.5 for vertex buffer objects,
	if (!GLEW_VERSION_1_5)
	{
	  std::cout << "Error: You need OpenGL version 1.5 to run this example." << std::endl;
	  exit(EXIT_FAILURE);
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

	glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
}

void OpenGLWidget::resizeGL(int w, int h)
{
	//Setup the viewport
	glViewport(0, 0, w, h);

	//Set up the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float frustumSize = 32.0f; //Half the volume size
	float aspect = static_cast<float>(width()) / static_cast<float>(height());
	glOrtho(frustumSize*aspect, -frustumSize*aspect, frustumSize, -frustumSize, 1.0, 1000);
}

void OpenGLWidget::paintGL()
{
	//Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Set up the viewing transformation
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-100.0f); //Centre volume and move back
	glRotatef(-m_xRotation, 0.0f, 1.0f, 0.0f);
	glRotatef(-m_yRotation, 1.0f, 0.0f, 0.0f);
	glTranslatef(-32.0f,-32.0f,-32.0f); //Centre volume and move back

	//Bind the index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

	//Bind the vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexPointer(3, GL_FLOAT, sizeof(PositionMaterialNormal), 0);
	glNormalPointer(GL_FLOAT, sizeof(PositionMaterialNormal), (GLvoid*)12);

	glDrawRangeElements(GL_TRIANGLES, m_uBeginIndex, m_uEndIndex-1, m_uEndIndex - m_uBeginIndex, GL_UNSIGNED_INT, 0);

	//Bind the index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferLow);

	//Bind the vertex buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferLow);
	glVertexPointer(3, GL_FLOAT, sizeof(PositionMaterialNormal), 0);
	glNormalPointer(GL_FLOAT, sizeof(PositionMaterialNormal), (GLvoid*)12);

	glDrawRangeElements(GL_TRIANGLES, m_uBeginIndexLow, m_uEndIndexLow-1, m_uEndIndexLow - m_uBeginIndexLow, GL_UNSIGNED_INT, 0);
	
	GLenum errCode = glGetError();
	if(errCode != GL_NO_ERROR)
	{
	  //What has replaced getErrorString() in the latest OpenGL?
	  std::cout << "OpenGL Error: " << errCode << std::endl;
	}
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
