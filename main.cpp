#include <iostream>
#include "Centralizer.h"
#include "Window.h"

using namespace std;
using namespace graphic;

int main( int argc, char * argv[] ){


    Centralizer center;
    Screen screen;

    center.setWindow(&screen);

    //cout<<"Enter number of element you want to draw"<<endl;

    screen.initialize();
    screen.update();

    bool wasDisplayed = 0;

    while(screen.processEvent() != 1){

        if(!wasDisplayed){
            cout<<"Render window sleeping!"<<endl<<endl<<"Press CTRL for menu"<<endl;
            wasDisplayed = 1;
        }

        screen.update();

        if(GetAsyncKeyState(VK_CONTROL)){
            system("cls");
            center.menu();
            wasDisplayed = 0;
        }

    }

    return 0;
}
