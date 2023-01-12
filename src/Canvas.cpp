//
// Created by joshm on 1/11/2023.
//

#include "../include/Canvas.h"
#include <vector>

Canvas::Canvas()
{
    width = 0.0;
    height = 0.0;
}

Canvas::Canvas(float width, float height)
{
    this->width = width;
    this->height = height;
    // create a vector to store the canvas pixels based on the canvas width and height
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            Pixel pixel;
            pixel.x = static_cast<float>(i);
            pixel.y = static_cast<float>(j);
            pixel.color = Tuple::Color(0.0, 0.0, 0.0);
            canvasPixels.push_back(pixel);
        }
    }

    //info on 2d vectors based on Digital Ocean doc: https://www.digitalocean.com/community/tutorials/2d-vectors-in-c-plus-plus
}

void Canvas::writePixel(Canvas canvas, float x, float y, Tuple color)
{
    Pixel p = {x, y, color};
    // how should i make this pixel belong to this canvas?
    //canvasPixels.push_back(p);

}

Pixel Canvas::pixelAt(Canvas canvas, float x, float y)
{
}

int canvasMain()
{
    // initialize a canvas with a width of 2 and a height of 3

}

// might change this and do it how the book does it later, inheritance might get messy later on :shrug:
//Pixel::Pixel() {
//    x = 0.0;
//    y = 0.0;
//    Tuple::Color(0, 0, 0);
//}
//
//Pixel::Pixel(float x, float y, Tuple color)
//{
//    this->x = x;
//    this->y = y;
//    this->color = color; // might be a possible bug, could need to use Equals from Tuple class
//}
//
//void Pixel::writePixel(Canvas can, float x, float y, Tuple color)
//{
//    Pixel pix = Pixel(x, y, color);
//
//
//}
