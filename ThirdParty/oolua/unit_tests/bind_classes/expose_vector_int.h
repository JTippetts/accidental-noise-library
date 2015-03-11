#ifndef EXPOSE_VECTOR_INT_H_
#	define EXPOSE_VECTOR_INT_H_

#	include <vector>
#	include "oolua.h"

///\remark typedef the type of vector into the global namespace
//This is required as a vector has more than one template type
//and the commas in the template confuse a macro.
typedef std::vector<int> vector_int;

OOLUA_CLASS_NO_BASES(vector_int)
	OOLUA_NO_TYPEDEFS
	OOLUA_ONLY_DEFAULT_CONSTRUCTOR
	OOLUA_MEM_FUNC_1(void ,push_back,vector_int::const_reference  )
	OOLUA_MEM_FUNC_0(void ,pop_back)
	OOLUA_MEM_FUNC_0_CONST(vector_int::size_type, size)
OOLUA_CLASS_END


#endif
