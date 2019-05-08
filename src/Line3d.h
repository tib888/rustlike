#pragma once

#include "Point.h"
#include "Direction.h"
#include "traits/Line.h"

class Line3d : public Line<Line3d>
{
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
	
	//impl Line for Line3d
	const Point &point() const
	{
		return _point;
	}

	const Direction &direction() const
	{
		return _direction;
	}
};
