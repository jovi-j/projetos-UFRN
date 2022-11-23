#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

#include "test_manager.h"
#include "all_any_none_of.h"



int main ( void )
{
    TestManager tm{ "Interator Template Tests" };
    //== all_of

    std::cout<<"running tests"<<std::endl;

    {
        BEGIN_TEST( tm,"AllOf", "Input: 10, 20, 30, 40, 50, 60, 70; test if all are greater than 0; expecting True");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = all_of( std::begin(A), std::end(A),
                []( const int& e ){ return e > 0; } );

        EXPECT_TRUE( result, "At main.cpp line " + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm,"AllOf2", "Input: 10, 20, 30, 40, 50, 60, 70; test if all are less than 0; expecting False");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = all_of( std::begin(A), std::end(A),
                []( const int& e ){ return e < 0; } );

        EXPECT_FALSE( result, "At main.cpp line " + std::to_string(__LINE__) );
    }

    {
        BEGIN_TEST( tm,"AllOf3", "Input: 10, 20, 30, 40, 50, 60, 70; test if all are greater than 30; expecting False");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = all_of( std::begin(A), std::end(A),
                []( const int& e ){ return e > 30; } );

        EXPECT_FALSE( result, "At main.cpp line " + std::to_string(__LINE__) );
    }

    {
        BEGIN_TEST( tm,"AllOf4", "Input: Empty; test if all are greater than 30; expecting False");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = all_of( std::begin(A), std::begin(A),
                []( const int& e ){ return e > 30; } );

        EXPECT_FALSE( result, "At main.cpp line " + std::to_string(__LINE__) );
    }

    //== any_of

    {
        BEGIN_TEST( tm,"AnyOf", "Input: 10, 20, 30, 40, 50, 60, 70; test if any is greater than 0; expecting True");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = any_of( std::begin(A), std::end(A),
                []( const int& e ){ return e > 0; } );

        EXPECT_TRUE( result, "At main.cpp line " + std::to_string(__LINE__) );
    }

    {
        BEGIN_TEST( tm,"AnyOf1", "Input: 10, 20, 30, 40, 50, 60, 70; test if any is less than 0; expecting False");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = any_of( std::begin(A), std::end(A),
                []( const int& e ){ return e < 0; } );

        EXPECT_FALSE( result, "At main.cpp line " + std::to_string(__LINE__) );
    }

    {
        BEGIN_TEST( tm,"AnyOf2", "Input: 10, 20, 30, 40, 50, 60, 70; test if any is greater than 30; expecting True");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = any_of( std::begin(A), std::end(A),
                []( const int& e ){ return e > 30; } );

        EXPECT_TRUE( result, "At main.cpp line " + std::to_string(__LINE__) );
    }


    //== none_of

    {
        BEGIN_TEST( tm,"NoneOf", "Input: 10, 20, 30, 40, 50, 60, 70; test if all are not greater than 0; expecting False");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = none_of( std::begin(A), std::end(A),
                []( const int& e ){ return e > 0; } );

        EXPECT_FALSE( result, "At main.cpp line " + std::to_string(__LINE__) );
    }

    {
        BEGIN_TEST( tm,"NoneOf2", "Input: 10, 20, 30, 40, 50, 60, 70; test if all are not less than 0; expecting True");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = none_of( std::begin(A), std::end(A),
                []( const int& e ){ return e < 0; } );

        EXPECT_TRUE( result, "At main.cpp line " + std::to_string(__LINE__) );
    }

    {
        BEGIN_TEST( tm,"NoneOf3", "Input: 10, 20, 30, 40, 50, 60, 70; test if all are not greater than 30; expecting False");
        int A[]{ 10, 20, 30, 40, 50, 60, 70 };
        bool result;

        result = none_of( std::begin(A), std::end(A),
                []( const int& e ){ return e > 30; } );

        EXPECT_FALSE( result, "At main.cpp line " + std::to_string(__LINE__) );
    }


    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
