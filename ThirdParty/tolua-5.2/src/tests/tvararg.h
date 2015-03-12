#include <stdio.h>

struct B
{
  static int n;
  B() {++n; }
  ~B() {--n; }
};

class A
{
  double v[3];
public:
  A() { v[0]=1.0; v[1]=2.0; v[2]=3.0;}
  double get (int i) 
  {
    return v[i];
  }
  int bounce (int i, int* j, int* k)
  {
    *k = i;
    return i;
  }
  double add (lua_State* L)
  {
    double a = 0.0;
    int n=2;
    while (lua_isnumber(L, n)) {
      a += lua_tonumber(L, n);
      ++n;
    }
    return a;
  }
  B* GetB ()
  {
    return new B();
  }
};
