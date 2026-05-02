#include "CppUnitTest.h"
#include "../PolygonLib/point.h"
#include "../PolygonLib/polygon.h"
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonTests
{
    TEST_CLASS(PointTests)
    {
    public:
        TEST_METHOD(Point_DefaultConstructor)
        {
            Point p;
            Assert::AreEqual(0u, p.getX());
            Assert::AreEqual(0u, p.getY());
        }

        TEST_METHOD(Point_ValidConstructor)
        {
            Point p(10, 20, 100);
            Assert::AreEqual(10u, p.getX());
            Assert::AreEqual(20u, p.getY());
        }

        TEST_METHOD(Point_Equality)
        {
            Point p1(5, 5, 100);
            Point p2(5, 5, 100);
            Point p3(5, 6, 100);
            Assert::IsTrue(p1 == p2);
            Assert::IsFalse(p1 == p3);
        }

        TEST_METHOD(Point_Output)
        {
            Point p(7, 8, 100);
            std::ostringstream oss;
            oss << p;
            Assert::AreEqual(std::string("(7, 8)"), oss.str());
        }

        TEST_METHOD(Point_Input)
        {
            std::istringstream iss("15 25");
            Point p;
            iss >> p;
            Assert::AreEqual(15u, p.getX());
            Assert::AreEqual(25u, p.getY());
        }
    };

    TEST_CLASS(PolygonTests)
    {
    public:
        TEST_METHOD(Polygon_ConstructFromVertices)
        {
            std::vector<Point> verts = { Point(0,0,100), Point(10,0,100), Point(10,10,100), Point(0,10,100) };
            Polygon poly(verts, 100);
            std::string expected = "Многоугольник: (0, 0) (10, 0) (10, 10) (0, 10) ";
            Assert::AreEqual(expected, poly.ToString());
        }

        TEST_METHOD(Polygon_ConstructFromCoordinatesArray)
        {
            unsigned int coords[] = { 0,0, 10,0, 10,10, 0,10 };
            Polygon poly(coords, 8, 100);
            Assert::AreEqual(std::string("Многоугольник: (0, 0) (10, 0) (10, 10) (0, 10) "), poly.ToString());
        }

        TEST_METHOD(Polygon_StaticToString)
        {
            std::vector<Point> verts = { Point(1,2,100), Point(3,4,100) };
            std::string expected = "Многоугольник: (1, 2) (3, 4) ";
            Assert::AreEqual(expected, Polygon::ToString(verts));
        }

        TEST_METHOD(Polygon_ReadFromStream)
        {
            std::istringstream iss("3\n0 0\n10 0\n0 10\n");
            Polygon poly = Polygon::readFromStream(iss, 100);
            Assert::AreEqual(std::string("Многоугольник: (0, 0) (10, 0) (0, 10) "), poly.ToString());
        }

        TEST_METHOD(Polygon_OperatorOutput)
        {
            std::vector<Point> verts = { Point(1,1,100), Point(2,2,100) };
            Polygon poly(verts, 100);
            std::ostringstream oss;
            oss << poly;
            Assert::AreEqual(std::string("Многоугольник: (1, 1) (2, 2) "), oss.str());
        }
    };
}
