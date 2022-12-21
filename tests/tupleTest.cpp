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
            CHECK(Equals(a.x, 4.3));
        }
        AND_THEN("a.y = -4.2")
        {
            CHECK(Equals(a.y, -4.2));
        }
        AND_THEN("a.z = 3.1")
        {
            CHECK(Equals(a.z, 3.1));
        }
        AND_THEN("a.w = 1.0")
        {
            CHECK(Equals(a.w, 1.0));
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
            CHECK(Equals(a.x, 4.3));
        }
        AND_THEN("a.y = -4.2")
        {
            CHECK(Equals(a.y,-4.2));
        }
        AND_THEN("a.z = 3.1")
        {
            CHECK(Equals(a.z, 3.1));
        }
        AND_THEN("a.w = 0.0")
        {
            CHECK(Equals(a.w, 0.0));
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

