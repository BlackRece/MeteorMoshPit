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

	void Rotate(float fAngle);

	void Update(float fDelta) override;

	//void GetProjectiles(m_vecDrawables, m_vecMovables);

private:
	float m_fAngle;
	float m_fDrag;
	float m_fTurnSpeed;
};

#endif // !SHIP_H
