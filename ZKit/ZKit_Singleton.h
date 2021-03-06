#ifndef _ZKit_Singleton_h_
#define _ZKit_Singleton_h_

#include "ZKit_Config.h"

BEGIN_ZKIT

template <class T> 
class Singleton  
{
public:
	static T* instance()
	{ 
		if ( 0 == s_instance )
		{
			s_instance = new T;
		}

		return s_instance;
	}

	static void unInstance()
	{
		if ( 0 != s_instance )
		{
			delete s_instance;
			s_instance = 0;
		}
	}

protected:
	Singleton() {}
	virtual ~Singleton() {}

private:
	Singleton(const Singleton<T> &); 
	Singleton<T>& operator= (const Singleton<T> &); 

	static T* s_instance;
};

template <class T>
T* Singleton<T>::s_instance = 0;

//////////////////////////////////////////////////////////////////////////
//用宏实现单件模式的代码重用, 可作为上面模板类的替代品
#define DECLARE_SINGLETON(Singleton) \
public:\
	static Singleton* Instance(){if (m_instance == 0)m_instance = new Singleton();return m_instance;}\
	static void Release(){delete m_instance;m_instance = 0;}\
private:\
	Singleton& operator=(const Singleton&);\
	Singleton(const Singleton&);\
	static Singleton* m_instance;

#define IMPLEMENT_SINGLETON(Singleton) Singleton* Singleton::m_instance = 0;

END_ZKIT

#endif // _ZKit_Singleton_h_
