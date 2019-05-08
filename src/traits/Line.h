#pragma once

#include "Projector.h"

template<typename Self>
class Line : 
	public Projector<Line<Self>>
{
public:
	//trait Line
	const Point &point() const
	{
		return SELF->point();
	}
	const Direction &direction() const
	{
		return SELF->direction();
	}

public:
	//impl Projector for Line:
	Point calc_projection(const Point &p) const
	{
		auto v0 = p - point();
		auto v1 = direction().value() * Vector::dot(v0, direction().value());
		return point() + v1;
	}
};
