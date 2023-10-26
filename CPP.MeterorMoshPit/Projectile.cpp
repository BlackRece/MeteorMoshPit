#include "Projectile.h"

Projectile::Projectile(float fRadius, float fSpeed, float fMaxLifeTime)
	: m_bAlive(false)
	, m_fAngle(0.f)
	, m_fLifeTime(0.f)
	, m_fMaxLifeTime(fMaxLifeTime)
{
	SetSpeed(fSpeed);

	CreateShape(fRadius, 3);
	SetLineThickness(3.f);
	SetLineColor(sf::Color::Yellow);
}

Projectile::~Projectile()
{
}


void Projectile::Update(float fDelta)
{
	if (!m_bAlive)
		return;

	m_fLifeTime -= fDelta;
	if(m_fLifeTime <= 0.f)
	{
		m_bAlive = false;
		return;
	}

	MoveForward(fDelta);

	SetPosition(GetLocation());
	AMoveable::Update(fDelta);
	SetLocation(GetPosition());
}

void Projectile::Draw(sf::RenderWindow& window)
{
	if (m_bAlive)
		ADrawable::Draw(window);
}


void Projectile::SetRadius(float fRadius)
{
}

void Projectile::SetLifeTime(float fLifeTime)
{
	m_fLifeTime = fLifeTime;
}

float Projectile::GetLifeTime() const
{
	return m_fLifeTime;
}

void Projectile::SetAlive(bool bAlive)
{
	m_bAlive = bAlive;
	m_fLifeTime = m_fMaxLifeTime;
}

bool Projectile::IsAlive() const
{
	return m_bAlive;
}