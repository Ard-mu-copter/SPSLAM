# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/hzj/.local/lib/python2.7/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/hzj/.local/lib/python2.7/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hzj/paper/IROS2021/WORKSPACE/src/sp_orb_slam/orb_slam2/3rdparty/DBoW2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hzj/paper/IROS2021/WORKSPACE/src/sp_orb_slam/orb_slam2/3rdparty/DBoW2/build

# Include any dependencies generated for this target.
include CMakeFiles/demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo.dir/flags.make

CMakeFiles/demo.dir/demo/demo.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/demo/demo.cpp.o: ../demo/demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hzj/paper/IROS2021/WORKSPACE/src/sp_orb_slam/orb_slam2/3rdparty/DBoW2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demo.dir/demo/demo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/demo/demo.cpp.o -c /home/hzj/paper/IROS2021/WORKSPACE/src/sp_orb_slam/orb_slam2/3rdparty/DBoW2/demo/demo.cpp

CMakeFiles/demo.dir/demo/demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/demo/demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hzj/paper/IROS2021/WORKSPACE/src/sp_orb_slam/orb_slam2/3rdparty/DBoW2/demo/demo.cpp > CMakeFiles/demo.dir/demo/demo.cpp.i

CMakeFiles/demo.dir/demo/demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/demo/demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hzj/paper/IROS2021/WORKSPACE/src/sp_orb_slam/orb_slam2/3rdparty/DBoW2/demo/demo.cpp -o CMakeFiles/demo.dir/demo/demo.cpp.s

# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/demo/demo.cpp.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

demo: CMakeFiles/demo.dir/demo/demo.cpp.o
demo: CMakeFiles/demo.dir/build.make
demo: libDBoW2.so
demo: /usr/local/lib/libopencv_dnn.so.4.5.0
demo: /usr/local/lib/libopencv_gapi.so.4.5.0
demo: /usr/local/lib/libopencv_highgui.so.4.5.0
demo: /usr/local/lib/libopencv_ml.so.4.5.0
demo: /usr/local/lib/libopencv_objdetect.so.4.5.0
demo: /usr/local/lib/libopencv_photo.so.4.5.0
demo: /usr/local/lib/libopencv_stitching.so.4.5.0
demo: /usr/local/lib/libopencv_video.so.4.5.0
demo: /usr/local/lib/libopencv_videoio.so.4.5.0
demo: /usr/local/lib/libopencv_calib3d.so.4.5.0
demo: /usr/local/lib/libopencv_features2d.so.4.5.0
demo: /usr/local/lib/libopencv_flann.so.4.5.0
demo: /usr/local/lib/libopencv_imgcodecs.so.4.5.0
demo: /usr/local/lib/libopencv_imgproc.so.4.5.0
demo: /usr/local/lib/libopencv_core.so.4.5.0
demo: CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hzj/paper/IROS2021/WORKSPACE/src/sp_orb_slam/orb_slam2/3rdparty/DBoW2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo.dir/build: demo

.PHONY : CMakeFiles/demo.dir/build

CMakeFiles/demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo.dir/clean

CMakeFiles/demo.dir/depend:
	cd /home/hzj/paper/IROS2021/WORKSPACE/src/sp_orb_slam/orb_slam2/3rdparty/DBoW2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hzj/paper/IROS2021/WORKSPACE/src/sp_orb_slam/orb_slam2/3rdparty/DBoW2 /home/hzj/paper/IROS2021/WORKSPACE/src/sp_orb_slam/orb_slam2/3rdparty/DBoW2 /home/hzj/paper/IROS2021/WORKSPACE/src/sp_orb_slam/orb_slam2/3rdparty/DBoW2/build /home/hzj/paper/IROS2021/WORKSPACE/src/sp_orb_slam/orb_slam2/3rdparty/DBoW2/build /home/hzj/paper/IROS2021/WORKSPACE/src/sp_orb_slam/orb_slam2/3rdparty/DBoW2/build/CMakeFiles/demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo.dir/depend

