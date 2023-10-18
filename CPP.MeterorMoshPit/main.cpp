#include <SFML/Graphics.hpp>
#include <string>
#include "Ship.h"
#include "GameWindow.h"
#include "Asteroid.h"
#include "Game.h"

int main()
{
    //setup window
    int iWidth = 600;
    int iHeight = 400;
    int iFPS = 60;

    Game game(iWidth, iHeight, iFPS);
    game.Run();

    return 0;
}
