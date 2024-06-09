cmake_minimum_required(VERSION 3.13)
project(caffe_wine)

set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)

# Add third-party dependencies (optional)
add_subdirectory(third_party/Caffe)
set(CMAKE_CXX_STANDARD 14)