#ifndef CPP_ENUM_PARAM_H_
#	define CPP_ENUM_PARAM_H_

class Enums
{
public:
	enum COLOUR{GREEN=0,INVALID};
	Enums()
		:m_enum(INVALID)
	{}
	Enums(COLOUR e)
		:m_enum(e)
	{}
	COLOUR m_enum;
	void set_enum(COLOUR e)
	{
		m_enum = e;
	}
	COLOUR get_enum()
	{
		return m_enum;
	}
};

#endif

