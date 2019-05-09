#pragma once

class Vector
{
	//struct Point
protected:
	Length _x;
	Length _y;
	Length _z;

private:
	Vector(Length x, Length y, Length z) :
		_x(x),
		_y(y),
		_z(z)
	{
	};

	//impl vector
public:
	static Vector create(Length x, Length y, Length z)
	{
		return Vector(x, y, z);
	}
		
	Length x() const { return _x; }
	Length y() const { return _y; }
	Length z() const { return _z; }

	Length sq_length() const { return _x * _x + _y * _y + _z * _z; }
	Length length() const { return sqrt(sq_length()); }
	
	static Length dot(const Vector &lhs, const Vector &rhs)
	{
		return lhs._x * rhs._x + lhs._y * rhs._y + lhs._z * rhs._z;
	}

	friend Vector operator -(const Vector &lhs, const Vector &rhs)
	{
		return Vector(
			lhs._x - rhs._x,
			lhs._y - rhs._y,
			lhs._z - rhs._z);
	}

	friend Vector operator +(const Vector &lhs, const Vector &rhs)
	{
		return Vector(
			lhs._x + rhs._x,
			lhs._y + rhs._y,
			lhs._z + rhs._z);
	}

	friend Vector operator *(const Vector &lhs, Scalar rhs)
	{
		return Vector(
			lhs._x * rhs,
			lhs._y * rhs,
			lhs._z * rhs);
	}

	friend Vector operator *(Scalar lhs, const Vector &rhs)
	{
		return Vector(
			lhs * rhs._x,
			lhs * rhs._y,
			lhs * rhs._z);
	}

	friend Vector operator /(const Vector &lhs, Scalar rhs)
	{
		return Vector(
			lhs._x / rhs,
			lhs._y / rhs,
			lhs._z / rhs);
	}

	Option<Vector> with_length(Length l) const;

	static const Vector zero;
	static const Vector i_unit;
	static const Vector j_unit;
	static const Vector k_unit;
};

const Vector Vector::zero = Vector(0, 0, 0);
const Vector Vector::i_unit = Vector(1, 0, 0);
const Vector Vector::j_unit = Vector(0, 1, 0);
const Vector Vector::k_unit = Vector(0, 0, 1);