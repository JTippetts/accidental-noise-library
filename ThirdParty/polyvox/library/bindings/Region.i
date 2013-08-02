%module Region
%{
#define SWIG_DAVID
#include "Region.h"
%}

%ignore depth;
%ignore height;
%ignore width;
%ignore dimensions;

%include "Region.h"