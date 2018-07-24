//
//  classe Bidimensionale.cpp
//  Bidimensionale
//
//  Created by Crismesy ing on 22/05/18.
//  Copyright © 2018 Crismesy ing. All rights reserved.
//

#include "Bidimensionale.h"

Bidimensionale::Bidimensionale(const string &pathName, const string &imgName, const int &nImages):Immagine(pathName,imgName),file(imread(estraiNome(),CV_8UC1)),size(file.size())
{
    Immagine::print();
}
Bidimensionale::~Bidimensionale(){
    cout<<"Immagine ";
    Immagine::print();
    cout<<" distrutta!"<<endl;
}
string Bidimensionale::estraiNome()const{
    return Immagine::toString();
}
Mat Bidimensionale::estraiFile()const{
    return this->file;
}
Size Bidimensionale::estraiSize()const{
    return this->size;
}
void Bidimensionale::salva()const{
    cout<< "Nome immagine: ";
    Immagine::print();
    cout<<". Salvata! "<<endl;
}


