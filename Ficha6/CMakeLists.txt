cmake_minimum_required(VERSION 3.30)
project(Ficha5 C)

set(CMAKE_C_STANDARD 99)

add_executable(Ficha6 main.c
        ponto.c
        retangulo.c
        retangulo.h
        ponto.h
        tabela.c
        tabela.h)
add_executable(ponto.c
        ponto.c
        ponto.h
        retangulo.c
        retangulo.h
        tabela.c
        tabela.h
        )
