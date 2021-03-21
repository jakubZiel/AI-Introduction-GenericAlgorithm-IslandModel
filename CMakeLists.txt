cmake_minimum_required(VERSION 3.17)
project(pszt_island_model)

set(CMAKE_CXX_STANDARD 14)

add_executable(pszt_island_model main.cpp proto.cpp New_Population_Factory.cpp New_Population_Factory.h)