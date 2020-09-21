cmake_minimum_required(VERSION 3.6)
project(hello_world)

file(GLOB SOURCE_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/../hello/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../world/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/../hello_world/inc
        )

file(GLOB SOURCE_SO_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
        )

include_directories(
        ${SOURCE_INCLUDE_DIRS}
)

link_directories(
        ${SOURCE_SO_DIRS}
)

add_library(hello_world_static STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/hello_world.cpp
        )

target_link_libraries(hello_world_static
        PRIVATE
        -Wl,--start-group
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libhello_static.a
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libworld_static.a
        -Wl,--end-group
        -static
        )

add_library(hello_world SHARED
        ${CMAKE_CURRENT_SOURCE_DIR}/src/hello_world.cpp
        )

#target_link_libraries(hello_world
#        -Wl,--start-group
#        -Wl,-Bstatic
#        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libworld_static.a
#        -Wl,-Bdynamic
#        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libhello.so
#        -static -Wl,-Bdynamic,-lgcc_s,-Bstatic
#        -Wl,--end-group
#        )

target_link_libraries(hello_world
        -Wl,--start-group
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libhello.so
        ${CMAKE_CURRENT_SOURCE_DIR}/lib/libworld.so
        -Wl,--end-group
        )

add_executable(main main.cpp)

target_link_libraries(main
        -Wl,--start-group
        hello_world
        -Wl,--end-group
        )
