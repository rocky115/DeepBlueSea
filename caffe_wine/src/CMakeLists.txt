# Define the source files
set(SOURCE_FILES
        base.cpp
        logging.cpp
        # Add other source files here
        )

# Create a static library
add_library(caffe STATIC ${SOURCE_FILES})

# Link third-party dependencies if necessary
# target_link_libraries(caffe third_party_libs)