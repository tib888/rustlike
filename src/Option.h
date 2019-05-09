#pragma once

#include <type_traits>
#include <functional>

template<typename T>
class Option
{
	//struct Option
private:
	bool _some;
	union {
		T _content;
	};

private:
	Option() :
		_some(false)
	{
	};

	Option(const T &content) :
		_some(true),
		_content(content)
	{
	};

public:
	~Option() 
	{
		if (is_some()) {
			_content.~T();
		}
	};

	//impl Option
public:
	static Option None() 
	{
		return Option();
	};

	static Option Some(const T &content) 
	{
		return Option(content);
	};

	//trait Option
public:
	//typedef T ContentType;

	bool is_some() const
	{
		return _some;
	}

public:
	template<typename U>
	Option<U> map(std::function<U(T)> func)
	{
		if (is_some())
		{
			return Option<U>::Some(func(_content));
		}
		return Option<U>::None();
	}

	template<typename U>
	Option<U> and_then(std::function<Option<U>(T)> func)	//= map_flat
	{
		if (is_some())
		{
			return func(&_content);
		}
		return Option<U>::None();
	}
};

//template<typename T, std::enable_if_t<std::is_pointer<T>::value>* = 0>
//class Option
//{
//	//struct Option
//private:
//	T _content;
//	
//private:
//	Option() :
//	_content(static_cast<T>(nullptr))
//	{
//	};
//
//	Option(const T content) :
//	_content(content)
//	{
//		assert(content != static_cast<T>(nullptr));
//	};
//
//	//impl Option
//public:
//	static Option None()
//	{
//		return Option<T>();
//	};
//
//	static Option Some(T content)
//	{
//		return Option(content);
//	};
//
//	//trait Option
//public:
//	//typedef T ContentType;
//
//	bool is_some() const
//	{
//		return _content != static_cast<T>(nullptr);
//	}
//
//	#include "Option.traitimpl"
//};
