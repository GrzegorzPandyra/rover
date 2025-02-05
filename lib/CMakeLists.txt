cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(LIB_NAME "lib")

add_library(${LIB_NAME} 
    ncurses_wrapper.cpp
    wiringpi_wrapper.cpp
)