cmake_minimum_required(VERSION 3.12)

add_library(frequency_analysis OBJECT
    src/complex.cpp
)

target_include_directories(frequency_analysis
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)