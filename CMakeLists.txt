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
add_executable(ans-3 answers/3/ans.cpp)
add_executable(ans-5 answers/5/ans.cpp)
add_executable(ans-6 answers/6/ans.cpp)
add_executable(ans-7 answers/7/ans.cpp)
add_executable(ans-9 answers/9/ans.cpp)
add_executable(ans-11 answers/11/ans.cpp)
add_executable(ans-12 answers/12/ans.cpp)
add_executable(ans-13 answers/13/ans.cpp)
add_executable(ans-14 answers/14/ans.cpp)
add_executable(ans-15 answers/15/ans.cpp)
add_executable(ans-17 answers/17/ans.cpp)
add_executable(ans-19 answers/19/ans.cpp)
add_executable(ans-20 answers/20/ans.cpp)
add_executable(ans-21 answers/21/ans.cpp)
add_executable(ans-22 answers/22/ans.cpp)
add_executable(ans-26 answers/26/ans.cpp)
add_executable(ans-28 answers/28/ans.cpp)
add_executable(ans-29 answers/29/ans.cpp)

# vim:fileencoding=UTF-8:ts=4:sw=4:sta:et:sts=4:ai
