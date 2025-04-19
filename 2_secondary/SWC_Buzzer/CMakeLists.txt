cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "-g -O0 -fmacro-prefix-map=${CMAKE_CURRENT_SOURCE_DIR}/=")

set(LIB_NAME "SWC_Buzzer")
set(ROOT_DIR "../..")
set(INIT_DIR        ${ROOT_DIR}/0_init      )
set(PRIMARY_DIR     ${ROOT_DIR}/1_primary   )
set(SECONDARY_DIR   ${ROOT_DIR}/2_secondary )
set(AUXILIARY_DIR   ${ROOT_DIR}/3_auxiliary )
set(DIAGNOSTIC_DIR  ${ROOT_DIR}/4_diagnostic)
set(CFG_DIR         ${ROOT_DIR}/5_cfg       )
set(COMMON_DIR      ${ROOT_DIR}/6_common    )
set(LIBRARY_DIR     ${ROOT_DIR}/7_lib       )

add_library(${LIB_NAME} 
    "src/SWC_Buzzer.cpp"
)

target_include_directories( ${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/if
    ${CMAKE_CURRENT_SOURCE_DIR}/cfg
    ${COMMON_DIR}
    ${COMMON_DIR}/DelayedCall
    ${INIT_DIR}/SWC_ThreadMgr/if
    ${DIAGNOSTIC_DIR}/SWC_Logger/if
    ${LIBRARY_DIR}/WiringPi/if
)

target_link_libraries(${LIB_NAME} PUBLIC DelayedCall)