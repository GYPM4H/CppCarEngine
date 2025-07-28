cmake_minimum_required(VERSION 3.31)
project(CppCarEngine)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 3 COMPONENTS System Graphics Window)

add_executable(CppCarEngine
        main.cpp
        include/crankshaft.hpp
        src/crankshaft.cpp
        include/utils.hpp
        src/utils.cpp
        include/connecting_rod.hpp
        src/connecting_rod.cpp
        include/piston.hpp
        src/piston.cpp)

target_include_directories(CppCarEngine PUBLIC include)
target_link_libraries(CppCarEngine PRIVATE SFML::Graphics SFML::Window SFML::System)