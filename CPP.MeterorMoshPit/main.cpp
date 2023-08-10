#include <SFML/Graphics.hpp>
#include <string>
#include "Ship.h"

class MovableEntity
{
public:
    MovableEntity();
    ~MovableEntity();

private:

};

MovableEntity::MovableEntity()
{
}

MovableEntity::~MovableEntity()
{
}

int main()
{
    float fWidth = 600.0f;
    float fHeight = 400.0f;
    std::string sTitle = "Meteor Mosh Pit";

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(
        sf::VideoMode(fWidth, fHeight),
        sTitle,
        sf::Style::Default,
        settings);
    window.setFramerateLimit(60);
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    //draw triangular ship
    sf::CircleShape ship(10.f, 3);
    ship.setFillColor(sf::Color::Black);
    ship.setOutlineColor(sf::Color::White);
    ship.setOutlineThickness(2.0f);
    ship.setPosition(fWidth / 2.0f, fHeight / 2.0f);
    sf::FloatRect shipBounds = ship.getGlobalBounds();
    ship.setOrigin(shipBounds.width / 2, shipBounds.height / 2);
    float fShipSpeed = 10.0f;
    Ship shipClass = Ship(fShipSpeed);

    shipClass.SetPosition(ship.getPosition());
    shipClass.SetHeadingAngle(ship.getRotation());

    //debug ship angle text
    int nFontSize = 25;
    sf::Vector2f v2fTextPosition(10.0f, 10.0f);
    sf::Font font;
    font.loadFromFile("Dimension.ttf");
    sf::Text texts[10];

    for(int i = 0; i < 10; i++)
    {
        texts[i].setFont(font);
        texts[i].setCharacterSize(25);
        texts[i].setFillColor(sf::Color::Red);
        texts[i].setPosition(v2fTextPosition);
        v2fTextPosition.y += nFontSize;
    }


    while (window.isOpen())
    {
        // window events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // time
        sf::Time time = sf::seconds(1.0f / 60.0f);
        float fDelta = time.asSeconds();

        // update
        if (window.hasFocus())
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))
            {
				ship.rotate(-1.0f);
			}
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
            {
                ship.rotate(1.0f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
            {
                float fAngle = (ship.getRotation() - 90) * 3.14159265359f / 180.0f;
                shipClass.SetPosition(ship.getPosition());
                shipClass.SetHeadingAngle(fAngle);

                shipClass.ApplyThrust(fDelta);
                ship.setPosition(shipClass.GetPosition());
                
                /*float fAngle = (ship.getRotation() - 90) * 3.14159265359f / 180.0f;
               float fAngle = ship.getRotation() * 3.14159265359f / 180.0f;
                sf::Vector2f velocity(
                    fShipSpeed * cos(fAngle), 
                    fShipSpeed * sin(fAngle));

                sf::Vector2f pos = ship.getPosition();
                pos.x += velocity.x;
                pos.y += velocity.y;
                ship.setPosition(pos);*/
			}

            std::string sAngle = std::to_string(ship.getRotation());
            texts[0].setString("Angle: " + sAngle);
            std::string sShipPos = std::to_string(ship.getPosition().x);
            sShipPos.append(", ");
            sShipPos.append(std::to_string(ship.getPosition().y));
            texts[1].setString("ShipPosition: " + sShipPos);

            std::string sClass = std::to_string(shipClass.GetHeadingAngle());
            texts[2].setString("Class Angle: " + sClass);
        }

        // render
        window.clear();
        window.draw(shape);
        window.draw(ship);

        for (int i = 0; i < 10; i++)
            window.draw(texts[i]);

        window.display();
    }

    return 0;
}