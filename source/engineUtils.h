#include <SDL.h>
#include <cmath>
#include <iostream>
#ifndef ENGINEUTILS_H_INCLUDED
#define ENGINEUTILS_H_INCLUDED

namespace engineUtils {

    void clearScreen(SDL_Renderer* renderer, short r, short g, short b, short a = 255); //clears the screen and fills with a specified colour

    float rads2Degs(float angle); //converts radians to degrees
    float degs2Rads(float angle); //converts degrees to radians

    class engineRect { //rectangle class to be used throughout the engine

    private:

        SDL_Point pointList[4]; //the list of points that make up the rectangle
        SDL_Point centerPoint; //the point in the centre of the rectangle

        short hypotenuse; //the distance between the centre and the corner of the rectangle
        short baseAngle1; //the larger angle equal to 90 degrees minus the inverse tangent of the height divided by the width
        short baseAngle2; //the smaller angle equal to 90 degrees minus the inverse tangent of the width divided by the height
        short pointAngles[4]; //the angles that relate to the points

    public:

        signed short rotationCurrent {0};

        void drawRect(SDL_Renderer* renderer, short r, short g, short b, short a = 255); //draws the rectangle itself

        engineRect(short x, short y, short width, short height, short rotation) { //constructor taking position, dimensions and rotation as parameters

            hypotenuse = std::sqrt(std::pow(width, 2) + std::pow(height, 2)); //copies a value to the hypotenuse

            centerPoint = {(x + width) / 2, (y + height) / 2};

            //std::cout << hypotenuse << std::endl;

            baseAngle1 = std::ceil(90 - rads2Degs(std::atan2(height / 2, width / 2))); //copies a value to baseAngle1
            baseAngle2 = std::floor(90 - rads2Degs(std::atan2(width / 2, height / 2))); //copies a value to baseAngle2

            //std::cout << baseAngle1 << ", " << baseAngle2 << std::endl;

            pointAngles[0] = baseAngle1 + 90;
            pointAngles[1] = baseAngle2;
            pointAngles[2] = baseAngle2 + 180;
            pointAngles[3] = baseAngle1 + 270;

            //std::cout << pointAngles[3] << std::endl;

            pointList[0] = {static_cast<short>((std::cos(degs2Rads(pointAngles[0] + rotation)) * hypotenuse) + centerPoint.x), static_cast<short>((std::sin(degs2Rads(pointAngles[0] + rotation)) * hypotenuse) + centerPoint.y)};
            pointList[1] = {static_cast<short>((std::cos(degs2Rads(pointAngles[1] + rotation)) * hypotenuse) + centerPoint.x), static_cast<short>((std::sin(degs2Rads(pointAngles[1] + rotation)) * hypotenuse) + centerPoint.y)};
            pointList[3] = {static_cast<short>((std::cos(degs2Rads(pointAngles[2] + rotation)) * hypotenuse) + centerPoint.x), static_cast<short>((std::sin(degs2Rads(pointAngles[2] + rotation)) * hypotenuse) + centerPoint.y)};
            pointList[2] = {static_cast<short>((std::cos(degs2Rads(pointAngles[3] + rotation)) * hypotenuse) + centerPoint.x), static_cast<short>((std::sin(degs2Rads(pointAngles[3] + rotation)) * hypotenuse) + centerPoint.y)};

        }

        void rotateRect(signed short rotation);

    };

};

#endif // ENGINEUTILS_H_INCLUDED
