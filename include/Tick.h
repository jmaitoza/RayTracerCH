//
// Created by joshm on 1/10/2023.
//

#ifndef RAYTRACERCH_TICK_H
#define RAYTRACERCH_TICK_H
//create header file based on Tick.cpp
#include "../include/Tuple.h"
#include <iostream>
#include <chrono>
#include <thread>

struct Projectile {

    Tuple position; //a point
    Tuple velocity; // a vector

};

struct Environment {

    Tuple gravity; // a vector
    Tuple wind; // a vector

};

//returns a new projectile, representing the given projectile after one unit of time has passed. (1 second)
Projectile tick(Environment env, Projectile proj)
{
    auto position = proj.position + proj.velocity;
    auto velocity = proj.velocity + env.gravity + env.wind;
    return {position, velocity};
}

int Tick()
{
    using namespace std::this_thread;
    using namespace std::chrono_literals;
    using std::chrono::system_clock;

    // projectile starts one unit above the origin
//    velocity is normalized to 1 unit/tick
    struct Projectile p = {Point(0, 1, 0), Normalize(Vector(1, 1, 0))};
    //modify initial velocity here
    p.velocity = p.velocity*69.0;

    // gravity -0.1 unit/tick, and wind is -0.01 unit/tick
    struct Environment e = {Vector(0, -3000.1, 0), Vector(-12.01, 0, 0)};

    int count = 0;
    std::cout<< "starting pos: ";
    printTuple(p.position);
    std::cout << " [x,y,z,w] respectively" << std::endl;
    while (p.position.y > 0)
    {
        p = tick(e,p);
        count++;
        std::cout << "position: ";
        printTuple(p.position);
        std::cout << std::endl;
        std::this_thread::sleep_for(1ms);
    }
    std::cout << "The projectile hit the ground after tick number " << count << std::endl;
    std::cout << "Final projectile position: ";
    printTuple(p.position);
    std::cout << std::endl;

    return 0;
}


#endif //RAYTRACERCH_TICK_H
