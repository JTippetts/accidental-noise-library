**********************
Principles of PolyVox
**********************

.. warning ::
	This section is being written and is just a skeleton for now

PolyVox provides a library for managing 3D arrays (volumes) of data (voxels). It gives you the tools to iterate through, randomly access, read and write volumes. It supports any type you'd like to represent each voxel whether it's just an ``int`` or a class which encapsulates both density and colour.

Once you have a volume, PolyVox provides a number of tools for turning it into something that you can pass to your rendering engine. These are called `surface extractors`.

Each surface extractor needs to be told how to interperet your voxel type and that is done using...

Link to a page describing how to write your own voxel type and link it to a surface extractor...
