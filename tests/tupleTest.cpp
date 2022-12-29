//
// Created by joshm on 12/19/2022.
//
#include "doctest.h"
#include "../include/Tuple.h"

//gherkin syntax
//Scenario: A tuple with w=1.0 is a point
//        Given a <- tuple(4.3, -4.2, 3.1, 1.0)
//        Then a.x = 4.3
//            And a.y = -4.2
//            And a.z = 3.1
//            And a.w = 1.0
//            And a is a point
//            And a is not a vector

//doctest syntax
SCENARIO("A tuple with w=1.0 is a point")
{
    GIVEN("A tuple with w=1.0 is a point")
    {
        auto a = Tuple(4.3, -4.2, 3.1, 1.0);
        THEN("a.x = 4.3")
        {
            CHECK(floatEquals(a.x, 4.3));
        }
        AND_THEN("a.y = -4.2")
        {
            CHECK(floatEquals(a.y, -4.2));
        }
        AND_THEN("a.z = 3.1")
        {
            CHECK(floatEquals(a.z, 3.1));
        }
        AND_THEN("a.w = 1.0")
        {
            CHECK(floatEquals(a.w, 1.0));
        }
        AND_THEN("a is a point")
        {
            CHECK(a.isPoint());
        }
        AND_THEN("a is not a vector")
        {
            CHECK_FALSE(a.isVector());
        }
    }
}

//gherkin syntax
//Scenario: A tuple with w=0 is a vector
//        Given a ← tuple(4.3, -4.2, 3.1, 0.0)
//Then a.x = 4.3
//And a.y = -4.2
//And a.z = 3.1
//And a.w = 0.0
//And a is not a point
//And a is a vector

//doctest syntax
SCENARIO("A tuple with w=0 is a vector")
{
    GIVEN("A tuple with w=0 is a vector")
    {
        auto a = Tuple(4.3, -4.2, 3.1, 0.0);
        THEN("a.x = 4.3")
        {
            CHECK(floatEquals(a.x, 4.3));
        }
        AND_THEN("a.y = -4.2")
        {
            CHECK(floatEquals(a.y, -4.2));
        }
        AND_THEN("a.z = 3.1")
        {
            CHECK(floatEquals(a.z, 3.1));
        }
        AND_THEN("a.w = 0.0")
        {
            CHECK(floatEquals(a.w, 0.0));
        }
        AND_THEN("a is not a point")
        {
            CHECK_FALSE(a.isPoint());
        }
        AND_THEN("a is a vector")
        {
            CHECK(a.isVector());
        }
    }
}

//gherkin syntax
//Scenario: point() creates tuples with w=1
//        Given p ← point(4, -4, 3)
//        Then p = tuple(4, -4, 3, 1)
//Scenario: vector() creates tuples with w=0
//        Given v ← vector(4, -4, 3)
//        Then v = tuple(4, -4, 3, 0)

//doctest syntax
SCENARIO("point() creates tuples with w=1")
{
    GIVEN("point() creates tuples with w=1")
    {
        auto p = Point(4, -4, 3);

        REQUIRE(p.x == 4);
        REQUIRE(p.y == -4);
        REQUIRE(p.z == 3);

        THEN("p = tuple(4, -4, 3, 1)")
        {
            //CHECK(p == Tuple(4, -4, 3, 1));
//            CHECK(p.x == 4);
//            CHECK(p.x == -4);
//            CHECK(p.x == 3);
            CHECK(p.w == 1);
        }
    }
}
SCENARIO("vector() creates tuples with w=0")
{
    GIVEN("vector() creates tuples with w=0")
    {
        auto v = Vector(4, -4, 3);

        REQUIRE(v.x == 4);
        REQUIRE(v.y == -4);
        REQUIRE(v.z == 3);

        THEN("v = tuple(4, -4, 3, 0)")
        {
            //CHECK(v == Tuple(4, -4, 3, 0));
            CHECK(v.w == 0.0);
        }
    }
}

SCENARIO("Adding two tuples")
{
    GIVEN("Adding two tuples")
    {
        auto a1 = Tuple(3, -2, 5, 1);
        auto a2 = Tuple(-2, 3, 1, 0);

        auto result = a1 + a2;

        THEN("result = tuple(1, 1, 6, 1)")
        {
            CHECK(result == Tuple(1, 1, 6, 1));
        }
    }
}

SCENARIO("Subtracting two points")
{
    GIVEN("Subtracting two points")
    {
        auto p1 = Point(3, 2, 1);
        auto p2 = Point(5, 6, 7);

        auto result = p1 - p2;

        THEN("result = vector(-2, -4, -6)")
        {
            CHECK(result == Vector(-2, -4, -6));
        }
    }
}

SCENARIO("Subtracting a vector from a point")
{
    GIVEN("Subtracting a vector from a point")
    {
        auto p = Point(3, 2, 1);
        auto v = Vector(5, 6, 7);

        auto result = p - v;

        THEN("result = point(-2, -4, -6)")
        {
            CHECK(result == Point(-2, -4, -6));
        }
    }
}

SCENARIO("Subtracting two vectors")
{
    GIVEN("Subtracting two vectors")
    {
        auto v1 = Vector(3, 2, 1);
        auto v2 = Vector(5, 6, 7);

        auto result = v1 - v2;

        THEN("result = vector(-2, -4, -6)")
        {
            CHECK(result == Vector(-2, -4, -6));
        }
    }
}

SCENARIO("Subtracting a vector from the zero vector")
{
    GIVEN("Subtracting a vector from the zero vector")
    {
        auto zero = Vector(0, 0, 0);
        auto v = Vector(1, -2, 3);

        auto result = zero - v;

        THEN("result = vector(-1, 2, -3)")
        {
            CHECK(result == Vector(-1, 2, -3));
        }
    }
}

SCENARIO("Negating a tuple")
{
    GIVEN("Negating a tuple")
    {
        auto a = Tuple(1, -2, 3, -4);

        auto result = -a;

        THEN("result = tuple(-1, 2, -3, 4)")
        {
            CHECK(result == Tuple(-1, 2, -3, 4));
        }
    }
}

SCENARIO("Multiplying a tuple by a scalar")
{
    GIVEN("Multiplying a tuple by a scalar")
    {
        auto a = Tuple(1, -2, 3, -4);

        auto result = a * 3.5;

        THEN("result = tuple(3.5, -7, 10.5, -14)")
        {
            CHECK(result == Tuple(3.5, -7, 10.5, -14));
        }
    }
}

SCENARIO("Multiplying a tuple by a fraction")
{
    GIVEN("Multiplying a tuple by a fraction")
    {
        auto a = Tuple(1, -2, 3, -4);

        auto result = a * 0.5;

        THEN("result = tuple(0.5, -1, 1.5, -2)")
        {
            CHECK(result == Tuple(0.5, -1, 1.5, -2));
        }
    }
}

SCENARIO("Dividing a tuple by a scalar")
{
    GIVEN("Dividing a tuple by a scalar")
    {
        auto a = Tuple(1, -2, 3, -4);

        auto result = a / 2;

        THEN("result = tuple(0.5, -1, 1.5, -2)")
        {
            CHECK(result == Tuple(0.5, -1, 1.5, -2));
        }
    }
}

