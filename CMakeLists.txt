cmake_minimum_required(VERSION 3.12)
project(UNIT-TEST)

set(CMAKE_CXX_STANDARD 20)
set(GTEST_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include/googletest/googletest/include)
message(${CMAKE_SOURCE_DIR}/include/googletest/googletest/include)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(include)

enable_testing()
add_executable(unit testUnit.cpp testTemplate.cpp testCpp17.cpp
        testMove.cpp
        testDesignPattern/testSimpleFactory.cpp
        testRecurtion.cpp
        testAlgoruthm/testSort.cpp
        main.cpp
        testHash.cpp
        testClassDrive.cpp
        testWork/testMemGuard.cpp
        testTemplate2.cpp
        testWork/testClockCrossing.cpp
        testEraseIf.cpp
        testWork/testFalsePath.cpp
        testUnorderdMap.cpp
        testStdCopy.cpp
        testEqual.cpp
        testSetMerge.cpp
        testString.cpp
        testExplicit.cpp
)
target_link_libraries(unit gtest gtest_main)