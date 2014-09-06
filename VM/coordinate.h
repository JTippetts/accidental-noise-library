#ifndef COORDINATE_H
#define COORDINATE_H
#include "../types.h"

namespace anl
{
    struct CCoordinate
    {
        CCoordinate();
        CCoordinate(ANLFloatType x, ANLFloatType y);
        CCoordinate(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        CCoordinate(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        CCoordinate(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);
		CCoordinate(const CCoordinate &c);

        void set(ANLFloatType x, ANLFloatType y);
        void set(ANLFloatType x, ANLFloatType y, ANLFloatType z);
        void set(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w);
        void set(ANLFloatType x, ANLFloatType y, ANLFloatType z, ANLFloatType w, ANLFloatType u, ANLFloatType v);

        CCoordinate operator *(ANLFloatType rhs);
        CCoordinate operator *(CCoordinate &rhs);
        CCoordinate operator +(CCoordinate &rhs);
		CCoordinate &operator =(const CCoordinate &rhs);
		bool operator ==(const CCoordinate &rhs);

        ANLFloatType x_, y_, z_, w_, u_, v_;
        unsigned int dimension_;
    };
};

#endif
