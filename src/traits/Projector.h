#pragma once

template<typename Self>
class Projector
{
public:
	//trait Projector:
	Point calc_projection(const Point &p) const
	{
		return SELF->calc_projection(p);
	}
};
