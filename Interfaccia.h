#ifndef Interfaccia_H
#define Intefaccia_H

#include "Configurazione.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/Fl_Image.H>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

class Interfaccia {
public:
	Interfaccia();
	void costruzioneFinestra();
	std::vector<std::string> getPath();

private:
	Fl_Button *buts = NULL;
	Fl_Button *butd = NULL;
	Fl_Button *avanti = NULL;
	Fl_Button *cancella = NULL;
	Fl_Window *win = NULL;
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


