#ifndef AMMOPOOL_H
#define AMMOPOOL_H

#include "Projectile.h"
#include "AMoveable.h"

class AmmoPool
{
public:
	AmmoPool();
	~AmmoPool();

	void Fire(std::shared_ptr<AMoveable> pMoveable);

	void Update(float fDelta);
	void Draw(sf::RenderWindow& window);

	/*
	* Required:
	* GetProjectile()
	* Return a projectile from the pool
	* If there are no projectiles available, create more
	* build a queue of projectiles
	* 
	*/

private:
	std::vector<std::shared_ptr<Projectile>> m_vecProjectiles;
	std::vector<std::shared_ptr<Projectile>> m_vecActiveProjectiles;
	std::vector<std::shared_ptr<Projectile>> m_vecInactiveProjectiles;

	int const m_iProjectileCount = 10;
};

#endif // !AMMOPOOL_H
