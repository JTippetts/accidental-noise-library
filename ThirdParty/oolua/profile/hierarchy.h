#ifndef PROFILE_HIERARCHY_H_
#	define PROFILE_HIERARCHY_H_

class ProfileBase
{
public:
	ProfileBase():_i(0){}
	virtual ~ProfileBase(){}
	void increment_a_base(ProfileBase* base)
	{
		++base->_i;
	}
	virtual void virtual_func()
	{
		++_i;
	}
	virtual void pure_virtual_func() = 0;
private:
	int _i;
};

class ProfileAnotherBase
{
public:
	virtual ~ProfileAnotherBase(){}
};
class ProfileDerived : public ProfileBase
{
public:
	virtual ~ProfileDerived(){}
	virtual void pure_virtual_func()
	{
		++_i;
	}
private:
	int _i;
};

class ProfileMultiBases : public ProfileDerived, public ProfileAnotherBase
{
public:
	void virtual_func()
	{
		++_i;
	}
private:
	int _i;
};

#endif
