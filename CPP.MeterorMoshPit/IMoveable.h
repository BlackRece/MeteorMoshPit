#ifndef IMOVEABLE_H
#define IMOVEABLE_H

#include <SFML/Graphics.hpp>

class IMoveable
{
public:
	virtual ~IMoveable() {};

	virtual void MoveForward(float fDelta, float fSpeed) = 0;
	virtual void Rotate(float fAngle) = 0;
	virtual void Update(float fDelta) = 0;

	virtual void SetPosition(sf::Vector2f v2fPosition) = 0;
	virtual sf::Vector2f GetPosition() const = 0;
	virtual float GetRadius() const = 0;

private:
};

#endif // !IMOVEABLE_H
