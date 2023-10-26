#ifndef ASTEROID_H
#define ASTEROID_H

#include "AMoveable.h"
#include "ADrawable.h"

class Asteroid : public AMoveable, public ADrawable
{
public:
	Asteroid(float fRadius, int iPoints);
	~Asteroid();

	// AMoveable
	void Update(float fDelta) override;

private:
	float const m_fBaseSpeed = 10.f;

	float	m_fAngle;
	int		m_iPoints;
	float	m_fDrag;
	float	m_fTurnSpeed;
};

#endif // !ASTEROID_H
