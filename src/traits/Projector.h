#pragma once

class Point;

template<typename Self>
class Projector
{
public:
	//trait Projector:
	Option<Point> calc_projection(const Point &p) const
	{
		return SELF->calc_projection(p);
	};
};
