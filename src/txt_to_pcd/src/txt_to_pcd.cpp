#include "txt_to_pcd/txt_to_pcd.hpp"

TxtToPcd::TxtToPcd() : Node("txt_to_pcd")
{
    RCLCPP_INFO(this->get_logger(), "TxtToPcd node has been started.");
    std::string txt_path, pcd_path;
    int mode;
    this->declare_parameter("txt_path", "");
    this->declare_parameter("pcd_path", "");
    this->declare_parameter("mode", 0);
    this->get_parameter("txt_path", txt_path);
    this->get_parameter("pcd_path", pcd_path);
    this->get_parameter("mode", mode);
    if(txt_to_pcd(txt_path, pcd_path, mode))
    {
        RCLCPP_INFO(this->get_logger(), "Save pcd file successfully. Node finished.");
    }
    else
    {
        RCLCPP_ERROR(this->get_logger(), "Save pcd file failed. Node finished.");
    }
}

bool TxtToPcd::txt_to_pcd(std::string txt_path, std::string pcd_path, int mode)
{
    std::ifstream txt_in(txt_path); // 读取txt文件
    std::string line;   // 用于临时存储txt文件中的每一行数据。
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>); // 创建一个点云对象
    pcl::PointXYZ point;    // 用于存储每一行数据中的点
    if (txt_in.is_open()) // 判断文件是否被打开
    {
        while(getline(txt_in, line))  // 读取txt文件中的一行，默认遇到“/n”停止
        {
            if(mode == 0)
            {
                std::stringstream ss(line); // 将这一行的字符串转换s为输入流，以便提取数据
                char deliminator;   // 用于存储分隔符
                ss >> point.x;
                ss >> deliminator;  // 读取分隔符
                ss >> point.y;
                ss >> deliminator;  // 读取分隔符
                ss >> point.z;
                cloud->push_back(point);    // 将读取的数据添加进cloud中
            }
            else if(mode == 1)
            {
                std::stringstream ss(line); // 将这一行的字符串转换s为输入流，以便提取数据
                ss >> point.x;
                ss >> point.y;
                ss >> point.z;
                cloud->push_back(point);    // 将读取的数据添加进cloud中
            }
            else
            {
                RCLCPP_ERROR(this->get_logger(), "Mode error!");
                return false;
            }
        }   
        txt_in.close();   // 关闭文件流
        pcl::io::savePCDFileASCII(pcd_path, *cloud); // 将点云数据保存为pcd文件
        return true;
    }
    else    // 错误处理
    {
        RCLCPP_ERROR(this->get_logger(), "无法打开文件");
        RCLCPP_INFO(this->get_logger(), txt_path.c_str());
        return false;
    }   
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TxtToPcd>());
    rclcpp::shutdown();
    return 0;
}