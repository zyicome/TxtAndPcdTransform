#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include "cv_bridge/cv_bridge.h"
#include <iostream>
#include <fstream>
#include <rclcpp/rclcpp.hpp>
#include <pcl/point_cloud.h>
#include <sensor_msgs/msg/detail/image__struct.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/compressed_image.hpp>
#include <pcl/conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl_conversions/pcl_conversions.h>
#include <vector>

class TxtToPcd : public rclcpp::Node
{
public:
    TxtToPcd();

    bool txt_to_pcd(std::string txt_path, std::string pcd_path, int mode);
};