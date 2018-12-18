#include <iostream>
#include <thread>
#include <windows.h>


#include "Centralizer.h"
#include "Window.h"

using namespace std;
using namespace graphic;

int main( int argc, char * argv[] ){
    int *a = new int;
    cin>>*a;
    *a *= 2;
    cout<<*a<<endl;
    SDL_Delay(500);
    delete a;

    Screen screen;
    Centralizer center;

    center.setWindow(&screen);

    screen.initialize();

    //thread th2(threader, &screen, &center);

    while( screen.processEvent() != 1 ){
        center.menu();
    }

    //th2.join();
    return 0;
}
