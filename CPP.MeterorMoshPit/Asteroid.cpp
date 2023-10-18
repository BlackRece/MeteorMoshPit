#include "Asteroid.h"
#include "Maths.h"

Asteroid::Asteroid(float fRadius, int iPoints)
	: m_v2fPosition(0.f, 0.f)
	, m_fAngle(0.f)
	, m_fRadius(fRadius)
	, m_iPoints(iPoints)
	, m_fDrag(0.99f)
	, m_fTurnSpeed(1.f)
	, m_v2fVelocity(0.f, 0.f)
{
	m_fMoveSpeed = (m_fBaseSpeed * (m_fBaseSpeed / m_fRadius)) * 10.f;

	m_shape = std::make_shared<Shape>(m_v2fPosition, m_fRadius, m_iPoints);
	m_shape->SetLineThickness(2.f);
	m_shape->SetShape();
}

Asteroid::~Asteroid()
{
}

std::shared_ptr<Shape> Asteroid::GetShape() const
{
	return m_shape;
}

float Asteroid::GetHeadingAngle() const
{
	return (Maths::Modf(m_shape->GetRotation(), 360.f));
}

void Asteroid::SetHeadingAngle(float fAngle)
{
	m_shape->SetRotation(Maths::Modf(fAngle, 360.f));
}

sf::Vector2f Asteroid::GetPosition() const
{
    return m_v2fPosition;
}

void Asteroid::SetPosition(sf::Vector2f v2fPosition)
{
	m_v2fPosition = v2fPosition;
}

void Asteroid::ApplyThrust(float fDelta)
{
	MoveForward(fDelta, m_fMoveSpeed);
}

float Asteroid::GetRadius() const
{
    return m_shape->GetRadius();
}

void Asteroid::MoveForward(float fDelta, float fSpeed)
{
	float fAngle = Maths::ToRadians(GetHeadingAngle());

	m_v2fVelocity = sf::Vector2f(
		cos(fAngle),
		sin(fAngle));

	m_v2fVelocity *= fSpeed * fDelta;
}

void Asteroid::Rotate(float fAngle)
{
	SetHeadingAngle(GetHeadingAngle() + (fAngle * m_fTurnSpeed));
}

void Asteroid::Update(float fDelta)
{
	MoveForward(fDelta, m_fMoveSpeed);
	m_v2fPosition += m_v2fVelocity;
	m_shape->SetPosition(m_v2fPosition);
}

