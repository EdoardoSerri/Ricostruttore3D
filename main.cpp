//
//  main.cpp
//  Ricostruttore3d
//
//  Created by Crismesy ing on 24/06/18.
//  Copyright © 2018 Gruppo. All rights reserved.
//

#include "Interfaccia.h"
#include "Configurazione.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Parametri globali per configurazione del Ricostruttore
float Configurazione::p_disparity = 48;
float Configurazione::p_prefiltercap =        61;
float Configurazione::p_texturethreshold =        507;
float Configurazione::p_min =       0;
float Configurazione::p_uratio =    10;
float Configurazione::p_sws =       400;
float Configurazione::p_sr =        600;
float Configurazione::p_diff12 =      1;
float Configurazione::p_scallefactor =      1;

int main(int argc, const char * argv[]) {
    Interfaccia *i=new Interfaccia();
    i->costruzioneFinestra();
}
