#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include "engineUtils.h"

void engineUtils::clearScreen(SDL_Renderer* renderer, short r, short g, short b, short a) { //the definition of a function that clears the screen and fills it with a specified colour

    SDL_SetRenderDrawColor(renderer, r, g, b, a); //sets the window renderer to that specified by the arguments
    SDL_RenderClear(renderer); //clears the window and fills with the colour

};

void engineUtils::engineRect::drawRect(SDL_Renderer* renderer, short r, short g, short b, short a) { //draws the rectangle based on the object

    /* to draw the rectangle the SDL_RenderDrawLines is used, to use this function you must provide a list of points with the first
       being the origin and the last being the endpoint therefore to create a closed shape the last point will be equal to the first.
       So to draw the Rectangle you start with the origin proceed to the next points as it works its way around in a clockwise way
       until it reaches the last point which is equal to the first point
    */

    SDL_Point tempPoints[] = {pointList[0], pointList[1], pointList[2], pointList[3], pointList[0]}; //declaring the point list

    SDL_SetRenderDrawColor(renderer, r, g, b, a); //setting the colour
    SDL_RenderDrawLines(renderer, tempPoints, 5); //supplying the renderer, pointList and amount of points to the function

};

float engineUtils::rads2Degs(float angle) {return angle * (180 / 3.14159265358979);}; //converts a value in radians to degrees by multiplying by 180 divided by pi

float engineUtils::degs2Rads(float angle) {return angle / (180 / 3.14159265358979);}; //converts a value in degrees to radians by dividing by 180 divided by pi

void engineUtils::engineRect::rotateRect(signed short rotation) {

        rotationCurrent += rotation;

        rotation = rotationCurrent;

        pointList[0] = {(std::cos(degs2Rads(pointAngles[0] + rotation)) * hypotenuse) + centerPoint.x, (std::sin(degs2Rads(pointAngles[0] + rotation)) * hypotenuse) + centerPoint.y};
        pointList[1] = {(std::cos(degs2Rads(pointAngles[1] + rotation)) * hypotenuse) + centerPoint.x, (std::sin(degs2Rads(pointAngles[1] + rotation)) * hypotenuse) + centerPoint.y};
        pointList[3] = {(std::cos(degs2Rads(pointAngles[2] + rotation)) * hypotenuse) + centerPoint.x, (std::sin(degs2Rads(pointAngles[2] + rotation)) * hypotenuse) + centerPoint.y};
        pointList[2] = {(std::cos(degs2Rads(pointAngles[3] + rotation)) * hypotenuse) + centerPoint.x, (std::sin(degs2Rads(pointAngles[3] + rotation)) * hypotenuse) + centerPoint.y};

};

void engineUtils::engineRect::moveRect(signed short x, signed short y) {

    centerPoint.x += x;
    centerPoint.y += y;

    pointList[0] = {(std::cos(degs2Rads(pointAngles[0] + rotationCurrent)) * hypotenuse) + centerPoint.x, (std::sin(degs2Rads(pointAngles[0] + rotationCurrent)) * hypotenuse) + centerPoint.y};
    pointList[1] = {(std::cos(degs2Rads(pointAngles[1] + rotationCurrent)) * hypotenuse) + centerPoint.x, (std::sin(degs2Rads(pointAngles[1] + rotationCurrent)) * hypotenuse) + centerPoint.y};
    pointList[3] = {(std::cos(degs2Rads(pointAngles[2] + rotationCurrent)) * hypotenuse) + centerPoint.x, (std::sin(degs2Rads(pointAngles[2] + rotationCurrent)) * hypotenuse) + centerPoint.y};
    pointList[2] = {(std::cos(degs2Rads(pointAngles[3] + rotationCurrent)) * hypotenuse) + centerPoint.x, (std::sin(degs2Rads(pointAngles[3] + rotationCurrent)) * hypotenuse) + centerPoint.y};

};

SDL_Texture* engineUtils::loadTexture(std::string path) {


};
