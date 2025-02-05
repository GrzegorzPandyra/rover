cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(LIB_NAME "dummy_app")

add_library( ${LIB_NAME}
    dummy_app.cpp
)

target_include_directories( ${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
