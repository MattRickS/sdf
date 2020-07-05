cmake_minimum_required(VERSION 3.10)

project(Voxel)

file(GLOB SOURCES "src/*.cpp")

add_executable(test ${SOURCES})
