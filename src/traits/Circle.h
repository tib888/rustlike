#ifndef TRAIT_Circle
#define TRAIT_Circle(Self)\
public:\
	/*trait Circle*/ \
	Length radius() const; \
	const Point &center() const; \
	const Direction &axis_direction() const; \
	/*#include "Projector.trait"*/ \
	/*impl Projector for Circle*/ \
	inline Point calc_projection(const Point &p) const \
	{ \
		auto v0 = p - center(); \
		auto v1 = v0 - axis_direction().value() * Vector::dot(v0, axis_direction().value()); \
		return center() + v1; \
	};
#endif //TRAIT_Circle