// stdafx.cpp : source file that includes just the standard includes
// rustlike.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file


#include "Into.h"
#include "Option.h"
#include "Result.h"
#include "Point.h"
#include "Direction.h"

#include "Projector.h"

#include "Circle.h"
#include "Circle2d.h"
#include "Circle3d.h"

#include "Line.h"

bool test() 
{
	const auto c2 = Circle2d::unchecked_create(1, Point::origo);
	const auto c3 = Circle3d::unchecked_create(1, Point::origo, Direction::k_unit);
	const auto p = Point::create(1, 1, 1);

	//auto d3 = Projector<Circle<Circle3d>>::calc_projection(c3, p); //c3.calc_projection(p);
	auto dex3 = Projector::calc_projection(c3, p);
	auto dex2 = Projector::calc_projection(c2, p);

	auto x = Result<int, int>::Ok(1);

	auto c32 = Circle3d::from(c2);
	Circle3d c32_ = Into::into<Circle3d>(c2);

	return false;
}