#ifndef STRING_UTIL_H_LVD
#	define STRING_UTIL_H_LVD
#include <string>
#include <sstream>
#include <vector>

namespace STRING_UTIL
{
	inline std::string trim_right(std::string const &source , std::string const & t = " ")
	{
		//std::string str = source;
		//std::string::size_type sz = str.find_last_not_of(t);
		//if(sz == std::string::npos)return source;
		//return str.erase( str.find_last_not_of(t) + 1);
		return source.substr(0,source.find_last_not_of(t) +1);
	}

	inline std::string trim_left(std::string const & source, std::string const & t = " ")
	{
		std::string str = source;
		return str.erase(0 , source.find_first_not_of(t) );
		//return source.substr(source.find_first_not_of(t),source.size());
	}

	inline std::string trim(std::string const & source, std::string const & t = " ")
	{
		return trim_left( trim_right( source , t) , t );
	} 

	inline std::vector<std::string> split(std::string const& str, std::string const& delim)
	{
		using std::string;
		string::size_type start(0);
		string::size_type end(string::npos);
		std::vector<string> sub;

		while( (end = str.find(delim,start)) != string::npos)
		{
			if(end!=start)sub.push_back(str.substr(start, end - start));
			start = end + delim.size();
		}
		if(start < str.size() )sub.push_back(str.substr(start, str.size() - start));
		return sub;
	} 

	template<typename T>
	inline T extract_type(std::string const& str)
	{
		T t;
		std::stringstream ss;
		ss <<str;
		ss >>t;
		return t;
	}
	template<>
	inline std::string extract_type<std::string>(std::string const& str)
	{
		return std::string(str);
	}
}

#endif