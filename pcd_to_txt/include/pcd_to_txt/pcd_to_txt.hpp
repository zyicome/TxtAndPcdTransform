#include <iostream>
#include <fstream>
#include <rclcpp/rclcpp.hpp>
#include <pcl/point_cloud.h>
#include <pcl/conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl_conversions/pcl_conversions.h>

class PcdToTxt : public rclcpp::Node
{
public:
    PcdToTxt();

    bool pcd_to_txt(std::string txt_path, std::string pcd_path, int mode);
};