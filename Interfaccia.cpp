#include "Interfaccia.h"


	Interfaccia::Interfaccia() {

		this->win = new Fl_Window(600, 180, "Ricostruttore 3D"); // costruttore inizializza grandezza finestra principale	
	}

	void Interfaccia::setInitButt(Fl_Button *buts, Fl_Button *butd, Fl_Button *avanti, Fl_Button *cancella) { //funzione che definisce i bottoni e le funzioni ad essi associate
		buts = new Fl_Button(this->win->w() / 2 - 230, 30, 120, 80, "Scegli l'immagine \n di sinistra");
		buts->callback(Interfaccia::staticScegliFileCB, (void*)this); // apre il file explorer

		butd = new Fl_Button(this->win->w() / 2-50, 30, 120, 80, "Scegli l'immagine \n di destra");
		butd->callback(Interfaccia::staticScegliFileCB, (void*)this); // apre il file explorer

		avanti = new Fl_Button(this->win->w() - 120, 80, 80, 30, "Avanti");
		avanti->callback(Interfaccia::staticAvantiCB, (void*)this);	
		
		cancella = new Fl_Button(this->win->w() - 120, 30, 80, 30, "Esci");
		cancella->callback(Interfaccia::staticEsci_CB); // chiude il programma
	}

	void Interfaccia::costruzioneFinestra() { // Funzione per la creazione della finestra
		this->win->size_range(this->win->w(), this->win->h(), 0, 0);
		this->win->begin();
		{
			Interfaccia::setInitButt( this->buts, this->butd,this->avanti, this->cancella);		
		}
		this->win->end();
		this->win->show();
		Fl::run(); //loop per la visualizzazione della finestra
	}

	std::vector<std::string> Interfaccia::getPath() { // Funzione per ritorno dei percorsi dei file
		return this->path;
	}

	void Interfaccia::scegliFile_CB(Fl_Widget* w) {
			if (this->path.size()<2) {
				// Crea File Chooser
				Fl_Native_File_Chooser native;
				native.title("Scegli File per la ricostruzione"); //titolo file chooser
				native.type(Fl_Native_File_Chooser::BROWSE_FILE);
				native.directory("C:\\Users\\");
				native.filter("*.ppm\n*.jpg\n*.jpeg\n"); //tipi supportati
														 // Mostra File Chooser
				switch (native.show()) {
				case -1: native.errmsg(); break;	// ERRORE
				case  1:  fl_beep(); break;		// CANCELLA
				default: 								// FILE SCELTI
					if (native.filename()) {
						this->path.push_back(native.filename()); // Inserisco path del file in un vector per caricamento posteriore	
					}
					break;
				}
			}
			else {
				fl_alert("Hai già scelto due immagini");
			}
	}

	void Interfaccia::staticScegliFileCB(Fl_Widget* w, void* data) {
		Interfaccia *o = (Interfaccia*)data; // Istanzio oggetto per static callback per aprire la finestra per scegliere i file
		o->Interfaccia::scegliFile_CB(w);
	}

	void Interfaccia::avantiCB(Fl_Widget* w) {

		if (this->path.size()==2) {

			std::string nomifile = "Hai scelto \n"; // stringa per finestra di scelta
			for (std::vector<std::string>::iterator it = this->path.begin(); it != this->path.end();it++) {
				nomifile += *it + "\n";
			}

			switch (fl_choice(nomifile.c_str(), "Indietro", "Avanti", 0)) { // chiede all'utente se i file scelti sono corretti
				case 0: // i file non sono corretti..
					this->path.clear(); // libera il vector
					break;
				case 1: // esegue il ricostruttore
					this->win->hide();
					delete this->win;
					this->win = 0;
					Configurazione *c=new Configurazione(this->getPath());
					break;
			}
		}
		else {
			fl_alert("Scegli due file prima di procedere"); // Alert per scelta di due foto
		}


	}

	void Interfaccia::staticAvantiCB(Fl_Widget* w, void* data) {
		Interfaccia *o = (Interfaccia*)data; // Istanzio oggetto per static callback per aprire la finestra per scegliere i file
		o->Interfaccia::avantiCB(w);
	}

	void Interfaccia::esci_CB(Fl_Widget* w) {// Callback per uscire
		exit(0);
	}

	void Interfaccia::staticEsci_CB(Fl_Widget* w, void* data) { // Callback statica per uscire
		Interfaccia *o = (Interfaccia*)data;
		o->Interfaccia::esci_CB(w);
	}


