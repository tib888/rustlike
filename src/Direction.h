#pragma once
#include <math.h>
#include <cassert>
#include "Units.h"
#include "Option.h"
#include "Vector.h"

template<>
class Unit<Vector>
{
private:
	Vector _value;

	Unit(const Vector &value) :
		_value(value)
	{
	}

public:

	static Option<Unit<Vector>> try_create(Scalar x, Scalar y, Scalar z)
	{
		return try_create(Vector::create(x, y, z));
	}

	static Option<Unit<Vector>> try_create(const Vector &value)
	{
		auto l2 = value.sq_length();
		if (l2 > 1E-32)
		{
			auto l = sqrt(l2);
			return Option<Unit<Vector>>::Some(Unit(value / sqrt(l2)));
		}
	}

	static Unit<Vector> unchecked_create(Scalar x, Scalar y, Scalar z)
	{
		return unchecked_create(Vector::create(x, y, z));
	}

	static Unit<Vector> unchecked_create(Vector value)
	{
		assert(fabs(value.sq_length() - 1) < 1e-16);
		return Unit(value);
	}

	const Vector& value() const
	{
		return _value;
	};

	static const Unit<Vector> i_unit;
	static const Unit<Vector> j_unit;
	static const Unit<Vector> k_unit;
};
	
const Unit<Vector> Unit<Vector>::i_unit = Unit<Vector>(Vector::create(1, 0, 0));
const Unit<Vector> Unit<Vector>::j_unit = Unit<Vector>(Vector::create(0, 1, 0));
const Unit<Vector> Unit<Vector>::k_unit = Unit<Vector>(Vector::create(0, 0, 1));

typedef Unit<Vector> Direction;
