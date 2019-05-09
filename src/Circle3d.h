#pragma once

#include <cassert>

#include "Units.h"
#include "Option.h"
#include "Point.h"
#include "Vector.h"
#include "Direction.h"
#include "Line3d.h"
#include "traits/Circle.h"
#include "traits/From.h"

class Circle3d : 
	public Circle<Circle3d, const Line3d &>,
	public From<Circle3d, Circle2d>
{
	//struct Circle3d:
private:
	Length _radius;
	Line3d _center;

private:
	Circle3d(Length radius, const Line3d &center) :
		_radius(radius),
		_center(center)
	{
	};

	//impl Circle3d:
public:
	static Option<Circle3d> try_create(Length radius, const Line3d &center)
	{
		if (radius >= 0)
		{
			return Option<Circle3d>::Some(Circle3d(radius, center));
		}

		return Option<Circle3d>::None();
	}

	static Circle3d unchecked_create(Length radius, const Line3d &center)
	{
		assert(radius >= 0);
		return Circle3d(radius, center);
	}

	//impl Circle for Circle3d
	Length radius() const
	{
		return _radius;
	}

	//impl Centered<const Line3d&> for Circle
	const Line3d &center() const
	{
		return _center;
	}

	//impl from<Circle2d> for Circle3d:
	static Circle3d from(const Circle2d &item)
	{
		return Circle3d(item.radius(), item.center());
	}
};