cmake_minimum_required(VERSION 3.17)
project(pszt_island_model)

set(CMAKE_CXX_STANDARD 14)

add_executable(pszt_island_model main.cpp proto.cpp std-algorithm/evolutionary_operations.h structures/structures.h structures/structures.cpp std-algorithm/evolutionary_operations.cpp)
add_executable(test test/main.cpp proto.cpp std-algorithm/evolutionary_operations.h structures/structures.h structures/structures.cpp std-algorithm/evolutionary_operations.cpp)
