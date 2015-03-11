#ifndef OPTIONS_H_LVD
#	define OPTIONS_H_LVD

#include <stdexcept>
#include <iostream>
#include <map>
#include <string>
#include "string_util.h"
#include <typeinfo>

namespace EXECUTABLE
{

	template<typename T>
	struct Option_value;

	struct Option
	{
		Option(std::string const& str)
			:_detail(str)
		{}
		virtual ~Option(){}
		virtual std::string const& detail()
		{
			return _detail;
		}
		template<typename T>
		T value()
		{
			Option_value<T>* option = dynamic_cast<Option_value<T>* >(this);
			if(!option)throw std::bad_cast();//"Option_value is incorrect type");
			return option->virtual_value();
		}
		virtual void show_value(std::ostream & s)  const = 0;
		virtual void value(std::string const& str) = 0;
		virtual Option* clone() const = 0;
	protected:
		std::string _detail;
	};

	template<typename T>
	struct Option_value : public Option
	{
		Option_value(std::string const& detail,T const& default_value)
			:Option(detail),_value(default_value)
		{}
		Option_value(Option_value const& rhs)
			:Option(rhs._detail),_value(rhs._value)
		{}
		void value(std::string const& str)
		{
			_value = STRING_UTIL::extract_type<T>(str);
		}
		void show_value(std::ostream & s) const
		{
			s <<"\tCurrent value:" <<_value <<std::endl;
		}
		virtual Option_value* clone() const
		{
			return new Option_value(*this);
		}
		T virtual_value() const
		{
			return _value;
		}
		protected:
		T _value;
	};

	struct Options
	{
		~Options()
		{
			for(iter it = table.begin(); it != table.end();++it)
			{
				delete it->second;
			}
		}
		bool process(int argc,char** argv)
		{
			//first arg is exe name
			for( int i = 1; i < argc;++i)
			{
				std::string key = STRING_UTIL::trim(argv[i]);
				if( key == "--help")
				{
					help();
					return false;
				}
				iter it = table.find(key);
				if( (i + 1) > argc)
				{
					std::cout <<"Options require a key and value. Key: " << key <<" provided but no value." <<std::endl;
					return false;
				}
				else if( it == table.end() )
				{
					std::cout <<"Error unknown program option :" << key <<std::endl;
					help();
					return false;
				}
				else
				{
					it->second->value( STRING_UTIL::trim(argv[++i]) );
				}
			}
			return true;
		}
		void help()
		{
			std::cout <<"\nProgram usage:\n"
				<<"--help : displays this menu\n"
				<<"When any option other than \"--help\" is provided to the executable,\n"
				<<"a value is required." <<std::endl;
			for(iter it = table.begin();it != table.end(); ++it)
			{
				std::cout <<it->first <<" : " <<it->second->detail() <<std::endl;
				it->second->show_value(std::cout);
			}

		}
		template<typename T>
		T value(std::string const& key)
		{
			iter it = table.find(key);
			if(it == table.end())throw std::runtime_error("key not found in Options::table");
			return it->second->value<T>();
		}
		void add (std::string const& key, Option const& opt)
		{
			iter it = table.find(key);
			if( it != table.end() )
			{
				delete it->second ;
				it->second = opt.clone();
			}
			else
			{
				table.insert(std::make_pair(key,opt.clone()));
			}
		}
	private:
		typedef std::map<std::string,Option*> Table;
		typedef Table::iterator iter;
		Table table;
	};

}

#endif
