set(TARGET_NAME "shapes")
set(TARGET_SOURCES
    shapes.cpp
)

find_package(SDL2 REQUIRED)

add_library(
    ${TARGET_NAME}
    STATIC
        ${TARGET_SOURCES}
)

target_link_libraries(${TARGET_NAME} 
    PRIVATE
        ${SDL2_LIBRARIES}
        utils
)

target_include_directories(
    ${TARGET_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)