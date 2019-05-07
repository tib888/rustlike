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


};
