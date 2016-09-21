cmake_minimum_required(VERSION 3.6)
project(accelerated_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    ch4/grade.cpp
    ch4/grade.h
    ch4/main.cpp
    ch4/median.cpp
    ch4/median.h
    ch4/Student_info.cpp
    ch4/Student_info.h
    ch5/remove.cpp
    accelerated-cpp.cpp
    Makefile ch5/split-string.cpp ch6/url.cpp ch10/Student_info.h ch10/Student_info.cpp)

add_executable(accelerated_cpp ${SOURCE_FILES})