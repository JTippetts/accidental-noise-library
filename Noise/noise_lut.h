// Lookup tables for 2D, 4D and 6D gradient oise.
// Generated with boost::random, using a lagged Fibonacci generator and a uniform_on_sphere distribution.
#include "../types.h"

extern ANLFloatType gradient2D_lut[256][2];
extern ANLFloatType gradient3D_lut[256][3];
extern ANLFloatType gradient4D_lut[256][4];
extern ANLFloatType gradient6D_lut[256][6];
extern ANLFloatType whitenoise_lut[256];
