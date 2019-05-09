#pragma once

#include "Units.h"
#include "Vector.h"

class Point 
{
	//struct Point
protected:
	Length _x;
	Length _y;
	Length _z;

private:
	Point(Length x, Length y, Length z) :
		_x(x),
		_y(y),
		_z(z)
	{
	};

	//impl Point
public:	
	static Point create(Length x, Length y, Length z)
	{
		return Point(x, y, z);
	}

	Length x() const { return _x; }
	Length y() const { return _y; }
	Length z() const { return _z; }

	friend Vector operator -(const Point &lhs, const Point &rhs)
	{
		return Vector::create(
			lhs._x - rhs._x,
			lhs._y - rhs._y,
			lhs._z - rhs._z);
	}

	friend Point operator -(const Point &lhs, const Vector &rhs)
	{
		return Point(
			lhs._x - rhs.x(),
			lhs._y - rhs.y(),
			lhs._z - rhs.z());
	}

	friend Point operator +(const Point &lhs, const Vector &rhs)
	{
		return Point(
			lhs._x + rhs.x(),
			lhs._y + rhs.y(),
			lhs._z + rhs.z());
	}

	static const Point origo;

public:
	//impl Projector for Point:
	Option<Point> calc_projection(const Point &p) const
	{
		return Option<Point>::Some(*this);
	}
};

const Point Point::origo = Point(0, 0, 0);
