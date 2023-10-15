#include "GameWindow.h"

GameWindow::GameWindow(int const iWidth, int const iHeight, int const iFramesPerSecond)
    : m_iWidth(iWidth)
    , m_iHeight(iHeight)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    m_rWindow = std::make_unique<sf::RenderWindow>();
    
    m_rWindow->create(
		sf::VideoMode(iWidth, iHeight),
		sTitle,
		sf::Style::Default,
		settings);
     
    m_rWindow->setFramerateLimit(iFramesPerSecond);
}

GameWindow::~GameWindow()
{
}

sf::RenderWindow& GameWindow::GetWindow() const
{
	return *m_rWindow;
}

bool GameWindow::IsOpen() const
{
    return m_rWindow->isOpen();
}

bool GameWindow::HasFocus() const
{
    return m_rWindow->hasFocus();
}

void GameWindow::BeginRender()
{
	m_rWindow->clear();
}

void GameWindow::EndRender()
{
	m_rWindow->display();
}