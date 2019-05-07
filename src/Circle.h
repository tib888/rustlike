#pragma once
#include <cassert>

#include "Units.h"
#include "Point.h"
#include "Direction.h"

//use crate::Projector
#include "Projector.h"

//trait Circle:
class Circle
{	
public:	
	template<typename Self>
	static Length radius(const Self &self)
	{
		return self.radius();
	}
	
	template<typename Self>
	static const Point &center(const Self &self)
	{
		return self.center();
	}

	template<typename Self>
	static const Direction &axis_direction(const Self &self)
	{
		return self.axis_direction();
	}

	//impl Projector for Circle<>
	template<typename Self>
	static Point calc_projection(const Self &self, const Point &p)
	{
		auto v0 = p - center(self);
		auto v1 = v0 - axis_direction(self).value() * Vector::dot(v0, axis_direction(self).value());
		return center(self) + v1;
	};
};
