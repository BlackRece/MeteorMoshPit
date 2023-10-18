#ifndef SHIP_H
#define SHIP_H

#include "IMoveable.h"
#include "Shape.h"
#include <SFML/Graphics.hpp>

#define SHIP_SIDES 3
#define SHIP_RADIUS 10.f

class Ship : public IMoveable
{
public:
	Ship(float fSpeed);
	~Ship();

	std::shared_ptr<Shape> GetShape() const;

	float GetHeadingAngle() const;
	void SetHeadingAngle(float fAngle);
	void ApplyThrust(float fDelta);

	// IMoveable
	void MoveForward(float fDelta, float fSpeed) override;
	sf::Vector2f GetPosition() const override;
	void SetPosition(sf::Vector2f v2fPosition) override;
	void Rotate(float fAngle) override;
	void Update(float fDelta) override;
	float GetRadius() const override;

private:
	std::shared_ptr<Shape> m_pShape;
	sf::Vector2f m_v2fPosition;
	sf::Vector2f m_v2fVelocity;
	float m_fAngle;
	float m_fMoveSpeed;
	float m_fDrag;
	float m_fTurnSpeed;
	float m_fAngleOffset;
};

#endif // !SHIP_H
