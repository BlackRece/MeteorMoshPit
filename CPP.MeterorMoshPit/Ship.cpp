#include "Ship.h"

Ship::Ship(float fSpeed)
	: m_fFireTimer(0.f), m_fFireDelay(0.5f)
{
	SetSpeed(fSpeed);

	CreateShape(SHIP_RADIUS, SHIP_SIDES);
	SetLineThickness(2.f);

	m_pAmmoPool = std::make_unique<AmmoPool>();
}

Ship::~Ship()
{
}

void Ship::ApplyThrust(float fDelta)
{
	MoveForward(fDelta);
}

bool Ship::IsFiring()
{
	return m_fFireTimer > 0.f;
}

void Ship::FireProjectile()
{
	if (m_fFireTimer <= 0.f)
	{
		m_fFireTimer = m_fFireDelay;
		std::shared_ptr<AMoveable> pMoveable = shared_from_this();
		m_pAmmoPool->Fire(pMoveable);
	}
}

void Ship::Rotate(float fAngle)
{
	TurnTowards(GetRotation() + fAngle);
	SetRotation(GetHeading());
}

void Ship::Update(float fDelta)
{
	SetPosition(GetLocation());
	AMoveable::Update(fDelta);
	SetLocation(GetPosition());

	if (m_fFireTimer > 0.f)
		m_fFireTimer -= fDelta;
}
