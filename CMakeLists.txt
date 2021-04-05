cmake_minimum_required(VERSION 3.17)
project(pszt_island_model)

set(CMAKE_CXX_STANDARD 14)

add_executable(pszt_island_model main.cpp std-algorithm/evolutionary_operations.h structures/structures.h structures/structures.cpp std-algorithm/evolutionary_operations.cpp std-algorithm/Evolution.cpp std-algorithm/Evolution.h std-algorithm/Evolution.cpp island-model-algorithm/Island_model_evolution.cpp island-model-algorithm/Island_model_evolution.h)
add_executable(test test/main.cpp std-algorithm/evolutionary_operations.h structures/structures.h structures/structures.cpp std-algorithm/evolutionary_operations.cpp std-algorithm/Evolution.cpp std-algorithm/Evolution.h std-algorithm/Evolution.cpp island-model-algorithm/Island_model_evolution.cpp island-model-algorithm/Island_model_evolution.h )
add_executable(cec_test CEC_2017/main.cpp CEC_2017/cec17_test_func.cpp)

include_directories(${PROJECT_SOURCE_DIR})