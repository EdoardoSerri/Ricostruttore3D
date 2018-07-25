//
//  Configurazione.cpp
//
//  Creato da Cristian Greco s1053410
//
#include "Configurazione.h"

Configurazione::Configurazione(const vector<string> &files):file(files){
    //this->inizializzazioneParametri(); //Inizializzazione degli eventuali dati settati precedentemente
    Fl_Window *win = new Fl_Window(500, 300, "Parametri per la ricostruzione 3d");//Costruzione Finestra del matcher
    Fl_Clock *fcl=new Fl_Clock(400,10,50,50,"Team Alpha");  // Costruzione dell'orologio analogico e settaggio del nome: Nel caso scelto ho preferito inserire il nome del gruppo
    Fl_Progress *fpl=new Fl_Progress(20, 220, 150, 15,"Caricamento"+10); //Costruzione dello slider che fungerà da indicatore di completamento della ricostruzione
    fpl->maximum(100); //Imposto il valore massimo dell'indicatore di completamento
    fpl->minimum(0);    //Imposto il valore minimo dell'indicatore di completamento
    fpl->value(75);     //Imposto il valore iniziale "0" dell'indicatore di cmpletamento
    fpl->hide();        //Nascondo l'indicatore di cmpletamento fino al click del bottone calcola
    
    Fl_Hor_Value_Slider *disp=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER,LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Disparita'"); //Instanzio l'oggetto *disparita della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    disp->minimum(16);  //Imposto il valore minimo per la disparita
    disp->maximum(1000);//Imposto il valore massimo per la disparita
    disp->value(this->p_disparity);//Imposto il valore contenuto nel data member della classe
    disp->align(FL_ALIGN_RIGHT);   //allineo a destra gli indicatori
    disp->step(16.0);              //imposto che ad ogni incremendo o decremento deve essere precisamente di 16
    disp->callback(Disparita_CB);  // definisco la funzione di callback per l'eventuale modifica della barra orizontale per la disparita
    
    
    Fl_Hor_Value_Slider *mind=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Disparita' minima"); //Instanzio l'oggetto *mininima disparita della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    mind->minimum(0);//Imposto il valore minimo per la mininima disparita
    mind->maximum(1000);//Imposto il valore massimo per la mininima disparita
    mind->value(this->p_min);//Imposto il valore contenuto nel data member della classe
    mind->align(FL_ALIGN_RIGHT);//allineo a destra l' indicatore
    mind->step(1.0);//imposto che ad ogni incremendo o decremento deve essere precisamente di 1
    mind->callback(MinDisparita_CB);// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la disparita
    
    Fl_Hor_Value_Slider *uratio=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+2*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Unicita' ratio");//Instanzio l'oggetto *uniquess ratio della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    uratio->minimum(1);//Imposto il valore minimo per la uniquess ratio
    uratio->maximum(1000);//Imposto il valore massimo per la uniquess ratio
    uratio->value(this->p_uratio);//Imposto il valore contenuto nel data member della classe
    uratio->align(FL_ALIGN_RIGHT);//allineo a destra l' indicatore
    uratio->step(1.0);//imposto che ad ogni incremendo o decremento deve essere precisamente di 1
    uratio->callback(UniquessRatio_CB);// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la mininima disparita
    
     Fl_Hor_Value_Slider *prefiltercap=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+3*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Prefiltraggio");//Instanzio l'oggetto *prefiltercap della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    prefiltercap->minimum(1);//Imposto il valore minimo per il prefiltercap
    prefiltercap->maximum(100);//Imposto il valore massimo per il prefiltercap
    prefiltercap->value(this->p_prefiltercap);//Imposto il valore contenuto nel data member della classe
    prefiltercap->align(FL_ALIGN_RIGHT);//allineo a destra l' indicatore
    prefiltercap->step(1.0);//imposto che ad ogni incremendo o decremento deve essere precisamente di 1
    prefiltercap->callback(PreFilterCap_CB);// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la mininima disparita
    
    Fl_Hor_Value_Slider *texturethreshold=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+4*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Soglia Texture");//Instanzio l'oggetto *prefiltercap della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    texturethreshold->minimum(1);//Imposto il valore minimo per il prefiltercap
    texturethreshold->maximum(1000);//Imposto il valore massimo per il prefiltercap
    texturethreshold->value(this->p_texturethreshold);//Imposto il valore contenuto nel data member della classe
    texturethreshold->align(FL_ALIGN_RIGHT);//allineo a destra l' indicatore
    texturethreshold->step(1.0);//imposto che ad ogni incremendo o decremento deve essere precisamente di 1
    texturethreshold->callback(TextureThreshold_CB);// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la mininima disparita
    
    Fl_Hor_Value_Slider *sws=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+5*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Grandezza finestra spettrale");//Instanzio l'oggetto *speckle window size ratio della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    sws->minimum(0);//Imposto il valore minimo per la speckle window size
    sws->maximum(1000);//Imposto il valore massimo per la speckle window size
    sws->value(this->p_sws);//Imposto il valore contenuto nel data member della classe
    sws->align(FL_ALIGN_RIGHT);//allineo a destra l' indicatore
    sws->step(1.0);//imposto che ad ogni incremendo o decremento deve essere precisamente di 1
    sws->callback(SpekleWindow_CB);// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la speckle window size
    
    Fl_Hor_Value_Slider *sr=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+6*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Range spettro");//Instanzio l'oggetto *speckle range ratio della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    sr->minimum(0);//Imposto il valore minimo per la speckle range
    sr->maximum(100);//Imposto il valore massimo per la speckle range
    sr->value(this->p_sr);//Imposto il valore contenuto nel data member della classe
    sr->align(FL_ALIGN_RIGHT);//allineo a destra l' indicatore
    sr->step(1.0);//imposto che ad ogni incremendo o decremento deve essere precisamente di 1
    sr->callback(SpekleRange_CB);// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la speckle range
    
    Fl_Hor_Value_Slider *diff12=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+7*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Differenza di disparita' tra foto");//Instanzio l'oggetto *Disp12MaxDiff della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    diff12->minimum(0);//Imposto il valore minimo per la Disp12MaxDiff
    diff12->maximum(100);//Imposto il valore massimo per la Disp12MaxDiff
    diff12->value(this->p_diff12);//Imposto il valore contenuto nel data member della classe
    diff12->align(FL_ALIGN_RIGHT);//allineo a destra l' indicatore
    diff12->step(1.0);//imposto che ad ogni incremendo o decremento deve essere precisamente di 1
    diff12->callback(Diff12_CB);// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la Disp12MaxDiff
    
    Fl_Hor_Value_Slider *scallefactor = new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+8*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Fattore di scala"); //Instanzio l'oggetto *scallefactor della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    scallefactor->minimum(1);  //Imposto il valore minimo per la scallefactor
    scallefactor->maximum(5);//Imposto il valore massimo per la scallefactor
    scallefactor->value(this->p_scallefactor);//Imposto il valore contenuto nel data member della classe
    scallefactor->align(FL_ALIGN_RIGHT);   //allineo a destra gli indicatori
    scallefactor->step(0.001);              //imposto che ad ogni incremendo o decremento deve essere precisamente di 16
    scallefactor->callback(ScalleFactor_CB);  // definisco la funzione di callback per l'eventuale modifica della barra orizontale per la scallefactor
    
    Fl_Button *btn = new Fl_Button(POSITION_X_SLIDER,POSITION_Y_SLIDER+9*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Calcola");// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la Disp12MaxDiff
    btn->callback(Butt_CB,(void*)this);// definisco la funzione di callback per l'eventuale click del pulsante calcola e passo l'oggetto instanziato tramite questo costruttore
    win->show();    //Mostro la finestra
    Fl::run();      //Faccio partire l'interfaccia
}
//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::Disparita_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;  //instanzio un oggetto di riferimento a quello passato
    Configurazione::p_disparity=slider->value();
}
//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::PreFilterCap_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione::p_prefiltercap=slider->value();}
//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::TextureThreshold_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione::p_texturethreshold=slider->value();
}

