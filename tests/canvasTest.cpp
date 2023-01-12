//
// Created by joshm on 1/11/2023.
//
#include "doctest.h"
#include "../include/Canvas.h"

//Scenario: Creating a canvas
//        Given c ← canvas(10, 20)
//Then c.width = 10
//And c.height = 20
//And every pixel of c is color(0, 0, 0)
//

SCENARIO("Creating a canvas")
{
    GIVEN("c = Canvas(10, 20)")
    {
        // c = Canvas(10 ,20);
        THEN("c.width = 10")
        {
//            CHECK(c.width == 10);
        }
        AND_THEN("c.height = 20")
        {
//            CHECK(c.height == 20);
        }
        AND_THEN("every pixel of c is Color(0, 0, 0)")
        {
            //CHECK()
        }
    }
}

//Scenario: Writing pixels to a canvas
//        Given c ← canvas(10, 20)
//And red ← color(1, 0, 0)
//When write_pixel(c, 2, 3, red)
//Then pixel_at(c, 2, 3) = red
