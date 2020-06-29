cmake_minimum_required(VERSION 3.16)
project(hello_world)

set(CMAKE_CXX_STANDARD 14)

file(GLOB ODA_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/../hello/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../world/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../hello_world/inc
        )

file(GLOB ODA_SO_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/../hello/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/../world/lib
        )

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    message("system is windows.")
    file(GLOB ODA_SO_FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/../hello/lib/*.lib
            ${CMAKE_CURRENT_SOURCE_DIR}/../world/lib/*.lib
            )
else ()
    file(GLOB ODA_SO_FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/../hello/lib/*.a
            ${CMAKE_CURRENT_SOURCE_DIR}/../world/lib/*.a
            )
endif ()

include_directories(
        ${ODA_INCLUDE_DIRS}
)

link_directories(
        ${ODA_SO_DIRS}
)

add_library(hello_world ${CMAKE_CURRENT_SOURCE_DIR}/src/hello_world.cpp)

target_link_libraries(hello_world
        -Wl,--start-group
        ${ODA_SO_FILES}
        -Wl,--end-group
        )

add_executable(main main.cpp)

target_link_libraries(main
        PRIVATE
        -Wl,--start-group
        ${ODA_SO_FILES}
        -Wl,--end-group
        hello_world
        )

