#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include <SFML/Graphics.hpp>

class IDrawable
{
public:
	virtual ~IDrawable() {};

	virtual void SetFillColor(sf::Color color) = 0;
	virtual sf::Color GetFillColor() const = 0;

	virtual void SetLineColor(sf::Color color) = 0;
	virtual sf::Color GetLineColor() const = 0;

	virtual void SetLineThickness(float fThickness) = 0;
	virtual float GetLineThickness() const = 0;

	virtual void SetRadius(float fRadius) = 0;
	virtual float GetRadius() const = 0;

	virtual void SetPosition(sf::Vector2f v2fPosition) = 0;
	virtual sf::Vector2f GetPosition() const = 0;

	virtual void Draw(sf::RenderWindow& window) = 0;

private:

};

#endif // !IDRAWABLE_H
