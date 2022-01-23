cmake_minimum_required(VERSION 3.1)
project(character_recognition)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

SET(OpenCV_DIR $PWD//installation/OpenCV-master/lib/cmake/opencv4)


add_executable(character_recognition src/main.cpp)
