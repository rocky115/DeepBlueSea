# Enable testing
#enable_testing()

## Define the test executable
#add_executable(test_base test_base.cpp)
#add_executable(test_logging test_logging.cpp)
## Add other test files here
#
## Link the library and third-party dependencies to the test executables
#target_link_libraries(test_base caffe)
#target_link_libraries(test_logging caffe)
#
### Add tests
##add_test(NAME BaseTest COMMAND test_base)
##add_test(NAME LoggingTest COMMAND test_logging)

cmake_minimum_required(VERSION 3.10)
project(caffe_test)

set(CMAKE_CXX_STANDARD 14)

# Locate test source files
#file(GLOB TEST_SOURCES "*.cpp")

# Add executable for tests
#add_executable(test_base ${TEST_SOURCES})
#
#add_executable(test_blob ${TEST_SOURCES})

enable_testing()

add_executable(test_blob testBlob.cpp)
target_link_libraries(test_blob blob base)

add_test(NAME test_blob COMMAND test_blob)



## Link the test executable with the main library
#target_link_libraries(test_base PRIVATE caffe)
#target_include_directories(test_base PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
#
#
## Link the test executable with the main library
#target_link_libraries(test_blob PRIVATE caffe)
#target_include_directories(test_blob PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)


