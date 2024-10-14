cmake_minimum_required(VERSION 3.10)

project(ArrayPerformance)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_COMPILER_IS_GNUXX)
	add_compile_options(-Wall -Wextra -pedantic)
endif()

# Add executable for main application
add_executable(ArrayPerformance main.cpp sortutils.cpp)

# Find Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the Unit Test Runner executable
add_executable(UnitTestRunner TestPerformance.cpp sortutils.cpp)
target_link_libraries(UnitTestRunner ${GTEST_LIBRARIES} pthread)

# Enable testing
enable_testing()
add_test(UnitTest UnitTestRunner)
