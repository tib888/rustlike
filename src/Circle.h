#pragma once
#include <cassert>

#include "Units.h"
#include "Point.h"
#include "Direction.h"

//use crate::Projector
#include "Projector.h"

template<typename Self> 
class Circle
{	
public:
	static Length radius(const Self &self);
	static const Point &center(const Self &self);
	static const Direction &axis_direction(const Self &self);
};

//impl Projector for Circle<>
template<typename Self>
class Projector<Circle<Self>>
{
public:
	static Point calc_projection(const Self &self, const Point &p)
	{
		auto v0 = p - Circle<Self>::center(self);
		auto v1 = v0 - Circle<Self>::axis_direction(self).value() * Vector::dot(v0, Circle<Self>::axis_direction(self).value());
		return Circle<Self>::center(self) + v1;
	};
};