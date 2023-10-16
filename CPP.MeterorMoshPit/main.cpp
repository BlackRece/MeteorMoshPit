#include <SFML/Graphics.hpp>
#include <string>
#include "Ship.h"
#include "GameWindow.h"
#include "Asteroid.h"

int main()
{
    //setup window
    int iWidth = 600;
    int iHeight = 400;
    std::string sTitle = "Meteor Mosh Pit";

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(
        sf::VideoMode(iWidth, iHeight),
        sTitle,
        sf::Style::Default,
        settings);
    window.setFramerateLimit(60);

    std::unique_ptr<GameWindow> gameWindow = 
        std::make_unique<GameWindow>(iWidth, iHeight, 60);
    
    //setup test shape
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    //setup ship
    float fShipSpeed = 20.0f;
    Ship shipClass = Ship(fShipSpeed);
    shipClass.SetPosition(sf::Vector2f (iWidth / 2.0f, iHeight / 2.0f));

    //setup asteroids
    // TODO: randomise asteroid positions and speeds
    float fAsteroidSpeed = 10.0f;
    int iAstroidCount = 10;
    std::vector<Asteroid> asteroids;
    for (int i = 0; i < iAstroidCount; i++)
    {
        asteroids.push_back(Asteroid(fAsteroidSpeed));
        asteroids[i].SetPosition(sf::Vector2f(
			rand() % iWidth, 
			rand() % iHeight));
    }

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

    while (gameWindow->IsOpen())
    {
        sf::Event event;
        while (gameWindow->GetWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow->GetWindow().close();
        }

        // time
        sf::Time time = sf::seconds(1.0f / 60.0f);
        float fDelta = time.asSeconds();

        // update
        if (gameWindow->HasFocus())
        {
            //keyboard input
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape))
            {
                gameWindow->GetWindow().close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left))
            {
                shipClass.Rotate(-1.0f);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
            {
                shipClass.Rotate(1.0f);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up))
            {
                shipClass.ApplyThrust(fDelta);
            }
        }

        shipClass.Update(fDelta);
        // wrap ship around screen
        // TODO: do this for all IMoveable objects
        sf::Vector2f v2fShipPosition = shipClass.GetPosition();
        float fShipRadius = shipClass.GetRadius();
        if (v2fShipPosition.x - fShipRadius > iWidth)
            v2fShipPosition.x = 0.0f - fShipRadius;
        else if (v2fShipPosition.x + fShipRadius < 0.0f)
            v2fShipPosition.x = iWidth + fShipRadius;

        if (v2fShipPosition.y - fShipRadius > iHeight)
            v2fShipPosition.y = 0.0f - fShipRadius;
        else if (v2fShipPosition.y + fShipRadius < 0.0f)
            v2fShipPosition.y = iHeight + fShipRadius;

        shipClass.SetPosition(v2fShipPosition);

        //debug display
        std::string sShipRadius = std::to_string(fShipRadius);
        texts[0].setString("Radius: " + sShipRadius);

        std::string sShipPos = std::to_string(v2fShipPosition.x);
        sShipPos.append(", ");
        sShipPos.append(std::to_string(v2fShipPosition.y));
        texts[1].setString("ShipPosition: " + sShipPos);

        std::string sClass = std::to_string(shipClass.GetHeadingAngle());
        texts[2].setString("ShapeAngle: " + sClass);

        texts[3].setString("Width: " + std::to_string(iWidth));
        texts[4].setString("Height: " + std::to_string(iHeight));

        //render
        sf::RenderWindow &window = gameWindow->GetWindow();

        gameWindow->BeginRender();
        
        window.draw(shape);
        shipClass.Draw(window);

        for (int i = 0; i < iAstroidCount; i++)
        {
            asteroids[i].Update(fDelta);
			asteroids[i].Draw(window);
        }

        for (int i = 0; i < 10; i++)
            window.draw(texts[i]);

        gameWindow->EndRender();
    }

    /*
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
            //keyboard input
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
                
                /*
                float fAngle = (ship.getRotation() - 90) * 3.14159265359f / 180.0f;
                float fAngle = ship.getRotation() * 3.14159265359f / 180.0f;
                sf::Vector2f velocity(
                    fShipSpeed * cos(fAngle), 
                    fShipSpeed * sin(fAngle));

                sf::Vector2f pos = ship.getPosition();
                pos.x += velocity.x;
                pos.y += velocity.y;
                ship.setPosition(pos);
                */
    /*
			}

            //debug display
            std::string sAngle = std::to_string(ship.getRotation());
            texts[0].setString("Angle: " + sAngle);
            std::string sShipPos = std::to_string(ship.getPosition().x);
            sShipPos.append(", ");
            sShipPos.append(std::to_string(ship.getPosition().y));
            texts[1].setString("ShipPosition: " + sShipPos);

            std::string sClass = std::to_string(shipClass.GetHeadingAngle());
            texts[2].setString("Class Angle: " + sClass);
        }

        // render drawables
        window.clear();
        window.draw(shape);
        window.draw(ship);

        for (int i = 0; i < 10; i++)
            window.draw(texts[i]);

        window.display();
    }
    */

    return 0;
}
