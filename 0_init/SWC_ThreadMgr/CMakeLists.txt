cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "-g -O0 -fmacro-prefix-map=${CMAKE_CURRENT_SOURCE_DIR}/=")

set(LIB_NAME "SWC_ThreadMgr")

set(ROOT_DIR        ../..                   )
set(INIT_DIR        ${ROOT_DIR}/0_init      )
set(PRIMARY_DIR     ${ROOT_DIR}/1_primary   )
set(SECONDARY_DIR   ${ROOT_DIR}/2_secondary )
set(AUXILIARY_DIR   ${ROOT_DIR}/3_auxiliary )
set(DIAGNOSTIC_DIR  ${ROOT_DIR}/4_diagnostic)
set(CFG_DIR         ${ROOT_DIR}/5_cfg       )
set(COMMON_DIR      ${ROOT_DIR}/6_common    )
set(LIBRARY_DIR     ${ROOT_DIR}/7_lib       )

add_library(${LIB_NAME} 
    src/SWC_ThreadMgr.cpp
    src/ThreadContext.cpp
)

target_include_directories( ${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/if
    ${COMMON_DIR}
)