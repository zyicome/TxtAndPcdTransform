# Transform between txt file and pcd file

## update
**2024/08/13:**

（1）增加从txt文件转化为pcd文件的工具,两个模式
（2）增加从pcd文件转化为txt文件的工具,两个模式

## Prerequisites
- pcl
- ros2

## Compile
```shell
git clone https://github.com/zyicome/TxtAndPcdTransform.git
cd TxtAndPcdTransform
colcon build
```

### Run txt_to_pcd
```shell
cd TxtAndPcdTransform
#创建一个目录保存txt和pcd文件，可根据自己的目录修改
mkdir data && cd data && mkdir txt && mkdir pcd && cd ../
. install/setup.bash
ros2 launch txt_to_pcd txt_to_pcd.launch.py txt_path:=./data/txt/yourpoints.txt pcd_path:=./data/pcd/yourpoints.pcd mode:=0
```

### Run pcd_to_txt
```shell
cd TxtAndPcdTransform
#创建一个目录保存txt和pcd文件，可根据自己的目录修改
mkdir data && cd data && mkdir txt && mkdir pcd && cd ../
. install/setup.bash
ros2 launch pcd_to_txt pcd_to_txt.launch.py txt_path:=./data/txt/yourpoints.txt pcd_path:=./data/pcd/yourpoints.pcd mode:=0
```

#### parameters
- `txt_path`: your txt file path
- `pcd_path`: your pcd file path
- `mode`: 0: txt_example(2.1151,1.255,6.1515) 1: txt_example(2.1151 1.255 6.1515)