//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::MinDisparita_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione::p_min=slider->value();
}
//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::UniquessRatio_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione::p_uratio=slider->value();
}
//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::SpekleWindow_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione::p_sws=slider->value();
}
//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::SpekleRange_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione::p_sr=slider->value();
}
//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::Diff12_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione::p_diff12=slider->value();
}

//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::ScalleFactor_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione::p_scallefactor=slider->value();
}



float Configurazione:: estraiDisparita() const{
    return this->p_disparity;
}
float Configurazione::estraiPrefilterCap() const{
    return this->p_prefiltercap;
}
float Configurazione::estraiTextureThreshould() const{
    return this->p_texturethreshold;
}
float Configurazione::estraiMinDisparita() const{
    return this->p_min;
}
float Configurazione::estraiUniqueRatio() const{
    return this->p_uratio;
}
float Configurazione::estraiSWS() const{
    return this->p_sws;
}
float Configurazione::estraiSR() const{
    return this->p_sr;
}
float Configurazione::estraiDiff12() const{
    return this->p_diff12;
}
float Configurazione::estraiScalle() const{
    return this->p_scallefactor;
}

void Configurazione::Butt_CB(Fl_Widget*w, void*data) {
    Configurazione *o = (Configurazione*)data;
    o->Configurazione::setParams(w);
    
}
void Configurazione::setParams(Fl_Widget*w){
    Ricostruttore3d *r = new Ricostruttore3d(this->file,2,this->estraiDisparita(),this->estraiMinDisparita(),this->estraiUniqueRatio(),this->estraiSWS(),this->estraiSR(),this->estraiDiff12(),this->estraiPrefilterCap(),this->estraiTextureThreshould(),this->estraiScalle());
    delete r;
    r = 0;
}

vector<string> Configurazione::explode(const string &stringa,const char &delimitatore){
    string buff{""};
    vector<string> v;
    
    for(auto n:stringa)
    {
        if(n != delimitatore) buff+=n; else
            if(n == delimitatore && buff != "") { v.push_back(buff); buff = ""; }
    }
    if(buff != "") v.push_back(buff);
    
    return v;
}
