# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nexte/Desktop/ARM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nexte/Desktop/ARM/build

# Include any dependencies generated for this target.
include CMakeFiles/autoaim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/autoaim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/autoaim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/autoaim.dir/flags.make

CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.o: CMakeFiles/autoaim.dir/flags.make
CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.o: /home/nexte/Desktop/ARM/hik_camera/hik_camera/HikCam.cpp
CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.o: CMakeFiles/autoaim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nexte/Desktop/ARM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.o -MF CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.o.d -o CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.o -c /home/nexte/Desktop/ARM/hik_camera/hik_camera/HikCam.cpp

CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nexte/Desktop/ARM/hik_camera/hik_camera/HikCam.cpp > CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.i

CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nexte/Desktop/ARM/hik_camera/hik_camera/HikCam.cpp -o CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.s

CMakeFiles/autoaim.dir/Detector/src/detector.cpp.o: CMakeFiles/autoaim.dir/flags.make
CMakeFiles/autoaim.dir/Detector/src/detector.cpp.o: /home/nexte/Desktop/ARM/Detector/src/detector.cpp
CMakeFiles/autoaim.dir/Detector/src/detector.cpp.o: CMakeFiles/autoaim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nexte/Desktop/ARM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/autoaim.dir/Detector/src/detector.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autoaim.dir/Detector/src/detector.cpp.o -MF CMakeFiles/autoaim.dir/Detector/src/detector.cpp.o.d -o CMakeFiles/autoaim.dir/Detector/src/detector.cpp.o -c /home/nexte/Desktop/ARM/Detector/src/detector.cpp

CMakeFiles/autoaim.dir/Detector/src/detector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/autoaim.dir/Detector/src/detector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nexte/Desktop/ARM/Detector/src/detector.cpp > CMakeFiles/autoaim.dir/Detector/src/detector.cpp.i

CMakeFiles/autoaim.dir/Detector/src/detector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/autoaim.dir/Detector/src/detector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nexte/Desktop/ARM/Detector/src/detector.cpp -o CMakeFiles/autoaim.dir/Detector/src/detector.cpp.s

CMakeFiles/autoaim.dir/Detector/src/serial.cpp.o: CMakeFiles/autoaim.dir/flags.make
CMakeFiles/autoaim.dir/Detector/src/serial.cpp.o: /home/nexte/Desktop/ARM/Detector/src/serial.cpp
CMakeFiles/autoaim.dir/Detector/src/serial.cpp.o: CMakeFiles/autoaim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nexte/Desktop/ARM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/autoaim.dir/Detector/src/serial.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autoaim.dir/Detector/src/serial.cpp.o -MF CMakeFiles/autoaim.dir/Detector/src/serial.cpp.o.d -o CMakeFiles/autoaim.dir/Detector/src/serial.cpp.o -c /home/nexte/Desktop/ARM/Detector/src/serial.cpp

CMakeFiles/autoaim.dir/Detector/src/serial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/autoaim.dir/Detector/src/serial.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nexte/Desktop/ARM/Detector/src/serial.cpp > CMakeFiles/autoaim.dir/Detector/src/serial.cpp.i

CMakeFiles/autoaim.dir/Detector/src/serial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/autoaim.dir/Detector/src/serial.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nexte/Desktop/ARM/Detector/src/serial.cpp -o CMakeFiles/autoaim.dir/Detector/src/serial.cpp.s

CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.o: CMakeFiles/autoaim.dir/flags.make
CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.o: /home/nexte/Desktop/ARM/Detector/src/classifier.cpp
CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.o: CMakeFiles/autoaim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nexte/Desktop/ARM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.o -MF CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.o.d -o CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.o -c /home/nexte/Desktop/ARM/Detector/src/classifier.cpp

CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nexte/Desktop/ARM/Detector/src/classifier.cpp > CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.i

CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nexte/Desktop/ARM/Detector/src/classifier.cpp -o CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.s

CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.o: CMakeFiles/autoaim.dir/flags.make
CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.o: /home/nexte/Desktop/ARM/Detector/src/pnp.cpp
CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.o: CMakeFiles/autoaim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nexte/Desktop/ARM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.o -MF CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.o.d -o CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.o -c /home/nexte/Desktop/ARM/Detector/src/pnp.cpp

CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nexte/Desktop/ARM/Detector/src/pnp.cpp > CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.i

CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nexte/Desktop/ARM/Detector/src/pnp.cpp -o CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.s

CMakeFiles/autoaim.dir/main.cpp.o: CMakeFiles/autoaim.dir/flags.make
CMakeFiles/autoaim.dir/main.cpp.o: /home/nexte/Desktop/ARM/main.cpp
CMakeFiles/autoaim.dir/main.cpp.o: CMakeFiles/autoaim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nexte/Desktop/ARM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/autoaim.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/autoaim.dir/main.cpp.o -MF CMakeFiles/autoaim.dir/main.cpp.o.d -o CMakeFiles/autoaim.dir/main.cpp.o -c /home/nexte/Desktop/ARM/main.cpp

CMakeFiles/autoaim.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/autoaim.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nexte/Desktop/ARM/main.cpp > CMakeFiles/autoaim.dir/main.cpp.i

CMakeFiles/autoaim.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/autoaim.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nexte/Desktop/ARM/main.cpp -o CMakeFiles/autoaim.dir/main.cpp.s

# Object files for target autoaim
autoaim_OBJECTS = \
"CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.o" \
"CMakeFiles/autoaim.dir/Detector/src/detector.cpp.o" \
"CMakeFiles/autoaim.dir/Detector/src/serial.cpp.o" \
"CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.o" \
"CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.o" \
"CMakeFiles/autoaim.dir/main.cpp.o"

# External object files for target autoaim
autoaim_EXTERNAL_OBJECTS =

autoaim: CMakeFiles/autoaim.dir/hik_camera/hik_camera/HikCam.cpp.o
autoaim: CMakeFiles/autoaim.dir/Detector/src/detector.cpp.o
autoaim: CMakeFiles/autoaim.dir/Detector/src/serial.cpp.o
autoaim: CMakeFiles/autoaim.dir/Detector/src/classifier.cpp.o
autoaim: CMakeFiles/autoaim.dir/Detector/src/pnp.cpp.o
autoaim: CMakeFiles/autoaim.dir/main.cpp.o
autoaim: CMakeFiles/autoaim.dir/build.make
autoaim: /usr/local/lib/libopencv_gapi.so.4.8.0
autoaim: /usr/local/lib/libopencv_highgui.so.4.8.0
autoaim: /usr/local/lib/libopencv_ml.so.4.8.0
autoaim: /usr/local/lib/libopencv_objdetect.so.4.8.0
autoaim: /usr/local/lib/libopencv_photo.so.4.8.0
autoaim: /usr/local/lib/libopencv_stitching.so.4.8.0
autoaim: /usr/local/lib/libopencv_video.so.4.8.0
autoaim: /usr/local/lib/libopencv_videoio.so.4.8.0
autoaim: /opt/MVS/lib/64/libMvCameraControl.so
autoaim: /usr/local/lib/libopencv_imgcodecs.so.4.8.0
autoaim: /usr/local/lib/libopencv_dnn.so.4.8.0
autoaim: /usr/local/lib/libopencv_calib3d.so.4.8.0
autoaim: /usr/local/lib/libopencv_features2d.so.4.8.0
autoaim: /usr/local/lib/libopencv_flann.so.4.8.0
autoaim: /usr/local/lib/libopencv_imgproc.so.4.8.0
autoaim: /usr/local/lib/libopencv_core.so.4.8.0
autoaim: CMakeFiles/autoaim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nexte/Desktop/ARM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable autoaim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/autoaim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/autoaim.dir/build: autoaim
.PHONY : CMakeFiles/autoaim.dir/build

CMakeFiles/autoaim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/autoaim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/autoaim.dir/clean

CMakeFiles/autoaim.dir/depend:
	cd /home/nexte/Desktop/ARM/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nexte/Desktop/ARM /home/nexte/Desktop/ARM /home/nexte/Desktop/ARM/build /home/nexte/Desktop/ARM/build /home/nexte/Desktop/ARM/build/CMakeFiles/autoaim.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/autoaim.dir/depend

