//
//  Ricostruttore3d.hpp
//  From2dTo3d
//
//  Created by Crismesy ing on 22/05/18.
//  Copyright © 2018 Crismesy ing. All rights reserved.
//

#ifndef Ricostruttore3d_hpp
#define Ricostruttore3d_hpp

#include <string>
#include <vector>
#include <iostream>
#include "opencv2/calib3d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/core.hpp"
#include "opencv2/stereo.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <fstream>
#include <ctype.h>
#include "Bidimensionale.h"
#include "Tridimensionale.h"
#include <stdio.h>
using namespace std;
using namespace cv;
using namespace cv::stereo;
class Bidimensionale;
class Configurazione;
class Ricostruttore3d{
public:
    Ricostruttore3d(const vector <string> &, const int &, const float &, const float &, const float &, const float &, const float &, const float &, const float &, const float &, const float &);
    ~Ricostruttore3d();
    
    void vediImmagine(const int &);
    void vediImmagini();
    void vediNumeroImmagini();
    void ricostruisci();
private:
    void riprogettazione(const cv::Mat&, const cv::Mat&, cv::Mat&)const;
    void mostraMessaggio() const;
    void visualizza();
    vector <string> estraiInformazioniElemento(const string &) const;
    vector <string> explode(const string &,const char &) const;
    Mat estraiDisparityDepthMap( Bidimensionale ,  Bidimensionale );
     bool occupato();
    const int nImages=0;
    const int core;
    const vector <string> listaNomiImg;
    vector<Mat> listDisparity;
    vector <Bidimensionale*> listaImmagini;
    Mat disparita;
    bool lock;
    Mat matrixQ;
};

#endif /* Ricostruttore3d_hpp */
