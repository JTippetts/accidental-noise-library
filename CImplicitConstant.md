# CImplicitConstant #

The CImplicitConstant module encapsulate a constant output. It is not technically required (as function inputs for other modules can default to constant values if no functional source is set); however, it does provide a point of visibility in larger function chains for setting and tweaking constants.

```
-- Lua
c=anl.CImplicitConstant(1.3)

// C++
anl::CImplicitConstant c(1.3);
```