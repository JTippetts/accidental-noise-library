#ifndef CPP_PUBLIC_INSTANCES_OOLUA_H_
#	define CPP_PUBLIC_INSTANCES_OOLUA_H_ 

#include "cpp_stub_classes.h"


class Public_variables
{
public:
	Public_variables();
	~Public_variables();
	int an_int;
	int* int_ptr;
	Stub1* dummy_instance;
	Stub1 dummy_instance_none_ptr;
	Stub1& dummy_ref;

	
	static const int set_value = 1;
	static const int initial_value = 0;
	
	
	Public_variables(Public_variables const&);
	Public_variables& operator = (Public_variables const& );
	
};



#endif
