#ifndef ASTEROID_H
#define ASTEROID_H

#include "IMoveable.h"
#include "Shape.h"
#include <SFML/Graphics.hpp>

class Asteroid : public IMoveable
{
public:
	Asteroid(float fSpeed, float fRadius, int iPoints);
	~Asteroid();

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
	std::shared_ptr<Shape> m_shape;
	sf::Vector2f m_v2fPosition;
	sf::Vector2f m_v2fVelocity;
	float	m_fAngle;
	float	m_fMoveSpeed;
	float	m_fRadius;
	int		m_iPoints;
	float	m_fDrag;
	float	m_fTurnSpeed;
};

#endif // !ASTEROID_H
