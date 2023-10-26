#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "GameWindow.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Projectile.h"

class Game
{
public:
    Game(int const iWidth, int const iHeight, int const iFramesPerSecond);
    ~Game();

    void Run();

private:
    void Update();
    void Render();

    void UpdateKeyboardInput();

    std::unique_ptr<GameWindow> m_gameWindow;

    std::string const sTitle = "Meteor Mosh Pit";
    int iFPS;
    float fFrameTime = 1.0f / iFPS;
    float m_fDelta;
    sf::Clock m_clock;
    sf::Text m_texts[10];

    std::shared_ptr<Ship> m_pShip;
    std::vector<std::shared_ptr<Asteroid>> m_vecAsteroids;
    std::vector<std::shared_ptr<Projectile>> m_vecProjectiles;

    std::vector<std::shared_ptr<AMoveable>> m_vecMovables;
    std::vector<std::shared_ptr<ADrawable>> m_vecDrawables;
};

 #endif // !GAME_H