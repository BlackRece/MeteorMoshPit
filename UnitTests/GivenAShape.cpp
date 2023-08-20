#include "pch.h"
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

		TEST_METHOD(ThenTheDefaultValuesAreAsExpected)
		{
			sf::Vector2f v2fExpectedPosition(0.f, 0.f);
			float fExpectedRadius = 1.f;
			sf::Color expectedFillColor = sf::Color::Black;
			sf::Color expectedLineColor = sf::Color::White;
			float fExpectedLineThickness = 1.f;

			Shape shape = Shape(v2fExpectedPosition, fExpectedRadius);
			sf::Vector2f v2fActualPosition = shape.GetPosition();
			float fActualRadius = shape.GetRadius();
			sf::Color actualFillColor = shape.GetFillColor();
			sf::Color actualLineColor = shape.GetLineColor();
			float fActualLineThickness = shape.GetLineThickness();

			Assert::AreEqual(v2fExpectedPosition.x, v2fActualPosition.x);
			Assert::AreEqual(v2fExpectedPosition.y, v2fActualPosition.y);
			Assert::AreEqual(fExpectedRadius, fActualRadius);
			
			Assert::AreEqual(expectedFillColor.r, actualFillColor.r);
			Assert::AreEqual(expectedFillColor.g, actualFillColor.g);
			Assert::AreEqual(expectedFillColor.b, actualFillColor.b);

			Assert::AreEqual(expectedLineColor.r, actualLineColor.r);
			Assert::AreEqual(expectedLineColor.g, actualLineColor.g);
			Assert::AreEqual(expectedLineColor.b, actualLineColor.b);

			Assert::AreEqual(fExpectedLineThickness, fActualLineThickness);
		}

		TEST_METHOD(ThenThePositionIsAsExpected)
		{
			sf::Vector2f v2fExpectedPosition(0.f, 0.f);
			float fRadius = 1.f;

			Shape shape = Shape(v2fExpectedPosition, fRadius);
			sf::Vector2f v2fActualPosition = shape.GetPosition();
			Assert::AreEqual(v2fExpectedPosition.x, v2fActualPosition.x);

			shape.SetPosition(v2fExpectedPosition);
			v2fActualPosition = shape.GetPosition();
			Assert::AreEqual(v2fExpectedPosition.x, v2fActualPosition.x);
		}
		
		TEST_METHOD(ThenTheRotationAngleGivesExpectedResult)
		{
			Shape shape = Shape(sf::Vector2f(0.f, 0.f), 1.f);

			float fExpectedAngle = 90;
			shape.SetRotation(fExpectedAngle);
			float fActualAngle = shape.GetRotation();

			Assert::AreEqual(fExpectedAngle, fActualAngle);
		}

		TEST_METHOD(ThenTheFillColourCanBeSet)
		{
			Shape shape = Shape(sf::Vector2f(0.f, 0.f), 1.f);
			
			sf::Color expectedFillColor = sf::Color::Red;

			shape.SetFillColor(expectedFillColor);
			sf::Color actualFillColor = shape.GetFillColor();

			Assert::AreEqual(expectedFillColor.r, actualFillColor.r);
			Assert::AreEqual(expectedFillColor.g, actualFillColor.g);
			Assert::AreEqual(expectedFillColor.b, actualFillColor.b);
		}

		TEST_METHOD(ThenTheLineColourCanBeSet)
		{
			Shape shape = Shape(sf::Vector2f(0.f, 0.f), 1.f);

			sf::Color expectedLineColor = sf::Color::Red;

			shape.SetLineColor(expectedLineColor);
			sf::Color actualLineColor = shape.GetLineColor();

			Assert::AreEqual(expectedLineColor.r, actualLineColor.r);
			Assert::AreEqual(expectedLineColor.g, actualLineColor.g);
			Assert::AreEqual(expectedLineColor.b, actualLineColor.b);
		}

		TEST_METHOD(ThenTheLineThicknessCanBeSet)
		{
			Shape shape = Shape(sf::Vector2f(0.f, 0.f), 1.f);

			float fExpectedThickness = 3.f;
			shape.SetLineThickness(fExpectedThickness);
			float fActualThickness = shape.GetLineThickness();

			Assert::AreEqual(fExpectedThickness, fActualThickness);
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

		TEST_METHOD_CLEANUP(Teardown)
		{

		}

	};
}