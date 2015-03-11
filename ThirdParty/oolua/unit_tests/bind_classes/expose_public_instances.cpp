#include "expose_public_instances.h"
#include "expose_stub_classes.h"

EXPORT_OOLUA_FUNCTIONS_3_NON_CONST(Public_variables,
								   set_an_int,
								   set_int_ptr,
								   set_dummy_instance)

EXPORT_OOLUA_FUNCTIONS_5_CONST(Public_variables,
							   get_an_int,
							   get_int_ptr,
							   get_dummy_instance,
							   get_dummy_ref,
							   get_dummy_instance_none_ptr)