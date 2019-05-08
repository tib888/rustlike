#pragma once
#include "Option.h"
#include "traits/Circle.h"
#include "traits/From.h"

class Circle3d
{
public:
	typedef Circle3d Self;

	//struct Circle3d:
private:
	Length _radius;
	Point _center;
	Direction _axis_direction;

private:
	Circle3d(Length radius, Point center, Direction axis_direction) :
		_radius(radius),
		_center(center),
		_axis_direction(axis_direction)
	{
	};

	//impl Circle3d:
public:
	static Option<Circle3d> try_create(Length radius, Point center, Direction axis_direction)
	{
		if (radius >= 0)
		{
			return Option<Circle3d>::Some(Circle3d(radius, center, axis_direction));
		}

		return Option<Circle3d>::None();
	}

	static Circle3d unchecked_create(Length radius, Point center, Direction axis_direction)
	{
		assert(radius >= 0);
		return Circle3d(radius, center, axis_direction);
	}

	TRAIT_Circle(Circle3d);
	TRAIT_From(Circle3d, Circle2d)
};

//impl Circle for Circle3d
Length Circle3d::radius() const
{
	return _radius;
}

const Point &Circle3d::center() const
{
	return _center;
}

const Direction &Circle3d::axis_direction() const
{
	return _axis_direction;
}

//impl from<Circle2d> for Circle3d:
Circle3d Circle3d::from(const Circle2d &item)
{
	return Circle3d(item.radius(), item.center(), item.axis_direction());
}
