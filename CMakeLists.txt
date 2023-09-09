cmake_minimum_required(VERSION 3.15)

project(zuoye3)

set(OpenCV_DIR /home/xing/opencv-4.5.3/build)

find_package(OpenCV 4.5.3 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# include
add_executable(zuoye3 zuoye3.cpp)

target_link_libraries(zuoye3 ${OpenCV_LIBS})