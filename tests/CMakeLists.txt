set(TEST_PROJECT_NAME transfer_function_tests)

project(${TEST_PROJECT_NAME} VERSION 0.1)

add_executable(${TEST_PROJECT_NAME}
    transfer_function_tests.cpp
    polynomial_tests.cpp

    $<TARGET_OBJECTS:transfer_function>
    $<TARGET_OBJECTS:polynomial>
)

if(UNIX)
    set(GTEST_LINKS gtest_main GTest::GTest GTest::Main)
else()
    set(GTEST_LINKS gtest_main)
endif() #   UNIX

target_link_libraries(${TEST_PROJECT_NAME}
    ${GTEST_LINKS}
    
    transfer_function
    polynomial
)