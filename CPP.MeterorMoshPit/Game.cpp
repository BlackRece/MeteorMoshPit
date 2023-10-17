#include "Game.h"

Game::Game(int const iWidth, int const iHeight, int const iFramesPerSecond)
    : iFPS(iFramesPerSecond)
    , fFrameTime(1.0f / iFramesPerSecond)
	, m_fDeltaTime(0.0f)
{
    m_gameWindow = std::make_unique<GameWindow>(iWidth, iHeight, iFramesPerSecond);
}

Game::~Game()
{
}

void Game::Run()
{
    while (m_gameWindow->GetWindow().isOpen())
    {
        Update();
        Render();
    }
}

void Game::Update()
{
    //update delta time
    m_fDeltaTime = m_clock.restart().asSeconds();

    //update keyboard input
    UpdateKeyboardInput();

    for (std::shared_ptr<IMoveable> pMovable : m_vEntities)
    {
        pMovable->Update(m_fDeltaTime);
	}
}

void Game::Render()
{
    sf::RenderWindow &window = m_gameWindow->GetWindow();
    window.clear();

    //for (std::shared_ptr<IDrawable> pDrawable : m_vEntities)
    //{
    //    pDrawable->Draw(window);
    //}
    
    window.display();
}

void Game::UpdateKeyboardInput()
{
    if (!m_gameWindow->GetWindow().hasFocus())
        return;
}