cmake_minimum_required(VERSION 3.16)

get_filename_component(PROJECT_ID ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${PROJECT_ID})


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/version.cpp.in ${CMAKE_CURRENT_SOURCE_DIR}/version.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB SrcFiles 
    *.cpp
    core/*.cpp
    types/*.cpp
    utils/*.cpp
)

set(
    PROJECT_LIBS
)

add_library(${PROJECT_NAME} ${SrcFiles})

target_link_libraries(${PROJECT_NAME} ${PROJECT_LIBS})

if(BUILD_JSON_EXAMPLES)
file(GLOB examples examples/*.cpp)
    foreach(example ${examples})
        get_filename_component(original_name ${example} NAME_WE)
        set(example_name ygv_json_exp_${original_name})
        add_executable(${example_name} ${example})
        target_link_libraries(${example_name} json)        
    endforeach()


endif()
