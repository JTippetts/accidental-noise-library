# CImplicitCurve #

The CImplicitCurve module provides a means for mapping the output of a Noise function to an arbitrary curve. The curve is specified by designating points that map to the range (0,1). Output from the source module is used to interpolate the curve to determine the output of the function.

```
-- Lua
g=anl.CImplicitGradient(0,1,0,0)
c=anl.CImplicitCurve(g)

c:pushPoint(0,0.25)
c:pushPoint(0.5, 1)
c:pushPoint(1,0)
```

The above snippet remaps the output of a gradient function:

![http://i.imgur.com/QAAT8ca.png](http://i.imgur.com/QAAT8ca.png)

to the designated curve:

![http://i.imgur.com/c3wg5Mq.png](http://i.imgur.com/c3wg5Mq.png)

The second parameter passed to the constructor (or passed to the method **setInterpType()** ) chooses the type of interpolation to use when evaluating the curve, and is one of NONE, LINEAR, CUBIC or QUINTIC. The Same curve as above, evaluated using QUINTIC interpolation:

![http://i.imgur.com/oBwxBVd.png](http://i.imgur.com/oBwxBVd.png)