#!/bin/bash
echo "OpenCV installation"

# Define OpenCV version to install
cvVersion="master"

mkdir 3rdparty
cd 3rdparty

# Clean build directories
rm -rf opencv/build
rm -rf opencv_contrib/build

# Save current working directory
cwd=$(pwd)

git clone https://github.com/opencv/opencv.git
cd opencv
git checkout $cvVersion
cd ..

git clone https://github.com/opencv/opencv_contrib.git
cd opencv_contrib
git checkout $cvVersion
cd ..

# Create directory for installation
mkdir opencv/installation

cd opencv
mkdir build
cd build

cmake -D CMAKE_BUILD_TYPE=RELEASE \
            -D CMAKE_INSTALL_PREFIX=$cwd/opencv/installation \
            -D INSTALL_C_EXAMPLES=ON \
            -D WITH_TBB=ON \
            -D WITH_V4L=ON \
        -D WITH_QT=ON \
        -D WITH_OPENGL=ON \
        -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
        -D BUILD_EXAMPLES=ON ..

make -j4
make install







