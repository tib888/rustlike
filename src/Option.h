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

#include "Option.traitimpl"
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
