//
//  visualizzatore.cpp
//  viz
//
//  Created by Omar Cocchiarella on 03/07/18.
//  Copyright © 2018 Omar Cocchiarella. All rights reserved.
//

#include "visualizzatore.hpp"

Visualizzatore::Visualizzatore(cv::Mat cvcloud_load, cv::Mat color){
    
    cv::Mat cloud(1, 1889, CV_32FC3);
    std::ifstream ifs("/Users/omarcocchiarella/Desktop/PO/viz/viz/viz/bunny.ply");
    
    std::string str;
    for(size_t i = 0; i < 12; ++i)
        getline(ifs, str);
    
    cv::Point3f* data = cloud.ptr<cv::Point3f>();
    float dummy1, dummy2;
    for(size_t i = 0; i < 1889; ++i)
        ifs >> data[i].x >> data[i].y >> data[i].z >> dummy1 >> dummy2;
    
    cloud *= 5.0f;
    
    
    /// Create a PLY file from reprojectTo3D
    //creaPLY(cvcloud_load, color);
    
    /// Set camera following properties default
    //camera position
    if(cnt_cam_set(this->cam_pos))
        set_default_cam_set();
    //camera focale point
    if(cnt_cam_set(this->cam_focal_point))
        set_default_cam_focal_point();
    //camera yow direction
    if(cnt_cam_set(this->cam_y_dir))
        set_default_cam_y_dir();
    
    /// Mesch a PLY file
    //cv::viz::Mesh mesh = cv::viz::Mesh::load("/Users/omarcocchiarella/Desktop/PO/viz/viz/viz/bunny.ply",1);
    
    /// Create a window
    cv::viz::Viz3d myWindow("Visualizzatore Point Cloud");

    /// We can get the transformation matrix from camera coordinate system to global using
    /// - makeTransformToGlobal. We need the axes of the camera
    cv::Affine3f transform = cv::viz::makeTransformToGlobal(cv::Vec3f(0.0f,-1.0f,0.0f), cv::Vec3f(-1.0f,0.0f,0.0f), cv::Vec3f(0.0f,0.0f,-1.0f), cam_pos);
    
    /// Pose of the widget in camera frame
    cv::Affine3f cloud_pose = cv::Affine3f().translate(cv::Vec3f(0.0f,0.0f,3.0f));
    
    /// Pose of the widget in global frame
    cv::Affine3f cloud_pose_global = transform * cloud_pose;
    
    cv::viz::WCloud cloud_widget(cvcloud_load, cv::viz::Color::red());
    
    /// Visualize widget
    myWindow.showWidget("mesh", /*cv::viz::WMesh(mesh)*/cloud_widget, cloud_pose_global);
    
    
    /// Text description
    myWindow.showWidget("text2d", cv::viz::WText("Visualizzazione cloud point", cv::Point(30, 30), 30, cv::viz::Color::green()));
    
    /// Start event loop.
    myWindow.spin();
}

Visualizzatore::~Visualizzatore(){
    //camera position destroy
    this->cam_pos.val[0] = 0.0f;
    this->cam_pos.val[1] = 0.0f;
    this->cam_pos.val[2] = 0.0f;
    //camera focale point destroy
    this->cam_focal_point.val[0] = 0.0f;
    this->cam_focal_point.val[1] = 0.0f;
    this->cam_focal_point.val[2] = 0.0f;
    //camera yow direction destroy
    this->cam_y_dir.val[0] = 0.0f;
    this->cam_y_dir.val[1] = 0.0f;
    this->cam_y_dir.val[2] = 0.0f;
}


void Visualizzatore::creaPLY(cv::Mat cvcloud_load, cv::Mat color){
    DataExporter data_ex(cvcloud_load,color,"/Users/omarcocchiarella/Desktop/PO/viz/viz/viz/pointcloud.ply",PLY_ASCII);
    data_ex.exportToFile();
}


/// Set function

void Visualizzatore::set_cam_pos(float x, float y, float z){
    this->cam_pos.val[0] = y;
    this->cam_pos.val[1] = x;
    this->cam_pos.val[2] = z;
}

void Visualizzatore::set_cam_focal_point(float x, float y, float z){
    this->cam_focal_point.val[0] = y;
    this->cam_focal_point.val[1] = x;
    this->cam_focal_point.val[2] = z;
}

void Visualizzatore::set_cam_y_dir(float x, float y, float z){
    this->cam_y_dir.val[0] = y;
    this->cam_y_dir.val[1] = x;
    this->cam_y_dir.val[2] = z;
}

/// Get function

cv::Vec3f Visualizzatore::get_cam_pos(){return this->cam_pos;}

cv::Vec3f Visualizzatore::get_cam_focal_point(){return this->cam_focal_point;}

cv::Vec3f Visualizzatore::get_cam_y_dir(){return this->cam_y_dir;}

/// Control function

bool Visualizzatore::cnt_cam_set(cv::Vec3f vec_cnt){
    if(vec_cnt.val[0] != 0 && vec_cnt.val[1] != 0 && vec_cnt.val[2] != 0) return false;
    return true;
}

/// Set defoult parameters for position

void Visualizzatore::set_default_cam_set(){
    this->cam_pos.val[0] = 3.0f;
    this->cam_pos.val[1] = 3.0f;
    this->cam_pos.val[2] = 3.0f;
}

void Visualizzatore::set_default_cam_focal_point(){
    this->cam_focal_point.val[0] = 3.0f;
    this->cam_focal_point.val[1] = 3.0f;
    this->cam_focal_point.val[2] = 2.0f;
}

void Visualizzatore::set_default_cam_y_dir(){
    this->cam_y_dir.val[0] = -1.0f;
    this->cam_y_dir.val[1] = 0.0f;
    this->cam_y_dir.val[2] = 0.0f;
}
