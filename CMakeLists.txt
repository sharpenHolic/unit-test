cmake_minimum_required(VERSION 3.12)
project(unit_test)

set(CMAKE_CXX_STANDARD 23)

# Find Google Test package
find_package(GTest REQUIRED)

# Create the main test executable
enable_testing()

# Collect all test files
file(GLOB_RECURSE TEST_SOURCES 
    "tests/core/*.cpp"
    "tests/templates/*.cpp" 
    "tests/stl/*.cpp"
    "tests/design_patterns/*.cpp"
    "tests/modern_cpp/*.cpp"
    "tests/algorithms/*.cpp"
    "tests/utils/*.cpp"
)

# Create the main test executable
add_executable(unit_test ${TEST_SOURCES} main.cpp)
target_link_libraries(unit_test GTest::gtest GTest::gtest_main)

# Create specific test executables for different categories
add_executable(core_tests 
    tests/core/testUnit_test.cpp
    tests/core/testClassDrive_test.cpp
    tests/core/testExplicit_test.cpp
    tests/core/testEqual_test.cpp
    tests/core/testLamda_test.cpp
    tests/core/testMove_test.cpp
    tests/core/testString_test.cpp
    tests/core/testStdCopy_test.cpp
    tests/core/testRecurtion_test.cpp
    tests/core/testEraseIf_test.cpp
    tests/core/test_case_test.cpp
    tests/core/test_const_test.cpp
    tests/core/test_initial_test.cpp
    main.cpp
)
target_link_libraries(core_tests GTest::gtest GTest::gtest_main)

add_executable(template_tests
    tests/templates/testTemplate_test.cpp
    tests/templates/testTemplate2_test.cpp
    main.cpp
)
target_link_libraries(template_tests GTest::gtest GTest::gtest_main)

add_executable(stl_tests
    tests/stl/testHash_test.cpp
    tests/stl/testUnorderdMap_test.cpp
    tests/stl/testSetMerge_test.cpp
    main.cpp
)
target_link_libraries(stl_tests GTest::gtest GTest::gtest_main)

add_executable(design_pattern_tests
    tests/design_patterns/testFactory_test.cpp
    tests/design_patterns/testSimpleFactory_test.cpp
    main.cpp
)
target_link_libraries(design_pattern_tests GTest::gtest GTest::gtest_main)

add_executable(modern_cpp_tests
    tests/modern_cpp/testCpp17_test.cpp
    tests/modern_cpp/init_test.cpp
    tests/modern_cpp/testChrono_test.cpp
    main.cpp
)
target_link_libraries(modern_cpp_tests GTest::gtest GTest::gtest_main)

add_executable(algorithm_tests
    tests/algorithms/testSort_test.cpp
    main.cpp
)
target_link_libraries(algorithm_tests GTest::gtest GTest::gtest_main)

add_executable(utils_tests
    tests/utils/testClass_test.cpp
    tests/utils/testClockCrossing_test.cpp
    tests/utils/testFalsePath_test.cpp
    tests/utils/testMemGuard_test.cpp
    main.cpp
)
target_link_libraries(utils_tests GTest::gtest GTest::gtest_main)