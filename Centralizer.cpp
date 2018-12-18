#include "Centralizer.h"

namespace graphic{

Centralizer::Centralizer():
    pWindow(NULL)
{
    //ctor
}

void Centralizer::addElement() {



    if(pWindow == NULL){

        cout<<"No window selected. If attempted to draw in this state, the results may be critical"<<endl;
        return;
    }

    string m_elementName;

    system("cls");
    cout<<"Enter element's name > "<<flush;
    cin>>m_elementName;

    for(unsigned int i=0; i<m_elementName.length(); i++){
        m_elementName[i] = tolower(m_elementName[i]);
    }

    container.insert(make_pair(m_elementName, new Rect()));

}

void Centralizer::callElement(){
    system("cls");
    cout<<"Enter element name you want to search > "<<flush;
    cin>>m_elementName;

    if(container.find(m_elementName) != container.end()){
        cout<<"Element found!"<<endl<<endl;
    }else{
        cout<<"No result found"<<endl;
        return;
    }

//    container[m_elementName].setValues();
}


void Centralizer::renderAllElements(){

    system("cls");

    for(auto m_iterator : container){
        cout<<"KEY: "<<m_iterator.first<<" -> "<<m_iterator.second<<endl;
        Rect *pRect = m_iterator.second;
        Rect &pToRender = *pRect;

        pWindow->drawRect(*&pToRender);
    }

    m_iterator = container.begin();

}

void Centralizer::menu(){
    stringstream ss;
    ss<<"Press the following keys for:"<<endl<<endl;
    ss<<"SPACE New Rectangle"<<endl;

    cout<<ss.str()<<endl;

    do{

//        pWindow->update();

    }while( !GetAsyncKeyState(VK_SPACE) );

    addElement();
    renderAllElements();

}

void Centralizer::clearMemory(){


    for ( auto m_iterator : container){

        delete m_iterator.second;
        cout<<"DELETED element at KEY "<<m_iterator.first<<" -> "<<m_iterator.second<<endl;

    }

    container.clear();

}

Centralizer::~Centralizer()
{
    clearMemory();
}

}
