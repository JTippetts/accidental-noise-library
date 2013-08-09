-- Accidental Noise Library
-- Block World Example

-- Implements a large block world of varied terrain. Terrain is generated in chunks
-- sized chunkwidth, chunkheight, chunkdepth, and world is comprised of a nearly-infinite
-- layer of chunks in X and Z

-- Since the framework has no true visualization foundation, this example exports
-- chunks as a set of Wavefront .OBJ format files, each file named according to the
-- block type it represents.

chunkwidth, chunkheight, chunkdepth=64,256,64

-- Block types
blocktypes=
{
	Air=0,
	Grass=1,
	Dirt=2,
	Sand=3,   -- Currently not used
	Water=4,  -- Currently not used
	Stone=5,
	Obsidian=6,
	Gold=7,
	Iron=8,
	Bedrock=9,
	Lava=10
}


function eliminate_block_type(chunk, type)
	-- Iterate a chunk array and eliminate all blocks of type, setting them to 
	-- Air type.
	local w,h,d=chunk:width(), chunk:height(), chunk:depth()
	
	local x,y,z
	for x=0,w-1,1 do
		for y=0,h-1,1 do
			for z=0,d-1,1 do
				local v=chunk:get(x,y,z)
				if v==type then chunk:set(x,y,z,blocktypes.Air) end
			end
		end
	end
end

function export_block_meshes(chunk, chunkx, chunkz)
	-- Iterate a generated chunk and save out meshes for the various block types.
	
	anl.marchDensityFieldCubeOBJ(chunk, blocktypes.Lava, "lava_"..chunkx.."x"..chunkz..".obj")
	eliminate_block_type(chunk, blocktypes.Lava)
	
	anl.marchDensityFieldCubeOBJ(chunk, blocktypes.Bedrock, "bedrock_"..chunkx.."x"..chunkz..".obj")
	eliminate_block_type(chunk, blocktypes.Bedrock)
	
	anl.marchDensityFieldCubeOBJ(chunk, blocktypes.Iron, "iron_"..chunkx.."x"..chunkz..".obj")
	eliminate_block_type(chunk, blocktypes.Iron)
	
	anl.marchDensityFieldCubeOBJ(chunk, blocktypes.Gold, "gold_"..chunkx.."x"..chunkz..".obj")
	eliminate_block_type(chunk, blocktypes.Gold)
	
	anl.marchDensityFieldCubeOBJ(chunk, blocktypes.Obsidian, "obsidian_"..chunkx.."x"..chunkz..".obj")
	eliminate_block_type(chunk, blocktypes.Obsidian)
	
	anl.marchDensityFieldCubeOBJ(chunk, blocktypes.Stone, "stone_"..chunkx.."x"..chunkz..".obj")
	eliminate_block_type(chunk, blocktypes.Stone)
	
	anl.marchDensityFieldCubeOBJ(chunk, blocktypes.Water, "water_"..chunkx.."x"..chunkz..".obj")
	eliminate_block_type(chunk, blocktypes.Water)
	
	anl.marchDensityFieldCubeOBJ(chunk, blocktypes.Sand, "sand_"..chunkx.."x"..chunkz..".obj")
	eliminate_block_type(chunk, blocktypes.Sand)
	
	anl.marchDensityFieldCubeOBJ(chunk, blocktypes.Dirt, "dirt_"..chunkx.."x"..chunkz..".obj")
	eliminate_block_type(chunk, blocktypes.Dirt)
	
	anl.marchDensityFieldCubeOBJ(chunk, blocktypes.Grass, "grass_"..chunkx.."x"..chunkz..".obj")
end

function build_chunk(chunkx, chunkz, terrainfunc)
	-- Build a chunk using the given (chunkx, chunkz) index
	
	local range=anl.SMappingRanges(chunkx*chunkwidth, chunkx*chunkwidth+chunkwidth-1, 0, chunkheight-1, chunkz*chunkdepth, chunkz*chunkdepth+chunkdepth-1)
	local terrainadapter=anl.CVolumeAdapter(terrainfunc, anl.SEAMLESS_NONE, range)
	local chunk=anl.CArray3Dd()
	chunk:resize(chunkwidth, chunkheight, chunkdepth)
	terrainadapter:get(chunk)
	
	return chunk
end

-- Terrain Function

-- Main gradient; maps to the Y coordinate of a chunk. Creates a gradient that evaluates to 0 at the top of the chunk
-- and 1 at the bottom.
gradient=anl.CImplicitGradient(0,0,chunkheight-1,0,0,0)


-- Elevation function
-- Creates a fractal, scales it up and applies a "twistiness" factor. Twistiness determines
-- how turbulently the elevation function is allowed to modify the gradient.
-- The twistiness function is then used to translate the domain of the gradient function to create
-- the noiseified strata of the function

elev=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 8, (1/chunkwidth)*2, true)
elevscale=anl.CImplicitScaleOffset(elev, chunkwidth, 0.0)
twistiness=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 4, (1/chunkwidth)*0.25, true)
twistinessac=anl.CImplicitAutoCorrect(twistiness, 0.25, 0.5)
twistcache=anl.CImplicitCache(twistinessac)
applytwist=anl.CImplicitScaleDomain(elevscale, 1.0, twistcache, 1.0)

gradturb=anl.CImplicitTranslateDomain(gradient,0.0,applytwist,0.0)
grad=anl.CImplicitCache(gradturb)

-- Ore deposits

-- Iron occurs from 0.6 to 0.85
-- Gold occurs from 0.75 to 0.9

