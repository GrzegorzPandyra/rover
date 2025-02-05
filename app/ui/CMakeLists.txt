cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(LIB_NAME "ui")

add_library( ${LIB_NAME} 
    ui_input.cpp
    ui_joystick.cpp
    ui_logging.cpp
    ui_monitor.cpp
)

target_include_directories( ${LIB_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    "../../"
    "../dummy_app"
)

target_link_libraries(${LIB_NAME} PUBLIC dummy_app)