#include <SFML/Graphics.hpp>
#include <string>

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
    float fShipSpeed = 1.0f;

    //debug ship angle text
    sf::Font font;
    font.loadFromFile("Dimension.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::Red);
    text.setPosition(10.0f, 10.0f);

    while (window.isOpen())
    {
        // window events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

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
                sf::Vector2f velocity(
                    fShipSpeed * cos(fAngle), 
                    fShipSpeed * sin(fAngle));

                sf::Vector2f pos = ship.getPosition();
                pos.x += velocity.x;
                pos.y += velocity.y;
                ship.setPosition(pos);
			}

            std::string sAngle = std::to_string(ship.getRotation());
            text.setString("Angle: " + sAngle);
        }

        // render
        window.clear();
        window.draw(shape);
        window.draw(ship);
        window.draw(text);
        window.display();
    }

    return 0;
}