#ifndef AMOVEABLE_H
#define AMOVEABLE_H

#include <SFML/Graphics.hpp>

class AMoveable
{
public:
	AMoveable();
	virtual ~AMoveable() = default;

	void SetSpeed(float fSpeed);

	// velocity/angle
	virtual void TurnTowards(float fAngle);
	virtual void SetHeading(float fAngle);
	virtual float GetHeading() const;

	// position
	virtual void SetPosition(sf::Vector2f v2fPosition);
	virtual sf::Vector2f GetPosition() const;
	virtual void MoveForward(float fDelta);

	virtual void Update(float fDelta);

private:
	sf::Vector2f m_v2fPosition;
	sf::Vector2f m_v2fVelocity;

	float m_fMoveSpeed;
	float m_fAngle;
	float m_fDrag;
	float m_fTurnSpeed;
};

#endif // !AMOVEABLE_H
