#ifndef Interfaccia_H
#define Interfaccia_H

#include "Configurazione.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <iostream>
#include <vector>
#include <string>


class Interfaccia {
public:
	Interfaccia();
	void costruzioneFinestra();
	vector<std::string> getPath();

private:
	Fl_Button *but = NULL;
	Fl_Button *cancella = NULL;
	Fl_Window *win = NULL;
	vector<std::string> path;
	void setInitButt(Fl_Button *but, Fl_Button *cancella);
	void scegliFile_CB(Fl_Widget* w);
	static void staticScegliFileCB(Fl_Widget* w, void* data);
	void esci_CB(Fl_Widget* w);
	static void staticEsci_CB(Fl_Widget* w, void* data);
};

#endif 


