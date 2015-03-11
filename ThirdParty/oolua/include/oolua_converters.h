#ifndef OOLUA_CONVERTORS_H_
#	define OOLUA_CONVERTORS_H_

#	include <string> //used for C style strings

namespace OOLUA
{
	namespace INTERNAL 
	{
	template<typename Pull_type,typename Real_type>struct Converter;
	
	template<typename T>
	struct Converter<T*,T&>
	{
		Converter(T*& t):m_t(t){}
		operator T& () const
		{
			return *m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T* m_t;
	};
	
	
	template<typename T>
	struct Converter<T*,T>
	{
		Converter(T* t):m_t(t){}
		operator T& () const
		{
			return *m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T* m_t;
	};
	
	template<typename T>
	struct Converter<T,T*>
	{
		Converter(T& t):m_t(t){}
		operator T* () const
		{
			return &m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T& m_t;
	};
	
		
	template<typename T>
	struct Converter<T*,T*&>
	{
		Converter(T*& t):m_t(t){}//added reference
		operator T*& () //const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T*& m_t;//added reference
	};
	
		
	template<typename T>
	struct Converter<T*,T const&>
	{
		Converter(T* t):m_t(t){}
		operator T const&() const
		{
			return *m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T* m_t;
	};
	
	template<typename T>
	struct Converter<T*,T const*&>
	{
		Converter(T* t):m_t(t){}
		operator T const*&()
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T const* m_t;
	};
	
	template<typename T>
	struct Converter<T*,T const*>
	{
		Converter(T* t):m_t(t){}
		operator T const*() const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T* m_t;
	};
	
	template<typename T>
	struct Converter<T,T*const&>
	{
		Converter(T & t):m_t(t){}
		operator T* /*const*/  () const
		{
			return &m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T & m_t;
	};
	
	template<typename T>
	struct Converter<T,T const*&>
	{
		Converter(T & t):m_t(&t){}
		operator T const*&()
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T const* m_t;
	};
	template<typename T>
	struct Converter<T,T const *const &>
	{
		Converter(T& t):m_t(&t){}
		operator T*const &() const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T* m_t;
	};
	template<typename T>
	struct Converter<T*,T *const&>
	{
		Converter(T* t):m_t(t){}
		operator T *const&() const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T* m_t;
	};
	template<typename T>
	struct Converter<T*,T const*const&>
	{
		Converter(T* t):m_t(t){}
        operator T const * /*const*/() const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T* m_t;
	};
	template<typename T>
	struct Converter<T*,T const*const>
	{
		Converter(T* t):m_t(t){}
		operator T const * /*const*/() const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T* m_t;
	};
	template<typename T>
	struct Converter<T*,T*>
	{
		Converter(T* t):m_t(t){}
		operator T* () const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T* m_t;
	};
	
	template<typename T>
	struct Converter<T,T>
	{
		Converter(T& t):m_t(t){}
		operator T& () const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T& m_t;
	};
	template<typename T>
	struct Converter<T,T&>
	{
		Converter(T& t):m_t(t){}
		operator T& () const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T& m_t;
	};
	template<typename T>
	struct Converter<T,T*&>
	{
		Converter(T& t):m_t(&t){}
		operator T*& ()
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T* m_t;
	};
	template<typename T>
	struct Converter<T,T const&>
	{
		Converter(T& t):m_t(t){}
		operator T const& () const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T& m_t;
	};
	
	template<typename T>
	struct Converter<T*,T *const>
	{
		Converter(T* t):m_t(t){}
		operator T * () const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T* m_t;
	};
	template<typename T>
	struct Converter<T const*,T const*&>
	{
		Converter(T const*& t):m_t(t){}//added ref
		operator T const*&()
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T const*& m_t;//added ref
	};
	
	
	template<typename T>
	struct Converter<T,T const>
	{
		Converter(T& t):m_t(t){}
		operator T () const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T const & m_t;
	};
	
	template<typename T>
	struct Converter<T,T const*>
	{
		Converter(T & t):m_t(&t){}
		operator T const*&()
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T const* m_t;
	};
	template<typename T>
	struct Converter<T,T const *const>
	{
		Converter(T& t):m_t(&t){}
		operator T*const &() const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		T* m_t;
	};
	
	
	///////////////////////////////////////////////////////////////////////////////
	///  Specialisation for C style strings
	///////////////////////////////////////////////////////////////////////////////
	template<>
	struct Converter<std::string,char *>
	{
		Converter(std::string & t):m_t(&t[0]){}
		operator char * () const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		char * m_t;
	};
	

	template<>
	struct Converter<std::string,char const*>
	{
		Converter(std::string const& t):m_t(t.c_str()){}
		operator char const* () const
		{
			return m_t;
		}
		Converter& operator =(Converter const &);
		Converter(Converter const &);
		char const* m_t;
	};
	
	}

}

#endif
