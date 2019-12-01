cmake_minimum_required(VERSION 3.10)
project(aoc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dec01_1 dec01_1.cpp)
add_executable(dec01_2 dec01_2.cpp)

include_directories(PRIVATE "~/github/range-v3/include")
