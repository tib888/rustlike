#pragma once

template<typename Self>
class Orientable
{
public:
	//trait Orientable
	bool is_inner() const
	{
		return SELF->is_inner();
	}
};