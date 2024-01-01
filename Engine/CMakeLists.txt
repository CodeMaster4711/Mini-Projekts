cmake_minimum_required(VERSION 3.27)
project(Engine C)

set(CMAKE_C_STANDARD 23)

add_executable(Engine main.c
        database.h
        user_input.h
        programm_start_engine.h
)
