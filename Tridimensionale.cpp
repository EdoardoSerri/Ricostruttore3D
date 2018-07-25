
#include "Tridimensionale.h"

Tridimensionale::Tridimensionale(const std::string &pathName, const std::string &imgName, const cv::Mat &data_mat, const cv::Mat &color):Immagine(pathName,imgName),colorMat(color),file(data_mat)
{
    this->salva();
    std::cout<<"Immagine 3d Creata la path per il salvataggio e': "<<Immagine::toString()<<std::endl;
    int v = 0;
    float max_z = 1.0e4;
    int k = 0;
    for(int i = 0; i < data_mat.rows; i++){
        for(int j = 0; j < data_mat.cols; j++){
            cv::Vec3f point = data_mat.at<cv::Vec3f>(j, i);
            if(fabs(point[2] - max_z) < FLT_EPSILON || fabs(point[2]) > max_z){
                if(!cvIsInf(point[0]) && !cvIsInf(point[1]) && !cvIsInf(point[2])){
                    k++;
                }
            }
        }
    }
    cv::Mat img_pc(1, k, CV_32FC3);
    cv::Point3f* data = img_pc.ptr<cv::Point3f>();
    for(int i = 0; i < data_mat.rows; i++){
        for(int j = 0; j < data_mat.cols; j++){
            cv::Vec3f point = data_mat.at<cv::Vec3f>(j, i);
            if(fabs(point[2] - max_z) < FLT_EPSILON || fabs(point[2]) > max_z){
                if(!cvIsInf(point[0]) && !cvIsInf(point[1]) && !cvIsInf(point[2])){
                    data[v].x = point[0];
                    data[v].y = point[1];
                    data[v].z = point[2];
                    v++;
                }
            }
        }
    }
    img_pc *= 5.0f;
    img_pc.assignTo(this->file);
}
Tridimensionale::~Tridimensionale(){
    std::cout<<"Immagine 3d";
    std::cout<<Immagine::toString()<<std::endl;
    std::cout<<" distrutta!"<<std::endl;
}
void Tridimensionale::salva()const{
    std::cout<< "Nome immagine 3d: ";
    DataExporter data_ex(this->file,this->colorMat,Immagine::toString(),PLY_ASCII);
    data_ex.exportToFile();
    std::cout<<Immagine::toString()<<std::endl;
    std::cout<<". Salvata! "<<std::endl;
}
void Tridimensionale::stampa()const{
    Visualizzatore visualizza(this->file);
}


