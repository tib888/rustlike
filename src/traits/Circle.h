#pragma once

#include "HasArea.h"
#include "Projector.h"
#include "Centered.h"
#include "Direction.h"

template<typename Self, typename CenterT> 
class Circle : 
	public Centered<Self, CenterT>,
	public Projector<Self>,
	public HasArea<Self>
	//public HasArcLength<Self>,
{
public:
	//trait Circle
	Length radius() const
	{
		return SELF->radius();
	}

	//CenterT center() const
	//{
	//	return SELF->center();
	//}

public:
	//impl HasArea for Circle
	Area calc_area() const
	{
		return radius() * radius() * M_PI;
	}
	
public:
	//impl Projector for Circle
	Option<Point> calc_projection(const Point &p) const
	{
		auto axis = SELF->center();//why __super:: or SELF-> is needed here?
		const auto v0 = p - axis.point();
		const auto v1 = v0 - axis.direction().value() * Vector::dot(v0, axis.direction().value());
		return with_length(v1, radius()).map<Point>([&](const Vector &v)
		{ 
			return axis.point() + v; 
		});
	};
};
