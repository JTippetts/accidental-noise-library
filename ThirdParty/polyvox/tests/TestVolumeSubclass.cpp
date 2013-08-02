/*******************************************************************************
Copyright (c) 2010 Matt Williams

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

#include "TestVolumeSubclass.h"

#include "PolyVoxCore/Array.h"
#include "PolyVoxCore/BaseVolume.h"
#include "PolyVoxCore/CubicSurfaceExtractor.h"
#include "PolyVoxCore/Material.h"
#include "PolyVoxCore/Vector.h"

#include <QtTest>

using namespace PolyVox;

template <typename VoxelType>
class VolumeSubclass : public BaseVolume<VoxelType>
{
public:
	//There seems to be some descrepency between Visual Studio and GCC about how the following class should be declared.
	//There is a work around (see also See http://goo.gl/qu1wn) given below which appears to work on VS2010 and GCC, but
	//which seems to cause internal compiler errors on VS2008 when building with the /Gm 'Enable Minimal Rebuild' compiler
	//option. For now it seems best to 'fix' it with the preprocessor insstead, but maybe the workaround can be reinstated
	//in the future
	//typedef BaseVolume<VoxelType> VolumeOfVoxelType; //Workaround for GCC/VS2010 differences. See http://goo.gl/qu1wn
	//class Sampler : public VolumeOfVoxelType::template Sampler< VolumeSubclass<VoxelType> >
	#if defined(_MSC_VER)
		class Sampler : public BaseVolume<VoxelType>::Sampler< VolumeSubclass<VoxelType> > //This line works on VS2010
	#else
		class Sampler : public BaseVolume<VoxelType>::template Sampler< VolumeSubclass<VoxelType> > //This line works on GCC
	#endif
	{
	public:
		Sampler(VolumeSubclass<VoxelType>* volume)
			:BaseVolume<VoxelType>::template Sampler< VolumeSubclass<VoxelType> >(volume)
		{
			this->mVolume = volume;
		}
		//~Sampler();
	};

	/// Constructor for creating a fixed size volume.
	VolumeSubclass(const Region& regValid)
		:BaseVolume<VoxelType>(regValid)
	{
		mVolumeData.resize(ArraySizes(this->getWidth())(this->getHeight())(this->getDepth()));
	}
	/// Destructor
	~VolumeSubclass() {};

	/// Gets the value used for voxels which are outside the volume
	VoxelType getBorderValue(void) const { return 0; }
	/// Gets a voxel at the position given by <tt>x,y,z</tt> coordinates
	VoxelType getVoxelAt(int32_t uXPos, int32_t uYPos, int32_t uZPos) const
	{
		if(this->m_regValidRegion.containsPoint(Vector3DInt32(uXPos, uYPos, uZPos)))
		{
			return mVolumeData[uXPos][uYPos][uZPos];
		}
		else
		{
			return getBorderValue();
		}
	}
	/// Gets a voxel at the position given by a 3D vector
	VoxelType getVoxelAt(const Vector3DInt32& v3dPos) const { return getVoxelAt(v3dPos.getX(), v3dPos.getY(), v3dPos.getZ()); }

	/// Sets the value used for voxels which are outside the volume
	void setBorderValue(const VoxelType& tBorder) { }
	/// Sets the voxel at the position given by <tt>x,y,z</tt> coordinates
	bool setVoxelAt(int32_t uXPos, int32_t uYPos, int32_t uZPos, VoxelType tValue)
	{
		if(this->m_regValidRegion.containsPoint(Vector3DInt32(uXPos, uYPos, uZPos)))
		{
			mVolumeData[uXPos][uYPos][uZPos] = tValue;
			return true;
		}
		else
		{
			return false;
		}
	}
	/// Sets the voxel at the position given by a 3D vector
	bool setVoxelAt(const Vector3DInt32& v3dPos, VoxelType tValue) { return setVoxelAt(v3dPos.getX(), v3dPos.getY(), v3dPos.getZ(), tValue); }

	/// Calculates approximatly how many bytes of memory the volume is currently using.
	uint32_t calculateSizeInBytes(void) { return 0; }

	/// Deprecated - I don't think we should expose this function? Let us know if you disagree...
	//void resize(const Region& regValidRegion);

private:	
	Array<3, VoxelType> mVolumeData;
};

void TestVolumeSubclass::testExtractSurface()
{
	VolumeSubclass<Material8> volumeSubclass(Region(0,0,0,16,16,16));

	for(int32_t z = 0; z < volumeSubclass.getDepth() / 2; z++)
	{
		for(int32_t y = 0; y < volumeSubclass.getHeight(); y++)
		{
			for(int32_t x = 0; x < volumeSubclass.getWidth(); x++)
			{
				Material8 mat(1);
				volumeSubclass.setVoxelAt(Vector3DInt32(x,y,z),mat);
			}
		}
	}

	SurfaceMesh<PositionMaterial> result;
	CubicSurfaceExtractor< VolumeSubclass<Material8> > cubicSurfaceExtractor(&volumeSubclass, volumeSubclass.getEnclosingRegion(), &result);
	cubicSurfaceExtractor.execute();

	QCOMPARE(result.getNoOfVertices(), static_cast<uint32_t>(8));
}

QTEST_MAIN(TestVolumeSubclass)
