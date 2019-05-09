#pragma once

template<typename Self>
class HasArea
{
public:
	//trait HasArea
	Area calc_area() const
	{
		return SELF->calc_area();
	}
};