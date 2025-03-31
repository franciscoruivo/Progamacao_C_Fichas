cmake_minimum_required(VERSION 3.30)
project(Ficha5 C)

set(CMAKE_C_STANDARD 99)

add_executable(Ficha5 main.c
        ponto.c
        retangulo.c
        retangulo.h)
add_executable(ponto.c
        ponto.c
        retangulo.c
        retangulo.h)
