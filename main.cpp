#include "Interfaccia.h"
#include "Configurazione.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
//Parametri globali per configurazione del Ricostruttore
float Configurazione::p_disparity =             48;
float Configurazione::p_prefiltercap =          61;
float Configurazione::p_texturethreshold =      507;
float Configurazione::p_min =                   0;
float Configurazione::p_uratio =                10;
float Configurazione::p_sws =                   400;
float Configurazione::p_sr =                    600;
float Configurazione::p_diff12 =                1;
float Configurazione::p_scallefactor =          1;

void wait(int seconds)
{
    boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}

void thread()
{
    try
    {
        
    }
    catch (boost::thread_interrupted&) {}
}

int main(int argc, const char * argv[]) {
    Interfaccia *i=new Interfaccia();
    i->costruzioneFinestra();
    Configurazione *e=new Configurazione(i->getPath());
    boost::thread t{thread};
     wait(10);
}
