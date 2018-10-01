#include <iostream>
#include <SDL.h>
#include <cstdlib>
#include "engineMain(Engine).h"

void engine::gameRuntime::setup() {

    this->makeWindow(1200, 900);

    SDL_GetWindowSize(mainWindow, &dimensions[0], &dimensions[1]);

};

void engine::gameRuntime::update() {

    SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
    SDL_RenderClear(mainRenderer);

    SDL_RenderPresent(mainRenderer);

};

int main(int argc, char* args[]) {

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

        std::cout << "sdl init error: " << SDL_GetError() << std::endl;
        return 1;

    }

    engine::gameRuntime* game = new engine::gameRuntime();

    game->gameLoop();

    delete game;
    game = nullptr;

    SDL_Quit();

    return 0;

};
