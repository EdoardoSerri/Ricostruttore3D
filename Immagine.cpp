//
//  Immagine.cpp
//  Classe Immagine
//
#include "Immagine.h"
using namespace std;
Immagine::Immagine(const string &pathName,const string &name):path(pathName),nome(name)
{
    // empty body
}
Immagine::~Immagine(){
    cout<<"Distruzione della classe immagine "<<endl;
}
void Immagine::print()const{
    cout<<"Il file si trova in "<<this->path<<"/"<<this->nome<<endl;
}
string Immagine::toString()const{
    return this->path+"/"+this->nome;
}
