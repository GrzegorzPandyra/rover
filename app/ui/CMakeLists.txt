cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(LIB_NAME "ui")
set(ROOT_DIR "../..")

add_library( ${LIB_NAME} 
    ui_input.cpp
    ui_joystick.cpp
    ui_logging.cpp
    ui_monitor.cpp
)

target_include_directories( ${LIB_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    "${ROOT_DIR}"
    "${ROOT_DIR}/app/dummy_app"
    "${ROOT_DIR}/app/veh"
    "${ROOT_DIR}/app/pwr_mon"
    "${ROOT_DIR}/drv/light_ctrl"
    "${ROOT_DIR}/drv/pwtr"
    "${ROOT_DIR}/drv/steer_sys"
    "${ROOT_DIR}/drv/fan_ctrl"
)

target_link_libraries(${LIB_NAME} PUBLIC dummy_app)
target_link_libraries(${LIB_NAME} PUBLIC light_ctrl)