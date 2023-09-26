cmake_minimum_required(VERSION 3.12)
project(UNIT)

set(CMAKE_CXX_STANDARD 20)
set(GTEST_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include/googletest/googletest/include)
message(${CMAKE_SOURCE_DIR}/include/googletest/googletest/include)
# set(GTEST_LIBRARIES ${CMAKE_SOURCE_DIR}/include/googletest/build/lib/libgtest.a ${CMAKE_SOURCE_DIR}/include/googletest/build/lib/libgtest_main.a)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(include)
enable_testing()
add_executable(unit main.cpp testUnit.cpp testTemplate.cpp testCpp17.cpp)
target_link_libraries(unit gtest gtest_main)