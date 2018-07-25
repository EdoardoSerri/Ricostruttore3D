//
//  visualizzatore.hpp
//
//  *******************************************************
//  Il seguente software mostra un point cloud su una
//  finestra browser utilizzando "viz" della distribuzione
//  opencv.
//  *******************************************************
//

#ifndef VISUALIZZATORE_HPP
#define VISUALIZZATORE_HPP

#include <opencv2/viz.hpp>

class Visualizzatore{
public:
    /// Public Member Function
    // Costructor / Distructor
    Visualizzatore(cv::Mat);
    ~Visualizzatore();
    // Set function
    void set_cam_pos(float, float, float);
    void set_cam_focal_point(float, float, float);
    void set_cam_y_dir(float, float, float);
    // Get function
    cv::Vec3f get_cam_pos();
    cv::Vec3f get_cam_focal_point();
    cv::Vec3f get_cam_y_dir();
private:
    // Verify parameters cam is set
    bool cnt_cam_set(cv::Vec3f);
    // Default setting of cam set
    void set_default_cam_set();
    void set_default_cam_focal_point();
    void set_default_cam_y_dir();
    /// Data Member
    cv::Vec3f cam_pos;
    cv::Vec3f cam_focal_point;
    cv::Vec3f cam_y_dir;
};

#endif /* visualizzatore_hpp */
