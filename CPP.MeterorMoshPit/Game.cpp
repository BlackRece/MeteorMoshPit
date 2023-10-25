#include "Game.h"

Game::Game(int const iWidth, int const iHeight, int const iFramesPerSecond)
    : iFPS(iFramesPerSecond)
    , fFrameTime(1.0f / iFramesPerSecond)
	, m_fDelta(0.0f)
{
    m_gameWindow = std::make_unique<GameWindow>(iWidth, iHeight, iFramesPerSecond);

    // setup ship
    float fShipSpeed = 20.0f;
    m_pShip = std::make_shared<Ship>(fShipSpeed);
    m_pShip->SetLocation(sf::Vector2f(iWidth / 2.0f, iHeight / 2.0f));
    m_vecMovables.push_back(m_pShip);
    m_vecDrawables.push_back(m_pShip);
    //m_pShip->GetProjectiles(m_vecDrawables, m_vecMovables);

    // setup asteroids
    float fAsteroidRadius = 50.0f;
    int iAsteroidPoints = 15;
    int iAstroidCount = 5;
    for (int i = 0; i < iAstroidCount; i++)
    {
        std::shared_ptr<Asteroid> pAsteroid = 
            std::make_shared<Asteroid>(fAsteroidRadius, iAsteroidPoints);
        pAsteroid->SetLocation(sf::Vector2f(
            (float)(rand() % iWidth),
            (float)(rand() % iHeight)));
        pAsteroid->SetHeadingAngle((float)(rand() % 360));

        m_vecAsteroids.push_back(std::move(pAsteroid));
        m_vecMovables.push_back(m_vecAsteroids[i]);
        m_vecDrawables.push_back(m_vecAsteroids[i]);
    }

    // setup debug text log
    int nFontSize = 25;
    sf::Vector2f v2fTextPosition(10.0f, 10.0f);
    sf::Font font;
    font.loadFromFile("Dimension.ttf");

    for (int i = 0; i < 10; i++)
    {
        m_texts[i].setFont(font);
        m_texts[i].setCharacterSize(25);
        m_texts[i].setFillColor(sf::Color::Red);
        m_texts[i].setPosition(v2fTextPosition);
        v2fTextPosition.y += nFontSize;
    }
}

Game::~Game()
{
}

void Game::Run()
{
    sf::Event event;
    sf::RenderWindow &rWindow = m_gameWindow->GetWindow();

    // time
    sf::Time time = sf::seconds(1.0f / 60.0f);
    m_fDelta = time.asSeconds();

    while (rWindow.isOpen())
    {
        // handle window events
        while (rWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                rWindow.close();
        }

        Update();
        Render();
    }
}

void Game::Update()
{
    UpdateKeyboardInput();

    for (std::shared_ptr<AMoveable> pGameObjects : m_vecMovables)
    {
        pGameObjects->Update(m_fDelta);
        //pGameObjects->SetPosition(WrapPosition(pGameObjects->GetPosition(), pGameObjects->GetRadius()));
	}

    //debug display
    std::string sShipRadius = std::to_string(m_pShip->GetRadius());
    m_texts[0].setString("Radius: " + sShipRadius);

    std::string sShipPos = std::to_string(m_pShip->GetPosition().x);
    sShipPos.append(", ");
    sShipPos.append(std::to_string(m_pShip->GetPosition().y));
    m_texts[1].setString("ShipPosition: " + sShipPos);

    //std::string sClass = std::to_string(m_pShip->GetHeadingAngle());
    //m_texts[2].setString("ShapeAngle: " + sClass);

    m_texts[3].setString("Width: " + std::to_string(m_gameWindow->GetWidth()));
    m_texts[4].setString("Height: " + std::to_string(m_gameWindow->GetHeight()));
}

void Game::Render()
{
    sf::RenderWindow &window = m_gameWindow->GetWindow();
    m_gameWindow->BeginRender();

    for (std::shared_ptr<ADrawable> pDrawable : m_vecDrawables)
    {
        pDrawable->WrapLocation(m_gameWindow->GetWidth(), m_gameWindow->GetHeight());
        pDrawable->Draw(window);
    }

    //for (int i = 0; i < 10; i++)
    //    window.draw(m_texts[i]);

    m_gameWindow->EndRender();
}

void Game::UpdateKeyboardInput()
{
    if (!m_gameWindow->HasFocus())
        return;

    //keyboard input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Escape))
    {
        m_gameWindow->GetWindow().close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A))
    {
        m_pShip->Rotate(-1.0f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D))
    {
        m_pShip->Rotate(1.0f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W))
    {
        m_pShip->ApplyThrust(m_fDelta);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space))
    {
        //m_pShip->Fire();
    }
}

sf::Vector2f Game::WrapPosition(sf::Vector2f v2fPosition, float fRadius)
{
    sf::Vector2f v2fNewPosition = v2fPosition;

    int iWidth = m_gameWindow->GetWidth();
    int iHeight = m_gameWindow->GetHeight();

    if (v2fPosition.x - fRadius > iWidth)
        v2fNewPosition.x = 0.0f - fRadius;
    else if (v2fPosition.x + fRadius < 0.0f)
        v2fNewPosition.x = iWidth + fRadius;

    if (v2fPosition.y - fRadius > iHeight)
        v2fNewPosition.y = 0.0f - fRadius;
    else if (v2fPosition.y + fRadius < 0.0f)
        v2fNewPosition.y = iHeight + fRadius;

    return v2fNewPosition;
}
