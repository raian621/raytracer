cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(raytracer)

add_executable(${PROJECT_NAME})

add_subdirectory(src)
include_directories(include)