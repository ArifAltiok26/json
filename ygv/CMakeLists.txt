cmake_minimum_required(VERSION 3.16)

get_filename_component(PROJECT_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${PROJECT_ID})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(json)

file(GLOB SrcFiles ./*.cpp)
set(
    PROJECT_LIBS
    json
)

add_library(${PROJECT_NAME} ${SrcFiles})

target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBS})
