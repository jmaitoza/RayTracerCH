//
// Created by joshm on 12/21/2022.
//
#ifndef RAYTRACERCH_TUPLE_H
#define RAYTRACERCH_TUPLE_H

#include <iostream>
#define EPSILON 0.0001f     //used to compare floating pnt numbers

class Tuple {
public:
    float x, y, z, w;
    float red, green, blue;
    Tuple();
    Tuple(float x, float y, float z, float w);
    bool isPoint() const; //w = 1
    bool isVector() const; //w = 0

    //use friend function for standard tuple arithmetic operations
    friend bool operator==(const Tuple &t1, const Tuple &t2);
    friend Tuple operator+(const Tuple &t1, const Tuple &t2);
    friend Tuple operator-(const Tuple &t1, const Tuple &t2);
    friend Tuple operator-(const Tuple &t1); // negation of singular tuple
    friend Tuple operator*(const Tuple &t1, float scalar);
    friend Tuple operator/(const Tuple &t1, float scalar);

    static Tuple Color(float red, float green, float blue);
};


Tuple Point(float x, float y, float z);
Tuple Vector(float x, float y, float z);
//    Tuple Color(float x, float y, float z);
bool Equals(float a, float b);
float Magnitude(const Tuple &v1); // always a vector
Tuple Normalize(const Tuple &v1);
float Dot(const Tuple &v1, const Tuple &v2);
Tuple Cross(const Tuple &v1, const Tuple &v2);
void printTuple(const Tuple &t1);
Tuple HadamardProduct(const Tuple &c1, const Tuple &c2);
#endif //RAYTRACERCH_TUPLE_H
