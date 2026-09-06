cmake_minimum_required(VERSION "3.19")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(util C)

add_library(util STATIC src/assert.c)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ./include)
