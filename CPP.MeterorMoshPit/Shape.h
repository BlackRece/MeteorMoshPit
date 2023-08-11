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
	sf::Color GetFillColor() const { return m_fillColor; }

	void SetLineColor(sf::Color color);
	sf::Color GetLineColor() const { return m_lineColor; }

	void SetLineThickness(float fThickness);
	float GetLineThickness() const { return m_fLineThickness; }

	void SetRadius(float fRadius);
	float GetRadius() const { return m_fRadius; }

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