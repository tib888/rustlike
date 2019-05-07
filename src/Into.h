#pragma once

TRAIT(Into)
{
	template<typename T, typename Self>
	T into(Self item)
	{
		return T::from(item);
	}
}