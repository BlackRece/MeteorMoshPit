#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include <SFML/Graphics.hpp>

class IDrawable
{
public:
	virtual ~IDrawable() {};
	virtual void Draw(sf::RenderWindow& window) = 0;

private:

};

#endif // !IDRAWABLE_H
