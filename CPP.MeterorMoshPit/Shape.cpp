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
	m_bIsCircle = (iPoints == 3);
}

Shape::~Shape()
{
}

void Shape::SetShape()
{

	if (m_bIsCircle)
	{
		m_circleShape = sf::CircleShape(m_fRadius, m_iPoints);
	}
	else 
	{
		m_convexShape = sf::ConvexShape(m_iPoints);
		float fAngle = 2 * Maths::PI / m_iPoints;
		for (int i = 0; i < m_iPoints; i++)
		{
			float fOffset = (rand() % 30) - 15;
			sf::Vector2f v2fPoint(
				(m_fRadius + fOffset) * cos(fAngle * i),
				(m_fRadius + fOffset) * -sin(fAngle * i));

			m_convexShape.setPoint(i, v2fPoint);
		}
	}

	SetOrigin();
}

void Shape::SetFillColour(sf::Color fillColour)
{
	m_fillColour = fillColour;
	if(m_bIsCircle)
		m_circleShape.setFillColor(m_fillColour);
	else
		m_convexShape.setFillColor(m_fillColour);
}

sf::Color Shape::GetFillColour() const 
{
	return m_bIsCircle
		? m_circleShape.getFillColor()
		: m_convexShape.getFillColor();
}

void Shape::SetLineColor(sf::Color lineColour)
{
	m_lineColor = lineColour;
	if(m_bIsCircle)
		m_circleShape.setOutlineColor(m_lineColor);
	else
		m_convexShape.setOutlineColor(m_lineColor);
}

sf::Color Shape::GetLineColor() const 
{ 
	return m_bIsCircle
		? m_circleShape.getOutlineColor()
		: m_convexShape.getOutlineColor();
}

void Shape::SetLineThickness(float fThickness)
{
	m_fLineThickness = fThickness;
	if(m_bIsCircle)
		m_circleShape.setOutlineThickness(m_fLineThickness);
	else
		m_convexShape.setOutlineThickness(m_fLineThickness);
}

float Shape::GetLineThickness() const 
{
	return m_bIsCircle
		? m_circleShape.getOutlineThickness()
		: m_convexShape.getOutlineThickness();
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
	if(m_bIsCircle)
		m_circleShape.setPosition(v2fPosition);
	else
		m_convexShape.setPosition(v2fPosition);
}

sf::Vector2f Shape::GetPosition() const 
{ 
	return m_bIsCircle
		? m_circleShape.getPosition()
		: m_convexShape.getPosition();
}

void Shape::SetRotation(float const fAngle)
{
	if(m_bIsCircle)
		m_circleShape.setRotation(fAngle);
	else
		m_convexShape.setRotation(fAngle);
}

float Shape::GetRotation() const
{
	return m_bIsCircle
		? m_circleShape.getRotation()
		: m_convexShape.getRotation();
}

void Shape::Draw(sf::RenderWindow& window)
{
	if(m_bIsCircle)
		window.draw(m_circleShape);
	else
		window.draw(m_convexShape);
}

void Shape::SetOrigin()
{
	if (m_bIsCircle)
	{
		sf::FloatRect shipBounds = m_circleShape.getGlobalBounds();
		m_circleShape.setOrigin(shipBounds.width / 2, shipBounds.height / 2);
	}
	else
	{
		sf::FloatRect shipBounds = m_convexShape.getGlobalBounds();
		m_convexShape.setOrigin(shipBounds.width / 2, shipBounds.height / 2);
	}
}
