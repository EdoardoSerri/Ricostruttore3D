#ifndef InizializzatoreInterfaccia_H
#define InizializzatoreInterfaccia_H


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

class InizializzatoreInterfacce
{
public:
	InizializzatoreInterfacce(); 
	~InizializzatoreInterfacce();
	void setWindow(int, int, const char*); //setta parametri della Window
	Fl_Window* getWindow(); //prende il data member win

private:
	Fl_Window * win = NULL;
};





#endif // !InizializzatoreInterfaccia_H


