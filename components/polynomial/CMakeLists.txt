cmake_minimum_required(VERSION 3.16)

add_library(polynomial
    src/polynomial.cpp
)

target_include_directories(polynomial
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)