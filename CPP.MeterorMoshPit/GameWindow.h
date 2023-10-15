#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Graphics.hpp>

class GameWindow
{
public:
    GameWindow(
        int const iWidth,
        int const iHeight,
        int const iFramesPerSecond);
    ~GameWindow();

    sf::RenderWindow& GetWindow() const;
    bool IsOpen() const;
    bool HasFocus() const;

    void BeginRender();
    void EndRender();

private:
    std::string const sTitle = "Meteor Mosh Pit";

    int m_iWidth, m_iHeight;
    std::unique_ptr<sf::RenderWindow> m_rWindow;
};

#endif // !GAMEWINDOW_H