#include "Rect.h"

using namespace std;

namespace graphic{


Rect::Rect()
{
    cout<<"Rectangle Created"<<endl;

    int nX, nY, nW, nH;

    cout<<"X > "<<flush;
    cin>>nX;
    //system("cls");

    cout<<"Y > "<<flush;
    cin>>nY;
    //system("cls");

    cout<<"W > "<<flush;
    cin>>nW;
    //system("cls");

    cout<<"H > "<<flush;
    cin>>nH;
    //system("cls");

    this->x = nX;
    this->y = nY;
    this->w = nW;
    this->h = nH;
}

Rect::Rect(int x, int y, int w, int h):
      x(x), y(y), w(w), h(h){

    cout<<"Rectangle created by Param. Constructor"<<endl;
}

void Rect::setValues(){


}

void Rect::getValues(){
    cout<<"X: "<<this->x<<endl<<"Y: "<<this->y<<endl<<"W: "<<this->w<<endl<<"H: "<<this->h<<endl;
}

Rect::~Rect()
{
    //dtor
}

} //NAMESPACE GRAPHIC
