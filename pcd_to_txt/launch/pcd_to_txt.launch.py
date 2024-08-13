import os
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument, LogInfo

def generate_launch_description():
    txt_path = LaunchConfiguration('txt_path')
    pcd_path = LaunchConfiguration('pcd_path')
    mode = LaunchConfiguration('mode')

    declare_txt_path_cmd = DeclareLaunchArgument(
        'txt_path',
        default_value='./data/txt/points.txt',
        description='Path to the txt file'
    )

    declare_pcd_path_cmd = DeclareLaunchArgument(
        'pcd_path',
        default_value='./data/pcd/points.pcd',
        description='Path to the pcd file'
    )

    declare_mode_cmd = DeclareLaunchArgument(
        'mode',
        default_value="0",
        description='Used mode to read from pcd'
    )

    pcd_to_txt_node =Node(
        package='pcd_to_txt',
        executable='pcd_to_txt_node',
        name='pcd_to_txt_node',
        output='both',
        parameters=[
            {'txt_path': txt_path},
            {'pcd_path': pcd_path},
            {'mode': mode}
        ]
    )
    return LaunchDescription([
        declare_txt_path_cmd,
        declare_pcd_path_cmd,
        declare_mode_cmd,
        pcd_to_txt_node])