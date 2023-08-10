#include "Ship.h"

Ship::Ship()
{
}

Ship::~Ship()
{
}

float Ship::GetHeadingAngle() const
{
	//return (ship.getRotation() - 90) * 3.14159265359f / 180.0f;
	return m_fAngle;
}

void Ship::SetHeadingAngle(float fAngle)
{
	//ship.setRotation(fAngle);
	m_fAngle = fAngle;
}

sf::Vector2f Ship::GetPosition() const {
	return m_v2fPosition; 
}

void Ship::SetPosition(sf::Vector2f v2fPosition) { 
	m_v2fPosition = v2fPosition;
}

void Ship::MoveForward(float fDelta, float fSpeed)
{
	m_v2fPosition.x += cos(m_fAngle) * fSpeed * fDelta;
	m_v2fPosition.y += sin(m_fAngle) * fSpeed * fDelta;
}

void Ship::Rotate(float fAngle)
{
	m_fAngle += fAngle;
}