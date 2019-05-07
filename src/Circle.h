#pragma once
#include <cassert>

#include "Units.h"
#include "Point.h"
#include "Direction.h"

//use crate::Projector
#include "Projector.h"

//trait Circle:
template <typename Target>
class Circle
{	
public:
	typedef Target Self;

	static Length radius(const typename Target::Self &self)
	{
		return self.radius();
	}
	
	static const Point &center(const typename Target::Self &self)
	{
		return self.center();
	}

	static const Direction &axis_direction(const typename Target::Self &self)
	{
		return self.axis_direction();
	}

	//impl Projector for Circle<>
	static Point calc_projection(const typename Target::Self &self, const Point &p)
	{
		auto v0 = p - center(self);
		auto v1 = v0 - axis_direction(self).value() * Vector::dot(v0, axis_direction(self).value());
		return center(self) + v1;
	};
};
