#pragma once

#include "traits/Line.h"
#include "Point.h"
#include "Direction.h"

class Line3d
{
public:
	typedef Line3d Self;

	//struct Line3d:
private:
	Point _point;
	Direction _direction;

private:
	Line3d(Point point, Direction direction) :
		_point(point),
		_direction(direction)
	{
	};

public:
	//impl Line3d:
	static Line3d create(Point point, Direction direction)
	{
		return Line3d(point, direction);
	}

	TRAIT_Line(Line3d);
};
		
//impl Line for Line3d
const Point &Line3d::point() const
{
	return _point;
}

const Direction &Line3d::direction() const
{
	return _direction;
}
