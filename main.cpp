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
float Configurazione::p_disparity = 16;
float Configurazione::p_p1 =        100;
float Configurazione::p_p2 =        1000;
float Configurazione::p_min =       0;
float Configurazione::p_uratio =    10;
float Configurazione::p_sws =       400;
float Configurazione::p_sr =        600;
float Configurazione::p_diff12 =      1;

int main(int argc, const char * argv[]) {
    Interfaccia *i=new Interfaccia();
    i->costruzioneFinestra();
}
