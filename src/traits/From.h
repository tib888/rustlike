#pragma once

template<typename Self, typename T>
class From
{
public:
	static Self from(const T &item) {
		return Self::from(item);
	};
};
