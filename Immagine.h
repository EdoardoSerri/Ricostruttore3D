//
//   Classe Immagine
//      Immagine.h

#ifndef Immagine_h
#define Immagine_h

#include <stdio.h>  //inclusione della libreria standard input output
#include <iostream> //inclusione della libreria per lo stream input output
#include <string>   //inclusione della libreria string
using namespace std;
class Immagine{
public:
    Immagine(const string &,const string &);        //Costruttore Immagine prende in ingresso 1: percorso cartella-string , 2: nome file-string
    ~Immagine();                                    //Distruttore classe Immagine
    virtual void print() const;                   //Metodo che stampa la path e il nome del file, metodo virtuale
    virtual void salva() const=0;                   //Metodo che salva il file immagine in base alla classe specializzata, metodo virtuale puro da implementare nelle classi derivate, per ogni specializzazione
    string toString() const; //Metodo che concatena i suoi data member path+"/"+nome
protected:
    const string path;    //attributo della classe immagine. L'immagine può risiedere in una cartella specifica
    const string nome;    //attributo della classe immagine. L'immagine è distinto dagli altri tramite il suo nome.
};

#endif /* Immagine_h */
