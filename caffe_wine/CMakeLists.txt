cmake_minimum_required(VERSION 3.13)
project(caffe_wine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Add Google Test
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
#
## Include directories
#include_directories(${PROJECT_SOURCE_DIR}/include)
#
## Add subdirectories
#add_subdirectory(src)
#add_subdirectory(tests)
#
## Add third-party dependencies (optional)
#add_subdirectory(third_party/Caffe)
#add_subdirectory(third_party/gt/googletest)

#target_link_libraries(caffe_wine ${GTEST_LIBRARIES} pthread)

include_directories(include)

add_subdirectory(src)
add_subdirectory(tests)