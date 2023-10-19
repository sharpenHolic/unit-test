cmake_minimum_required(VERSION 3.12)
project(UNIT-TEST)

set(CMAKE_CXX_STANDARD 20)
set(GTEST_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include/googletest/googletest/include)
message(${CMAKE_SOURCE_DIR}/include/googletest/googletest/include)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(include)

enable_testing()
add_executable(unit main.cpp testUnit.cpp testTemplate.cpp testCpp17.cpp
        testMove.cpp
        testDP/testFactory.cpp
        testRecurtion.cpp
        testAlgoruthm/testSort.cpp
)
target_link_libraries(unit gtest gtest_main)