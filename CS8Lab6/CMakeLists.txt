cmake_minimum_required(VERSION 3.26)
project(CS8Lab6)

set(CMAKE_CXX_STANDARD 17)

add_executable(CS8Lab6 main.cpp
        mystring.h
)
add_executable(new_target mystring.cpp
        mystring.cpp)
