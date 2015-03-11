
#ifndef CPP_CLASS_OPS_TEST_H_
#	define CPP_CLASS_OPS_TEST_H_


class Class_ops
{
public:
	Class_ops(int const & i ):m_i(i){}
	Class_ops():m_i(0){}
	Class_ops( Class_ops const& rhs)
        :m_i(rhs.m_i)
	{}
	
	int const& geti()const
	{
		return m_i;
	}
	bool operator == (Class_ops const& rhs)const
	{
		return m_i == rhs.m_i;
	}
	bool operator < (Class_ops const& rhs)const
	{
		return m_i < rhs.m_i;
	}
	bool operator <= (Class_ops const& rhs)const
	{
		return m_i <= rhs.m_i;
	}
	Class_ops operator + (Class_ops const& rhs)const
	{
		return Class_ops( m_i + rhs.m_i );
	}
	Class_ops operator * (Class_ops const& rhs)const
	{
		return Class_ops(m_i * rhs.m_i);
	}
	Class_ops operator - (Class_ops const& rhs)const
	{
		return Class_ops(m_i - rhs.m_i);
	}
	Class_ops operator / (Class_ops const& rhs)const
	{
		return Class_ops(m_i / rhs.m_i);
	}
private:
	int m_i;
};

#endif
