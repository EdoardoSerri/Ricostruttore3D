
#include "Bidimensionale.h"

Bidimensionale::Bidimensionale(const std::string &pathName, const std::string &imgName, const int &nImages):Immagine(pathName,imgName),file(cv::imread(estraiNome(),cv::IMREAD_GRAYSCALE)),size(file.size())
{
    std::cout<<this->estraiNome()<<std::endl;
}
Bidimensionale::~Bidimensionale(){
    std::cout<<"Immagine ";
    Immagine::toString();
    std::cout<<" distrutta!"<<std::endl;
}
std::string Bidimensionale::estraiNome()const{
    return Immagine::toString();
}
cv::Mat Bidimensionale::estraiFile()const{
    return this->file;
}
cv::Size Bidimensionale::estraiSize()const{
    return this->size;
}
void Bidimensionale::salva()const{
    std::cout<< "Nome immagine: ";
    std::cout<<this->estraiNome()<<std::endl;
    std::cout<<". Salvata! "<<std::endl;
}
void Bidimensionale::stampa()const{
    cv::imshow(this->estraiNome(),this->estraiFile());
}

