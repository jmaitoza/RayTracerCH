//
// Created by joshm on 1/11/2023.
//

#ifndef RAYTRACERCH_CANVAS_H
#define RAYTRACERCH_CANVAS_H
#include "Tuple.h"
#include <vector>

struct Pixel
{
    float x{};
    float y{};
    Tuple color;
};

class Canvas {
public:
    float width, height;
    std::vector<Pixel> canvasPixels;
//    std::vector<std::vector<Pixel>> canvasPixels;
    // iterator for the 2-D vector
    std::vector<std::vector<Pixel>>::iterator it1;
    // iterator for each vector inside the 2-D vector
    std::vector<Pixel>::iterator it2;
    Canvas();
    Canvas(float width, float height);
    void writePixel(Canvas canvas, float x, float y, Tuple color);
    //TODO
    // pixelAt() method
    Pixel pixelAt(Canvas canvas, float x, float y);
};

//class Pixel : public Canvas
//{
//public:
//    float x, y;
//    Tuple color;
//    Pixel();
//    Pixel(float x, float y, Tuple color);
//    void writePixel(Canvas can, float x, float y, Tuple color);
//};

#endif //RAYTRACERCH_CANVAS_H
