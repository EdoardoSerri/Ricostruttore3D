//
//  Configurazione.h
//  Window
//
//  Created da Cristian greco 1053410
//

#ifndef Configurazione_h
#define Configurazione_h

#include <FL/Fl.H>
#include <FL/Fl_Hor_Value_Slider.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Progress.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Clock.H>
#include <string>
#include <vector>
#include <iostream>


class Configurazione{
public:
    Configurazione();
    
    float estraiDisparita() const;
    float estraiP1() const;
    float estraiP2() const;
    float estraiMinDisparita() const;
    float estraiUniqueRatio() const;
    float estraiSWS() const;
    float estraiSR() const;
    float estraiDiff12() const;
    bool inizializzato() const;
private:
    
    static void Butt_CB(Fl_Widget*, void*);
    void setParams(Fl_Widget*);
    Fl_Slider *disp=NULL;
    Fl_Slider *p1=NULL;
    Fl_Slider *p2=NULL;
    Fl_Slider *mind=NULL;
    Fl_Slider *uratio=NULL;
    Fl_Slider *sws=NULL;
    Fl_Slider *sr=NULL;
    Fl_Slider *diff12=NULL;
    float p_disparity;
    float p_p1;
    float p_p2;
    float p_min;
    float p_uratio;
    float p_sws;
    float p_sr;
    float p_diff12;
    bool init;
    
};

#endif /* Configurazione_h */
