#pragma once
#include <cassert>

#include "Units.h"
#include "Point.h"
#include "Direction.h"

//use crate::Projector
#include "Projector.h"

TRAIT(Circle)
{	
	template<typename Self>
	static Length radius(const Self &self);// { return 0; };

	template<typename Self>
	static const Point &center(const Self &self);

	template<typename Self>
	static const Direction &axis_direction(const Self &self);
};

//impl Projector for Circle
TRAITIMPL(Projector)
{
	template<typename Self>
	static Point calc_projection(const Self &self, const Point &p)
	{
		auto v0 = p - Circle::center(self);
		auto v1 = v0 - Circle::axis_direction(self).value() * Vector::dot(v0, Circle::axis_direction(self).value());
		return Circle::center(self) + v1;
	};
};