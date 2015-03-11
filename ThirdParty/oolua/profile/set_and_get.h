#ifndef SET_AND_GET_H_
#	define SET_AND_GET_H_


class Set_get
{
public:
	Set_get():_i(0.0){}
	void set(double i)
	{
		_i = i;
	}
	double get()const
	{
		return _i;
	}
private:
	double _i;
};

#endif