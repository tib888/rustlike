#pragma once

#include "Projector.h"

template<typename Self> 
class Circle : 
	public Projector<Circle<Self>>
{
public:
	//trait Circle
	Length radius() const
	{
		return SELF->radius();
	}

	const Point &center() const
	{
		return SELF->center();
	}

	const Direction &axis_direction() const
	{
		return SELF->axis_direction();
	}
	
public:
	//impl Projector for Circle
	Point calc_projection(const Point &p) const
	{
		auto v0 = p - center();
		auto v1 = v0 - axis_direction().value() * Vector::dot(v0, axis_direction().value());
		return center() + v1;
	};
};
