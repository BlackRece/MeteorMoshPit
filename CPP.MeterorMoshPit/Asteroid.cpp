#include "Asteroid.h"

Asteroid::Asteroid(float fRadius, int iPoints)
	: m_fAngle(0.f)
	, m_iPoints(iPoints)
	, m_fDrag(0.99f)
	, m_fTurnSpeed(1.f)
{
	float fMoveSpeed = (m_fBaseSpeed * (m_fBaseSpeed / fRadius)) * 10.f;
	SetSpeed(fMoveSpeed);

	CreateShape(fRadius, m_iPoints);
	SetLineThickness(2.f);
}

Asteroid::~Asteroid()
{
}

void Asteroid::ApplyThrust(float fDelta)
{
	MoveForward(fDelta);
}

//void Asteroid::Rotate(float fAngle)
//{
//	SetHeadingAngle(GetHeadingAngle() + (fAngle * m_fTurnSpeed));
//}

void Asteroid::Update(float fDelta)
{
	SetPosition(GetLocation());
	UpdateMovement(fDelta);
	SetLocation(GetPosition());
}

