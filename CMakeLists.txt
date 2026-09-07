cmake_minimum_required(VERSION 3.15)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(util STATIC
	src/assert.c
	src/dynarr.c
)
target_include_directories(util PUBLIC ./include)
