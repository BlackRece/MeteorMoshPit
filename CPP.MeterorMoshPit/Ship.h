#ifndef SHIP_H
#define SHIP_H

#include "IMoveable.h"
#include <SFML/Graphics.hpp>

class Ship : public IMoveable
{
public:
	Ship();
	~Ship();

	float GetHeadingAngle() const;
	void SetHeadingAngle(float fAngle);
	sf::Vector2f GetPosition() const { return m_v2fPosition; }

	void MoveForward(float fDelta, float fSpeed) override;
	void Rotate(float fAngle) override;

private:
	sf::Vector2f m_v2fPosition;
	float m_fAngle;
};

#endif // !SHIP_H
