cmake_minimum_required(VERSION 3.6)
project(ctemp)

set(CMAKE_CXX_STANDARD 14)

file(GLOB ODA_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/hello/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/world/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/hello_world/inc
        )

file(GLOB ODA_SO_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/hello/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/world/lib
        ${CMAKE_CURRENT_SOURCE_DIR}/hello_world/lib
        )

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    message("system is windows.")
    file(GLOB ODA_SO_FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/hello/lib/*.lib
            ${CMAKE_CURRENT_SOURCE_DIR}/world/lib/*.lib
            ${CMAKE_CURRENT_SOURCE_DIR}/hello_world/lib/*.lib
            )
else ()
    file(GLOB ODA_SO_FILES
            ${CMAKE_CURRENT_SOURCE_DIR}/hello/lib/*.a
            ${CMAKE_CURRENT_SOURCE_DIR}/world/lib/*.a
            ${CMAKE_CURRENT_SOURCE_DIR}/hello_world/lib/*.a
            )
endif ()

message("ODA_SO_FILES = ${ODA_SO_FILES}")

include_directories(
        ${ODA_INCLUDE_DIRS}
)

link_directories(
        ${ODA_SO_DIRS}
)

add_executable(ctemp
        main.cpp
        )

target_link_libraries(ctemp
        PRIVATE
        ${ODA_SO_FILES}
        )


