cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "-g -O0 -fmacro-prefix-map=${CMAKE_CURRENT_SOURCE_DIR}/=")

set(LIB_NAME "SWC_Logger")
set(ROOT_DIR "../..")

add_library(${LIB_NAME} 
    "SWC_Logger.cpp"
)

target_include_directories( ${LIB_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${ROOT_DIR}/common"
    "${ROOT_DIR}/primary/SWC_ThreadMgr"
    "${ROOT_DIR}/lib/NCurses"
)