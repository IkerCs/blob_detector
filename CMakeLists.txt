cmake_minimum_required(VERSION 3.27)
project(opencv)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include)

add_executable(opencv main.cpp
        lib/image_preprocessing.cpp
        include/blob_detection.h
        lib/blob_detection.cpp)

target_link_libraries(opencv ${OpenCV_LIBS})
