#include "Shape.h"

Shape::Shape(sf::Vector2f v2fPosition, float fRadius)
	: m_v2fPosition(v2fPosition)
	, m_fRadius(fRadius)
	, m_fillColor(sf::Color::Black)
	, m_lineColor(sf::Color::White)
	, m_fLineThickness(1.f)
{
}

Shape::~Shape()
{
}

void Shape::SetShape()
{
	m_shape = sf::CircleShape(m_fRadius);
}

void Shape::SetFillColor(sf::Color color)
{
}

void Shape::SetLineColor(sf::Color color)
{
}

void Shape::SetLineThickness(float fThickness)
{
}

void Shape::SetRadius(float fRadius)
{
}

void Shape::SetPosition(sf::Vector2f v2fPosition)
{
	m_shape.setPosition(v2fPosition);
}

void Shape::Draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

void Shape::SetOrigin()
{
	sf::FloatRect shipBounds = m_shape.getGlobalBounds();
	m_shape.setOrigin(shipBounds.width / 2, shipBounds.height / 2);
}
