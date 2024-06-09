# Enable testing
#enable_testing()

# Define the test executable
add_executable(test_base test_base.cpp)
add_executable(test_logging test_logging.cpp)
# Add other test files here

# Link the library and third-party dependencies to the test executables
target_link_libraries(test_base caffe)
target_link_libraries(test_logging caffe)

## Add tests
#add_test(NAME BaseTest COMMAND test_base)
#add_test(NAME LoggingTest COMMAND test_logging)


