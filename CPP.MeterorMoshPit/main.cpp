#include "Game.h"

int main()
{
    // setup window
    int iWidth = 600;
    int iHeight = 400;
    int iFPS = 60;

    Game game(iWidth, iHeight, iFPS);
    game.Run();

    return 0;
}
