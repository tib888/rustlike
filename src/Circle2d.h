#pragma once

#include "Units.h"
#include "Option.h"
#include "Point.h"
#include "Vector.h"
#include "Direction.h"
#include "Line3d.h"
#include "traits/Circle.h"
#include "traits/Orientable.h"

class Circle2d : 
	public Circle<Circle2d, Line3d>,
	public Orientable<Circle2d>
{
	//struct Circle2d:
private:
	Length _radius;
	Point _center;
	bool _is_inner;

private:
	Circle2d(Length radius, Point center, bool is_inner) :
		_radius(radius),
		_center(center),
		_is_inner(is_inner)
	{
	};

	//impl Circle2d:
public:
	static Option<Circle2d> try_create(Length radius, Point center, bool is_inner)
	{
		if (radius >= 0)
		{
			return Option<Circle2d>::Some(Circle2d(radius, center, is_inner));
		}

		return Option<Circle2d>::None();
	};

	static Circle2d unchecked_create(Length radius, Point center, bool is_inner)
	{
		assert(radius >= 0);
		return Circle2d(radius, center, is_inner);
	};
	
	//impl Circle for Circle2d
	Length radius() const
	{
		return _radius;
	}

	//impl Centered<Line3d> for Circle2d
	Line3d center() const
	{
		return Line3d::create(_center, Direction::k_unit);
	}

	//impl Orientable for Circle2d
	bool is_inner() const
	{
		return _is_inner;
	}

};
