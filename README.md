# Prerequisites

    1. ROS:

apt-get install ros-melodic-ros-base

    2. miscs:

apt-get install python-wstool python-catkin-tools 

    3. OpenCV3:

apt-get install libopencv-dev

    4. CUDA tookit, cuDNN (change the version of libtorch in install.sh according to CUDA version)

    5. Pangolin

    6. evo 

pip install evo --upgrade --no-binary evo

# Installation

1. Initialize a workspace:

mkdir -p /EXAMPLE/CATKIN/WORK_SPACE
cd /EXAMPLE/CATKIN/WORK_SPACE

mkdir src
catkin init
catkin config --extend /opt/ros/melodic
catkin config --cmake-args -DCMAKE_BUILD_TYPE=Release
catkin config --merge-devel

2. Clone the code:

cd src
git clone https://github.com/Ard-mu-copter/SPSLAM.git

Use the installation script:

cd sp_orb_slam
./install.sh

2. Running Examples

    Replace the /PATH/TO/TSUKUBA/DATASET in tsukuba.launch with where the sequence is decompressed:

<param name="data_path" value="/PATH/TO/TSUKUBA/DATASET" />

    Launch:

roslaunch tsukuba.launch seq:=lamps



