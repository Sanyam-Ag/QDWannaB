cmake_minimum_required(VERSION 3.16)
project(tsengine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(core)
add_subdirectory(cli)
add_subdirectory(tests)
 
