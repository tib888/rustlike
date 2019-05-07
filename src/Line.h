#pragma once

TRAIT(Line)
{
	template<typename Self>
	static const Point &point(const Self &self);

	template<typename Self>
	static const Direction &direction(const Self &self);
};

//impl Projector for Line
TRAITIMPL(Projector)
{
	//template<typename Self>
	//static Point calc_projection(const Self &self, const Point &p)
	//{
	//	auto v0 = p - Self::point(self);
	//	auto v1 = Self::direction(self) * Vector::dot(v0, Self::direction(self));
	//	return Self::point(self) + v1;
	//};
};