#ifndef SHIP_H
#define SHIP_H

#include "IMoveable.h"
#include "Shape.h"
#include <SFML/Graphics.hpp>

#define SHIP_SIDES 3

class Ship : public IMoveable //, public IDrawable
{
public:
	Ship(float fSpeed);
	~Ship();

	float GetHeadingAngle() const;
	void SetHeadingAngle(float fAngle);
	sf::Vector2f GetPosition() const;
	void SetPosition(sf::Vector2f v2fPosition);
	void ApplyThrust(float fDelta);

	// IMoveable
	void MoveForward(float fDelta, float fSpeed) override;
	void Rotate(float fAngle) override;

	// IDrawable
	void Draw(sf::RenderWindow& window);

private:
	Shape m_shape;
	sf::Vector2f m_v2fPosition;
	float m_fAngle;
	float m_fSpeed;
};

#endif // !SHIP_H
