#include "Shape.h"
#include "Maths.h"

Shape::Shape()
	: m_v2fPosition(sf::Vector2f(0.f,0.f))
	, m_fRadius(1.f)
	, m_iPoints(3)
	, m_fillColour(sf::Color::Black)
	, m_lineColor(sf::Color::White)
	, m_fLineThickness(1.f)
{
}

Shape::Shape(sf::Vector2f v2fPosition, float fRadius, int iPoints)
	: m_v2fPosition(v2fPosition)
	, m_fRadius(fRadius)
	, m_iPoints(iPoints)
	, m_fillColour(sf::Color::Black)
	, m_lineColor(sf::Color::White)
	, m_fLineThickness(1.f)
{
}

Shape::~Shape()
{
}

void Shape::SetShape()
{
	m_shape = sf::CircleShape(m_fRadius, m_iPoints);
	SetOrigin();
}

void Shape::SetFillColour(sf::Color fillColour)
{
	m_fillColour = fillColour;
	m_shape.setFillColor(m_fillColour);
}

sf::Color Shape::GetFillColour() const 
{
	return m_shape.getFillColor();
}

void Shape::SetLineColor(sf::Color lineColour)
{
	m_lineColor = lineColour;
	m_shape.setOutlineColor(m_lineColor);
}

sf::Color Shape::GetLineColor() const 
{ 
	return m_shape.getOutlineColor(); 
}

void Shape::SetLineThickness(float fThickness)
{
	m_fLineThickness = fThickness;
	m_shape.setOutlineThickness(m_fLineThickness);
}

float Shape::GetLineThickness() const 
{
	return m_shape.getOutlineThickness(); 
}

void Shape::SetRadius(float fRadius)
{
	m_fRadius = fRadius;
	m_shape.setRadius(m_fRadius);
}

float Shape::GetRadius() const 
{ 
	return m_shape.getRadius(); 
}

void Shape::SetPosition(sf::Vector2f v2fPosition)
{
	m_v2fPosition = v2fPosition;
	m_shape.setPosition(v2fPosition);
}

sf::Vector2f Shape::GetPosition() const 
{ 
	return m_shape.getPosition(); 
}

void Shape::SetRotation(float const fAngle)
{
	m_shape.setRotation(Maths::Modf(fAngle, 360.f));
}

float Shape::GetRotation() const
{
	return m_shape.getRotation();
}

float Shape::GetRotationInRadians() const
{
	return (Maths::ToDegrees(m_shape.getRotation()));
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
