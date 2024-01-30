# Exemplo de Módulo em C++ com testes

Uma pequena biblioteca como template para bibliotecas em C++.

## Requisitos
- pip3 install lizard
- pip3 install gcovr
- apt install libcpputest-dev cppcheck

## Compilar usando Makefile

- make
- make test
- make cppcheck
- make lizard
- make gcovr
- make gcovr-html

## Compilar usando CMake

- mkdir build
- cd build
- cmake ..
- make test
- cd ..
- gcovr
