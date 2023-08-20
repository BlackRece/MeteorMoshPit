#include "Shape.h"

Shape::Shape()
	: m_v2fPosition(sf::Vector2f(0.f,0.f))
	, m_fRadius(1.f)
	, m_fillColor(sf::Color::Black)
	, m_lineColor(sf::Color::White)
	, m_fLineThickness(1.f)
{
}

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

sf::Color Shape::GetFillColor() const 
{
	return m_fillColor;
}

void Shape::SetLineColor(sf::Color color)
{
}

sf::Color Shape::GetLineColor() const 
{ 
	return m_lineColor; 
}

void Shape::SetLineThickness(float fThickness)
{
}

float Shape::GetLineThickness() const 
{
	return m_fLineThickness; 
}

void Shape::SetRadius(float fRadius)
{
}

float Shape::GetRadius() const 
{ 
	return m_fRadius; 
}

void Shape::SetPosition(sf::Vector2f v2fPosition)
{
	m_shape.setPosition(v2fPosition);
}

sf::Vector2f Shape::GetPosition() const 
{ 
	return m_v2fPosition; 
}

void Shape::SetRotation(float const fAngle)
{
}

float Shape::GetRotation() const
{
	return 0.0f;
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
