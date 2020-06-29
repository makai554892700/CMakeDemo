cmake_minimum_required(VERSION 3.6)
project(world)

set(CMAKE_CXX_STANDARD 14)

file(GLOB ODA_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        )

add_library(world ${CMAKE_CURRENT_SOURCE_DIR}/src/world.cpp)

include_directories(${ODA_INCLUDE_DIRS})

add_executable(main
        main.cpp
        )

target_link_libraries(main
        PRIVATE
        world
        )
