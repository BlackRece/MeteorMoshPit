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

void AMoveable::TurnTowards(float fAngle)
{
	m_fAngle = Maths::Modf(fAngle * m_fTurnSpeed, 360.f);
}

void AMoveable::SetHeading(float fAngle)
{
	m_fAngle = Maths::Modf(fAngle, 360.f);
}

float AMoveable::GetHeading() const
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
	float fAngle = Maths::ToRadians(GetHeading());

	m_v2fVelocity = sf::Vector2f(
		cos(fAngle),
		sin(fAngle));

	m_v2fVelocity *= m_fMoveSpeed * fDelta;
}

void AMoveable::Update(float fDelta)
{
	m_v2fPosition += m_v2fVelocity;
	m_v2fVelocity *= m_fDrag;
}

void AMoveable::SetSpeed(float fSpeed)
{
	m_fMoveSpeed = fSpeed;
}
