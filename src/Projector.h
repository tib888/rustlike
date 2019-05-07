#pragma once

#include "Units.h"
#include "Point.h"

//trait Projector
template<typename Target>
class Projector
{	
public:	
	typedef Target Self;

	static Point calc_projection(const typename Target::Self &self, const Point &p)
	{
		return Target::calc_projection(self, p);
	};
};
