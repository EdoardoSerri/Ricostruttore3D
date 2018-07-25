
//  Tridimensionale.h


#ifndef Tridimensionale_h
#define Tridimensionale_h
#include "Immagine.h"
#include "visualizzatore.hpp"
#include "DataExporter.hpp"
#include <opencv2/calib3d.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

class Tridimensionale final:private Immagine{
public:
    Tridimensionale(const std::string &,const std::string &, const cv::Mat &,const cv::Mat &);
    ~Tridimensionale();
    virtual void stampa() const;
private:
    virtual void salva() const;
    cv::Mat file;
    const cv::Mat colorMat;
    
};
#endif /* Tridimensionale_h */
