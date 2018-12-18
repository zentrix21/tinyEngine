#include <iostream>
#include <SDL2/SDL.h>

#include "Window.h"
#include "Rect.h"

using namespace std;

namespace graphic{

Screen::Screen():
        m_render(NULL), m_window(NULL), m_texture(NULL), m_buffer(NULL)
{}


bool Screen::initialize(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout<<"SDL Initialization failed"<<endl;
        return false;
    }

    m_window = SDL_CreateWindow("New Screen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    m_render = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    m_texture = SDL_CreateTexture(m_render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, WIDTH, HEIGHT);
    m_buffer = new Uint32[WIDTH * HEIGHT];

    if(m_window == NULL){
        cout<<"SDL_Screen Couldn't be Initialized"<<endl;
        return false;
    }



    if(m_render == NULL){
        cout<<"Renderer Couldn't be created"<<endl;
        SDL_DestroyWindow(m_window);
        return false;
    }


    if(m_texture == NULL){
        cout<<"Couldn't initialize SDL_Texture"<<endl;
        return false;
    }

    th_updater = thread(&Screen::update, this);

    return true;
}

void Screen::setPixel(int x, int y, Uint32 red, Uint32 green, Uint32 blue){

    //cout<<"Pixel set"<<endl;

    if(x < 0 || y < 0){
        system("cls");
        cout<<"Invalid X, Y or coordinates"<<endl;
        return;
    }else if(y>HEIGHT){
        y -= (y/HEIGHT) * HEIGHT;
    }else if(x>HEIGHT){
        x -= (x/WIDTH) * WIDTH;
    }


    Uint32 color = 0;

    color += red;
    color <<= 8;

    color += green;
    color <<= 8;

    color += blue;
    color <<= 8;

    color += 0xFF;

    m_buffer[ (y * WIDTH) + x] = color;


}

int Screen::processEvent(){

    SDL_Event event;

    while(SDL_PollEvent(&event)){

        if(event.type == SDL_QUIT) return 1;

    }

    return 0;
}


void Screen::drawRect(Rect rectangle){

    for(int height=rectangle.y; height <= rectangle.y+rectangle.h; height++){
        for(int lgth=rectangle.x; lgth <= rectangle.x+rectangle.w; lgth++){
            setPixel(lgth, height, 128, 128, 128);
        }
    }

}

void Screen::drawRect(Rect* rectangle){

    cout<<"DRAWN OBJECT: RCT"<<endl;

    for(int height=rectangle->y; height <= (rectangle->y)+(rectangle->h); height++){
        for(int lgth=rectangle->x; lgth <= (rectangle->x)+(rectangle->w); lgth++){
            setPixel(lgth, height, 128, 128, 128);
        }
    }

}

void Screen::update(){

    SDL_UpdateTexture(m_texture, NULL, m_buffer, WIDTH*sizeof(Uint32));
    SDL_RenderClear(m_render);
    SDL_RenderCopy(m_render, m_texture, NULL, NULL);
    SDL_RenderPresent(m_render);

}

void Screen::close(){

    if(th_updater.joinable())th_updater.join();
    SDL_DestroyRenderer(m_render);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();

}

Screen::~Screen(){
    close();
}}
