**********************
Tutorial 1 - Basic use
**********************

Introduction
============
This tutorial covers the basic use of the PolyVox API. After reading this tutorial you should have a good idea how to create a PolyVox volume and fill it with data, extract a triangle mesh representing the surface, and render the result. This tutorial assumes you are already familiar with the basic concepts behind PolyVox (see the :doc:`principles of polyvox <principles>` document if not), and are reasonably confident with 3D graphics and C++. It also assumes you have already got PolyVox installed on your system, if this is not the case then please consult :doc:`installation guide <install>`.

The code samples and text in this tutorial correspond directly to the BasicExample which comes with PolyVox. This example uses the Qt toolkit for window and input handling, and for providing an OpenGL context to render into. In this tutorial we will omit code which performs these tasks and will instead focus on on the PolyVox code. You can consult the `Qt documentation <http://doc.qt.nokia.com/latest/>`_ if you want more information about these other aspects of the system.

Creating a volume
=================
To get started, we need to include the following headers:

.. code-block:: c++

	#include "PolyVoxCore/CubicSurfaceExtractorWithNormals.h"
	#include "PolyVoxCore/MarchingCubesSurfaceExtractor.h"
	#include "PolyVoxCore/SurfaceMesh.h"
	#include "PolyVoxCore/SimpleVolume.h"

The most fundamental construct when working with PolyVox is that of the volume. This is represented by the :polyvox:`SimpleVolume` class which stores a 3D grid of voxels. Our basic example application creates a volume with the following line of code:

.. code-block:: c++

	SimpleVolume<uint8_t> volData(PolyVox::Region(Vector3DInt32(0,0,0), Vector3DInt32(63, 63, 63)));

As can be seen, the SimpleVolume class is templated upon the voxel type. This means it is straightforward to create a volume of integers, floats, or a custom voxel type (see the :polyvox:`SimpleVolume documentation <PolyVox::SimpleVolume>` for more details). In this particular case we have created a volume in which each voxel is of type `uint8_t` which is an unsigned 8-bit integer.

Next, we set some of the voxels in the volume to be 'solid' in order to create a large sphere in the centre of the volume. We do this with the following function call:

.. code-block:: c++

	createSphereInVolume(volData, 30);

Note that this function is part of the BasicExample (rather than being part of the PolyVox library) and is implemented as follows:
	
.. code-block:: c++
	
	void createSphereInVolume(SimpleVolume<uint8_t>& volData, float fRadius)
	{
		//This vector hold the position of the center of the volume
		Vector3DFloat v3dVolCenter(volData.getWidth() / 2, volData.getHeight() / 2, volData.getDepth() / 2);

		//This three-level for loop iterates over every voxel in the volume
		for (int z = 0; z < volData.getDepth(); z++)
		{
			for (int y = 0; y < volData.getHeight(); y++)
			{
				for (int x = 0; x < volData.getWidth(); x++)
				{
					//Store our current position as a vector...
					Vector3DFloat v3dCurrentPos(x,y,z);	
					//And compute how far the current position is from the center of the volume
					float fDistToCenter = (v3dCurrentPos - v3dVolCenter).length();

					uint8_t uVoxelValue = 0;

					//If the current voxel is less than 'radius' units from the center then we make it solid.
					if(fDistToCenter <= fRadius)
					{
						//Our new voxel value
						uVoxelValue = 255;
					}

					//Wrte the voxel value into the volume	
					volData.setVoxelAt(x, y, z, uVoxelValue);
				}
			}
		}
	}
	
This function takes as input the :polyvox:`SimpleVolume` in which we want to create the sphere, and also a radius specifying how large we want the sphere to be. In our case we have specified a radius of 30 voxels, which will fit nicely inside our :polyvox:`SimpleVolume` of dimensions 64x64x64.

Because this is a simple example function it always places the sphere at the centre of the volume. It computes this centre by halving the dimensions of the volume as given by the functions :polyvox:`SimpleVolume::getWidth`, :polyvox:`SimpleVolume::getHeight` and :polyvox:`SimpleVolume::getDepth`. The resulting position is stored using a :polyvox:`Vector3DFloat`. This is simply a typedef from our templatised :polyvox:`Vector` class, meaning that other sizes and storage types are available if you need them. 