-- Remap the perturbed gradient for iron. Clamp the remap and multiply it against a distribution fractal.
-- Apply a select function against the deposit map, and select between stone and iron types.
ironremap=anl.CImplicitScaleOffset(grad, 0.25, 0.6)
ironclamp=anl.CImplicitClamp(ironremap,0,1)
ironfractal=anl.CImplicitFractal(anl.FBM, anl.GRADIENT, anl.QUINTIC, 2, (1/chunkwidth)*6, true)
irondeposit=anl.CImplicitMath(anl.MULTIPLY, ironclamp, ironfractal)
ironsel=anl.CImplicitSelect(blocktypes.Stone, blocktypes.Iron, irondeposit, 0.45, 0)

-- Remap gradient for gold, clamp and multiply against another distribution fractal.
-- Select between the iron selector and the Gold type.

goldremap=anl.CImplicitScaleOffset(grad, 0.15, 0.75)
goldclamp=anl.CImplicitClamp(goldremap,0,1)
goldfractal=anl.CImplicitFractal(anl.RIDGEDMULTI, anl.GRADIENT, anl.QUINTIC, 3, (1/chunkwidth)*2, true)
goldfractalac=anl.CImplicitAutoCorrect(goldfractal,0,1)
golddeposit=anl.CImplicitMath(anl.MULTIPLY, goldclamp, goldfractalac)
goldsel=anl.CImplicitSelect(ironsel, blocktypes.Gold, golddeposit, 0.75, 0)


-- Build selectors to map ranges of the perturbed gradient to strata types.

grasssel=anl.CImplicitSelect(blocktypes.Air, blocktypes.Grass, grad, 0.5, 0)
dirtsel=anl.CImplicitSelect(grasssel, blocktypes.Dirt, grad, 0.51, 0)
stonesel=anl.CImplicitSelect(dirtsel, goldsel, grad, 0.6, 0)
obsidiansel=anl.CImplicitSelect(stonesel, blocktypes.Obsidian, grad, 0.85, 0)
bedrocksel=anl.CImplicitSelect(obsidiansel, blocktypes.Bedrock, grad, 0.94, 0)

-- Set up an attenutation factor to scale off the caves as they near the surface.
caveattenuate=anl.CImplicitScaleOffset(grad, 0.65, 0.0)
caveattenuateclamp=anl.CImplicitClamp(caveattenuate, 0.0, 1.0)

-- Caves are done as 2 ridged multi-fractal, single-octave noise functions multiplied by the attenuation function, then
-- used to select between open and solid. They are then multiplied together. This multiplied function is then called
-- from another domain translation unit that applies the twisting turbulence that forms the shape of the ground.

caverm1=anl.CImplicitFractal(anl.RIDGEDMULTI, anl.GRADIENT, anl.QUINTIC, 1, (1/chunkwidth)*2, true)
caveac1=anl.CImplicitAutoCorrect(caverm1, 0, 1)
caveatten1=anl.CImplicitMath(anl.MULTIPLY, caveac1, caveattenuateclamp)
cavesel1=anl.CImplicitSelect(0,1,caveatten1,0.3,0)

caverm2=anl.CImplicitFractal(anl.RIDGEDMULTI, anl.GRADIENT, anl.QUINTIC, 1, (1/chunkwidth)*2, true)
caveac2=anl.CImplicitAutoCorrect(caverm2, 0, 1)
caveatten2=anl.CImplicitMath(anl.MULTIPLY, caveac2, caveattenuateclamp)
cavesel2=anl.CImplicitSelect(0,1,caveac2,0.3,0)

cavemul=anl.CImplicitMath(anl.MULTIPLY, cavesel1, cavesel2)

caveturb=anl.CImplicitTranslateDomain(cavemul,0.0,applytwist,0.0)


-- Caves in the Obsidian and lower regions are filled with magma, so set up a selection that uses the perturbed gradient to
-- select between lava and air.

lavaselect=anl.CImplicitSelect(blocktypes.Air, blocktypes.Lava, grad, 0.86, 0.0)


-- The final function selectis between cave and not-cave using the caveturb function.
cave=anl.CImplicitSelect(bedrocksel, lavaselect, caveturb, 0.5, 0)

-- A helper function for visualizing the caves as a solid cube structure.
cavevis=anl.CImplicitSelect(blocktypes.Air, blocktypes.Stone, caveturb, 0.5, 0)

-- The bottom-most layer of the world is solid bedrock, to keep people from digging through to the abyss. Set
-- up a select function that uses the base, non-perturbed, gradient with a high threshold to select for the last row
-- being bedrock.
bedrockclamp=anl.CImplicitSelect(cave, blocktypes.Bedrock, gradient, 0.996, 0)


-- Change this seed to generate a new world
seed=10456


caverm1:setSeed(seed+10)
caverm2:setSeed(seed+20)
elev:setSeed(seed+30)
goldfractal:setSeed(seed+40)
ironfractal:setSeed(seed+50)
twistiness:setSeed(seed+60)

-- The world is split into chunks, each chunk sized (chunkwidth, chunkheight, chunkdepth)
-- This pair of values denotes the chunk coordinate to generate.
chunkx,chunkz=4000, 2331

-- Call build_chunk with the final function and the chunk coordinates to generate the chunk at (chunkx, chunkz)
local chunk=build_chunk(chunkx,chunkz, bedrockclamp)

-- Export the block type meshes sequentially to .OBJ files. Files will be saved as <terraintype>_<chunkx>x<chunkz>.obj in the
-- execution directory.
export_block_meshes(chunk,chunkx,chunkz)