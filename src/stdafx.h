// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#pragma warning(error:4717)				// raised this warning to error to get error notification about not implemented trait methods

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#define _USE_MATH_DEFINES
#include <cmath>

#define SELF static_cast<const Self*>(this)

// TODO: reference additional headers your program requires here
