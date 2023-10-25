#ifndef ADRAWABLE_H
#define ADRAWABLE_H

#include <SFML/Graphics.hpp>

class ADrawable
{
public:
	//ADrawable();
	virtual ~ADrawable() = default;

	void CreateShape(float fRadius, int iPoints);
	void SetShape();
	void WrapLocation(int iWidth, int iHeight);


	virtual void SetFillColour(sf::Color color);
	virtual sf::Color GetFillColour() const;

	virtual void SetLineColor(sf::Color color);
	virtual sf::Color GetLineColor() const;

	virtual void SetLineThickness(float fThickness);
	virtual float GetLineThickness() const;

	virtual void SetRadius(float fRadius);
	virtual float GetRadius() const;

	virtual void SetLocation(sf::Vector2f v2fPosition);
	virtual sf::Vector2f GetLocation() const;

	virtual void SetRotation(float const fAngle);
	virtual float GetRotation() const;

	virtual void Draw(sf::RenderWindow& window);

private:

	std::unique_ptr<sf::ConvexShape> m_pConvexShape;
	float			m_fRadius;
	int				m_iPoints;
};

#endif // !ADRAWABLE_H
