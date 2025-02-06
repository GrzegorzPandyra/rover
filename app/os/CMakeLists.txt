cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(LIB_NAME "os")
set(ROOT_DIR "../..")

add_library( ${LIB_NAME} 
    os_scheduler.cpp
    os_task.cpp
)

target_include_directories( ${LIB_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    "${ROOT_DIR}"
    "../ui"
    "../dummy_app"
    "../pwr_mon"
    "${ROOT_DIR}/drv/i2c"
    "${ROOT_DIR}/drv/light_ctrl"
    "${ROOT_DIR}/drv/steer_sys"
    "${ROOT_DIR}/drv/pwtr"
    "${ROOT_DIR}/drv/fan_ctrl"
    "${ROOT_DIR}/drv/buzzer"
    "${ROOT_DIR}/drv/tacho"
)

target_link_libraries(os PUBLIC light_ctrl)