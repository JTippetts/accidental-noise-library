#ifndef CPP_PUSH_H_
#	define CPP_PUSH_H_

/*
class Push
{
public:
	Push():i_(0),pc_int(new int(0)){}
	~Push(){delete pc_int;}
	Push& ref(){return *this;}
	Push const & ref_const(){return *this;}
	Push* ptr(){return this;}
	Push const* ptr_const(){return this;}
*/
	//TODO why is this commented out?
//	Push const* /*const*/ const_ptr_const(){return this;}
/*
 void const_func()const{}

	int int_value(){return i_;}
	int& int_ref(){return i_;}
	int* int_ptr(){return &i_;}
	int const& int_ref_const(){return i_;}
	int const *const& int_ref_const_ptr_const(){return pc_int;}
	int const*& int_ref_ptr_const(){return pc_int;}
	int i_;
	Push(Push const & );
	Push& operator=(Push const&);
private:
	int const* pc_int;
};
*/

#endif//CPP_PUSH_H_
