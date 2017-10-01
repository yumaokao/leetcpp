cmake_minimum_required(VERSION 3.0)
project(leetcpp)
set(CMAKE_PROJECT_NAME leetcpp)
set(CMAKE_BUILD_TYPE DEBUG)

## for default arch ##
set(ARCH x86_64)

# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SWNR_SRCS)
add_definitions("-std=c++11")

## problems
add_executable(ans-1 answers/1/ans.cpp)
add_executable(ans-2 answers/2/ans.cpp)
add_executable(ans-14 answers/14/ans.cpp)
add_executable(ans-15 answers/15/ans.cpp)

# vim:fileencoding=UTF-8:ts=4:sw=4:sta:et:sts=4:ai
