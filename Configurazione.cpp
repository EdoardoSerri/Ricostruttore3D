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
    
    this->disp = new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER,LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Disparita'"); //Instanzio l'oggetto *disparita della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    this->disp->minimum(16);  //Imposto il valore minimo per la disparita
    this->disp->maximum(1000);//Imposto il valore massimo per la disparita
    this->disp->value(this->p_disparity);//Imposto il valore contenuto nel data member della classe
    this->disp->align(FL_ALIGN_RIGHT);   //allineo a destra gli indicatori
    this->disp->step(16.0);              //imposto che ad ogni incremendo o decremento deve essere precisamente di 16
    this->disp->callback(Disparita_CB);  // definisco la funzione di callback per l'eventuale modifica della barra orizontale per la disparita
    
    
    this->mind=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Disparita' minima"); //Instanzio l'oggetto *mininima disparita della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    this->mind->minimum(0);//Imposto il valore minimo per la mininima disparita
    this->mind->maximum(1000);//Imposto il valore massimo per la mininima disparita
    this->mind->value(this->p_min);//Imposto il valore contenuto nel data member della classe
    this->mind->align(FL_ALIGN_RIGHT);//allineo a destra l' indicatore
    this->mind->step(1.0);//imposto che ad ogni incremendo o decremento deve essere precisamente di 1
    this->mind->callback(MinDisparita_CB);// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la disparita
    
    this->uratio=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+2*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Unicita' ratio");//Instanzio l'oggetto *uniquess ratio della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    this->uratio->minimum(1);//Imposto il valore minimo per la uniquess ratio
    this->uratio->maximum(1000);//Imposto il valore massimo per la uniquess ratio
    this->uratio->value(this->p_uratio);//Imposto il valore contenuto nel data member della classe
    this->uratio->align(FL_ALIGN_RIGHT);//allineo a destra l' indicatore
    this->uratio->step(1.0);//imposto che ad ogni incremendo o decremento deve essere precisamente di 1
    this->uratio->callback(UniquessRatio_CB);// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la mininima disparita
    
    this->prefiltercap=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+3*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Prefiltraggio");//Instanzio l'oggetto *prefiltercap della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    this->prefiltercap->minimum(1);//Imposto il valore minimo per il prefiltercap
    this->prefiltercap->maximum(100);//Imposto il valore massimo per il prefiltercap
    this->prefiltercap->value(this->p_prefiltercap);//Imposto il valore contenuto nel data member della classe
    this->prefiltercap->align(FL_ALIGN_RIGHT);//allineo a destra l' indicatore
    this->prefiltercap->step(1.0);//imposto che ad ogni incremendo o decremento deve essere precisamente di 1
    this->prefiltercap->callback(PreFilterCap_CB);// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la mininima disparita
    
    this->texturethreshold=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+4*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Soglia Texture");//Instanzio l'oggetto *prefiltercap della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    this->texturethreshold->minimum(1);//Imposto il valore minimo per il prefiltercap
    this->texturethreshold->maximum(1000);//Imposto il valore massimo per il prefiltercap
    this->texturethreshold->value(this->p_texturethreshold);//Imposto il valore contenuto nel data member della classe
    this->texturethreshold->align(FL_ALIGN_RIGHT);//allineo a destra l' indicatore
    this->texturethreshold->step(1.0);//imposto che ad ogni incremendo o decremento deve essere precisamente di 1
    this->texturethreshold->callback(TextureThreshold_CB);// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la mininima disparita
    
    this->sws=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+5*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Grandezza finestra spettrale");//Instanzio l'oggetto *speckle window size ratio della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    this->sws->minimum(0);//Imposto il valore minimo per la speckle window size
    this->sws->maximum(1000);//Imposto il valore massimo per la speckle window size
    this->sws->value(this->p_sws);//Imposto il valore contenuto nel data member della classe
    this->sws->align(FL_ALIGN_RIGHT);//allineo a destra l' indicatore
    this->sws->step(1.0);//imposto che ad ogni incremendo o decremento deve essere precisamente di 1
    this->sws->callback(SpekleWindow_CB);// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la speckle window size
    
    this->sr=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+6*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Range spettro");//Instanzio l'oggetto *speckle range ratio della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    this->sr->minimum(0);//Imposto il valore minimo per la speckle range
    this->sr->maximum(100);//Imposto il valore massimo per la speckle range
    this->sr->value(this->p_sr);//Imposto il valore contenuto nel data member della classe
    this->sr->align(FL_ALIGN_RIGHT);//allineo a destra l' indicatore
    this->sr->step(1.0);//imposto che ad ogni incremendo o decremento deve essere precisamente di 1
    this->sr->callback(SpekleRange_CB);// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la speckle range
    
    this->diff12=new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+7*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Differenza di disparita' tra foto");//Instanzio l'oggetto *Disp12MaxDiff della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    this->diff12->minimum(0);//Imposto il valore minimo per la Disp12MaxDiff
    this->diff12->maximum(100);//Imposto il valore massimo per la Disp12MaxDiff
    this->diff12->value(this->p_diff12);//Imposto il valore contenuto nel data member della classe
    this->diff12->align(FL_ALIGN_RIGHT);//allineo a destra l' indicatore
    this->diff12->step(1.0);//imposto che ad ogni incremendo o decremento deve essere precisamente di 1
    this->diff12->callback(Diff12_CB);// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la Disp12MaxDiff
    
    this->scallefactor = new Fl_Hor_Value_Slider(POSITION_X_SLIDER,POSITION_Y_SLIDER+8*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Fattore di scala"); //Instanzio l'oggetto *scallefactor della classe Fl_Hor_Value_Slider per creare nella finestra uno slider orizzontale
    this->scallefactor->minimum(1);  //Imposto il valore minimo per la scallefactor
    this->scallefactor->maximum(5);//Imposto il valore massimo per la scallefactor
    this->scallefactor->value(this->p_scallefactor);//Imposto il valore contenuto nel data member della classe
    this->scallefactor->align(FL_ALIGN_RIGHT);   //allineo a destra gli indicatori
    this->scallefactor->step(0.001);              //imposto che ad ogni incremendo o decremento deve essere precisamente di 16
    this->scallefactor->callback(ScalleFactor_CB);  // definisco la funzione di callback per l'eventuale modifica della barra orizontale per la scallefactor
    
    Fl_Button btn(POSITION_X_SLIDER,POSITION_Y_SLIDER+9*(ALTEZZA_SLIDER),LARGHEZZA_SLIDER,ALTEZZA_SLIDER,"Calcola");// definisco la funzione di callback per l'eventuale modifica della barra orizontale per la Disp12MaxDiff
    btn.callback(Butt_CB,(void*)this);// definisco la funzione di callback per l'eventuale click del pulsante calcola e passo l'oggetto instanziato tramite questo costruttore
    win->show();    //Mostro la finestra
    Fl::run();      //Faccio partire l'interfaccia
}
//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::Disparita_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;  //instanzio un oggetto di riferimento a quello passato
    Configurazione *o= (Configurazione*)data;  //instanzio questa classe
    o->Configurazione::salvaValore(slider->value(),0); //salvo il valore
}
//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::PreFilterCap_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione *o= (Configurazione*)data;//instanzio questa classe
    o->Configurazione::salvaValore(slider->value(),1); //salvo il valore
}
//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::TextureThreshold_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione *o= (Configurazione*)data;//instanzio questa classe
    o->Configurazione::salvaValore(slider->value(),2); //salvo il valore
}

