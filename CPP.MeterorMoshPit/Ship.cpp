#include "Ship.h"

Ship::Ship(float fSpeed)
	: m_v2fPosition(0.f, 0.f)
	, m_fAngle(0.f)
	, m_fMoveSpeed(fSpeed)
	, m_fTurnSpeed(0.1f)
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
	//return (ship.getRotation() - 90) * 3.14159265359f / 180.0f;
	//return m_fAngle;
	return (m_shape.GetRotation() - m_fAngleOffset);
}

void Ship::SetHeadingAngle(float fAngle)
{
	m_shape.SetRotation(fAngle + m_fAngleOffset);
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
	m_fAngle = m_shape.GetRotationInRadians();

	sf::Vector2f velocity(
		cos(m_fAngle), 
		sin(m_fAngle));

	velocity *= fMoveSpeed;

	m_v2fPosition += velocity * fDelta;
	/*m_v2fPosition.x += cos(m_fAngle) * fSpeed * fDelta;
	m_v2fPosition.y -= sin(m_fAngle) * fSpeed * fDelta;*/
}

void Ship::Rotate(float fAngle)
{
	SetHeadingAngle(GetHeadingAngle() + (fAngle * m_fTurnSpeed));
	//m_fAngle += fAngle;
	//float fHeading = (m_fAngle - 90) * 3.14159265359f / 180.0f;
	//m_shape.SetRotation(m_fAngle);
}

void Ship::Update(float fDelta)
{
	m_shape.SetPosition(m_v2fPosition);
}

void Ship::Draw(sf::RenderWindow& window)
{
	m_shape.Draw(window);
}
