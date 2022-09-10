cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

target_sources(${PROJECT_NAME} 
    PRIVATE main.cpp
    PRIVATE vector/vec2.cpp
    PRIVATE vector/vec3.cpp
    PRIVATE vector/vec4.cpp
    PRIVATE canvas.cpp
    PRIVATE color.cpp
)
