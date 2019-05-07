#pragma once
#include "Option.h"

//use crate::Circle
#include "Circle.h"

class Circle3d 
{
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

	//impl from<Circle2d> for Circle3d:
	static Circle3d from(const Circle2d &item)
	{
		return Circle3d(item.radius(), item.center(), item.axis_direction());
	}

	//readonly property accessors:
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
		return _axis_direction;
	}

public:
	static Length radius(const Circle3d &self)
	{
		return self.radius();
	}

	static const Point &center(const Circle3d &self)
	{
		return self.center();
	}

	static const Direction &axis_direction(const Circle3d &self)
	{
		return self.axis_direction();
	}
};
