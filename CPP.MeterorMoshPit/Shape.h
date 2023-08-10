#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>
#include "IDrawable.h"

class Shape : public IDrawable
{
public:
	Shape(sf::Vector2f v2fPosition, float fRadius);
	~Shape();

	void SetShape();
	void SetFillColor(sf::Color color);
	void SetLineColor(sf::Color color);
	void SetLineThickness(float fThickness);
	void SetRadius(float fRadius);
	void SetPosition(sf::Vector2f v2fPosition);
	sf::Vector2f GetPosition() const { return m_v2fPosition; }


	// IDrawable
	void Draw(sf::RenderWindow& window) override;

private:
	void SetOrigin();
	sf::Vector2f m_v2fPosition;

	sf::CircleShape m_shape;
	sf::Color m_fillColor;
	sf::Color m_lineColor;
	float m_fLineThickness;
	float m_fRadius;


};

#endif // !SHAPE_H