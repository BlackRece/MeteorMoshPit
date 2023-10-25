#include "AMoveable.h"
#include "Maths.h"

AMoveable::AMoveable()
	: m_v2fVelocity(0.f, 0.f)
	, m_fAngle(0.f)
	, m_fDrag(0.99f)
	, m_fMoveSpeed(0.f)
	, m_fTurnSpeed(1.f)
{
}

void AMoveable::SetHeadingAngle(float fAngle)
{
	m_fAngle = Maths::Modf(fAngle, 360.f);
}

float AMoveable::GetHeadingAngle() const
{
	return m_fAngle;
}

sf::Vector2f AMoveable::GetPosition() const
{
	return m_v2fPosition;
}

void AMoveable::SetPosition(sf::Vector2f v2fPosition)
{
	m_v2fPosition = v2fPosition;
}

void AMoveable::MoveForward(float fDelta)
{
	float fAngle = Maths::ToRadians(GetHeadingAngle());

	m_v2fVelocity = sf::Vector2f(
		cos(fAngle),
		sin(fAngle));

	m_v2fVelocity *= m_fMoveSpeed * fDelta;
}

void AMoveable::UpdateMovement(float fDelta)
{
	m_v2fPosition += m_v2fVelocity;
	m_v2fVelocity *= m_fDrag;
}

void AMoveable::Update(float fDelta)
{
}

void AMoveable::SetSpeed(float fSpeed)
{
	m_fMoveSpeed = fSpeed;
}
