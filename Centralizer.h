#ifndef CENTRALIZER_H
#define CENTRALIZER_H

#include <iostream>
#include <map>
#include <string.h>
#include <windows.h>
#include "Rect.h"
#include "Window.h"

using namespace std;
namespace graphic{


class Centralizer{

private:

    string m_elementName;
    int m_elements=0;
    Screen *pWindow;

    map<string, Rect*> container;

public:

    map<string, Rect*>::iterator m_iterator = container.begin();

    Centralizer();
    ~Centralizer();

    void addElement();
    void callElement();
    void renderAllElements();
    void menu();

    void clearMemory();
    void setWindow(Screen *newValue){ pWindow = newValue;};

};


}
#endif // CENTRALIZER_H
