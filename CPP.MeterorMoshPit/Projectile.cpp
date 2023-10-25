#include "Projectile.h"

void Projectile::Update(float fDelta)
{
}

Projectile::Projectile()
	: m_bAlive(false)
	, m_fAngle(0.f)
	, m_fLifeTime(0.f)
{
}

Projectile::~Projectile()
{
}

void Projectile::SetRadius(float fRadius)
{
}

void Projectile::SetLifeTime(float fLifeTime)
{
}

float Projectile::GetLifeTime() const
{
	return 0.0f;
}

void Projectile::SetAlive(bool bAlive)
{
}

bool Projectile::IsAlive() const
{
	return false;
}