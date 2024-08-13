#include "pcd_to_txt/pcd_to_txt.hpp"

PcdToTxt::PcdToTxt() : Node("pcd_to_txt")
{
    RCLCPP_INFO(this->get_logger(), "PcdToTxt node has been started.");
    std::string txt_path, pcd_path;
    int mode;
    this->declare_parameter("txt_path", "");
    this->declare_parameter("pcd_path", "");
    this->declare_parameter("mode", 0);
    this->get_parameter("txt_path", txt_path);
    this->get_parameter("pcd_path", pcd_path);
    this->get_parameter("mode", mode);
    if(pcd_to_txt(txt_path, pcd_path, mode))
    {
        RCLCPP_INFO(this->get_logger(), "Save txt file successfully. Node finished.");
    }
    else
    {
        RCLCPP_ERROR(this->get_logger(), "Save txt file failed. Node finished.");
    }
}

bool PcdToTxt::pcd_to_txt(std::string txt_path, std::string pcd_path, int mode)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    if(pcl::io::loadPCDFile(pcd_path, *cloud) == -1)
    {
        RCLCPP_ERROR(this->get_logger(), "PCD文件打开失败.");
        RCLCPP_INFO(this->get_logger(), pcd_path.c_str());
        return false;
    }
 
    std::ofstream outfile;
    outfile.open(txt_path);
 
    if(mode == 0)
    {
        for (size_t i = 0; i < cloud->points.size(); i++) 
        {
            outfile << cloud->points[i].x << "," << cloud->points[i].y << "," << cloud->points[i].z << "\n";
        }
    }
    else if(mode == 1)
    {
        for (size_t i = 0; i < cloud->points.size(); i++) 
        {
            outfile << cloud->points[i].x << " " << cloud->points[i].y << " " << cloud->points[i].z << "\n";
        }
    }
    else
    {
        RCLCPP_ERROR(this->get_logger(), "Mode error!");
        return false;
    }

    outfile.close();
    return true;
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PcdToTxt>());
    rclcpp::shutdown();
    return 0;
}