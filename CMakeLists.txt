cmake_minimum_required(VERSION 3.10)

project(SDF)

add_subdirectory(external)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB SOURCES "src/*.cpp" "src/scene/*.cpp")

add_executable(test ${SOURCES})
