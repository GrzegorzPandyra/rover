cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(LIB_NAME "steer_sys")
set(ROOT_DIR "../..")
set(PRIMARY_DIR "${ROOT_DIR}/primary")
set(SECONDARY_DIR "${ROOT_DIR}/secondary")
set(AUXILIARY_DIR "${ROOT_DIR}/auxiliary")
set(DIAGNOSTIC_DIR "${ROOT_DIR}/diagnostic")

add_library(${LIB_NAME} 
    "SteeringSystem.cpp"
)

target_include_directories( ${LIB_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${ROOT_DIR}/common/if"
    "${ROOT_DIR}/cfg"
    "${PRIMARY_DIR}/thread_mgr"
    "${DIAGNOSTIC_DIR}/logger"
    "${DIAGNOSTIC_DIR}/status_mon"
)