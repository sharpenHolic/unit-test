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
    tests/core/testUnit.cpp
    tests/core/testClassDrive.cpp
    tests/core/testExplicit.cpp
    tests/core/testEqual.cpp
    tests/core/testLamda.cpp
    tests/core/testMove.cpp
    tests/core/testString.cpp
    tests/core/testStdCopy.cpp
    tests/core/testRecurtion.cpp
    tests/core/testEraseIf.cpp
    tests/core/test_case.cpp
    tests/core/test_const.cpp
    tests/core/test_initial.cpp
    main.cpp
)
target_link_libraries(core_tests GTest::gtest GTest::gtest_main)

add_executable(template_tests
    tests/templates/testTemplate.cpp
    tests/templates/testTemplate2.cpp
    main.cpp
)
target_link_libraries(template_tests GTest::gtest GTest::gtest_main)

add_executable(stl_tests
    tests/stl/testHash.cpp
    tests/stl/testUnorderdMap.cpp
    tests/stl/testSetMerge.cpp
    main.cpp
)
target_link_libraries(stl_tests GTest::gtest GTest::gtest_main)

add_executable(design_pattern_tests
    tests/design_patterns/testFactory.cpp
    tests/design_patterns/testSimpleFactory.cpp
    main.cpp
)
target_link_libraries(design_pattern_tests GTest::gtest GTest::gtest_main)

add_executable(modern_cpp_tests
    tests/modern_cpp/testCpp17.cpp
    tests/modern_cpp/init.cpp
    tests/modern_cpp/testChrono.cpp
    main.cpp
)
target_link_libraries(modern_cpp_tests GTest::gtest GTest::gtest_main)

add_executable(algorithm_tests
    tests/algorithms/testSort.cpp
    main.cpp
)
target_link_libraries(algorithm_tests GTest::gtest GTest::gtest_main)

add_executable(utils_tests
    tests/utils/testClass.cpp
    tests/utils/testClockCrossing.cpp
    tests/utils/testFalsePath.cpp
    tests/utils/testMemGuard.cpp
    main.cpp
)
target_link_libraries(utils_tests GTest::gtest GTest::gtest_main)

# Register the main test executable with CTest
add_test(NAME UnitTests COMMAND unit_test)

# Register specific test executables with CTest
add_test(NAME CoreTests COMMAND core_tests)
add_test(NAME TemplateTests COMMAND template_tests)
add_test(NAME STLTests COMMAND stl_tests)
add_test(NAME DesignPatternTests COMMAND design_pattern_tests)
add_test(NAME ModernCppTests COMMAND modern_cpp_tests)
add_test(NAME AlgorithmTests COMMAND algorithm_tests)
add_test(NAME UtilsTests COMMAND utils_tests)