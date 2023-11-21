#include "AmmoPool.h"

AmmoPool::AmmoPool()
{
	float fProjectileRadius = 2.0f;
	float fProjectileLifeTime = 2.0f;
	float fProjectileSpeed = 200.0f;
	int iProjectileCount = 10;

	for (int i = 0; i < iProjectileCount; i++)
	{
		std::shared_ptr<Projectile> pProjectile = std::make_shared<Projectile>(
			fProjectileRadius, 
			fProjectileSpeed, 
			fProjectileLifeTime);

		m_vecProjectiles.push_back(std::move(pProjectile));
		//m_vecMovables.push_back(m_vecProjectiles[i]);
		//m_vecDrawables.push_back(m_vecProjectiles[i]);
	}
}

void AmmoPool::Update(float fDelta)
{
	for (std::shared_ptr<Projectile> pProjectile : m_vecActiveProjectiles)
	{
		if(pProjectile->IsAlive())
			pProjectile->Update(fDelta);
	}
}

void AmmoPool::Draw(sf::RenderWindow& window)
{
	for (std::shared_ptr<Projectile> pProjectile : m_vecProjectiles)
	{
		if (pProjectile->IsAlive())
			pProjectile->Draw(window);
	}
}

void AmmoPool::Fire(std::shared_ptr<AMoveable> pMoveable)
{
	sf::Vector2f v2fLocation = pMoveable->GetPosition();
	m_vecProjectiles[0]->SetLocation(v2fLocation);

	float fHeading = pMoveable->GetHeading();
	m_vecProjectiles[0]->SetHeading(fHeading);
	m_vecProjectiles[0]->SetRotation(fHeading);

	m_vecProjectiles[0]->SetAlive(true);
}