Next, the function uses a three-level 'for' loop to iterate over each voxel in the volume. For each voxel it computes the distance from the voxel to the centre of the volume. If this distance is less than or equal to the specified radius then the voxel forms part of the sphere and is made solid. During surface extraction, the voxel will be considered empty if it has a value of zero, and otherwise it will be considered solid. In our case we simply set it to 255 which is the largest value a uint8_t can contain.

Extracting the surface
======================
Now that we have built our volume we need to convert it into a triangle mesh for rendering. This process can be performed by the :polyvox:`CubicSurfaceExtractorWithNormals` class. An instance of the :polyvox:`CubicSurfaceExtractorWithNormals` is created as follows:

.. code-block:: c++

	SurfaceMesh<PositionMaterialNormal> mesh;
	CubicSurfaceExtractorWithNormals< SimpleVolume<uint8_t> > surfaceExtractor(&volData, volData.getEnclosingRegion(), &mesh);

The :polyvox:`CubicSurfaceExtractorWithNormals` takes a pointer to the volume data, and also it needs to be told which :polyvox:`Region` of the volume the extraction should be performed on (in more advanced applications this is useful for extracting only those parts of the volume which have been modified since the last extraction). For our purpose the :polyvox:`SimpleVolume` class provides a convenient :polyvox:`SimpleVolume::getEnclosingRegion` function which returns a :polyvox:`Region` representing the whole volume. The constructor also takes a pointer to a :polyvox:`SurfaceMesh` object where it will store the result, so we need to create one of these before we can construct the :polyvox:`CubicSurfaceExtractorWithNormals`.

The actual extraction happens in the :polyvox:`CubicSurfaceExtractorWithNormals::execute` function. This means you can set up a :polyvox:`CubicSurfaceExtractorWithNormals` with the required parameters and then actually execute it later. For this example we just call it straight away.

.. code-block:: c++

	surfaceExtractor.execute();
	
This fills in our :polyvox:`SurfaceMesh` object, which basically contains an index and vertex buffer representing the desired triangle mesh.

Note: If you like you can try swapping the :polyvox:`CubicSurfaceExtractorWithNormals` for :polyvox:`MarchingCubesSurfaceExtractor`. We have already included the relevant header, and in the BasicExample you just need to change which line in commented out. The :polyvox:`MarchingCubesSurfaceExtractor` makes use of a smooth density field and will consider a voxel to be solid if it is above a threshold of half the voxel's maximum value (so in this case that's half of 255, which is 127).

Rendering the surface
=====================
Rendering the surface with OpenGL is handled by the OpenGLWidget class. Again, this is not part of PolyVox, it is simply an example based on Qt and OpenGL which demonstrates how rendering can be performed. Within this class there are mainly two functions which are of interest - the OpenGLWidget::setSurfaceMeshToRender() function which constructs OpenGL buffers from our :polyvox:`SurfaceMesh` and the OpenGLWidget::paintGL() function which is called each frame to perform the rendering.

The OpenGLWidget::setSurfaceMeshToRender() function is implemented as follows:

.. code-block:: c++

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
	
We begin by obtaining direct access to the index and vertex buffer in the :polyvox:`SurfaceMesh` class in order to make the following code slightly cleaner. Both the :polyvox:`SurfaceMesh::getIndices` and :polyvox:`SurfaceMesh::getVertices` functions return an std::vector containing the relevant data.

The OpenGL functions which are called to construct the index and vertex buffer are best explained by the OpenGL documentation. In both cases we are making an exact copy of the data stored in the :polyvox:`SurfaceMesh`.

The begin and end indices are used in the OpenGLWidget::paintGL() to control what part of the index buffer is actually rendered. For this simple example we will render the whole buffer from '0' to 'vecIndices.size()'.

With the OpenGL index and vertex buffers set up, we can now look at the code which is called each frame to render them:

.. code-block:: c++

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
		
		//Error checking code here...
	}
	
Again, the explanation of this code is best left to the OpenGL documentation. Note that is is called automatically by Qt each time the display needs to be updated.