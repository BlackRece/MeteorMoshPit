#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>
#include "IDrawable.h"

class Shape : public IDrawable
{
public:
	Shape();
	Shape(sf::Vector2f v2fPosition, float fRadius);
	~Shape();

	void SetShape();

	// IDrawable
	void SetFillColor(sf::Color color) override;
	sf::Color GetFillColor() const override;

	void SetLineColor(sf::Color color) override;
	sf::Color GetLineColor() const override;

	void SetLineThickness(float fThickness) override;
	float GetLineThickness() const override;

	void SetRadius(float fRadius) override;
	float GetRadius() const override;

	void SetPosition(sf::Vector2f v2fPosition) override;
	sf::Vector2f GetPosition() const override;

	void SetRotation(float const fAngle) override;
	float GetRotation() const override;

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