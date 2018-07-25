//
//  Immagine.cpp
//  Classe Immagine
//
#include "Immagine.h"
Immagine::Immagine(const std::string &pathName,const std::string &name):path(pathName),nome(name)
{
    // empty body
}
Immagine::~Immagine(){
    std::cout<<"Distruzione della classe immagine "<<std::endl;
}
std::string Immagine::toString()const{
    return this->path+"/"+this->nome;
}
