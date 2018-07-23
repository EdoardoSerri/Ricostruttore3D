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
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <Ricostruttore3d.h>
#define LARGHEZZA_SLIDER 200 //definisco una costante che voglio rimarrà identica per tutto il tempo di esecuzione
#define ALTEZZA_SLIDER 20 //definisco una costante che voglio rimarrà identica per tutto il tempo di esecuzione
#define POSITION_X_SLIDER 20 //definisco una costante che voglio rimarrà identica per tutto il tempo di esecuzione
#define POSITION_Y_SLIDER 20 //definisco una costante che voglio rimarrà identica per tutto il tempo di esecuzione
#define DATA "configurazione.txt" //definisco una costante che voglio rimarrà identica per tutto il tempo di esecuzione
using namespace std;    //

class Configurazione{
public:
    Configurazione(const vector<string> &);
    
    float estraiDisparita() const;
    float estraiP1() const;
    float estraiP2() const;
    float estraiMinDisparita() const;
    float estraiUniqueRatio() const;
    float estraiSWS() const;
    float estraiSR() const;
    float estraiDiff12() const;
private:
    void inizializzazioneParametri();
    void salvaSuFile(const float &,const float &,const float &,const float &,const float &,const float &,const float &,const float &)const;
    void salvaValore(const float&,const char&);
    vector<string> explode(const string&,const char&);
    static void Butt_CB(Fl_Widget*, void*);
    static void Disparita_CB(Fl_Widget*, void*);
    static void P1_CB(Fl_Widget*, void*);
    static void P2_CB(Fl_Widget*, void*);
    static void MinDisparita_CB(Fl_Widget*, void*);
    static void UniquessRatio_CB(Fl_Widget*, void*);
    static void SpekleWindow_CB(Fl_Widget*, void*);
    static void SpekleRange_CB(Fl_Widget*, void*);
    static void Diff12_CB(Fl_Widget*, void*);
    void creaFile()const;
    void setParams(Fl_Widget* w);
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
    const vector<string> file;
};

#endif /* Configurazione_h */
