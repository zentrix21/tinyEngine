#ifndef Screen_H
#define Screen_H

#include <iostream>
#include <SDL.h>
#include <thread>

#include "Rect.h"

using namespace std;

namespace graphic{

class Screen{
public:
    const int WIDTH = 1024;
    const int HEIGHT = 720;

private:
    SDL_Renderer* m_render;
    SDL_Window* m_window;
    SDL_Texture* m_texture;

    Uint32* m_buffer = new Uint32[WIDTH * HEIGHT];
    thread th_updater;  //UNIMPLEMENTED IN THE CPP!!!!!!!!!!!!!!!!

public:

    Screen();
    ~Screen();

    bool initialize();
    int processEvent();
    void drawRect(Rect rectangle);
    void drawRect(Rect* rectangle);
    void update();
    void setPixel(int x, int y, Uint32 red, Uint32 green, Uint32 blue);
    void close();

};

}
#endif // Screen_H
