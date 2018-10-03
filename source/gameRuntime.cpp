#include "gameRuntime.h"
#include <SDL.h>
#include <string>
#include <iostream>

void engine::gameRuntime::makeWindow(short width, short height, std::string title) {

    SDL_SetWindowSize(mainWindow, width, height); //Sets the window size
    SDL_SetWindowTitle(mainWindow, title.c_str()); //sets the window title

};


void engine::gameRuntime::gameLoop() {

    setup(); //calls the setup function

    while (running) { //game loop

        while (SDL_PollEvent(&event)) { //updates the event queue

            if (event.type == SDL_QUIT) {running = false;} //ends the loop if window is closed

        }

        update(); //calls the update function

    }

};


