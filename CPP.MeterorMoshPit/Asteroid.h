#ifndef ASTEROID_H
#define ASTEROID_H

#include "IMoveable.h"
#include "Shape.h"
#include <SFML/Graphics.hpp>

#define ROCK_SIDES 10
#define ROCK_RADIUS 20.f

class Asteroid : public IMoveable
{
public:
	Asteroid(float fSpeed);
	~Asteroid();

	float GetHeadingAngle() const;
	void SetHeadingAngle(float fAngle);
	sf::Vector2f GetPosition() const;
	void SetPosition(sf::Vector2f v2fPosition);
	void ApplyThrust(float fDelta);
	float GetRadius() const;

	// IMoveable
	void MoveForward(float fDelta, float fSpeed) override;
	void Rotate(float fAngle) override;
	void Update(float fDelta) override;

	// IDrawable
	void Draw(sf::RenderWindow& window);

private:
	Shape m_shape;
	sf::Vector2f m_v2fPosition;
	sf::Vector2f m_v2fVelocity;
	float m_fAngle;
	float m_fMoveSpeed;
	float m_fDrag;
	float m_fTurnSpeed;
	float m_fAngleOffset;
};

#endif // !ASTEROID_H
