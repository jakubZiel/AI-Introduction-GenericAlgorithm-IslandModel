cmake_minimum_required(VERSION 3.17)
project(pszt_island_model)

set(CMAKE_CXX_STANDARD 14)

add_executable(pszt_island_model main.cpp proto.cpp PopulationGeneration/New_Population_Factory.cpp PopulationGeneration/New_Population_Factory.h)