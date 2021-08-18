cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

set(PROJECT_NAME transfer_function)
set(TEST_PROJECT_NAME ${PROJECT_NAME}_tests)
project(${PROJECT_NAME})

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DEFAULT_BUILD_TYPE "Debug")

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g -O0 -fprofile-arcs -ftest-coverage")
endif()
if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif()

set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

option(BUILD_TESTS "Build tests" ON)

########### Add sources and includes ###########
include(GNUInstallDirs)

add_library(${PROJECT_NAME}
    src/transfer_function.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include/
)

################ Unit Tests ###################
if(BUILD_TESTS)
    if(UNIX)
        enable_testing()
        find_package(GTest REQUIRED)
        include_directories(${GTEST_INCLUDE_DIR})
        add_subdirectory(tests)
    else()
        enable_testing()
        include(FetchContent)
        FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
        )
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)
        include(GoogleTest)
        add_subdirectory(tests)
    endif()
endif() #   BUILD_TESTS