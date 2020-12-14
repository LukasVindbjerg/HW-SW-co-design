project(assignment_8)
cmake_minimum_required(VERSION 3.0)

add_library(cpp
    alarm_system.cpp
    camera.cpp
)

target_include_directories(cpp PUBLIC include)

add_executable(tests
    main.cpp
)

target_link_libraries(tests 
    cpp
)