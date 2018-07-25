#ifndef Interfaccia_H
#define Intefaccia_H

#include "InizializzatoreInterfacce.h"

class Interfaccia : public InizializzatoreInterfacce {
public:
	Interfaccia();
	void costruzioneFinestra();
	std::vector<std::string> getPath();

private:
	Fl_Button *buts = NULL;
	Fl_Button *butd = NULL;
	Fl_Button *avanti = NULL;
	Fl_Button *cancella = NULL;
	std::vector<std::string> path;
	void setInitButt(Fl_Button *buts, Fl_Button *butd, Fl_Button *avanti, Fl_Button *cancella);
	void scegliFile_CB(Fl_Widget* theButton);
	static void staticScegliFileCB(Fl_Widget* w, void* data);
	void avantiCB(Fl_Widget* w);
	static void staticAvantiCB(Fl_Widget* w, void* data);
	void esci_CB(Fl_Widget* w);
	static void staticEsci_CB(Fl_Widget* w, void* data);
};

#endif 


