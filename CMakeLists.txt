cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MergeSortTests)
# standard C++
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/test)
set(TEST_DIR ${CMAKE_BINARY_DIR}/build)

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add the main project
#add_subdirectory(. MergeSort)

# Add the test executable
add_executable(runTests test/test.cpp)

# Link the test executable against gtest & gtest_main
target_link_libraries(runTests gtest_main)

# Enable CTest
enable_testing()

# Discover tests
include(GoogleTest)
gtest_discover_tests(runTests)

add_custom_target(cleanup
    COMMAND ${CMAKE_COMMAND} -E rm -rf bin lib CMakeFiles/ MergeSort/ cmake_install.cmake Makefile _deps/  Testing/ CMakeCache.txt CTestTestfile.cmake SortArray SortArrayTest build/
    COMMENT "Czyszczenie katalogu build/test..."
)