cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

target_sources(${PROJECT_NAME} 
    PUBLIC vector/vec2.cpp
    PUBLIC vector/vec3.cpp
    PUBLIC vector/vec4.cpp
    PUBLIC matrix/mat2.cpp
    PUBLIC matrix/mat3.cpp
    PUBLIC matrix/mat4.cpp
    PUBLIC matrix/transformations.cpp
    PUBLIC primitives/sphere.cpp
    PUBLIC raytracer/ray.cpp
    PUBLIC canvas.cpp
    PUBLIC color.cpp
    PUBLIC material.cpp
    PUBLIC camera.cpp
    PUBLIC scene.cpp
    PUBLIC main.cpp
)
