cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(PROJECT_NAME Roman)
project(${PROJECT_NAME})

set(TESTS_T "test_${PROJECT_NAME}")
set(PROJECT_LIBRARY "myfunctoin")

include_directories(gtest)
include_directories("${PROJECT_LIBRARY}")

#set(PROJECT_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_subdirectory(src)
add_subdirectory(gtest)
add_subdirectory(test)
add_subdirectory(myfunctoin)
#add_subdirectory(include)