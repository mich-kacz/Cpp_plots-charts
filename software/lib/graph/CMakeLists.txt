set(TARGET_NAME "graph")
set(TARGET_SOURCES
    dataSerie.cpp
    graph.cpp
    column/columnGraph.cpp
    linear/linearGraph.cpp
    pie/pieGraph.cpp
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
        window
        shapes
)

target_include_directories(
    ${TARGET_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)