cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(LIB_NAME "pwtr")
set(ROOT_DIR "../..")

add_library(${LIB_NAME} 
    "pwtr.cpp"
)

target_link_libraries(${LIB_NAME} PUBLIC pwm_channel)
target_link_libraries(${LIB_NAME} PUBLIC fan_ctrl)

target_include_directories( ${LIB_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${ROOT_DIR}/app/ui"
    "${ROOT_DIR}/drv/fan_ctrl"
    "${ROOT_DIR}/common/pwm_channel"
)