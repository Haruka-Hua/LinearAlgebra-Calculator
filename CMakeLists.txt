cmake_minimum_required(VERSION 3.30)
project(LinearAlgebra C)

set(CMAKE_C_STANDARD 17)

add_executable(Determinants Determinants.c)
add_executable(Matrices Matrices.c)
add_executable(MatrixInverse MatrixInverse.c)