cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project(rover VERSION 1.0)
set(PRIMARY_DIR "primary")
set(DIAGNOSTIC_DIR "diagnostic")

add_executable(${PROJECT_NAME} "${PRIMARY_DIR}/init/init.cpp")


# add_subdirectory("lib")
add_subdirectory("${PRIMARY_DIR}/thread_mgr")
add_subdirectory("${DIAGNOSTIC_DIR}/logger")
# add_subdirectory("app/dummy_app")
# add_subdirectory("app/ui")
# add_subdirectory("app/veh")
# add_subdirectory("app/pwr_mon")
# add_subdirectory("drv/i2c")
# add_subdirectory("drv/light_ctrl")
# add_subdirectory("drv/tacho")
# add_subdirectory("drv/steer_sys")
# add_subdirectory("drv/pwtr")
# add_subdirectory("drv/fan_ctrl")
# add_subdirectory("drv/buzzer")
# add_subdirectory("common/pwm_channel")

target_link_libraries(${PROJECT_NAME} PUBLIC pthread)
target_link_libraries(${PROJECT_NAME} PUBLIC thread_mgr)
target_link_libraries(${PROJECT_NAME} PUBLIC logger)
# target_link_libraries(${PROJECT_NAME} PUBLIC ncurses)
# target_link_libraries(${PROJECT_NAME} PUBLIC lib)
# target_link_libraries(${PROJECT_NAME} PUBLIC ui)
# target_link_libraries(${PROJECT_NAME} PUBLIC veh)
# target_link_libraries(${PROJECT_NAME} PUBLIC dummy_app)
# target_link_libraries(${PROJECT_NAME} PUBLIC i2c)
# target_link_libraries(${PROJECT_NAME} PUBLIC light_ctrl)
# target_link_libraries(${PROJECT_NAME} PUBLIC tacho)
# target_link_libraries(${PROJECT_NAME} PUBLIC pwm_channel)
# target_link_libraries(${PROJECT_NAME} PUBLIC pwr_mon)
# target_link_libraries(${PROJECT_NAME} PUBLIC steer_sys)
# target_link_libraries(${PROJECT_NAME} PUBLIC pwtr)
# target_link_libraries(${PROJECT_NAME} PUBLIC fan_ctrl)
# target_link_libraries(${PROJECT_NAME} PUBLIC buzzer)

# target_include_directories(${PROJECT_NAME} PUBLIC 
#     ${CMAKE_CURRENT_SOURCE_DIR}
#     "app/ui"
# )