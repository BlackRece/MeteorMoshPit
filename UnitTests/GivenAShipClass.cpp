#include "pch.h"
#include "CppUnitTest.h"
#include "../CPP.MeterorMoshPit/Ship.h"
//#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"
//#inlcude "TestHelpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GivenAShipClass
{
    TEST_CLASS(WhenHeadingAngleIsSet)
    {
        TEST_METHOD(ThenTheHeadingAngleIsAsExpected)
        {
            float fExpectedAngle = 90.f;

            Ship ship;
            ship.SetHeadingAngle(fExpectedAngle);
            float fActualAngle = ship.GetHeadingAngle();

            Assert::AreEqual(fExpectedAngle, fActualAngle);
        }
    };

    TEST_CLASS(WhenMovingForward)
    {
        TEST_METHOD(ThenShipIsMovedToExpectedPosition)
        {
            float fHeadingAngle = 90.f;
            sf::Vector2f v2fStartingPosition(0.f, 0.f);
            Ship ship;
            ship.SetHeadingAngle(fHeadingAngle);
            ship.SetPosition(v2fStartingPosition);
            float fDelta = 1.f;
            float fSpeed = 1.f;

            sf::Vector2f v2fVelocity = sf::Vector2f(
                cos(fHeadingAngle) * fSpeed * fDelta, 
                sin(fHeadingAngle) * fSpeed * fDelta);
            sf::Vector2f fExpectedPosition = sf::Vector2f(
                v2fVelocity.x, 
                v2fVelocity.y);

            ship.MoveForward(fDelta, fSpeed);
            sf::Vector2f fActualPosition = ship.GetPosition();
            Assert::AreEqual(
                fExpectedPosition.x,
                fActualPosition.x);
        }
    };

    TEST_CLASS(WhenTheShipIsDrawn)
    {
    public:
        TEST_METHOD(ThenATriangleIsDrawn)
        {
            Ship ship;
            //ship.render();
            //Assert::IsTrue(ship.IsAlive());
        }

        //TEST_METHOD(MovePlayerShip_Forward)
        //{
            // Arrange
        //    PlayerShip playerShip;  // Create an instance of PlayerShip
        //    float initialX = playerShip.GetX();  // Get initial X position

        //    // Act
        //    playerShip.MoveForward();  // Move the ship forward

        //    // Assert
        //    float newX = playerShip.GetX();  // Get new X position
        //    Assert::IsTrue(newX > initialX);  // Check if the ship moved forward
        //}

        //TEST_METHOD(RotatePlayerShip_Left)
        //{
        //    // Arrange
        //    PlayerShip playerShip;  // Create an instance of PlayerShip
        //    float initialAngle = playerShip.GetAngle();  // Get initial angle

        //    // Act
        //    playerShip.RotateLeft();  // Rotate the ship left

        //    // Assert
        //    float newAngle = playerShip.GetAngle();  // Get new angle
        //    Assert::IsTrue(newAngle < initialAngle);  // Check if the ship rotated left
        //}

        // You can add more test methods to cover other ship behaviors
    };
}  // namespace GivenAShipClass