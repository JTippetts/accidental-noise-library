# CImplicitCellular #

The CImplicitCellular module is intended to act as an adapter to a [CCellularGenerator](CCellularGenerator.md) module, taking the output of the generator (4 distance values and 4 ID numbers) and turning it into [Worley noise](http://en.wikipedia.org/wiki/Worley_noise). It does this by applying a coefficient to each of the 4 distance values, then returning the sum of all 4 components. The coefficients are commonly denoted F1, F2, F3 and F4. Some of the more particularly useful variants include:

(F1=1, F2=0, F3=0, F4=0)

```
celgen=anl.CCellularGenerator(anl.EUCLID)
cell=anl.CImplicitCellular(celgen, 1.0, 0.0, 0.0, 0.0)
```

![http://i.imgur.com/zBkKSkT.png](http://i.imgur.com/zBkKSkT.png)

(F1=0, F2=1, F3=0, F4=0)

```
celgen=anl.CCellularGenerator(anl.EUCLID)
cell=anl.CImplicitCellular(celgen, 0.0, 1.0, 0.0, 0.0)
```

![http://i.imgur.com/yRN7oeu.png](http://i.imgur.com/yRN7oeu.png)

(F1=-1, F2=1, F3=0, F4=0)

```
celgen=anl.CCellularGenerator(anl.EUCLID)
cell=anl.CImplicitCellular(celgen, -1.0, 1.0, 0.0, 0.0)
```

![http://i.imgur.com/1etesU6.png](http://i.imgur.com/1etesU6.png)

The function can additionally be customized by altering the distance function of the underlying generator. Here is a shot of (F1=-1, F2=1) using the Manhattan metric:

![http://i.imgur.com/S7eFYAd.png](http://i.imgur.com/S7eFYAd.png)

Here is one using the Greatest Axis metric:

![http://i.imgur.com/NjClmWv.png](http://i.imgur.com/NjClmWv.png)

And the Least Axis metric:

![http://i.imgur.com/k3RaxnP.png](http://i.imgur.com/k3RaxnP.png)