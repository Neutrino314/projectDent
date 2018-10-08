#include <SDL.h>
#include <string>
#include "engineUtils.h"
#include <vector>

#ifndef GAMERUNTIME_H_INCLUDED
#define GAMERUNTIME_H_INCLUDED

namespace engine {

class gameRuntime {

    private:

        SDL_Window *mainWindow = SDL_CreateWindow("NULL", 0, 0, 64, 64, SDL_WINDOW_SHOWN); //creating the window for the game
        bool running = true; //a running variable for the game loop
        SDL_Event event; //a variable to hold the SDL_Event queue
        int dimensions[2] {0}; //holds the size of the window

    public:

        void makeWindow(short width = 800, short height = 600, std::string title = "New Window"); //method that "creates the window" which resizes and changes the caption

        SDL_Renderer *mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); //creating the renderer

        void update(); //declaring the update method

        void setup(); //declaring the setup method

        void gameLoop(); //the game loop method that handles events and calls setup and update

        ~gameRuntime() { //DESTRUCTOR

            SDL_DestroyWindow(mainWindow); //Deletes the window
            SDL_DestroyRenderer(mainRenderer); //deletes the renderer
            mainWindow = nullptr; //removes the dangling pointer
            mainRenderer = nullptr; //removes the dangling pointer

        };
};

};

#endif // GAMERUNTIME_H_INCLUDED
