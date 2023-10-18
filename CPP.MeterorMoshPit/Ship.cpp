#include "Ship.h"
#include "Maths.h"

Ship::Ship(float fSpeed)
	: m_v2fPosition(0.f, 0.f)
	, m_fAngle(0.f)
	, m_fMoveSpeed(fSpeed)
	, m_fDrag(0.99f)
	, m_fTurnSpeed(1.f)
	, m_v2fVelocity(0.f, 0.f)
{
	m_pShape = std::make_shared<Shape>(m_v2fPosition, SHIP_RADIUS, SHIP_SIDES);
	m_pShape->SetLineThickness(2.f);
	m_pShape->SetShape();
}

Ship::~Ship()
{
}

std::shared_ptr<Shape> Ship::GetShape() const
{
	return m_pShape;
}

float Ship::GetHeadingAngle() const
{
	return (Maths::Modf(m_pShape->GetRotation(), 360.f));
}

void Ship::SetHeadingAngle(float fAngle)
{
	m_pShape->SetRotation(Maths::Modf(fAngle, 360.f));
}

sf::Vector2f Ship::GetPosition() const 
{
	return m_v2fPosition; 
}

void Ship::SetPosition(sf::Vector2f v2fPosition) 
{ 
	m_v2fPosition = v2fPosition;
}

void Ship::ApplyThrust(float fDelta)
{
	MoveForward(fDelta, m_fMoveSpeed);
}

void Ship::MoveForward(float fDelta, float fMoveSpeed)
{
	float fAngle = Maths::ToRadians(GetHeadingAngle());

	m_v2fVelocity = sf::Vector2f(
		cos(fAngle), 
		sin(fAngle));

	m_v2fVelocity *= fMoveSpeed * fDelta;
}

void Ship::Rotate(float fAngle)
{
	SetHeadingAngle(GetHeadingAngle() + (fAngle * m_fTurnSpeed));
}

float Ship::GetRadius() const
{
	return m_pShape->GetRadius();
}

void Ship::Update(float fDelta)
{
	m_v2fPosition += m_v2fVelocity;
	m_pShape->SetPosition(m_v2fPosition);
	m_v2fVelocity *= m_fDrag;
}
