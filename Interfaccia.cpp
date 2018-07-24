#include "Interfaccia.h"

	Interfaccia::Interfaccia() {

		this->win = new Fl_Window(600, 200, "Ricostruttore 3D");	// costruttore inizializza grandezza finestra principale	
	}

	void Interfaccia::setInitButt(Fl_Button *but, Fl_Button *cancella) { //funzione che definisce i bottoni e le funzioni ad essi associate
		but = new Fl_Button(this->win->w() / 2 - 150, 30, 200, 100, "Scegli le immagini");
		but->callback(Interfaccia::staticScegliFileCB, (void*)this); // apre il file explorer
		cancella = new Fl_Button(this->win->w() - 200, 30, 80, 30, "Esci");
		cancella->callback(Interfaccia::staticEsci_CB); // chiude il programma
	}

	void Interfaccia::costruzioneFinestra() { // Funzione per la creazione della finestra
		this->win->size_range(this->win->w(), this->win->h(), 0, 0);
		this->win->begin();
		{
			Interfaccia::setInitButt( this->but, this->cancella);
		}
		this->win->end();
		this->win->show();
		Fl::run(); //loop per la visualizzazione della finestra
	}
    
	vector<string> Interfaccia::getPath() { // Funzione per ritorno dei percorsi dei file
		return this->path;
	}

	void Interfaccia::scegliFile_CB(Fl_Widget* w) {
		// Crea File Chooser
		Fl_Native_File_Chooser native;
		string nomifile = "Hai scelto \n"; // stringa per finestra di scelta
		native.title("Scegli File per la ricostruzione"); //titolo file chooser
		native.type(Fl_Native_File_Chooser::BROWSE_MULTI_FILE);
		native.directory("C:\\Users\\");
		native.filter("*.ppm\n*.jpg\n*.jpeg\n"); //tipi supportati
		// Mostra File Chooser
		switch (native.show()) {
		case -1: native.errmsg(); break;	// ERRORE
		case  1:  fl_beep(); break;		// CANCELLA
		default: 								// FILE SCELTI
			if (native.filename()) {
				if (native.count()==2) { //file scelti devono essere due
					for (int i = 0; i < native.count(); i++) {
						this->path.push_back(native.filename(i)); // Inserisco path del file in un vector per caricamento posteriore
						nomifile += (native.filename(i))+ (string)"\n"; // concateno la stringa da visualizzare con i file scelti
					}
					nomifile += "?";

					switch (fl_choice(nomifile.c_str(), "Indietro","Avanti",0)) { // chiede all'utente se i file scelti sono corretti
					case 0: // i file non sono corretti..
						for (int i = 0; i < native.count(); i++) {
							this->path.pop_back(); // libera il vector
						}
						break;
					case 1: // esegue il ricostruttore
                            this->win->hide();
                            delete this->win;
                            this->win=0;
                            Configurazione *c=new Configurazione(this->getPath());
							break;					
					}
				}
				else {
					native.errmsg(); // sono state scelte meno o più di due immagini
					fl_alert("Devi inserire più di un'immagine e massimo DUE immagini"); // Alert se i file sono meno di due
					break;
				}
			}
			break;
		}
	}

	void Interfaccia::staticScegliFileCB(Fl_Widget* w, void* data) {
		Interfaccia *o = (Interfaccia*)data; // Istanzio oggetto per static callback per aprire la finestra per scegliere i file
		o->Interfaccia::scegliFile_CB(w);
	}

	void Interfaccia::esci_CB(Fl_Widget* w) { // Callback per uscire
		exit(0);
	}

	void Interfaccia::staticEsci_CB(Fl_Widget* w, void* data) { // Callback statica per uscire
		Interfaccia *o = (Interfaccia*)data;
		o->Interfaccia::esci_CB(w);
	}


