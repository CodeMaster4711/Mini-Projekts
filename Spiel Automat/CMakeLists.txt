cmake_minimum_required(VERSION 3.27)
project(Spiel_Automat C)

set(CMAKE_C_STANDARD 23)

add_executable(Spiel_Automat main.c
        datenbank.h)
