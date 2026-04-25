#ifndef _IO_
#define _IO_

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

enum color {
    BLACK, 
    RED, 
    GREEN, 
    BLUE, 
    CYAN, 
    MAGENTA, 
    YELLOW, 
    WHITE,
    COLOR_MAX
};

class IO
{
public:
    IO();
    void DrawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC);
    void ClearScreen();
    int GetScreenHeight();
    int InitGraph();
    int Pollkey();
    int Getkey();
    int IsKeyDown(int pKey);
    void UpdateScreen();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif