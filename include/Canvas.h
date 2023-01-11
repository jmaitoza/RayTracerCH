//
// Created by joshm on 1/11/2023.
//

#ifndef RAYTRACERCH_CANVAS_H
#define RAYTRACERCH_CANVAS_H
#include "Tuple.h"

class Canvas {
public:
    float width, hight;
    Canvas();
    Canvas(float width,float hight);

    void writePixel(Canvas canvas, float x, float y, Tuple color);
    //TODO
    // pixelAt() method
};


#endif //RAYTRACERCH_CANVAS_H
