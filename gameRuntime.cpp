#include "gameRuntime.h"
#include <SDL.h>
#include <string>
#include <iostream>

bool engine::gameRuntime::makeWindow(short width, short height, std::string title) {

    SDL_SetWindowSize(mainWindow, width, height);
    SDL_SetWindowTitle(mainWindow, title.c_str());

};


void engine::gameRuntime::gameLoop() {

    setup();

    while (running) {

        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {running = false;}

        }

        update();

    }

};


