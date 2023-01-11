//
// Created by joshm on 12/21/2022.
//
#include "../include/Tuple.h"
#include <cmath>
#include <cassert> // assert preprocessor macro


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

// color tuple
Tuple Tuple::Color(float red, float green, float blue)
{
    Tuple c;
    c.red = red;
    c.green = green;
    c.blue = blue;
    return c;
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
    if(Equals(t1.x, t2.x) && Equals(t1.y, t2.y) && Equals(t1.z, t2.z) && Equals(t1.w, t2.w))
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

Tuple operator-(const Tuple &t1) {
   return {-t1.x, -t1.y, -t1.z, -t1.w};
}

Tuple operator*(const Tuple &t1, float scalar) {
   return {t1.x*scalar, t1.y*scalar, t1.z*scalar, t1.w*scalar};
}

Tuple operator/(const Tuple &t1, float scalar)
{
    return {t1.x/scalar, t1.y/scalar, t1.z/scalar, t1.w/scalar};
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
//Tuple Color(float x, float y, float z)
//{
//    // x coord = red, y coord = green, z coord = blue
//    float red = x;
//    float green = y;
//    float blue = z;
//
//    return Tuple(red, green, blue, 0);
//}

bool Equals(float a, float b)
{
    //check if two floats are functionally equivalent by comparing against round off constant
    if ((a-b) < EPSILON)
        return true;
    else
        return false;
}

float Magnitude(const Tuple &v1)
{
    // use pythagorius theorem to find magnitude of a vector
    float m = sqrtf((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z) + (v1.w * v1.w));
    return m;
}

Tuple Normalize(const Tuple &v1)
{
    return Tuple(v1.x/ Magnitude(v1),
                 v1.y/ Magnitude(v1),
                 v1.z/ Magnitude(v1),
                 v1.w/ Magnitude(v1));
}

float Dot(const Tuple &v1, const Tuple &v2)
{
    return (v1.x * v2.x) +
           (v1.y * v2.y) +
           (v1.z * v2.z) +
           (v1.w * v2.w);

}

Tuple Cross(const Tuple &v1, const Tuple &v2)
{
    assert(v1.isVector() && v2.isVector());
    return Vector((v1.y *v2.z)-(v1.z * v2.y),
                  (v1.z *v2.x)-(v1.x * v2.z),
                  (v1.x *v2.y)-(v1.y * v2.x));

}

void printTuple(const Tuple &t1) {
    std::cout << "(" << t1.x << ", " << t1.y << ", " << t1.z << ", " << t1.w << ")";
}

// multiply a color tuple by a color tuple
Tuple HadamardProduct(const Tuple &c1, const Tuple &c2)
{
    float red = c1.red * c2.red;
    float green = c1.green * c2.green;
    float blue = c1.blue * c2.blue;
    return Tuple::Color(red, green, blue);
}

