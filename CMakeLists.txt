cmake_minimum_required(VERSION 3.0)
project(projeto_exemplo)

# ============================================================================
#  Biblioteca Exemplo
# ============================================================================

SET(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")

add_library(exemplo src/exemplo.cpp)

# ============================================================================
#  Tests
# ============================================================================

enable_testing()

include_directories("./src")
add_executable(teste_exemplo tests/teste_exemplo.cpp)
target_link_libraries(teste_exemplo exemplo CppUTest CppUTestExt)
add_test(NAME teste_exemplo COMMAND teste_exemplo)