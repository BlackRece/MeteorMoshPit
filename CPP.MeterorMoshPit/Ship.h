#ifndef SHIP_H
#define SHIP_H

#include "AMoveable.h"
#include "ADrawable.h"

#define SHIP_SIDES 3
#define SHIP_RADIUS 10.f

class Ship : public AMoveable, public ADrawable
{
public:
	Ship(float fSpeed);
	~Ship();

	void ApplyThrust(float fDelta);
	bool IsFiring();
	void FireProjectile();

	void Rotate(float fAngle);

	void Update(float fDelta) override;

	//void GetProjectiles(m_vecDrawables, m_vecMovables);

private:
	float m_fFireDelay;
	float m_fFireTimer;
};

#endif // !SHIP_H
