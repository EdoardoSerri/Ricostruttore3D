//
//  Ricostruttore3d.cpp
//  From2dTo3d
//
//  Created by Crismesy ing on 22/05/18.
//  Copyright © 2018 Crismesy ing. All rights reserved.
//

#include "Ricostruttore3d.h"

Ricostruttore3d::Ricostruttore3d(const vector <string> &value,const int &ncore, const float &disparityValue, const float &mindisparityValue, const float &uniqValue, const float &swsValue, const float &srValue, const float &diff12Value, const float &filtercapValue, const float &textureValue, const float &scalleValue):core(ncore),listaNomiImg(value),nImages((int)value.size()),lock(false)
{
    mostraMessaggio();
    cout<<"Inizio la ricostruzione delle "<< value.size() <<" immagini"<<endl;
    if(nImages>=2&&nImages%2==0){
        int j=0;
            cout<<"Creo "<< j+1<<"a disparita'";
            Ptr<Bidimensionale> image = new Bidimensionale((string)estraiInformazioniElemento(this->listaNomiImg[j]).at(1),(string)estraiInformazioniElemento(this->listaNomiImg[j]).at(0),nImages);
        
            Ptr<Bidimensionale> image2 = new Bidimensionale((string)estraiInformazioniElemento(this->listaNomiImg[j+1]).at(1),(string)estraiInformazioniElemento(this->listaNomiImg[j+1]).at(0),nImages);
        
            RNG range;
            
            //set the parameters
            int binary_descriptor_type = range.uniform(0,8);
            int kernel_size, aggregation_window;
            if(binary_descriptor_type == 0)
                kernel_size = 5;
            else if(binary_descriptor_type == 2 || binary_descriptor_type == 3)
                kernel_size = 7;
            else if(binary_descriptor_type == 1)
                kernel_size = 11;
            else
                kernel_size = 9;
            if(binary_descriptor_type == 3)
                aggregation_window = 13;
            else
                aggregation_window = 11;
            
            Ptr<StereoBinaryBM> sbm = StereoBinaryBM::create(disparityValue, kernel_size);
            // we set the corresponding parameters
            sbm->setMinDisparity(mindisparityValue);
            sbm->setPreFilterCap(filtercapValue);
            sbm->setTextureThreshold(textureValue);
            sbm->setUniquenessRatio(uniqValue);
            sbm->setSpeckleWindowSize(swsValue); // speckle size
            sbm->setSpeckleRange(srValue);
            sbm->setDisp12MaxDiff(diff12Value);
            sbm->setScalleFactor(scalleValue); // the scaling factor
            sbm->setBinaryKernelType(binary_descriptor_type); // binary descriptor kernel
            sbm->setAgregationWindowSize(aggregation_window);
            // the user can choose between the average speckle removal algorithm or
            // the classical version that was implemented in OpenCV
            sbm->setSpekleRemovalTechnique(CV_SPECKLE_REMOVAL_AVG_ALGORITHM);
            sbm->setUsePrefilter(false);

            vector<vector<Point2f> > imagePoints[2];
            vector<vector<Point3f> > objectPoints;
            
            
            imagePoints[0].resize(2);
            imagePoints[1].resize(2);
            objectPoints.resize(2);
            Size boardSize;
            boardSize.width = 9;
            boardSize.height = 6;
            float squareSize = 1;
            for(int y = 0; y < boardSize.height; y++ ){
                for(int z = 0; z < boardSize.width; z++ ){
                    objectPoints[0].push_back(Point3f(z*squareSize, y*squareSize, 0));
                    objectPoints[1].push_back(Point3f(z*squareSize, y*squareSize, 0));
                    imagePoints[0][0].push_back(Point2f(z*squareSize, y*squareSize));
                    imagePoints[0][1].push_back(Point2f(z*squareSize, y*squareSize));
                    imagePoints[1][0].push_back(Point2f(z*squareSize, y*squareSize));
                    imagePoints[1][1].push_back(Point2f(z*squareSize, y*squareSize));
                }
                
            }
            cout << "Running stereo calibration ...\n";
            
            Mat cameraMatrix[2], distCoeffs[2];
            cout<<image->estraiSize()<<endl;
            cameraMatrix[0] = initCameraMatrix2D(objectPoints,imagePoints[0],image->estraiSize(),0);
            cameraMatrix[1] = initCameraMatrix2D(objectPoints,imagePoints[1],image2->estraiSize(),0);
            Mat R, T, E, F;
            
            stereoCalibrate(objectPoints, imagePoints[0], imagePoints[1],
                             cameraMatrix[0], distCoeffs[0],
                             cameraMatrix[1], distCoeffs[1],
                             image->estraiSize(), R, T, E, F,
                             CALIB_FIX_ASPECT_RATIO +
                             CALIB_ZERO_TANGENT_DIST +
                             CALIB_USE_INTRINSIC_GUESS +
                             CALIB_SAME_FOCAL_LENGTH +
                             CALIB_RATIONAL_MODEL +
                             CALIB_FIX_K3 + CALIB_FIX_K4 + CALIB_FIX_K5,
                             TermCriteria(TermCriteria::COUNT+TermCriteria::EPS, 100, 1e-5) );
        
        
        
            Mat map1x,map1y,map2x,map2y;
            Mat R1, R2, P1, P2, Q;
            Mat img_left, img_right;
            Mat disparity;
            Rect validRoi[2];
        
            disparity = Mat(image->estraiFile().rows, image->estraiFile().cols, CV_8UC1);
        
            initUndistortRectifyMap(cameraMatrix[0], distCoeffs[0], R1, P1, image->estraiSize(), CV_32FC1, map1x, map1y);
            initUndistortRectifyMap(cameraMatrix[1], distCoeffs[1], R2, P2, image2->estraiSize(), CV_32FC1, map2x, map2y);
            for(int size=0;size<2;size++){
                remap(imread(image->estraiNome(), IMREAD_GRAYSCALE), img_right, map1x, map1y, INTER_LINEAR);
                remap(imread(image2->estraiNome(), IMREAD_GRAYSCALE), img_left, map2x, map2y, INTER_LINEAR);
            }
        
            sbm->compute(img_left , img_right, disparity);
            
            stereoRectify(cameraMatrix[0], distCoeffs[0],
                          cameraMatrix[1], distCoeffs[1],
                          image->estraiSize(), R, T, R1, R2, P1, P2, Q,
                          CALIB_ZERO_DISPARITY, 1, image->estraiSize(), &validRoi[0], &validRoi[1]);
            
            Q.convertTo(Q, CV_32F);
            //(void *)visualizza();
            imshow("Prima",disparity);
            disparity.convertTo(disparity, CV_8U, 255 / (disparityValue*16.));
            disparity.convertTo(disparity, CV_32FC1, 1.f / 32.f);
            this->listDisparity.push_back(disparity);
            this->matrixQ=Q;
            
        cout<<"Creo disparita' a due a due";
        
        this->visualizza();
    }else{
        cout<<"Non e' possibile ricostruire con una sola foto";
    }
}
Ricostruttore3d::~Ricostruttore3d(){
    cout<<"Il ricostruttore 3d e' terminato"<<endl;
}
void Ricostruttore3d::visualizza(){
                Mat image3DOCV(this->listDisparity.at(0).size(), CV_32FC3);
                if(this->listDisparity.size()<2){
                    cout<<"visualizza"<<endl;
                    imshow("Ricostruttore", this->listDisparity.at(0));
                    
                    reprojectImageTo3D(this->listDisparity.at(0), image3DOCV, this->matrixQ,false,CV_32F );
                    
                    imshow("Ricostruttoree", image3DOCV);
                    
                    Mat color = imread(this->listaNomiImg[0], IMREAD_COLOR);
                    
                    Ptr<Tridimensionale> tri = new Tridimensionale((string)estraiInformazioniElemento(this->listaNomiImg[0]).at(1),"pointcloud.ply",image3DOCV,color);
                    
                        tri->stampa();
                    
                    
                }
    

    
}


void Ricostruttore3d::vediNumeroImmagini(){
    cout<< "Ci sono "<< this->listaNomiImg.size()<<" attualmente nel ricostruttore";
}
void Ricostruttore3d::mostraMessaggio() const {
    cout<<"Ricostruttore 3d per esame di programmazione ad oggetti"<<endl;
}
 vector<string> Ricostruttore3d::estraiInformazioniElemento(const string &s) const {
    vector <string> result=explode(s, '/');
    string name = result[((int)result.size()-1)];
    string percorso=s.substr(0,s.size()-name.size()-1);
    result.clear();
    result.push_back(name);
    result.push_back(percorso);
    return result;
}
 vector<string> Ricostruttore3d::explode(const string &stringa,const char &delimitatore) const{
    string buff{""};
    vector<string> v;
    
    for(auto n:stringa)
    {
        if(n != delimitatore) buff+=n; else
            if(n == delimitatore && buff != "") { v.push_back(buff); buff = ""; }
    }
    if(buff != "") v.push_back(buff);
    
    return v;
}
void Ricostruttore3d::ricostruisci(){
    
}
