#pragma once

template<typename Self, typename CenterT>
class Centered 
{
public:
	//trait Centered<CenterT>
	CenterT center() const
	{
		return SELF->center();
	}
};