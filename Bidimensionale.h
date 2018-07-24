//
//  Bidimensionale.h
//  From2dTo3d
//
//  Created by Crismesy ing on 22/05/18.
//  Copyright © 2018 Crismesy ing. All rights reserved.
//

#ifndef Bidimensionale_h
#define Bidimensionale_h
#include "Immagine.h"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"

using namespace cv;
using namespace std;
class Bidimensionale final:private Immagine{
public:
    Bidimensionale(const string &,const string &,const int &);
    ~Bidimensionale();
    string estraiNome() const;
    virtual void salva() const;
    Size estraiSize() const;
    Mat estraiFile() const;
private:
    const Mat file;
    const Size size;
};
#endif /* Bidimensionale_h */
