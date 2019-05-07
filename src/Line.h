#pragma once

//trait Line
template<typename Target>
class Line
{
public:
	typedef Target Self;

	static const Point &point(const typename Target::Self &self)
	{
		return self.point();
	};
	static const Direction &direction(const typename Target::Self &self)
	{
		return self.direction();
	};

	//impl Projector for Line<>:
	static Point calc_projection(const typename Target::Self &self, const Point &p)
	{
		auto v0 = p - point(self);
		auto v1 = direction(self).value() * Vector::dot(v0, direction(self).value());
		return point(self) + v1;
	};
};

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

	//impl Line3d:
public:
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
