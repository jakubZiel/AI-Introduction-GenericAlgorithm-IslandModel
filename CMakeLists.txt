cmake_minimum_required(VERSION 3.17)
project(pszt_island_model)

set(CMAKE_CXX_STANDARD 14)

add_executable(cec_test CEC_2017/main.cpp CEC_2017/cec17_test_func.cpp CEC_API/cec2017.h structures/structures.h structures/structures.cpp)
add_executable(test_integration integration/main.cpp std-algorithm/evolutionary_operations.h structures/structures.h structures/structures.cpp std-algorithm/evolutionary_operations.cpp std-algorithm/Evolution.h island-model-algorithm/Island_model_evolution.h CEC_API/cec2017.h CEC_2017/cec17_test_func.cpp std-algorithm/Evolution.cpp island-model-algorithm/Island_model_evolution.cpp benchmark/benchmark.h CEC_API/cec2017.cpp benchmark/benchmark.cpp)

include_directories(${PROJECT_SOURCE_DIR})