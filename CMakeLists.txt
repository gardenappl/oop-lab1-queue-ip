cmake_minimum_required(VERSION 3.9)
project(oop-lab1)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
include_directories("${CMAKE_BINARY_DIR}/include")
set(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB SOURCES
		"${PROJECT_SOURCE_DIR}/**/*.cpp",
		"${PROJECT_SOURCE_DIR}/oop-lab1.cpp")

add_executable(oop-lab1 ${SOURCES})