#ifndef MATHS_H
#define MATHS_H

#include <math.h>

static class Maths
{
public:
	static const float PI;
	
	static inline float ToRadians(float fDegrees)
	{
		return fDegrees * (PI / 180.0f);
	}

	static inline float ToDegrees(float fRadians)
	{
		return fRadians * (180.0f / PI);
	}

	static inline float Modf(float fValue, float fMax, float fMin = 0.0f)
	{
		return fMin > fMax 
			? Modf(fValue, fMin, fMax)
			: (fValue >= 0 ? fMin : fMax) + fmodf(fValue - fMin, fMax - fMin);
	}

private:
	Maths();
	~Maths();

};

const float Maths::PI = 3.14159265358979323846f;

Maths::Maths()
{
}

Maths::~Maths()
{
}

float fwrap_alternate(float x, float min, float max) {
	if (min > max)
		return fwrap_alternate(x, max, min);
	return (x >= 0 ? min : max) + fmodf(x - min, max - min);
}

#endif // !MATHS_H