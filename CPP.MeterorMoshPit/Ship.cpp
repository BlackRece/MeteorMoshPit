#include "Ship.h"
#include "Maths.h"

Ship::Ship(float fSpeed)
	: m_v2fPosition(0.f, 0.f)
	, m_fAngle(0.f)
	, m_fMoveSpeed(fSpeed)
	, m_fTurnSpeed(1.f)
	, m_fAngleOffset(90.f)
{
	m_shape = Shape(m_v2fPosition, SHIP_RADIUS, SHIP_SIDES);
	m_shape.SetLineThickness(2.f);
	m_shape.SetShape();
}

Ship::~Ship()
{
}

float Ship::GetHeadingAngle() const
{
	return (Maths::Modf(m_shape.GetRotation() - m_fAngleOffset, 360.f));
}

void Ship::SetHeadingAngle(float fAngle)
{
	m_shape.SetRotation(Maths::Modf(fAngle + m_fAngleOffset, 360.f));
}

sf::Vector2f Ship::GetPosition() const {
	return m_v2fPosition; 
}

void Ship::SetPosition(sf::Vector2f v2fPosition) { 
	m_v2fPosition = v2fPosition;
}

void Ship::ApplyThrust(float fDelta)
{
	MoveForward(fDelta, m_fMoveSpeed);
}

void Ship::MoveForward(float fDelta, float fMoveSpeed)
{
	float fAngle = Maths::ToRadians(GetHeadingAngle());

	sf::Vector2f velocity(
		cos(fAngle), 
		sin(fAngle));

	velocity *= fMoveSpeed * fDelta;

	m_v2fPosition += velocity;
}

void Ship::Rotate(float fAngle)
{
	SetHeadingAngle(GetHeadingAngle() + (fAngle * m_fTurnSpeed));
}

void Ship::Update(float fDelta)
{
	m_shape.SetPosition(m_v2fPosition);
}

void Ship::Draw(sf::RenderWindow& window)
{
	m_shape.Draw(window);
}
