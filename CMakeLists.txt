cmake_minimum_required(VERSION 3.1)
project(character_recognition)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

SET(OpenCV_DIR 3rdparty/opencv/installation/lib/cmake/opencv4/)

find_package( OpenCV REQUIRED )

include_directories(3rdparty/opencv/installation/include/opencv4/)

add_executable(character_recognition src/main.cpp)


link_directories(3rdparty/opencv/installation/lib)

target_link_libraries(character_recognition opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)


