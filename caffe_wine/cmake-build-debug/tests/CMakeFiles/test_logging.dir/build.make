# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/radha/paperworks/SW/clion-2018.3.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/radha/paperworks/SW/clion-2018.3.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/cmake-build-debug

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_logging.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_logging.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_logging.dir/flags.make

tests/CMakeFiles/test_logging.dir/test_logging.cpp.o: tests/CMakeFiles/test_logging.dir/flags.make
tests/CMakeFiles/test_logging.dir/test_logging.cpp.o: ../tests/test_logging.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_logging.dir/test_logging.cpp.o"
	cd /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/cmake-build-debug/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_logging.dir/test_logging.cpp.o -c /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/tests/test_logging.cpp

tests/CMakeFiles/test_logging.dir/test_logging.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_logging.dir/test_logging.cpp.i"
	cd /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/cmake-build-debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/tests/test_logging.cpp > CMakeFiles/test_logging.dir/test_logging.cpp.i

tests/CMakeFiles/test_logging.dir/test_logging.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_logging.dir/test_logging.cpp.s"
	cd /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/cmake-build-debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/tests/test_logging.cpp -o CMakeFiles/test_logging.dir/test_logging.cpp.s

# Object files for target test_logging
test_logging_OBJECTS = \
"CMakeFiles/test_logging.dir/test_logging.cpp.o"

# External object files for target test_logging
test_logging_EXTERNAL_OBJECTS =

tests/test_logging: tests/CMakeFiles/test_logging.dir/test_logging.cpp.o
tests/test_logging: tests/CMakeFiles/test_logging.dir/build.make
tests/test_logging: src/libcaffe.a
tests/test_logging: tests/CMakeFiles/test_logging.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_logging"
	cd /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/cmake-build-debug/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_logging.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_logging.dir/build: tests/test_logging

.PHONY : tests/CMakeFiles/test_logging.dir/build

tests/CMakeFiles/test_logging.dir/clean:
	cd /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/cmake-build-debug/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_logging.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_logging.dir/clean

tests/CMakeFiles/test_logging.dir/depend:
	cd /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/tests /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/cmake-build-debug /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/cmake-build-debug/tests /home/radha/Works-AI-CV/khaali_patho/igf_impl/frameworks/caffe2/2/caffe_wine/cmake-build-debug/tests/CMakeFiles/test_logging.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_logging.dir/depend
