cmake_minimum_required(VERSION 3.31)
project(CppCarEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(CppCarEngine main.cpp
        include/crankshaft.hpp
        src/crankshaft.cpp
        include/utils.hpp
        src/utils.cpp
        include/connecting_rod.hpp
        src/connecting_rod.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)
