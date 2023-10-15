#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "GameWindow.h"
#include "Ship.h"

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
    float fFrameTime = 1.0f / iFPS;
    int iFPS;
    float m_fDeltaTime;
    sf::Clock m_clock;

    std::unique_ptr<Ship> ship;
    std::vector<std::shared_ptr<Ship>> m_vEntities;
};

 #endif // !GAME_H