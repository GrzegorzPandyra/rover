cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project(rover VERSION 1.0)

add_executable(${PROJECT_NAME} "app/init/init.cpp")


add_subdirectory("lib")
add_subdirectory("app/os")
add_subdirectory("app/dummy_app")
add_subdirectory("app/ui")

target_link_libraries(${PROJECT_NAME} PUBLIC os)
target_link_libraries(${PROJECT_NAME} PUBLIC wiringPi)
target_link_libraries(${PROJECT_NAME} PUBLIC ncurses)
target_link_libraries(${PROJECT_NAME} PUBLIC lib)
target_link_libraries(${PROJECT_NAME} PUBLIC ui)
target_link_libraries(${PROJECT_NAME} PUBLIC dummy_app)

target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    "app/ui"
)