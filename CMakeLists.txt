cmake_minimum_required(VERSION 3.17)
project(pszt_island_model)

set(CMAKE_CXX_STANDARD 14)

add_executable(pszt_island_model main.cpp proto.cpp generation/New_Population_Factory.cpp generation/New_Population_Factory.h structures.h)