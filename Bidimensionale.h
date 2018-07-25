
#ifndef Bidimensionale_h
#define Bidimensionale_h
#include "Immagine.h"
#include "opencv2/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui/highgui.hpp>
class Bidimensionale final:private Immagine{
public:
    Bidimensionale(const std::string &,const std::string &,const int &);
    ~Bidimensionale();
    std::string estraiNome() const;
    virtual void salva() const;
    virtual void stampa() const;
    cv::Size estraiSize() const;
    cv::Mat estraiFile() const;
private:
    const cv::Mat file;
    const cv::Size size;
};
#endif /* Bidimensionale_h */
