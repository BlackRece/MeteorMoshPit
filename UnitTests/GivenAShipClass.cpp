#include "pch.h"
#include "CppUnitTest.h"
#include "../CPP.MeterorMoshPit/Ship.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GivenAShipClass
{
    TEST_CLASS(WhenTheShipIsDrawn)
    {
    public:
        TEST_METHOD(ThenATriangleIsDrawn)
        {
            Ship ship;
            ship.render();
            Assert::IsTrue(ship.IsAlive());
        }

        TEST_METHOD(MovePlayerShip_Forward)
        {
            // Arrange
            PlayerShip playerShip;  // Create an instance of PlayerShip
            float initialX = playerShip.GetX();  // Get initial X position

            // Act
            playerShip.MoveForward();  // Move the ship forward

            // Assert
            float newX = playerShip.GetX();  // Get new X position
            Assert::IsTrue(newX > initialX);  // Check if the ship moved forward
        }

        TEST_METHOD(RotatePlayerShip_Left)
        {
            // Arrange
            PlayerShip playerShip;  // Create an instance of PlayerShip
            float initialAngle = playerShip.GetAngle();  // Get initial angle

            // Act
            playerShip.RotateLeft();  // Rotate the ship left

            // Assert
            float newAngle = playerShip.GetAngle();  // Get new angle
            Assert::IsTrue(newAngle < initialAngle);  // Check if the ship rotated left
        }

        // You can add more test methods to cover other ship behaviors
    };
}  // namespace GivenAShipClass