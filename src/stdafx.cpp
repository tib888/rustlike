// stdafx.cpp : source file that includes just the standard includes
// rustlike.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

#include "Circle2d.h"
#include "Circle3d.h"
#include "Line3d.h"
#include "Result.h"

bool test() 
{
	const auto l1 = Line3d::create(Point::origo, Direction::i_unit);

	const auto c2 = Circle2d::unchecked_create(1, Point::origo, false);
	const auto c3 = Circle3d::unchecked_create(1, Line3d::create(Point::origo, Direction::k_unit));
	const auto p = Point::create(1, 1, 1);

	auto dex3d = c3.calc_projection(p);
	//auto dex3 = static_cast<const Circle<Circle3d>*>(&c3)->calc_projection(p);
	auto dex2 = c2.calc_projection(p);
	auto dlex2 = l1.calc_projection(p);

	auto r2 = c3.radius();
	auto r3 = static_cast<const Circle<Circle3d, const Line3d &>*>(&c3)->radius();

	auto x = Result<int, int>::Ok(1);

	auto c32 = Circle3d::from(c2);
	//Circle3d c32_ = c2.into<Circle3d>();

	return false;
}
