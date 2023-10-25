#include "ADrawable.h"

#include <SFML/Graphics.hpp>
#include "Maths.h"

void ADrawable::CreateShape(float fRadius, int iPoints)
{
	m_iPoints = iPoints;
	m_fRadius = fRadius;

	SetRadius(fRadius);

	SetShape();

	SetFillColour(sf::Color::Black);
	SetLineColor(sf::Color::White);
	SetLineThickness(1.f);
}
void ADrawable::SetShape()
{
	m_pConvexShape = std::make_unique<sf::ConvexShape>(m_iPoints);

	int iVariance = (int)floor(m_fRadius / 2);
	int iHalf = (int)floor(iVariance / 2);

	float fAngle = 2 * Maths::PI / m_iPoints;
	for (int i = 0; i < m_iPoints; i++)
	{
		float fOffset = (m_iPoints <= 4)
			? 0.f
			: (float)(rand() % iVariance) - iHalf;
		sf::Vector2f v2fPoint(
			(m_fRadius + fOffset) * cos(fAngle * i),
			(m_fRadius + fOffset) * sin(fAngle * i));

		m_pConvexShape->setPoint(i, v2fPoint);
	}
}

void ADrawable::SetFillColour(sf::Color color)
{
	m_pConvexShape->setFillColor(color);
}

sf::Color ADrawable::GetFillColour() const
{
	return m_pConvexShape->getFillColor();
}

void ADrawable::SetLineColor(sf::Color color)
{
	m_pConvexShape->setOutlineColor(color);
}

sf::Color ADrawable::GetLineColor() const
{
	return m_pConvexShape->getOutlineColor();
}

void ADrawable::SetLineThickness(float fThickness)
{
	m_pConvexShape->setOutlineThickness(fThickness);
}

float ADrawable::GetLineThickness() const
{
	return m_pConvexShape->getOutlineThickness();
}

void ADrawable::SetRadius(float fRadius)
{
	m_fRadius = abs(fRadius);
}

float ADrawable::GetRadius() const
{
	return m_fRadius;
}

void ADrawable::SetLocation(sf::Vector2f v2fPosition)
{
	m_pConvexShape->setPosition(v2fPosition);
}

sf::Vector2f ADrawable::GetLocation() const
{
	return m_pConvexShape->getPosition();
}

void ADrawable::SetRotation(float const fAngle)
{
	m_pConvexShape->setRotation(fAngle);
}

float ADrawable::GetRotation() const
{
	return m_pConvexShape->getRotation();
}

void ADrawable::Draw(sf::RenderWindow& window)
{
	window.draw(*m_pConvexShape);
}

void ADrawable::WrapLocation(int iWidth, int iHeight)
{
	sf::Vector2f v2fPosition = GetLocation();
	float fRadius = GetRadius();

	if (v2fPosition.x - fRadius > iWidth)
		v2fPosition.x = 0.0f - fRadius;
	else if (v2fPosition.x + fRadius < 0.0f)
		v2fPosition.x = iWidth + fRadius;

	if (v2fPosition.y - fRadius > iHeight)
		v2fPosition.y = 0.0f - fRadius;
	else if (v2fPosition.y + fRadius < 0.0f)
		v2fPosition.y = iHeight + fRadius;

	SetLocation(v2fPosition);
}