//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::MinDisparita_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione *o= (Configurazione*)data;//instanzio questa classe
    o->Configurazione::salvaValore(slider->value(),3); //salvo il valore
}
//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::UniquessRatio_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione *o= (Configurazione*)data;//instanzio questa classe
    o->Configurazione::salvaValore(slider->value(),4); //salvo il valore
}
//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::SpekleWindow_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione *o= (Configurazione*)data;//instanzio questa classe
    o->Configurazione::salvaValore(slider->value(),5); //salvo il valore
}
//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::SpekleRange_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione *o= (Configurazione*)data;//instanzio questa classe
    o->Configurazione::salvaValore(slider->value(),6); //salvo il valore
}
//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::Diff12_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione *o= (Configurazione*)data;//instanzio questa classe
    o->Configurazione::salvaValore(slider->value(),7); //salvo il valore
}

//////////
///// Definizione della funzione di callback che serve per settare i valori dopo una modifica degli slider
void Configurazione::ScalleFactor_CB(Fl_Widget *w, void*data) {
    
    Fl_Slider *slider = (Fl_Slider*)w;//instanzio un oggetto di riferimento a quello passato
    Configurazione *o= (Configurazione*)data;//instanzio questa classe
    o->Configurazione::salvaValore(slider->value(),8); //salvo il valore
}


