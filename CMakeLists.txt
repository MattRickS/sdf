cmake_minimum_required(VERSION 3.10)

project(SDF)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB SOURCES "src/*.cpp" "src/render/*.cpp" "src/sdf/*.cpp" "src/vec/*.cpp")

add_executable(test ${SOURCES})
