#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>
#include "ADrawable.h"

class Shape : public ADrawable
{
public:
	Shape(sf::Vector2f v2fPosition, float fRadius, int iPoints);
	~Shape();

private:
};

#endif // !SHAPE_H