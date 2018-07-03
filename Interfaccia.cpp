#include "Interfaccia.h"

using namespace std;


	Interfaccia::Interfaccia() {

		this->win = new Fl_Window(600, 200, "Ricostruttore 3D");
	}

	void Interfaccia::setInitButt(Fl_Button *but, Fl_Button *cancella) {
		
		but = new Fl_Button(this->win->w() / 2 - 150, 30, 200, 100, "Scegli le immagini");
		but->callback(Interfaccia::staticScegliFileCB, (void*)this);
		cancella = new Fl_Button(this->win->w() - 200, 30, 80, 30, "Esci");
		cancella->callback(Interfaccia::staticEsci_CB);
	}

	void Interfaccia::costruzioneFinestra() { // Funzione per la creazione della finestra
		
		this->win->size_range(this->win->w(), this->win->h(), 0, 0);
		this->win->begin();
		{
			Interfaccia::setInitButt( this->but, this->cancella);
		}
		this->win -> end();
		
		this->win->show();
		Fl::run();


	}

	vector<string> Interfaccia::getPath() { // Funzione per ritorno dei percorsi dei file
		return this->path;
	}



	void Interfaccia::setXY(int x, int y) {
		this->x = 80;
		this->y = 150;
	}

	void Interfaccia::scegliFile_CB(Fl_Widget* w) {
		// Crea File Chooser
		Fl_Native_File_Chooser native;
		native.title("Scegli File per la ricostruzione");
		native.type(Fl_Native_File_Chooser::BROWSE_MULTI_FILE);
		native.filter("Img\t*.jpg\n *.jpeg\n *.ppm)\n");
		// Mostra File Chooser
		setXY(x,y);
		switch (native.show()) {
		case -1: native.errmsg(); break;	// ERRORE
		case  1:  fl_beep(); break;		// CANCELLA
		default: 								// FILE SCELTI
			if (native.filename()) {
				if (native.count()>1) {
					for (int i = 0; i <= native.count(); i++) {

						this->path.push_back(native.filename(i)); // Inserisco path del file in un vector per caricamento posteriore
						this->G_filename = new Fl_Output(this->x + 30, this->y, this->win->w() - 150, 25, "Nome del File"); //Creo nuova barra Output
						this->G_filename->value(native.filename(i)); // Inserisco path
						this->win->add(this->G_filename);
					}
					this->win->redraw();
					this->win->resize(100, 100, 600, this->y + 50);
					this->avanti = new Fl_Button(this->win->w() - 100, 30, 80, 30, "Avanti");
					this->avanti->callback(Interfaccia::staticAvanti_CB);
					this->win->add(avanti);
					 // Ricarico la finestra con un nuovo bottone per andare Avanti

				}
				else {
					native.errmsg();
					fl_alert("Devi inserire più di un'immagine"); // Alert se i file sono meno di due
					break;
				}


			}
			else {
				this->G_filename->value("NULL");
			}
			break;
		}
	}

	void Interfaccia::staticScegliFileCB(Fl_Widget* w, void* data) {
		Interfaccia *o = (Interfaccia*)data; // Istanzio oggetto per static callback
		o->Interfaccia::scegliFile_CB(w);
	}

	void Interfaccia::esci_CB(Fl_Widget* w) { // Callback per uscire
		exit(0);
	}

	void Interfaccia::staticEsci_CB(Fl_Widget* w, void* data) { // Callback statica per uscire
		Interfaccia *o = (Interfaccia*)data;
		o->Interfaccia::esci_CB(w);
	}

	void Interfaccia::avanti_CB(Fl_Widget* w) { // Calback per proseguire
		switch (fl_choice("Confermi i file scelti?", "No", "Sì", 0)) {
			case 0:
				break;
			case 1:
				exit(0);
				break;
		} //Richiesta se i file immessi sono corretti

	}

	void Interfaccia::staticAvanti_CB(Fl_Widget* w, void* data) { // Callback statica di avanti
		Interfaccia *o = (Interfaccia*)data;
		o->Interfaccia::avanti_CB(w);
	}
