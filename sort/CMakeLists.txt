
cmake_minimum_required(VERSION 3.10)
# set the project name

project(sort
VERSION 1.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(test tests/test.cpp tests/sort.cpp tests/utils.cpp)
target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/include)

# add the executable
