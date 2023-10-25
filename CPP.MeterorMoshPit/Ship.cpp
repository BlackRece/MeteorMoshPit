#include "Ship.h"

Ship::Ship(float fSpeed)
	: m_fAngle(0.f)
	, m_fDrag(0.99f)
	, m_fTurnSpeed(1.f)
{
	SetSpeed(fSpeed);

	CreateShape(SHIP_RADIUS, SHIP_SIDES);
	SetLineThickness(2.f);
}

Ship::~Ship()
{
}

void Ship::ApplyThrust(float fDelta)
{
	MoveForward(fDelta);
}

void Ship::Rotate(float fAngle)
{
	SetHeadingAngle(GetRotation() + (fAngle * m_fTurnSpeed));
	SetRotation(GetHeadingAngle());
}

void Ship::Update(float fDelta)
{
	SetPosition(GetLocation());
	UpdateMovement(fDelta);
	SetLocation(GetPosition());
}
