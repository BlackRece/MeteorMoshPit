#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>
#include "IDrawable.h"

class Shape : public IDrawable
{
public:
	Shape();
	Shape(sf::Vector2f v2fPosition, float fRadius, int iPoints);
	~Shape();

	void SetShape();

	// IDrawable
	void SetFillColour(sf::Color color) override;
	sf::Color GetFillColour() const override;

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

	sf::Vector2f	m_v2fPosition;
	sf::ConvexShape m_convexShape;
	sf::Color		m_fillColour;
	sf::Color		m_lineColor;
	float			m_fLineThickness;
	float			m_fRadius;
	int				m_iPoints;
};

#endif // !SHAPE_H