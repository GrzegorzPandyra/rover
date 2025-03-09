cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "-g -O0 -fmacro-prefix-map=${CMAKE_CURRENT_SOURCE_DIR}/=")

set(LIB_NAME "WiringPi")
set(ROOT_DIR        "../..")
set(PRIMARY_DIR     "${ROOT_DIR}/primary")
set(SECONDARY_DIR   "${ROOT_DIR}/secondary")
set(AUXILIARY_DIR   "${ROOT_DIR}/auxiliary")
set(DIAGNOSTIC_DIR  "${ROOT_DIR}/diagnostic")
set(LIBRARY_DIR     "${ROOT_DIR}/lib")

add_library(${LIB_NAME} 
    WiringPi.cpp
)

target_include_directories( ${LIB_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${ROOT_DIR}/common/"
    "${DIAGNOSTIC_DIR}/SWC_Logger"
)


target_link_libraries(${LIB_NAME} PUBLIC wiringPi)