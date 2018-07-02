//
//  Configurazione.cpp
//
//  Creato da Cristian Greco s1053410
//
#include "Configurazione.h"

Configurazione::Configurazione():p_disparity(16.00),p_p1(100),p_p2(1000),p_min(0),p_uratio(10),p_sws(400),p_sr(600),p_diff12(1),init(false){
    
    
    Fl_Window *win = new Fl_Window(500, 240, "Parametri per matcher");
    //Fl_Slider slider(300,35, 300,20);
    
    Fl_Clock *fcl=new Fl_Clock(400,10,50,50,"Ora Legale");
    Fl_Progress *fpl=new Fl_Progress(20, 220, 150, 15,"Caricamento"+10);
    fpl->maximum(100);
    fpl->minimum(0);
    fpl->value(75);
    fpl->hide();
    int x=20;
    int y=20;
    int larg=200;
    int alt=20;
    
    this->disp = new Fl_Hor_Value_Slider(x,y,larg,alt,"Disparita'");
    this->disp->minimum(0);
    this->disp->maximum(1000);
    this->disp->value(this->p_disparity);
    this->disp->align(FL_ALIGN_RIGHT);
    
    this->p1=new Fl_Hor_Value_Slider(x,y+alt,larg,alt,"P1");
    this->p1->minimum(0);
    this->p1->maximum(100);
    this->p1->value(this->p_p1);
    this->p1->align(FL_ALIGN_RIGHT);
    this->p2=new Fl_Hor_Value_Slider(x,y+2*(alt),larg,alt,"P2");
    this->p2->minimum(0);
    this->p2->maximum(1000);
    this->p2->value(this->p_p2);
    this->p2->align(FL_ALIGN_RIGHT);
    this->mind=new Fl_Hor_Value_Slider(x,y+3*(alt),larg,alt,"Disparita' minima");
    this->mind->minimum(0);
    this->mind->maximum(100);
    this->mind->value(this->p_min);
    this->mind->align(FL_ALIGN_RIGHT);
    this->uratio=new Fl_Hor_Value_Slider(x,y+4*(alt),larg,alt,"Unicita' ratio");
    this->uratio->minimum(0);
    this->uratio->maximum(100);
    this->uratio->value(this->p_uratio);
    this->uratio->align(FL_ALIGN_RIGHT);
    this->sws=new Fl_Hor_Value_Slider(x,y+5*(alt),larg,alt,"Grandezza finestra spettrale");
    this->sws->minimum(0);
    this->sws->maximum(100);
    this->sws->value(this->p_sws);
    this->sws->align(FL_ALIGN_RIGHT);
    this->sr=new Fl_Hor_Value_Slider(x,y+6*(alt),larg,alt,"Range spettro");
    this->sr->minimum(0);
    this->sr->maximum(100);
    this->sr->value(this->p_sr);
    this->sr->align(FL_ALIGN_RIGHT);
    this->diff12=new Fl_Hor_Value_Slider(x,y+7*(alt),larg,alt,"Differenza di disparita' tra foto");
    this->diff12->minimum(0);
    this->diff12->maximum(100);
    this->diff12->value(this->p_diff12);
    this->diff12->align(FL_ALIGN_RIGHT);
    
    Fl_Button btn(250,y+9*(alt), 60,20,"Calcola");
    btn.callback(Butt_CB);
    
    std::cout<<this->p_disparity<<std::endl;
    win->show();
    Fl::run();
}
float Configurazione:: estraiDisparita() const{
    return this->p_disparity;
}
float Configurazione::estraiP1() const{
    return this->p_p1;
}
float Configurazione::estraiP2() const{
    return this->p_p2;
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
bool Configurazione::inizializzato()const{
    return this->init;
}
void Configurazione::Butt_CB(Fl_Widget*w, void*data) {
    Configurazione *o= (Configurazione*)data;
    o->setParams(w);
    
}

void Configurazione::setParams(Fl_Widget*w){
    this->p_disparity=this->disp->value();
    this->p_p1=this->p1->value();
    this->p_p2=this->p2->value();
    this->p_min=this->mind->value();
    this->p_uratio=this->uratio->value();
    this->p_sws=this->sws->value();
    this->p_sr=this->sr->value();
    this->p_diff12=this->diff12->value();
    this->init=true;
}
