#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "AMoveable.h"
#include "ADrawable.h"

class Projectile : public AMoveable, public ADrawable
{
public:
	Projectile(float fRadius, float fSpeed, float fMaxLifeTime);
	~Projectile();

	void SetRadius(float fRadius);

	void SetLifeTime(float fLifeTime);
	float GetLifeTime() const;

	void SetAlive(bool bAlive);
	bool IsAlive() const;

	// AMoveable
	void Update(float fDelta) override;

	// ADrawable
	void Draw(sf::RenderWindow& window) override;

private:
	float m_fAngle;
	float m_fLifeTime;
	float m_fMaxLifeTime;
	bool m_bAlive;
};

#endif // !PROJECTILE_H