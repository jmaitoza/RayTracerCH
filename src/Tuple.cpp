//
// Created by joshm on 12/21/2022.
//
#include "../include/Tuple.h"
#include <cmath>


//Tuple Constructor -- default
Tuple::Tuple()
{
    this->x = 0.0;
    this->y = 0.0;
    this->z = 0.0;
    this->w = 0.0;
}

// constructor
Tuple::Tuple(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

bool Tuple::isPoint() const {
   if (this->w == 1.0)
      return true;
   else
       return false;
}

bool Tuple::isVector() const {
    if (this->w == 0.0)
        return true;
    else
        return false;
}

bool operator==(const Tuple &t1, const Tuple &t2) {
    if(floatEquals(t1.x, t2.x) && floatEquals(t1.y, t2.y) && floatEquals(t1.z, t2.z) && floatEquals(t1.w, t2.w))
        return true;
    else
        return false;
}

Tuple operator+(const Tuple &t1, const Tuple &t2)
{
    Tuple t3;
    t3.x = t1.x + t2.x;
    t3.y = t1.y + t2.y;
    t3.z = t1.z + t2.z;
    t3.w = t1.w + t2.w;
    return t3;
}

Tuple operator-(const Tuple &t1, const Tuple &t2) {
   Tuple t3;
    t3.x = t1.x - t2.x;
    t3.y = t1.y - t2.y;
    t3.z = t1.z - t2.z;
    t3.w = t1.w - t2.w;
    return t3;
}

Tuple Point(float x, float y, float z) //w = 1
{
    Tuple p = Tuple(x,y,z,1.0);
    return p;
}
Tuple Vector(float x, float y, float z) //w = 0
{
    Tuple v = Tuple(x,y,z,0.0);
    return v;
}
bool floatEquals(float a, float b)
{
    //check if two floats are functionally equivalent by comparing against round off constant
    if ((a-b) < EPSILON)
        return true;
    else
        return false;
}

// see if i can simplify this better
//bool tupEquals(Tuple t1, Tuple t2)
//{
//    //compare if two tuple objects are equal
//    if (floatEquals(t1.x, t2.x) && floatEquals(t1.y, t2.y) && floatEquals(t1.z, t2.z) && floatEquals(t1.w, t2.w))
//        return true;
//    else
//        return false;
//}
