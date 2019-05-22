cmake_minimum_required(VERSION 3.12)
project(cannyEdge)

set(CMAKE_CXX_STANDARD 14)

add_executable(cannyEdge
        main.cpp
        cannyEdgeDetection.cpp cannyEdgeDetection.h
        headers.h
        utilities.cpp utilities.h)

find_package( OpenCV 3.3.0 REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

target_link_libraries( cannyEdge ${OpenCV_LIBS})