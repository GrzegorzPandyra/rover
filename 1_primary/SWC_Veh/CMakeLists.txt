cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "-g -O0 -fmacro-prefix-map=${CMAKE_CURRENT_SOURCE_DIR}/src/=")

set(LIB_NAME "SWC_Veh")

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
    "src/SWC_Veh.cpp"
)

target_include_directories( ${LIB_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/if
    ${CMAKE_CURRENT_SOURCE_DIR}/cfg
    ${COMMON_DIR}
    ${COMMON_DIR}/PeriodicCall
    ${COMMON_DIR}/PWMChannel
    ${CFG_DIR}
    ${INIT_DIR}/SWC_ThreadMgr/if
    ${DIAGNOSTIC_DIR}/SWC_Logger/if
    ${DIAGNOSTIC_DIR}/SWC_StatMon/if
    ${PRIMARY_DIR}/SWC_Pwtr/if
    ${PRIMARY_DIR}/SWC_StSys/if
    ${PRIMARY_DIR}/SWC_Tacho/if
    ${PRIMARY_DIR}/SWC_Fan/if
)

target_link_libraries(${LIB_NAME} PUBLIC PWMChannel     )
target_link_libraries(${LIB_NAME} PUBLIC PeriodicCall   )
target_link_libraries(${LIB_NAME} PUBLIC SWC_ThreadMgr  )
target_link_libraries(${LIB_NAME} PUBLIC SWC_Logger     )
target_link_libraries(${LIB_NAME} PUBLIC SWC_StatMon    )
target_link_libraries(${LIB_NAME} PUBLIC SWC_Pwtr       )
target_link_libraries(${LIB_NAME} PUBLIC SWC_StSys      )
target_link_libraries(${LIB_NAME} PUBLIC SWC_Tacho      )
target_link_libraries(${LIB_NAME} PUBLIC SWC_Fan        )