set(TARGET_NAME "window")
set(TARGET_SOURCES
    window.cpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_library(
    ${TARGET_NAME}
    STATIC
        ${TARGET_SOURCES}
)

target_link_libraries(${TARGET_NAME} 
    PRIVATE
        ${SDL2_LIBRARIES}
        SDL2_image
        utils
)

target_include_directories(
    ${TARGET_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)