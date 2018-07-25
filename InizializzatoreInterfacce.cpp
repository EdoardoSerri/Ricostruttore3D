#include "InizializzatoreInterfacce.h"



InizializzatoreInterfacce::InizializzatoreInterfacce()
{
}


InizializzatoreInterfacce::~InizializzatoreInterfacce()
{
}

void InizializzatoreInterfacce::setWindow(int x, int y, const char* nomefinestra) {
	this-> win = new Fl_Window(x, y, nomefinestra);
}

Fl_Window* InizializzatoreInterfacce::getWindow() {

	return this->win;
}