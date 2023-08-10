#include "pch.h"
//#include "CppUnitTest.h"
#include "../CPP.MeterorMoshPit/Shape.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GivenAShape
{
	TEST_CLASS(WhenTheShapeIsCreated)
	{
	public:
		TEST_METHOD_INITIALIZE(Setup)
		{
			//sf::Vector2f v2fPosition(0.f, 0.f);
			//float fRadius = 1.f;

			//Shape shape = Shape(v2fPosition, fRadius);
		}

		TEST_METHOD_CLEANUP(Teardown)
		{

		}

		TEST_METHOD(ThenThePositionIsAsExpected)
		{
			sf::Vector2f v2fExpectedPosition(0.f, 0.f);
			float fRadius = 1.f;

			Shape shape = Shape(v2fExpectedPosition, fRadius);
			sf::Vector2f v2fActualPosition = shape.GetPosition();
			Assert::AreEqual(v2fExpectedPosition.x, v2fActualPosition.x);
		}

		TEST_METHOD(ThenACircleIsDrawn)
		{
			sf::Vector2f v2fPosition(0.f, 0.f);
			sf::Color color = sf::Color::White;
			float fRadius = 1.f;

			Shape shape = Shape(v2fPosition, fRadius);
			shape.SetShape();
			shape.SetFillColor(color);
			shape.SetLineColor(color);
			shape.SetLineThickness(1.f);
			shape.SetRadius(fRadius);
			shape.SetPosition(v2fPosition);
			//shape.SetOrigin();

			//sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
			//shape.Draw(window);
		}
	};
}