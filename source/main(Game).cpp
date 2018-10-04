#include <iostream>
#include <SDL.h>
#include "engineMain(Engine).h" //includes the game engine main header

void engine::gameRuntime::setup() { //Declares all the tasks to be performed befor the gameloop starts

    this->makeWindow(1200, 900); //make the window with dimensions 1200x900 with the default caption

    rectVector.push_back(engineUtils::engineRect(400, 400, 80, 30, 0));

};

void engine::gameRuntime::update() { //the update method to be called once per loop(Kind of)

    SDL_SetRenderDrawColor(mainRenderer, 230, 230, 255, 255);
    SDL_RenderClear(mainRenderer); //clears the screen

    if (keyboardState[SDL_SCANCODE_LEFT]) {

        rectVector[0].rotateRect(1);

    }

    if (keyboardState[SDL_SCANCODE_RIGHT]) {

        rectVector[0].rotateRect(-1);

    }

    rectVector[0].drawRect(mainRenderer, 255, 0, 0);

    SDL_RenderPresent(mainRenderer); // presents the changes to the renderer

};

int main(int argc, char* args[]) {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { //Checks whether SDL initialises properly and if not prints the error and ends the function

        std::cout << "sdl init error: " << SDL_GetError() << std::endl;
        return 1;

    }

    engine::gameRuntime* game = new engine::gameRuntime(); //creates a new instance of the class gameRuntime

    game->gameLoop(); //the gameRuntime object calls the game loop method

    delete game; //deletes the object
    game = nullptr; //sets the pointer to nullptr to avoid dangling pointers

    SDL_Quit(); //de initialises SDL

    return 0;

};
