#ifndef CPP_STATIC_AND_C_FUNCTIONS_H_
#	define CPP_STATIC_AND_C_FUNCTIONS_H_

class ClassHasStaticFunction
{
public:
	static void static_function(){}
	static void static_function(int){}
	static int returns_input(int t){return t;}
};


#endif
