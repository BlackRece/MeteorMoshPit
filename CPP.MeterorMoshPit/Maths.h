#ifndef MATHS_H
#define MATHS_H

#include <math.h>

namespace Maths
{
	const float PI = 3.14159265358979323846f;
	
	inline float ToRadians(float fDegrees)
	{
		return fDegrees * (PI / 180.0f);
	}

	inline float ToDegrees(float fRadians)
	{
		return fRadians * (180.0f / PI);
	}

	inline float Modf(float fValue, float fMax, float fMin = 0.0f)
	{
		return fMin > fMax 
			? Modf(fValue, fMin, fMax)
			: (fValue >= 0 ? fMin : fMax) + fmodf(fValue - fMin, fMax - fMin);
	}
};


#endif // !MATHS_H