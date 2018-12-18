#ifndef RECT_H
#define RECT_H

#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

namespace graphic{

struct Rect{

private:

public:
    string name;



    int x;
    int y;
    int w;
    int h;


    Rect();
    Rect(int x, int y, int w, int h);

    void setValues();
    void getValues();

    ~Rect();

};

}

#endif // RECT_H
