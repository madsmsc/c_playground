cmake_minimum_required(VERSION 3.16)

SET(PROJECTNAME c_playground)
project(${PROJECTNAME} C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out)
set(CMAKE_VERBOSE_MAKEFILE ON)

ENABLE_LANGUAGE(C)
set(CMAKE_EXECUTABLE_SUFFIX_C ".out")

SET(CMAKE_C_FLAGS "-O0 -g -ffunction-sections -fdata-sections -Wall -std=c99")

SET(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections")

file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

message(STATUS "Found source files: ${SRC_FILES}")

add_executable(${PROJECT_NAME} ${SRC_FILES})
