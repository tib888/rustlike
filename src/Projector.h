#pragma once

#include "Units.h"
#include "Point.h"

TRAIT(Projector)
{
	template<typename Self>
	static Point calc_projection(const Self &self, const Point &p);
};
