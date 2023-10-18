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
	m_bIsCircle = false;
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
	m_convexShape = sf::ConvexShape(m_iPoints);
	float fAngle = 2 * Maths::PI / m_iPoints;
	for (int i = 0; i < m_iPoints; i++)
	{
		float fOffset = (m_iPoints <= 4) 
			? 0
			: (rand() % 30) - 15;
		sf::Vector2f v2fPoint(
			(m_fRadius + fOffset) * cos(fAngle * i),
			(m_fRadius + fOffset) * sin(fAngle * i));

		m_convexShape.setPoint(i, v2fPoint);
	}

	SetOrigin();
}

void Shape::SetFillColour(sf::Color fillColour)
{
	m_fillColour = fillColour;
	m_convexShape.setFillColor(m_fillColour);
}

sf::Color Shape::GetFillColour() const 
{
	return m_convexShape.getFillColor();
}

void Shape::SetLineColor(sf::Color lineColour)
{
	m_lineColor = lineColour;
	m_convexShape.setOutlineColor(m_lineColor);
}

sf::Color Shape::GetLineColor() const 
{ 
	return m_convexShape.getOutlineColor();
}

void Shape::SetLineThickness(float fThickness)
{
	m_fLineThickness = fThickness;
	m_convexShape.setOutlineThickness(m_fLineThickness);
}

float Shape::GetLineThickness() const 
{
	return m_convexShape.getOutlineThickness();
}

void Shape::SetRadius(float fRadius)
{
	m_fRadius = fRadius;
	SetShape();
}

float Shape::GetRadius() const 
{ 
	return m_fRadius;
}

void Shape::SetPosition(sf::Vector2f v2fPosition)
{
	m_v2fPosition = v2fPosition;
	m_convexShape.setPosition(v2fPosition);
}

sf::Vector2f Shape::GetPosition() const 
{ 
	return m_convexShape.getPosition();
}

void Shape::SetRotation(float const fAngle)
{
	m_convexShape.setRotation(fAngle);
}

float Shape::GetRotation() const
{
	return m_convexShape.getRotation();
}

void Shape::Draw(sf::RenderWindow& window)
{
	window.draw(m_convexShape);
}

void Shape::SetOrigin()
{
	sf::FloatRect shipBounds = m_convexShape.getGlobalBounds();
	m_convexShape.setOrigin(shipBounds.width / 2, shipBounds.height / 2);
}
