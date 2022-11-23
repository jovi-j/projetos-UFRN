#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

#include "test_manager.h"
#include "FiguraGeometrica.hpp"

/*compare floats*/
bool f_equals(float a, float b)
{
    return fabs(a - b) < std::numeric_limits<float>::epsilon();
}

int main ( void )
{
    TestManager tm{ "Interator Template Tests" };
    //== all_of

    std::cout<<"running tests"<<std::endl;

    {
        BEGIN_TEST( tm,"Area of Rect", "Input: (-9, -1), (-6, -5); test if area equals to 12;");
        FiguraGeometrica f("R1",0);
        f.addPoint({-9, -1});
        f.addPoint({-6, -5});

        auto result = f.getArea();
        EXPECT_TRUE( f_equals(result, 12) , "At main.cpp line " + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm,"Area of Rect 2", "Input: (1, 4), (3, 2); test if area equals to 4;");
        FiguraGeometrica f("R2",0);
        f.addPoint({1, 4});
        f.addPoint({3, 2});

        auto result = f.getArea();
        EXPECT_TRUE( f_equals(result, 4) , "At main.cpp line " + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm,"Area of Rect 3", "Input: (-1, 3), (5, -1); test if area equals to 4 and toString");
        FiguraGeometrica f("R3",0);
        f.addPoint({-1, 3});
        f.addPoint({5, -1});

        auto result = f.getArea();
        EXPECT_TRUE( f_equals(result, 24) , "At main.cpp line " + std::to_string(__LINE__));
        EXPECT_TRUE( f.toString() == "R3:RETANGULO - {(-1, 3), (5, -1)}" , "At main.cpp line " + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm,"Area of Rect 3", "Input: (-1, -1); test if area equals to -1 and adding 3 points");
        FiguraGeometrica f("R4",0);
        f.addPoint({2.56, 4});
        auto result = f.getArea();
        EXPECT_TRUE( f_equals(result, -1) , "At main.cpp line " + std::to_string(__LINE__));
        f.addPoint({2, -1});
        EXPECT_FALSE( f.addPoint({2, 3}) , "At main.cpp line " + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm,"Area of Triangle", "Input: (-3, 0), (0, 0) (-1, 3); test area equals to 4.5;");
        FiguraGeometrica f("T1",1);
        f.addPoint({-3, 0});
        f.addPoint({0, 0});
        f.addPoint({-1, 3});
        auto result = f.getArea();

        EXPECT_TRUE( f_equals(result, 4.5) , "At main.cpp line " + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm,"Area of Triangle", "Input: (-2, -1), (2, 0) (-2, 2); test area equals to 6 and toString;");
        FiguraGeometrica f("T2",1);
        f.addPoint({-3, 0});
        f.addPoint({0, 0});
        f.addPoint({-1, 3});
        auto result = f.getArea();

        EXPECT_TRUE( f_equals(result, 6) , "At main.cpp line " + std::to_string(__LINE__));
        EXPECT_TRUE( f.toString() == "T2:TRIANGULO - {(-2, -1), (2, 0) (-2, 2)}" , "At main.cpp line " + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm,"Area of Triangle", "Input: (-3, 1), (2, -2) (1, 3); test area equals to 12 and toString;");
        FiguraGeometrica f("T3",1);
        f.addPoint({-3, 1});
        f.addPoint({2, -2});
        f.addPoint({1, 3});
        auto result = f.getArea();
        EXPECT_TRUE( f_equals(result, 12) , "At main.cpp line " + std::to_string(__LINE__));
        EXPECT_TRUE( f.toString() == "T3:TRIANGULO - {(-3, 1), (2, -2) (1, 3)}" , "At main.cpp line " + std::to_string(__LINE__));

    }

    {
        BEGIN_TEST( tm,"Area of Triangle", "Input: (-2, -1), (2, 0) (-2, 2); testing if area equal to -1 and adding more than 3 points;");
        FiguraGeometrica f("T4",1);
        f.addPoint({-3, 0});
        
        auto result = f.getArea();
        EXPECT_TRUE( f_equals(result, -1) , "At main.cpp line " + std::to_string(__LINE__));
        f.addPoint({0, 0});
        f.addPoint({-1, 3});
        EXPECT_FALSE( f.addPoint({2, 3}) , "At main.cpp line " + std::to_string(__LINE__));
    }


    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
