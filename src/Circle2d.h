#pragma once

#include "Option.h"

//use crate::Circle
#include "Circle.h"

class Circle2d 
{
	//struct Circle2d:
private:
	Length _radius;
	Point _center;

private:
	Circle2d(Length radius, Point center) :
		_radius(radius),
		_center(center)
	{
	};

	//impl Circle2d:
public:
	static Option<Circle2d> try_create(Length radius, Point center)
	{
		if (radius >= 0)
		{
			return Option<Circle2d>::Some(Circle2d(radius, center));
		}

		return Option<Circle2d>::None();
	}

	static Circle2d unchecked_create(Length radius, Point center)
	{
		assert(radius >= 0);
		return Circle2d(radius, center);
	}

	Length radius() const
	{
		return _radius;
	}

	const Point &center() const
	{
		return _center;
	}

	const Direction &axis_direction() const
	{
		return Direction::k_unit;
	}

public:
	static Length radius(const Circle2d &self)
	{
		return self.radius();
	}

	static Point center(const Circle2d &self)
	{
		return self.center();
	}

	static Direction axis_direction(const Circle2d &self)
	{
		return self.axis_direction();
	}
};
