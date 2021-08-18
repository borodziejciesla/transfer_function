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

############### Static Analysis ###############
include(cppcheck)
include(cpplint)

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

########### CodeCoverage ##############
if(UNIX)
    if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
        include(CodeCoverage)
        
        set(COVERAGE_EXCLUDES
            '/usr/*'
            '${PROJECT_SOURCE_DIR}/tests/*'
            '${CMAKE_BINARY_DIR}/googletest-src/googletest/include/gtest/*'
            '${CMAKE_BINARY_DIR}/googletest-src/googletest/src/*'
            '${CMAKE_BINARY_DIR}/googletest-src/googlemock/include/gmock/*'
            '${CMAKE_BINARY_DIR}/googletest-src/googlemock/src/*'
        )
        setup_target_for_coverage(coverage ${TEST_PROJECT_NAME} ${PROJECT_NAME})

        set_target_properties(${PROJECT_NAME}
            PROPERTIES
            COMPILE_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage"
        )
    endif() #CMAKE_BUILD_TYPE STREQUAL "Coverage"
endif() # UNIX