cmake_minimum_required(VERSION 3.28)
project(mlla)

set(CMAKE_CXX_STANDARD 17)


# Include directories
include_directories(src)

# Enable testing
enable_testing()

# Assuming Google Test is within a subdirectory named GTest
# This requires that GTest directory to have a CMakeLists.txt configured correctly
add_subdirectory(GTest)


add_executable(mlla src/main.cpp
        src/matrix.cpp
        include/matrix.h
)

# Define the test executable
add_executable(MatrixTests tests/MatrixTest.cpp src/Matrix.cpp
        tests/MatrixTest.cpp)
target_link_libraries(MatrixTests gtest gtest_main pthread)

# Define a test to be run by ctest
add_test(NAME MatrixTest COMMAND MatrixTests)
