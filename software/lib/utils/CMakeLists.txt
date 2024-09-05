set(TARGET_NAME "utils")
set(TARGET_SOURCES
    colors.cpp
    font.cpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_library(
    ${TARGET_NAME}
    STATIC
        ${TARGET_SOURCES}
)

target_link_libraries(${TARGET_NAME} 
    PRIVATE
        ${SDL2_LIBRARIES}
        SDL2_ttf
)

target_include_directories(
    ${TARGET_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)