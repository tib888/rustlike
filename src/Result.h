#pragma once

template<typename R, typename E>
class Result
{
	//struct Result
private:
	bool _ok;
	union {
		R _result;
		E _error;
	};

private:
	Result(const R &result) :
		_ok(true),
		_result(result)
	{
	};

	Result(const E &error, bool dummy) :	//dummy is here because R and E may be the same.
		_ok(false),
		_error(error)
	{
	};

public:
	~Result()
	{
		if (is_ok()) 
		{
			_result.~R();
		}
		else 
		{
			_error.~E();
		}
	};

	bool is_ok() const { return _ok; }
	bool is_err() const { return !_ok; }

	//impl Result
public:
	static Result Err(const E &error)
	{
		return Result(error, false);
	};

	static Result Ok(const R &result)
	{
		return Result(result);
	};

	//trait Result
public:
	typedef E ErrorType;
	typedef R ResultType;

	template<typename U>
	Result<U, E> map(std::function<U(R)> func)
	{
		if (is_ok())
		{
			return Result<U, E>::Ok(func(_content));
		}
		return Result<U, E>::Err(_error);
	}

	template<typename U>
	Result<U, E> and_then(std::function<Result<U, E>(R)> func)
	{
		if (is_ok())
		{
			return func(_content);
		}
		return Result<U, E>::Err(_error);
	}

	template<typename F>
	Result<R, F> or_else(std::function<Result<R, F>(E)> func)
	{
		if (is_err())
		{
			return func(_error);
		}
		return Result<T, F>::Ok(_content);
	}

	Option<R> ok()
	{
		if (is_ok())
		{
			return Option<R>::Some(_content);
		}
		return Option<R>::None();
	}

	Option<E> err()
	{
		if (is_err())
		{
			return Option<E>::Some(_error);
		}
		return Option<E>::None();
	}
};
