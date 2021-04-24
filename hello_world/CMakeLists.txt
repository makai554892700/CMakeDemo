cmake_minimum_required(VERSION 3.6)
project(hello_world)

file(GLOB SOURCE_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/../hello/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../world/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        )

file(GLOB SOURCE_SO_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/../hello/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/../world/lib
        )

include_directories(
        ${SOURCE_INCLUDE_DIRS}
)

link_directories(
        ${SOURCE_SO_DIRS}
)

#add_library(hello_world SHARED
#        ${CMAKE_CURRENT_SOURCE_DIR}/src/hello_world.cpp
#        )

add_library(hello_world_static STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/hello_world.cpp
        )

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    message("system is windows.")
    file(GLOB SOURCE_SO_FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/../hello/lib/*.lib
            ${CMAKE_CURRENT_SOURCE_DIR}/../world/lib/*.lib
            )
else ()
    file(GLOB SOURCE_SO_FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/../hello/lib/*.a
            ${CMAKE_CURRENT_SOURCE_DIR}/../world/lib/*.a
            )
endif ()

add_executable(main main.cpp)

target_link_libraries(main
        PRIVATE
        ${SOURCE_SO_FILES}
        hello_world_static
        )
