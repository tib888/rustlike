#pragma once

#include "Units.h"
#include "Point.h"

//trait Projector
class Projector
{	
public:		
	template<typename Target, typename Self>
	static Point calc_projection(const Self &self, const Point &p)
	{
		return Target::calc_projection(self, p);
	};
};
