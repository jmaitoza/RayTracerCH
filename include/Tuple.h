//
// Created by joshm on 12/21/2022.
//
#ifndef RAYTRACERCH_TUPLE_H
#define RAYTRACERCH_TUPLE_H

#include <iostream>
#define EPSILON 0.0001f     //used to compare floating pnt numbers

class Tuple
{
public:
    float x,y,z,w;
    Tuple();
    Tuple(float x, float y, float z, float w);
    bool isPoint() const; //w = 1
    bool isVector() const; //w = 0


};

Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);
bool Equals(float a, float b);

#endif //RAYTRACERCH_TUPLE_H
