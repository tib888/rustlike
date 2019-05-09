#pragma once

typedef double Scalar;
typedef double Length;
typedef double Angle;
typedef double Area;

template<typename T>
class Unit
{
private:
	Unit();

public:
	const T& value() const;
};