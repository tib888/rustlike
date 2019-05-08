#pragma once

template<typename Self, typename T>
class Into
{
public:
	T into() {
		return SELF->into();
	};
};
