#ifndef Interfaccia_H
#define Intefaccia_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Input.H>
#include<FL/Fl_Output.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <iostream>
#include <vector>
#include <string>





class Interfaccia {
public:
	Interfaccia();
	void costruzioneFinestra();
	std::vector<std::string> getPath();

private:
	int x, y;
	Fl_Button *but;
	Fl_Button *cancella;
	Fl_Button *avanti;
	Fl_Output *G_filename;
	Fl_Window *win;
	std::vector<std::string> path;
	void setXY(int x, int y);
	void setInitButt(Fl_Button *but, Fl_Button *cancella);
	void scegliFile_CB(Fl_Widget* w);
	static void staticScegliFileCB(Fl_Widget* w, void* data);
	void esci_CB(Fl_Widget* w);
	static void staticEsci_CB(Fl_Widget* w, void* data);
	void avanti_CB(Fl_Widget* w);
	static void staticAvanti_CB(Fl_Widget* w, void* data);
};

#endif 


