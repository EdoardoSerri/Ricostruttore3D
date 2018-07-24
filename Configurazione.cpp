//
//  Configurazione.cpp
//
//  Creato da Cristian Greco s1053410
//
#include "Configurazione.h"

Configurazione::Configurazione(const vector<string> &files):file(files){
    //this->inizializzazioneParametri();
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
    
    Fl_Hor_Value_Slider *disparita = new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER,LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Disparita'"); //Instanzio l'oggetto *disparita della classe Fl_Hor_Value_Slider
    disparita->minimum(0);
    disparita->maximum(1000);
    disparita->value(this->p_disparity);
    disparita->align(FL_ALIGN_RIGHT);
    disparita->step(16.0);
    disparita->callback(Disparita_CB);
    
    
    this->p1=new Fl_Hor_Value_Slider(x,y+alt,larg,alt,"P1");
    this->p1->minimum(0);
    this->p1->maximum(100);
    this->p1->value(this->p_p1);
    this->p1->align(FL_ALIGN_RIGHT);
    this->p1->step(1.0);
    this->p1->callback(P1_CB);
    
    this->p2=new Fl_Hor_Value_Slider(x,y+2*(alt),larg,alt,"P2");
    this->p2->minimum(0);
    this->p2->maximum(1000);
    this->p2->value(this->p_p2);
    this->p2->align(FL_ALIGN_RIGHT);
    this->p2->step(1.0);
    this->p2->callback(P2_CB);
    
    this->mind=new Fl_Hor_Value_Slider(x,y+3*(alt),larg,alt,"Disparita' minima");
    this->mind->minimum(0);
    this->mind->maximum(100);
    this->mind->value(this->p_min);
    this->mind->align(FL_ALIGN_RIGHT);
    this->mind->step(1.0);
    this->mind->callback(MinDisparita_CB);
    
    this->uratio=new Fl_Hor_Value_Slider(x,y+4*(alt),larg,alt,"Unicita' ratio");
    this->uratio->minimum(0);
    this->uratio->maximum(100);
    this->uratio->value(this->p_uratio);
    this->uratio->align(FL_ALIGN_RIGHT);
    this->uratio->step(1.0);
    this->uratio->callback(UniquessRatio_CB);
    
    this->sws=new Fl_Hor_Value_Slider(x,y+5*(alt),larg,alt,"Grandezza finestra spettrale");
    this->sws->minimum(0);
    this->sws->maximum(100);
    this->sws->value(this->p_sws);
    this->sws->align(FL_ALIGN_RIGHT);
    this->sws->step(1.0);
    this->sws->callback(SpekleWindow_CB);
    
    this->sr=new Fl_Hor_Value_Slider(x,y+6*(alt),larg,alt,"Range spettro");
    this->sr->minimum(0);
    this->sr->maximum(100);
    this->sr->value(this->p_sr);
    this->sr->align(FL_ALIGN_RIGHT);
    this->sr->step(1.0);
    this->sr->callback(SpekleRange_CB);
    
    this->diff12=new Fl_Hor_Value_Slider(x,y+7*(alt),larg,alt,"Differenza di disparita' tra foto");
    this->diff12->minimum(0);
    this->diff12->maximum(100);
    this->diff12->value(this->p_diff12);
    this->diff12->align(FL_ALIGN_RIGHT);
    this->diff12->step(1.0);
    this->diff12->callback(Diff12_CB);
    
    Fl_Button btn(250,y+9*(alt), 60,20,"Calcola");
    btn.callback(Butt_CB,(void*)this);
    win->show();
    Fl::run();
}
void Configurazione::Disparita_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;
    Configurazione *o= (Configurazione*)data;
    o->Configurazione::salvaValore(slider->value(),0);
}
void Configurazione::P1_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;
    Configurazione *o= (Configurazione*)data;
    o->Configurazione::salvaValore(slider->value(),1);
}
void Configurazione::P2_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;
    Configurazione *o= (Configurazione*)data;
    o->Configurazione::salvaValore(slider->value(),2);
}
void Configurazione::MinDisparita_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;
    Configurazione *o= (Configurazione*)data;
    o->Configurazione::salvaValore(slider->value(),3);
}
void Configurazione::UniquessRatio_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;
    Configurazione *o= (Configurazione*)data;
    o->Configurazione::salvaValore(slider->value(),4);
}
void Configurazione::SpekleWindow_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;
    Configurazione *o= (Configurazione*)data;
    o->Configurazione::salvaValore(slider->value(),5);
}
void Configurazione::SpekleRange_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;
    Configurazione *o= (Configurazione*)data;
    o->Configurazione::salvaValore(slider->value(),6);
}
void Configurazione::Diff12_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;
    Configurazione *o= (Configurazione*)data;
    o->Configurazione::salvaValore(slider->value(),7);
}
void Configurazione::salvaValore(const float &valore,const int &scelta){
    fstream myfile("configurazione.txt");
    vector<string> configurazione;
    if (myfile.is_open())
    {
        
        cout<<"leggo file"<<endl;
        if ( myfile.good() )
        {
            string temp;
            getline (myfile,temp);
            configurazione=this->explode(temp, ' ');
        }
        myfile.close();
    }
    switch (scelta) {
        case 0:
        {
            this->salvaSuFile(valore, stof(configurazione[1]), stof(configurazione[2]), stof(configurazione[3]), stof(configurazione[4]), stof(configurazione[5]), stof(configurazione[6]), stof(configurazione[7]));
            this->p_disparity=valore;
        }
            break;
        case 1:
        {
            this->salvaSuFile(stof(configurazione[0]), valore, stof(configurazione[2]), stof(configurazione[3]), stof(configurazione[4]), stof(configurazione[5]), stof(configurazione[6]), stof(configurazione[7]));
            this->p_p1=valore;
        }
            break;
        case 2:
        {
            this->salvaSuFile(stof(configurazione[0]), stof(configurazione[1]), valore, stof(configurazione[3]), stof(configurazione[4]), stof(configurazione[5]), stof(configurazione[6]), stof(configurazione[7]));
            this->p_p2=valore;
        }
            break;
        case 3:
        {
            this->salvaSuFile(stof(configurazione[0]), stof(configurazione[1]), stof(configurazione[2]), valore, stof(configurazione[4]), stof(configurazione[5]), stof(configurazione[6]), stof(configurazione[7]));
            this->p_min=valore;
        }
            break;
        case 4:
        {
            this->salvaSuFile(stof(configurazione[0]), stof(configurazione[1]), stof(configurazione[2]), stof(configurazione[3]), valore, stof(configurazione[5]), stof(configurazione[6]), stof(configurazione[7]));
            this->p_uratio=valore;
        }
            break;
        case 5:
        {
            this->salvaSuFile(stof(configurazione[0]), stof(configurazione[1]), stof(configurazione[2]), stof(configurazione[3]), stof(configurazione[4]), valore, stof(configurazione[6]), stof(configurazione[7]));
            this->p_sws=valore;
        }
            break;
        case 6:
        {
            this->salvaSuFile(stof(configurazione[0]), stof(configurazione[1]), stof(configurazione[2]), stof(configurazione[3]), stof(configurazione[4]), stof(configurazione[5]), valore, stof(configurazione[7]));
            this->p_sr=valore;
        }
            break;
        case 7:
        {
            this->salvaSuFile(stof(configurazione[0]), stof(configurazione[1]), stof(configurazione[2]), stof(configurazione[3]), stof(configurazione[4]), stof(configurazione[5]), stof(configurazione[6]), valore);
            this->p_diff12=valore;
        }
            break;
            
        default:
            break;
    }
}
void Configurazione::salvaSuFile(const float &disparita,const float &p1,const float &p2,const float &minDisparita,const float &uniquessRatio,const float &sws,const float &sr,const float &diff12)const{
    FILE* fp = fopen("configurazione.txt", "wt");
    fprintf(fp, "%f %f %f %f %f %f %f %f\n",disparita, p1, p2, minDisparita, uniquessRatio, sws, sr, diff12);
    fclose(fp);
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

void Configurazione::Butt_CB(Fl_Widget*w, void*data) {
    Configurazione *o = (Configurazione*)data;
    o->Configurazione::setParams(w);
    
}
void Configurazione::creaFile()const{
    ofstream myfile;
    myfile.open ("filename.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();
    FILE* fp = fopen("configurazione.txt", "wt");
    
    fprintf(fp, "%f %f %f %f %f %f %f %f\n", this->p_disparity, this->p_p1, this->p_p2, this->p_min, this->p_uratio, this->p_sws, this->p_sr, this->p_diff12);
    fclose(fp);
}
void Configurazione::inizializzazioneParametri(){
    string configurazione;
    fstream myfile("configurazione.txt");
    cout<<myfile.good();
    if (myfile.is_open())
    {
        
        cout<<"leggo file"<<endl;
        if ( myfile.good() )
        {
            string temp;
            getline (myfile,temp);
            if(configurazione.length()>0){
                configurazione=temp;
            }else{
                cout<<"creo file";
                this->creaFile();
            }
        }
        myfile.close();
    }else{
        cout<<"file non trovato";
        this->creaFile();
    }
    cout<<configurazione<<endl;
    vector<string> values = explode(configurazione, ' ');
    this->p_disparity=stof(values.at(0));
    this->p_p1=stof(values.at(1));
    this->p_p2=stof(values.at(2));
    this->p_min=stof(values.at(3));
    this->p_uratio=stof(values.at(4));
    this->p_sws=stof(values.at(5));
    this->p_sr=stof(values.at(6));
    this->p_diff12=stof(values.at(7));
    
}
void Configurazione::setParams(Fl_Widget*w){
    Ricostruttore3d *r = new Ricostruttore3d(this->file,2,this->estraiDisparita(),this->estraiMinDisparita(),this->estraiUniqueRatio(),this->estraiSWS(),this->estraiSR(),this->estraiDiff12(),this->estraiP1(),this->estraiP2());
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