//////////
///// Definizione della funzione di che permette di salvare il valore opportuno sia nel data member  che nel file
/// Primo parametro: valore del parametro in float, secondo parametro e' l'identificatore del valore
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
    switch (scelta) { // salvo il valore in base al'identificatore
        case 0:
        {
            //this->salvaSuFile(valore, stof(configurazione[1]), stof(configurazione[2]), stof(configurazione[3]), stof(configurazione[4]), stof(configurazione[5]), stof(configurazione[6]), stof(configurazione[7]), stof(configurazione[8])); //salva il valore sul file insieme agli altri
            this->p_disparity=valore;   //salvo il valore nel data member della classe
        }
            break;
        case 1:
        {
            //this->salvaSuFile(stof(configurazione[0]), valore, stof(configurazione[2]), stof(configurazione[3]), stof(configurazione[4]), stof(configurazione[5]), stof(configurazione[6]), stof(configurazione[7]), stof(configurazione[8]));
            this->p_prefiltercap=valore;//salvo il valore nel data member della classe
        }
            break;
        case 2:
        {
            //this->salvaSuFile(stof(configurazione[0]), stof(configurazione[1]), valore, stof(configurazione[3]), stof(configurazione[4]), stof(configurazione[5]), stof(configurazione[6]), stof(configurazione[7]), stof(configurazione[8]));
            this->p_texturethreshold=valore;//salvo il valore nel data member della classe
        }
            break;
        case 3:
        {
            //this->salvaSuFile(stof(configurazione[0]), stof(configurazione[1]), stof(configurazione[2]), valore, stof(configurazione[4]), stof(configurazione[5]), stof(configurazione[6]), stof(configurazione[7]), stof(configurazione[8]));
            this->p_min=valore;
        }
            break;
        case 4:
        {
            //this->salvaSuFile(stof(configurazione[0]), stof(configurazione[1]), stof(configurazione[2]), stof(configurazione[3]), valore, stof(configurazione[5]), stof(configurazione[6]), stof(configurazione[7]), stof(configurazione[8]));
            this->p_uratio=valore;
        }
            break;
        case 5:
        {
            //this->salvaSuFile(stof(configurazione[0]), stof(configurazione[1]), stof(configurazione[2]), stof(configurazione[3]), stof(configurazione[4]), valore, stof(configurazione[6]), stof(configurazione[7]), stof(configurazione[8]));
            this->p_sws=valore;
        }
            break;
        case 6:
        {
            //this->salvaSuFile(stof(configurazione[0]), stof(configurazione[1]), stof(configurazione[2]), stof(configurazione[3]), stof(configurazione[4]),stof(configurazione[5]), valore, stof(configurazione[7]),stof(configurazione[8]));
            this->p_sr=valore;
        }
            break;
        case 7:
        {
            //this->salvaSuFile(stof(configurazione[0]), stof(configurazione[1]), stof(configurazione[2]), stof(configurazione[3]), stof(configurazione[4]), stof(configurazione[5]), stof(configurazione[6]), valore,stof(configurazione[8]));
            this->p_diff12=valore;
        }
            break;
        case 8:
        {
           // this->salvaSuFile(stof(configurazione[0]), stof(configurazione[1]), stof(configurazione[2]), stof(configurazione[3]), stof(configurazione[4]), stof(configurazione[5]), stof(configurazione[6]),stof(configurazione[7]), valore);
            this->p_scallefactor=valore;
        }
            break;
            
        default:
            break;
    }
}
void Configurazione::salvaSuFile(const float &disparita,const float &prefiltercap,const float &texturethreshold,const float &minDisparita,const float &uniquessRatio,const float &sws,const float &sr,const float &diff12,const float &scalle)const{
    FILE* fp = fopen("configurazione.txt", "wt");//apro il file
    fprintf(fp, "%f %f %f %f %f %f %f %f %f\n",disparita, prefiltercap, texturethreshold, minDisparita, uniquessRatio, sws, sr, diff12,scalle);//salvo i valori
    fclose(fp);//chiudo file
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
void Configurazione::creaFile()const{
    ofstream myfile;
    myfile.open ("filename.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();
    FILE* fp = fopen("configurazione.txt", "wt");
    
    fprintf(fp, "%f %f %f %f %f %f %f %f\n", this->p_disparity, this->p_prefiltercap, this->p_texturethreshold, this->p_min, this->p_uratio, this->p_sws, this->p_sr, this->p_diff12, this->p_scallefactor);
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
    this->p_prefiltercap=stof(values.at(1));
    this->p_texturethreshold=stof(values.at(2));
    this->p_min=stof(values.at(3));
    this->p_uratio=stof(values.at(4));
    this->p_sws=stof(values.at(5));
    this->p_sr=stof(values.at(6));
    this->p_diff12=stof(values.at(7));
    this->p_scallefactor=stof(values.at(8));
    
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
