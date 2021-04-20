## Prerequisites

1. [ROS](http://wiki.ros.org/melodic/Installation) :
```
apt-get install ros-melodic-ros-base
```

2. miscs:
```
apt-get install python-wstool python-catkin-tools 
```

3. [OpenCV3](https://docs.opencv.org/3.4.11/d7/d9f/tutorial_linux_install.html):
```
apt-get install libopencv-dev
```

4. CUDA tookit, cuDNN (change the version of libtorch in [install.sh](https://github.com/HyHuang1995/sp_orb_slam/blob/master/install.sh) according to CUDA version)

5. [Pangolin](https://github.com/stevenlovegrove/Pangolin) :

6. [evo](https://github.com/MichaelGrupp/evo) :
```
pip install evo --upgrade --no-binary evo
```

## Installation
Initialize a workspace:

```
mkdir -p /EXAMPLE/CATKIN/WORK_SPACE
cd /EXAMPLE/CATKIN/WORK_SPACE

mkdir src
catkin init
catkin config --extend /opt/ros/melodic
catkin config --cmake-args -DCMAKE_BUILD_TYPE=Release
catkin config --merge-devel
```

Clone the code:
```
cd src
git clone git@github.com:hyhuang1995/sp_orb_slam.git
```

Use the installation script:
```
cd sp_orb_slam
./install.sh
```

## Running Examples
To run the demo on the New Tsukuba sequences:

1. Download the [dataset](https://home.cvlab.cs.tsukuba.ac.jp/dataset)

2. Replace the **/PATH/TO/TSUKUBA/DATASET** in [tsukuba.launch](https://github.com/HyHuang1995/sp_orb_slam/blob/master/orb_ros/launch/tsukuba.launch) with where the sequence is decompressed:
```
<param name="data_path" value="/PATH/TO/TSUKUBA/DATASET" />
```

3. Launch:
```
roslaunch tsukuba.launch seq:=lamps
```

To run the demo on the EuRoC MAV dataset:
1. Download the [sequences](https://projects.asl.ethz.ch/datasets/doku.php?id=kmavvisualinertialdatasets) (ASL Format)

2. Replace the **/PATH/TO/EUROC/DATASET/** in [euroc_mono.launch](https://github.com/HyHuang1995/sp_orb_slam/blob/master/orb_ros/launch/euroc_mono.launch) with where the sequence is decompressed:
```
<param name="data_path" value="/PATH/TO/EUROC/DATASET/$(arg seq)/mav0/" />
```

3. Launch:
```
roslaunch euroc_mono.launch seq:=MH_05_difficult
```
The output trajectories would be saved to **orb_ros/expr**.


