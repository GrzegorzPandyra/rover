cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(LIB_NAME "os")

add_library( ${LIB_NAME} 
    os_scheduler.cpp
    os_task.cpp
)

target_include_directories( ${LIB_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    "../../"
    "../ui"
    "../dummy_app"
    "../pwr_mon"
    "../../drv/i2c"
    "../../drv/light_ctrl"
    "../../drv/steer_sys"
    "../../drv/pwtr"
    "../../drv/fan_ctrl"
)

target_link_libraries(os PUBLIC light_ctrl)