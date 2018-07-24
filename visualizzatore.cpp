//
//  visualizzatore.cpp
//  viz
//
//  Created by Omar Cocchiarella on 03/07/18.
//  Copyright © 2018 Omar Cocchiarella. All rights reserved.
//

#include "visualizzatore.hpp"

Visualizzatore::Visualizzatore(cv::Mat cvcloud_load){
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
    
    /// Create a window
    
    cv::viz::Viz3d myWindow("Visualizzatore Point Cloud");
    myWindow.setBackgroundColor(cv::viz::Color::white());
    
    /// We can get the pose of the cam using makeCameraPose
    cv::Affine3f cam_pose = cv::viz::makeCameraPose(this->cam_pos, this->cam_focal_point, this->cam_y_dir);
    
    /// We can get the transformation matrix from camera coordinate system to global using
    
    /// - makeTransformToGlobal. We need the axes of the camera
    cv::Affine3f transform = cv::viz::makeTransformToGlobal(cv::Vec3f(0.0f,-1.0f,0.0f), cv::Vec3f(-1.0f,0.0f,0.0f), cv::Vec3f(0.0f,0.0f,-1.0f), cam_pos);
    
    /// Create a cloud widget.
    cv::viz::WCloud cloud_widget(cvcloud_load, cv::viz::Color::green());
    
    /// Visualize widget
    myWindow.showWidget("point cloud", cloud_widget, transform);
    
    /// Set the viewer pose to that of camera
    myWindow.setViewerPose(cam_pose);
    
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
