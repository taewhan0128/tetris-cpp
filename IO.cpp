#include "IO.h"
#include <stdio.h>
#include <stdlib.h>

static Uint32 mColors[COLOR_MAX] = {
    0xFF000000, // BLACK
    0xFF0000FF, // BLUE
    0xFF00FF00, // GREEN
    0xFFFF0000, // RED
    0xFFFFFF00, // CYAN
    0xFFFF00FF, // MAGENTA
    0xFF00FFFF, // YELLOW
    0xFFFFFFFF  // WHITE
};

IO::IO(){
    InitGraph();
}

void IO::ClearScreen(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void IO::DrawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC){
    boxColor(renderer, pX1, pY1, pX2, pY2-1, mColors[static_cast<int>(pC)]);
}

int IO::GetScreenHeight(){
    return 480;
}

void IO::UpdateScreen(){
    SDL_RenderPresent(renderer);
}

int IO::Pollkey(){
    SDL_Event event;

    if(SDL_PollEvent(&event))
    {
        if (event.type == SDL_KEYDOWN){
            return event.key.keysym.sym;
        }
        if (event.type == SDL_QUIT){
            exit(0);
        }
    }

    return -1;
}

int IO::Getkey(){
    SDL_Event event;

    while (true)
    {
        SDL_WaitEvent(&event);
        if (event.type == SDL_KEYDOWN){
            return event.key.keysym.sym;
        }
        if (event.type == SDL_QUIT){
            exit(0);
        }
    }
}

int IO::IsKeyDown(int pKey){
    SDL_PumpEvents();
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    SDL_Scancode sc = SDL_GetScancodeFromKey(pKey);
    return keystate[sc];
}

int IO::InitGraph(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow(
        "Tetris",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        720,
        480,
        SDL_WINDOW_SHOWN
    );

    if (!window)
    {
        printf("Window creation failed: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        return 1;
    }
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
    return 0;
}