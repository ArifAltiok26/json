cmake_minimum_required(VERSION 3.16)

get_filename_component(PROJECT_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${PROJECT_ID})

set(CMAKE_CXX_STANDARD 11)


file(GLOB_RECURSE SrcFiles ./*.cpp)

add_library(${PROJECT_NAME} ${SrcFiles})