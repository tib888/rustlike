#pragma once

template<typename Self>
class Line
{
public:
	static const Point &point(const Self &self);
	static const Direction &direction(const Self &self);
};

//impl Projector for Line
template<typename Self>
class Projector<Line<Self>>
{
public:
	static Point calc_projection(const Self &self, const Point &p)
	{
		auto v0 = p - Line<Self>::point(self);
		auto v1 = Line<Self>::direction(self) * Vector::dot(v0, Line<Self>::direction(self));
		return Line<Self>::point(self) + v1;
	};
};