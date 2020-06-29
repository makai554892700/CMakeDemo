cmake_minimum_required(VERSION 3.6)
project(hello)

set(CMAKE_CXX_STANDARD 14)

file(GLOB ODA_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        )

include_directories(${ODA_INCLUDE_DIRS})

add_library(hello ${CMAKE_CURRENT_SOURCE_DIR}/src/hello.cpp)

add_executable(main
        main.cpp
        )

target_link_libraries(main
        PRIVATE
        hello
        )
