#pragma once

#include "Units.h"
#include "Point.h"

template<typename Self>
class Projector
{	
public:
	static Point calc_projection(const Self &self, const Point &p);
};
