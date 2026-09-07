cmake_minimum_required(VERSION "3.19")

project(util C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(util STATIC
	src/assert.c
	src/dynarr.c
)
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
