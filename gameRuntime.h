#include <SDL.h>
#include <string>

#ifndef GAMERUNTIME_H_INCLUDED
#define GAMERUNTIME_H_INCLUDED

namespace engine {

class gameRuntime {

    private:

        SDL_Window *mainWindow = SDL_CreateWindow("NULL", 0, 0, 64, 64, SDL_WINDOW_SHOWN);
        bool running = true;
        SDL_Event event;
        int dimensions[2] {0};


    public:

        bool makeWindow(short width = 800, short height = 600, std::string title = "New Window");

        SDL_Renderer *mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

        void update();

        void setup();

        void gameLoop();

        ~gameRuntime() {

            SDL_DestroyWindow(mainWindow);
            SDL_DestroyRenderer(mainRenderer);
            mainWindow = nullptr;
            mainRenderer = nullptr;

        };
};

};

#endif // GAMERUNTIME_H_INCLUDED
