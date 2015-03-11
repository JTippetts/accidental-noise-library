#ifndef CPP_PRIVATE_DESTRUCTOR_H_
#	define CPP_PRIVATE_DESTRUCTOR_H_

#	include "oolua.h"

struct PrivateDestructor
{
	void release()
	{
		delete this;
	}
	static PrivateDestructor* create()
	{
		return new PrivateDestructor;
	}
private:
	PrivateDestructor (PrivateDestructor const&);
	PrivateDestructor& operator =(PrivateDestructor const&);
	PrivateDestructor(){}
	~PrivateDestructor(){}
};


OOLUA_CLASS_NO_BASES(PrivateDestructor)
	OOLUA_TYPEDEFS
		No_public_constructors
		,No_public_destructor 
	OOLUA_END_TYPES
OOLUA_CLASS_END

#endif
