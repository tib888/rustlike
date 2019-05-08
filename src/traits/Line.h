#ifndef TRAIT_Line
#define TRAIT_Line(Self)\
public:\
	/*trait Line*/\
	const Point &point() const;\
	const Direction &direction() const;\
	/*#include "Projector.trait"*/\
	/*impl Projector for Line:*/\
	Point calc_projection(const Point &p) const\
	{\
		auto v0 = p - point();\
		auto v1 = direction().value() * Vector::dot(v0, direction().value());\
		return point() + v1;\
	}
#endif //TRAIT_Line