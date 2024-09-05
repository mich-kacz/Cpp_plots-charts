set(TARGET_NAME "app")

find_package(SDL2 REQUIRED)

set(TARGET_SOURCES
        src/main.cpp
)

add_executable(${TARGET_NAME} ${TARGET_SOURCES})

target_link_libraries(${TARGET_NAME}
    PRIVATE
        shapes
        window
        utils
        graph
)

include_directories(${TARGET_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
