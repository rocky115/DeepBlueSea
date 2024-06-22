# Define the source files
#set(SOURCE_FILES
#        base.cpp
#        logging.cpp
#        # Add other source files here
#        )
#
## Create a static library
#add_library(caffe STATIC ${SOURCE_FILES})

# Link third-party dependencies if necessary
# target_link_libraries(caffe third_party_libs)

cmake_minimum_required(VERSION 3.10)
project(caffe_src)

#set(CMAKE_CXX_STANDARD 11)
## Locate source files
#file(GLOB SOURCES "*.cpp")
#
## Create library
#add_library(caffe STATIC ${SOURCES})
#target_include_directories(caffe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_library(base SHARED base.cpp)
add_library(blob SHARED blob.cpp)

target_link_libraries(blob base)
