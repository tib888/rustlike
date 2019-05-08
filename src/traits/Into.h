#ifndef TRAIT_Into
#define TRAIT_Into(Self, T)\
	static T into()\
	{\
		return T::from(item);\
	}
#endif //TRAIT_Into